#pragma once
#include <iostream>
#include "SDL.h"

namespace YapoiEngine
{
	// Forward declaration
	class eWorld;
	class mRenderer;
	class mInputManager;
	class mSceneNodeFactory;

	class YAPOI_Engine
	{
	public:

		const std::string EngineVersion = "v0.1.0";

		YAPOI_Engine() {
			_renderer = NULL;
			_world = NULL;
			e = SDL_Event();
			_inputmanager = NULL;
			nodeFactory = NULL;
		 }
		~YAPOI_Engine()
		{
			std::cout << "YAPOI Engine Shutting down" << std::endl;
			cleanup();
			std::cout << "YAPOI Engine successfully shut down " << std::endl;
		}

		int SCREEN_WIDTH = 1280;
		int SCREEN_HEIGHT = 720;


		float GetDeltaTime();


		// Initialise engine modules and world
		bool init();

		//Start engine post initialisation
		void start();

		mSceneNodeFactory* nodeFactory;

		void TravelNewWorld(std::string WorldFile);
	protected:

		// Quit flag
		bool bQuit = false;

		// Event handler
		SDL_Event e;

		// Time between frame renders
		float DeltaTime = 0.00f;
		
	private:
		mRenderer* _renderer;
		eWorld* _world;
		mInputManager* _inputmanager;

		void cleanup();


		unsigned long int LastFrameTime = 0;
	};

	struct EngineModuleRefs {
		EngineModuleRefs(YAPOI_Engine* engine, eWorld* world, mRenderer* renderer, mInputManager* inputmanage) { engineRef = engine; worldRef = world; rendererRef = renderer; inputmanageRef = inputmanage; }
		YAPOI_Engine* engineRef;
		eWorld* worldRef;
		mRenderer* rendererRef;
		mInputManager* inputmanageRef;

	};
}