#pragma once
#include "YAPOI_SceneNode.h"

namespace YapoiEngine
{
	class eWorld : public eSceneNode
	{
	public:
		eWorld(std::string name, EngineModuleRefs refs) : eSceneNode(name) { _engineRef = refs.engineRef; _worldRef = refs.worldRef; _rendererRef = refs.rendererRef; _inputmanageRef = refs.inputmanageRef; };
		virtual bool Initialise() override;

		virtual void Tick() override;

		
	};
}