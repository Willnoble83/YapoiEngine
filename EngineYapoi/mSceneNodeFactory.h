#pragma once
#include <iostream>
#include <vector>

namespace YapoiEngine
{
	class eSceneNode;

	class mSceneNodeFactory
	{

	public:
		mSceneNodeFactory() {};
		eSceneNode* CreateSceneNode(std::string ClassName, std::vector<std::string> Arguments);
	};
}
