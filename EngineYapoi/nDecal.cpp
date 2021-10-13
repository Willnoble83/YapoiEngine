#include "nDecal.h"
#include "YAPOI_Vector.h"


YapoiEngine::nDecal::nDecal(std::string name, std::string imagepath) : eSceneNode(name)
{
	_currentimage = imagepath;
}

bool YapoiEngine::nDecal::Initialise()
{
	eSceneNode::Initialise();
	return true;
} 