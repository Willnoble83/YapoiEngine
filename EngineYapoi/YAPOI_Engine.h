#pragma once
#include <iostream>
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
			std::cout << "YAPOI Engine Shutting down" << std::endl;
			delete _renderer;
			delete _world;
			std::cout << "YAPOI Engine successfully shut down " << std::endl;
		}

		int SCREEN_WIDTH = 1280;
		int SCREEN_HEIGHT = 720;


		// Initialise engine modules and world
		bool init();

		//Start engine post initialisation
		void start();

	private:
		mRenderer* _renderer;
		eWorld* _world;

	};
}