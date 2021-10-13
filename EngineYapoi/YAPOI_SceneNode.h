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
		eSceneNode(std::string name) { _name = name; _worldLocation = vector2D(0,0); }
		~eSceneNode(void) { };

		// Node Functions
		virtual bool Initialise(mRenderer* Renderer);
		virtual void Update(vector2D change);
		virtual void Shutdown();

		void SetWorldLocation(vector2D newLoc) { _worldLocation = newLoc; };
		void UpdateRenderer(const std::string& file);

		virtual void Add(eSceneNode* node);
		virtual void Remove(eSceneNode* node);
		virtual eSceneNode* Find(std::string name);

	protected:
		std::string _name;
		vector2D _worldLocation;
		std::vector<eSceneNode*> _children;
		mRenderer* _rendererRef;
		int _renderPriority = 0;
	};
}