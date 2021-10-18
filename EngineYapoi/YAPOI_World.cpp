#include "YAPOI_World.h"
#include "YAPOI_SceneNode.h"
#include "nDecal.h"
#include "nAnimatedDecal.h"
#include "YAPOI_Character.h"
#include <iostream>
#include "mSceneNodeFactory.h"
#include <fstream>


bool YapoiEngine::eWorld::Initialise()
{
	_renderPriority = 0;
	_currentimage = "Resources/PinkSquare.bmp";

	nAnimatedDecal* newAnimDecal = new nAnimatedDecal("TestDecal", std::vector<std::string>() = { "Resources/Poggers.bmp", "Resources/PoggersChild.bmp" }, 3);
	Add(newAnimDecal, NODE_CONSTRUCT_ENGINE_REFS());
	UpdateRenderer(_currentimage);
	eSceneNode::Initialise();

	return true;
}

void YapoiEngine::eWorld::Tick()
{
	eSceneNode::Tick();
}

void YapoiEngine::eWorld::LoadFromFile(const char* File)
{
	rapidxml::file<> xmlFile(File);
	rapidxml::xml_document<>* doc = new rapidxml::xml_document<>();
	doc->parse<rapidxml::parse_declaration_node>(xmlFile.data());
	rapidxml::xml_node<>* FirstNode = doc->first_node("rootnode");
	FirstNode = FirstNode->first_node("worldnodes");
	if (FirstNode != 0)
	{
		ParseChildren(FirstNode, this);
	}
	else {
		std::cout << "World Nodes doesn't exist" << std::endl;
	}
}

void YapoiEngine::eWorld::ParseChildren(rapidxml::xml_node<>* node, eSceneNode* parentNode)
{
	rapidxml::xml_node<>* cur_node = node->first_node("scenenode");
	while (cur_node != 0)
	{

		// Read data from xml
		rapidxml::xml_attribute<>* attr = cur_node->first_attribute("class");
		std::string classname = attr->value();

		// Get generic node arguments
		std::vector<std::string> args = {};
		attr = cur_node->first_attribute("name");
		args.push_back(attr->value());
		int LocX = std::stoi(cur_node->first_attribute("locationX")->value());
		int LocY = std::stoi(cur_node->first_attribute("locationY")->value());

		//Find node specific arguments
		rapidxml::xml_node<>* argNode = cur_node->first_node("arg");
		while (argNode != 0)
		{
			args.push_back((std::string)argNode->value());
			argNode = argNode->next_sibling("arg");
		}

		// Create node, and add it, move to specified loc
		eSceneNode* newNode = _engineRef->nodeFactory->CreateSceneNode(classname, args);
		parentNode->Add(newNode, NODE_CONSTRUCT_ENGINE_REFS());
		newNode->SetWorldLocation(vector2D(LocX,LocY));

		// Find any children
		ParseChildren(cur_node, newNode);

		cur_node = cur_node->next_sibling("scenenode");
	}
}

