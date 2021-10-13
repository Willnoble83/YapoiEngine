#include "YAPOI_World.h"
#include "nTestImage.h"

bool YapoiEngine::eWorld::Initialise(mRenderer* Renderer)
{
	nTestImage* TestImage = new nTestImage("TestImage");
	Add(TestImage);
	eSceneNode::Initialise(Renderer);
	UpdateRenderer("Resources/Poggers.bmp");
	return true;
}