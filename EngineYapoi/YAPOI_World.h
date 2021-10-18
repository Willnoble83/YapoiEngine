#pragma once
#include "YAPOI_SceneNode.h"
#include <rapidxml.hpp>
#include <rapidxml_utils.hpp>
#include <rapidxml_iterators.hpp>
#include <rapidxml_print.hpp>

namespace YapoiEngine
{
	class eWorld : public eSceneNode
	{
	public:
		eWorld(std::string name, EngineModuleRefs refs) : eSceneNode(name) { _engineRef = refs.engineRef; _worldRef = refs.worldRef; _rendererRef = refs.rendererRef; _inputmanageRef = refs.inputmanageRef; };
		virtual bool Initialise() override;

		virtual void Tick() override;

		void LoadFromFile(const char* File);
		
		void ParseChildren(rapidxml::xml_node<>* node, eSceneNode* parentNode);
	};
}