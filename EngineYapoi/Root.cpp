#include <iostream>
#include <SDL.h>
#include "YAPOI_Engine.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;




/**
* Loads a BMP image into a texture on the rendering device
* @param file The BMP image file to load
* @param ren The renderer to load the texture onto
* @return the loaded texture, or nullptr if something went wrong.
*/
/*
SDL_Texture* loadTexture(const std::string& file, SDL_Renderer* ren) {
	//Initialize to nullptr to avoid dangling pointer issues

	SDL_Texture* texture = nullptr;
	//Load the image

	SDL_Surface* loadedImage = SDL_LoadBMP(file.c_str());
	//If the loading went ok, convert to texture and return the texture

	if (loadedImage != nullptr) {
		texture = SDL_CreateTextureFromSurface(ren, loadedImage);
		SDL_FreeSurface(loadedImage);
		//Make sure converting went ok too

		if (texture == nullptr) {
			logSDLError(std::cout, "CreateTextureFromSurface");
		}
	}
	else {
		logSDLError(std::cout, "LoadBMP");
	}
	return texture;
}*/

/**
* Draw an SDL_Texture to an SDL_Renderer at position x, y, preserving
* the texture's width and height
* @param tex The source texture we want to draw
* @param ren The renderer we want to draw to
* @param x The x coordinate to draw to
* @param y The y coordinate to draw to
*/
/*
void renderTexture(SDL_Texture* tex, SDL_Renderer* ren, int x, int y) {
	//Setup the destination rectangle to be at the position we want

	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	//Query the texture to get its width and height to use

	SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(ren, tex, NULL, &dst);
}

void cleanup(SDL_Texture* tex, SDL_Renderer* ren, SDL_Window* win)
{
	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}
*/
int main(int, char**) {
	
	YapoiEngine::YAPOI_Engine* Engine = new YapoiEngine::YAPOI_Engine();
	Engine->init();
	return 0;
}

/* Renderer code
* if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		logSDLError(std::cout, "SDL_Init");
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow("Lesson 2", 100, 100, SCREEN_WIDTH,
		SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		logSDLError(std::cout, "CreateWindow");
		SDL_Quit();
		return 1;
	}
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		logSDLError(std::cout, "CreateRenderer");
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1;
	}


	// Load the image into memory
	SDL_Texture* tex = loadTexture("Resources/Poggers.bmp", renderer);


	// Render
	for (int i = 0; i < 3; ++i) {
		//First clear the renderer

		SDL_RenderClear(renderer);
		//Draw the texture

		renderTexture(tex, renderer, 0, 0);
		//Update the screen

		SDL_RenderPresent(renderer);
		//Take a quick break after all that hard work

		SDL_Delay(1000);
	}
	cleanup(tex, renderer, window);
	return 0;

*/