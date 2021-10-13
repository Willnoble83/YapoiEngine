#pragma once
#include "YAPOI_Renderer.h"
#include "YAPOI_World.h"

namespace YapoiEngine
{
	

	class YAPOI_Engine
	{
	public:

		const std::string EngineVersion = "v0.1.0";

		YAPOI_Engine() {
			_renderer = NULL;
			_world = NULL;
		 }
		~YAPOI_Engine()
		{
			delete _renderer;
			delete _world;
		}

		int SCREEN_WIDTH = 1280;
		int SCREEN_HEIGHT = 720;


		// Initialise engine modules
		bool init();

		void start();

	private:
		mRenderer* _renderer;
		eWorld* _world;

	};
}