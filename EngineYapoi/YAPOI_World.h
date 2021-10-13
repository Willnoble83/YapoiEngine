#pragma once
#include "YAPOI_SceneNode.h"

namespace YapoiEngine
{
	class eWorld : public eSceneNode
	{
	public:
		eWorld(std::string name) : eSceneNode(name) {};
		virtual bool Initialise(mRenderer* Renderer) override;

		virtual void Tick() override;
	};
}