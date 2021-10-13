#include "YAPOI_World.h"
#include "YAPOI_SceneNode.h"
#include "nDecal.h"
#include "YAPOI_Character.h"



bool YapoiEngine::eWorld::Initialise()
{
	_renderPriority = 0;
	_currentimage = "Resources/PinkSquare.bmp";
	// Initialise any starting entities in the world.
	nDecal* TestImage = new nDecal("TestImage1", "Resources/Poggers.bmp");
	Add(TestImage, NODE_CONSTRUCT_ENGINE_REFS());

	nCharacter* PC = new nCharacter("PC");
	Add(PC, NODE_CONSTRUCT_ENGINE_REFS());

	nDecal* TestImage2 = new nDecal("testImage2", "Resources/Poggers.bmp");
	Add(TestImage2, NODE_CONSTRUCT_ENGINE_REFS());


	nDecal* TestImage2Child = new nDecal("testImage2-1", "Resources/PoggersChild.bmp");
	TestImage2->Add(TestImage2Child, NODE_CONSTRUCT_ENGINE_REFS());
	UpdateRenderer(_currentimage);
	// Initialise all nodes in the world
	eSceneNode::Initialise();
	// Update renderer with world image


	// Set positions and add velocitys
	PC->SetWorldLocation(vector2D(200, 200));
	TestImage->SetWorldLocation(vector2D(0, 0));
	TestImage->AddVelocity(vector2D(200, 0), true);
	TestImage2->SetWorldLocation(vector2D(500, 500));
	TestImage2->AddVelocity(vector2D(-200, 0), true);
	TestImage2Child->SetWorldLocation(vector2D(500, 500));


	return true;
}

void YapoiEngine::eWorld::Tick()
{
	eSceneNode::Tick();
}