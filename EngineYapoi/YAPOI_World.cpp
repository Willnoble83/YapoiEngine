#include "YAPOI_World.h"
#include "YAPOI_SceneNode.h"
#include "nDecal.h"
#include "YAPOI_Character.h"



bool YapoiEngine::eWorld::Initialise()
{
	_renderPriority = 0;
	_currentimage = "Resources/PinkSquare.bmp";

	nCharacter* PC = new nCharacter("PC");
	Add(PC, NODE_CONSTRUCT_ENGINE_REFS());

	UpdateRenderer(_currentimage);
	// Initialise all nodes in the world
	eSceneNode::Initialise();
	// Update renderer with world image


	// Set positions and add velocitys
	PC->SetWorldLocation(vector2D(200, 200));



	return true;
}

void YapoiEngine::eWorld::Tick()
{
	eSceneNode::Tick();
}