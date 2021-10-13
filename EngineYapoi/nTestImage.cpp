#include "nTestImage.h"
#include "YAPOI_Vector.h"

bool YapoiEngine::nTestImage::Initialise(mRenderer* Renderer)
{
	eSceneNode::Initialise(Renderer);
	SetWorldLocation(YapoiEngine::vector2D(300, 300));
	UpdateRenderer("Resources/TestImageWork.bmp");
	return true;
} 