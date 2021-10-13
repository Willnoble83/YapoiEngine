#pragma once
#include <iostream>
#include <vector>
#include "YAPOI_Vector.h"
#include "YAPOI_Renderer.h"
#include "YAPOI_Engine.h"
#include "YAPOI_InputManager.h"


#define NODE_CONSTRUCT_ENGINE_REFS() {EngineModuleRefs(_engineRef,_worldRef, _rendererRef, _inputmanageRef) }


namespace YapoiEngine
{
	class YAPOI_Engine;

	class eSceneNode
	{
	public:
		eSceneNode(std::string name) { _name = name; _worldLocation = vector2D(0,0), _velocity = vector2D(0,0); }
		~eSceneNode(void) { };

		// Node Functions
		virtual bool Initialise();
		virtual void Tick();
		virtual void Update(vector2D change);
		virtual void Shutdown();
		virtual void ReceiveInput(SDL_Keycode Key);

		void SetWorldLocation(vector2D newLoc);
		vector2D AddVelocity(vector2D newVel, bool bOverride);

		void UpdateRenderer(const std::string& file);
		void UpdateRenderPriority(int newPrio);

		virtual void Add(eSceneNode* node, EngineModuleRefs modules);
		virtual void Remove(eSceneNode* node);
		virtual eSceneNode* Find(std::string name);
		std::string GetName() { return _name; }

		bool DoesTick();

	protected:
		std::string _name;
		vector2D _worldLocation;
		std::vector<eSceneNode*> _children;
		YAPOI_Engine* _engineRef;
		eWorld* _worldRef;
		mRenderer* _rendererRef;
		mInputManager* _inputmanageRef;
		int _renderPriority = 1;
		std::string _currentimage;
		vector2D _velocity;

		RenderObject* _renderInfoPtr;

		virtual bool getDoesRender() { return false; }

		/*
		* Whether tick functions are called on this class - WARNING WILL PREVENT CHILDREN TICKING
		*/
		bool bDoesTick = true;
	};
}