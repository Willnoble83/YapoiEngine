#pragma once
#include <iostream>
#include <SDL.h>

namespace YapoiEngine
{


	class YAPOI_Renderer
	{
	public:

		const std::string RendererVersion = "v0.1.0";

		YAPOI_Renderer(const int new_SCREEN_WIDTH, const int new_SCREEN_HEIGHT)
		{
			SCREEN_WIDTH = new_SCREEN_WIDTH;
			SCREEN_HEIGHT = new_SCREEN_HEIGHT;
		}
		~YAPOI_Renderer();

		int SCREEN_WIDTH;
		int SCREEN_HEIGHT;

		// Initialise renderer
		bool init();

		void logSDLError(std::ostream& os, const std::string& msg);

	protected:
		void cleanup();

		SDL_Window* Window;
		SDL_Renderer* Renderer;
	};
}
