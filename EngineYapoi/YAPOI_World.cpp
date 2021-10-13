#include "YAPOI_World.h"
#include "nDecal.h"

bool YapoiEngine::eWorld::Initialise(mRenderer* Renderer)
{
	_renderPriority = 0;
	_currentimage = "Resources/PinkSquare.bmp";
	// Initialise any starting entities in the world.
	nDecal* TestImage = new nDecal("TestImage1", "Resources/Poggers.bmp");
	Add(TestImage);

	nDecal* TestImage2 = new nDecal("testImage2", "Resources/Poggers.bmp");
	Add(TestImage2);


	nDecal* TestImage2Child = new nDecal("testImage2-1", "Resources/PoggersChild.bmp");
	TestImage2->Add(TestImage2Child);
	_rendererRef = Renderer;
	UpdateRenderer(_currentimage);
	// Initialise all nodes in the world
	eSceneNode::Initialise(Renderer);
	// Update renderer with world image


	// Set positions and add velocitys
	TestImage->SetWorldLocation(vector2D(0, 0));
	TestImage->AddVelocity(vector2D(10, 10), true);
	TestImage2->SetWorldLocation(vector2D(500, 500));
	TestImage2->AddVelocity(vector2D(-10, -10), true);
	TestImage2Child->SetWorldLocation(vector2D(500, 500));


	return true;
}

void YapoiEngine::eWorld::Tick()
{
	eSceneNode::Tick();
}