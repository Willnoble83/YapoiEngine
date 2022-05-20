#include <iostream>
#include "YAPOI_Engine.h"
#include "YAPOI_Renderer.h"
#include "YAPOI_World.h"
#include "mSceneNodeFactory.h"


float YapoiEngine::YAPOI_Engine::GetDeltaTime()
{
	return DeltaTime;
}

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
	_inputmanager = new mInputManager();
	if (!_inputmanager->Initialise())
	{
		std::cout << "YAPOI Engine " << EngineVersion << "Startup Failed: Input Manager failed to initialise" << std::endl;
		delete _world;
		delete _renderer;
		delete _inputmanager;
		return false;
	}
	_world = new eWorld("WorldRoot", EngineModuleRefs(this, _world, _renderer, _inputmanager));
	_world->LoadFromFile("Worlds/testworld.xml");
	if (!_world->Initialise())
	{
		std::cout << "YAPOI Engine " << EngineVersion << "Startup Failed: World failed to initialise" << std::endl;
		delete _world;
		delete _renderer;
		return false;
	}

	nodeFactory = new YapoiEngine::mSceneNodeFactory();

	std::cout << "YAPOI Engine " << EngineVersion << " initialise Successful" << std::endl;
	return true;

}

void YapoiEngine::YAPOI_Engine::start()
{
	while (!bQuit)
	{

		while (SDL_PollEvent(&e) != 0)
		{
			//User Requests Quit
			if (e.type == SDL_QUIT)
			{
				bQuit = true;
			}
			if (e.type == SDL_KEYDOWN)
			{
				_inputmanager->ProcessKeyEvent(e.key.keysym.sym, false);
			}
			if (e.type == SDL_KEYUP)
			{
				_inputmanager->ProcessKeyEvent(e.key.keysym.sym, true);
			}
		}

		//std::cout << SDL_GetTicks() << " / " << LastFrameTime << std::endl;
		DeltaTime = ((float)SDL_GetTicks() - (float)LastFrameTime) / 1000.0f;
		//std::cout << "Delta: " << DeltaTime << std::endl;
		LastFrameTime = SDL_GetTicks();
		

		_world->Tick();


		// Render state update
		_renderer->Render();
	}

}

void YapoiEngine::YAPOI_Engine::TravelNewWorld(std::string WorldFile)
{
	eWorld* newWorld = NULL;
	newWorld = new eWorld("WorldRoot", EngineModuleRefs(this, newWorld, _renderer, _inputmanager));
	newWorld->UpdateWorldRef(newWorld);
	_world->Shutdown();
	_world = newWorld;
	_inputmanager->PurgeInputRegistration();
	_world->LoadFromFile(WorldFile.c_str());
	_world->Initialise();
}

void YapoiEngine::YAPOI_Engine::cleanup()
{
	delete _renderer;
	delete _world;
}
