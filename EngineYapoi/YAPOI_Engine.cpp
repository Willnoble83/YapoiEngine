#include <iostream>
#include "YAPOI_Engine.h"


bool YapoiEngine::YAPOI_Engine::init()
{
	std::cout << "YAPOI Engine " << EngineVersion << " initialising" << std::endl;

	// Initialise the renderer
	_renderer = new YapoiEngine::mRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, "YapoiEngine");
	if (!_renderer->init())
	{
		std::cout << "YAPOI Engine " << EngineVersion << "Startup Failed: Renderer Failed to initialise" << std::endl;
		delete _renderer;
		return false;
	}
	_world = new eWorld("WorldRoot");
	if (!_world->Initialise(_renderer))
	{
		std::cout << "YAPOI Engine " << EngineVersion << "Startup Failed: World failed to initialise" << std::endl;
		delete _world;
		return false;
	}


	std::cout << "YAPOI Engine " << EngineVersion << " initialise Successful" << std::endl;
	return true;

}

void YapoiEngine::YAPOI_Engine::start()
{
	for (int i = 0; i < 10; i++)
	{
		// Render state after last update
		_renderer->Render();
		_world->Tick();
		SDL_Delay(2000);
	}

}