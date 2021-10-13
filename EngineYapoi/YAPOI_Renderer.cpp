#include <iostream>
#include "YAPOI_Engine.h"

using namespace YapoiEngine;

bool mRenderer::init()
{
	std::cout << "YAPOI Renderer " << RendererVersion << " initialising" << std::endl;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		logSDLError(std::cout, "SDL_Init");
		return 0;
	}

	_window = SDL_CreateWindow("YapoiEngine", 100, 100, SCREEN_WIDTH,
		SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (_window == nullptr) {
		logSDLError(std::cout, "CreateWindow");
		SDL_Quit();
		return 0;
	}
	_renderer = SDL_CreateRenderer(_window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (_renderer == nullptr) {
		logSDLError(std::cout, "CreateRenderer");
		SDL_DestroyWindow(_window);
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
void mRenderer::logSDLError(std::ostream& os, const std::string& msg) {
	os << msg << " error: " << SDL_GetError() << std::endl;
}

void mRenderer::cleanup(SDL_Renderer* ren, SDL_Window* win)
{
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}



void YapoiEngine::mRenderer::startRender()
{

	// Render
	for (int i = 0; i < 3; ++i) {
		//First clear the renderer

		SDL_RenderClear(_renderer);
		//Draw the texture

		for (const auto& entry : _nodeRenderInfo)
		{
			renderTexture(entry.second._texture,entry.second._x , entry.second._y);
		}

		//Update the screen

		SDL_RenderPresent(_renderer);
		//Take a quick break after all that hard work

		SDL_Delay(1000);
	}
}

void YapoiEngine::mRenderer::renderTexture(SDL_Texture* tex, int x, int y) {
	//Setup the destination rectangle to be at the position we want

	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	//Query the texture to get its width and height to use

	SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(_renderer, tex, NULL, &dst);
}


SDL_Texture* mRenderer::loadTexture(const std::string& file) {
	//Initialize to nullptr to avoid dangling pointer issues

	SDL_Texture* texture = nullptr;
	//Load the image

	SDL_Surface* loadedImage = SDL_LoadBMP(file.c_str());
	//If the loading went ok, convert to texture and return the texture

	if (loadedImage != nullptr) {
		texture = SDL_CreateTextureFromSurface(_renderer, loadedImage);
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
}

void YapoiEngine::mRenderer::UpdateRenderState(std::string nodeName, RenderObject RenderInfo)
{
	_nodeRenderInfo[nodeName] = RenderInfo;
}

void YapoiEngine::mRenderer::RemoveRenderState(std::string nodeName)
{
	_nodeRenderInfo.erase(nodeName);
}
