#pragma once
#include <iostream>
#include <vector>
#include "YAPOI_Vector.h"
#include "YAPOI_Renderer.h"


namespace YapoiEngine
{
	class eSceneNode
	{
	public:
		eSceneNode(std::string name) { _name = name; _worldLocation = vector2D(0,0), _velocity = vector2D(0,0); }
		~eSceneNode(void) { };

		// Node Functions
		virtual bool Initialise(mRenderer* Renderer);
		virtual void Tick();
		virtual void Update(vector2D change);
		virtual void Shutdown();

		void SetWorldLocation(vector2D newLoc);
		vector2D AddVelocity(vector2D newVel, bool bOverride);

		void UpdateRenderer(const std::string& file);


		virtual void Add(eSceneNode* node);
		virtual void Remove(eSceneNode* node);
		virtual eSceneNode* Find(std::string name);

		bool DoesTick();

	protected:
		std::string _name;
		vector2D _worldLocation;
		std::vector<eSceneNode*> _children;
		mRenderer* _rendererRef;
		int _renderPriority = 1;
		std::string _currentimage;
		vector2D _velocity;
		/*
		* Whether tick functions are called on this class - WARNING WILL PREVENT CHILDREN TICKING
		*/
		bool bDoesTick = true;
	};
}