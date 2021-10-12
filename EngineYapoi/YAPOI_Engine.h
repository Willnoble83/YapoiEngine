#pragma once
#include "YAPOI_Renderer.h"

namespace YapoiEngine
{
	

	class YAPOI_Engine
	{
	public:

		const std::string EngineVersion = "v0.1.0";

		YAPOI_Engine() {
			Renderer = NULL;
		 }
		~YAPOI_Engine()
		{
			delete Renderer;
		}

		int SCREEN_WIDTH = 1280;
		int SCREEN_HEIGHT = 720;


		// Initialise engine modules
		bool init();

		void start();

	private:
		YAPOI_Renderer* Renderer;

	};
}