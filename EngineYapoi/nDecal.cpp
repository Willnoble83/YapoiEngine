#include "nDecal.h"
#include "YAPOI_Vector.h"


YapoiEngine::nDecal::nDecal(std::string name, std::string imagepath) : eSceneNode(name)
{
	_currentimage = imagepath;
}

bool YapoiEngine::nDecal::Initialise(mRenderer* Renderer)
{
	eSceneNode::Initialise(Renderer);
	return true;
} 