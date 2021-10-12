#include <iostream>
#include "YAPOI_Engine.h"

using namespace YapoiEngine;

bool YAPOI_Engine::init()
{
	std::cout << "YAPOI Engine " << EngineVersion << " starting" << std::endl;

	// Initialise the renderer
	Renderer = new YAPOI_Renderer(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!Renderer->init())
	{
		std::cout << "YAPOI Engine " << EngineVersion << "Startup Failed: Renderer Failed to initialise" << std::endl;
		return false;
	}

	std::cout << "YAPOI Engine " << EngineVersion << " Startup Successful" << std::endl;
	return true;

}