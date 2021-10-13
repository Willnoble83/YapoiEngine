#pragma once
#include "YAPOI_SceneNode.h"

namespace YapoiEngine
{

	class nPawn : public eSceneNode
	{
	public:
		nPawn(std::string name) : eSceneNode(name) {};
		
		virtual bool Initialise() override;

		virtual void Move(vector2D Direction);


		virtual float GetMovementSpeed() { return _moveSpeed; }
		virtual float GetDefaultMoveSpeed() { return 600; }
	protected:
		virtual bool getDoesRender() override;
		virtual void SetMovementSpeed(float newSpeed) { _moveSpeed = newSpeed; }
		float _moveSpeed = 0;
	};
}

