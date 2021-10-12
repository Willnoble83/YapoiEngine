#include <iostream>
#include "YAPOI_Engine.h"

using namespace YapoiEngine;

bool YAPOI_Renderer::init()
{
	std::cout << "YAPOI Renderer " << RendererVersion << " initialising" << std::endl;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		logSDLError(std::cout, "SDL_Init");
		return 0;
	}

	SDL_Window* window = SDL_CreateWindow("Lesson 2", 100, 100, SCREEN_WIDTH,
		SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		logSDLError(std::cout, "CreateWindow");
		SDL_Quit();
		return 0;
	}
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		logSDLError(std::cout, "CreateRenderer");
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 0;
	}
	std::cout << "YAPOI Renderer " << RendererVersion << " Successfully Initialised" << std::endl;
	return 1;
}

/**
* Logs an error from SDL with an error message to the stream of our choice
* @param os The output stream
* @param msg The error message to write, format will be msg error: SDL_GetError()
*/
void YAPOI_Renderer::logSDLError(std::ostream& os, const std::string& msg) {
	os << msg << " error: " << SDL_GetError() << std::endl;
}

void YAPOI_Renderer::cleanup(SDL_Renderer* ren, SDL_Window* win)
{
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}