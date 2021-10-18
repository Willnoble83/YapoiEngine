#include "mSceneNodeFactory.h"
#include "nDecal.h"
#include "YAPOI_Pawn.h"
#include "YAPOI_Character.h"

YapoiEngine::eSceneNode* YapoiEngine::mSceneNodeFactory::CreateSceneNode(std::string ClassName, std::vector<std::string> Arguments)
{
	if (ClassName == "decal") // Args: NodeName, ImageToLoad
	{
		return new nDecal(Arguments[0], Arguments[1]);
	}
	if (ClassName == "pawn") // Args: NodeName
	{
		return new nPawn(Arguments[0]);
	}
	if (ClassName == "character") // Args: NodeName
	{
		return new nCharacter(Arguments[0]);
	}
	std::cout << "No Valid Scene Node Type found" << std::endl;
}
