#pragma once
#include <iostream>
#include <SDL.h>
#include <vector>
#include <map>

namespace YapoiEngine
{
	struct RenderObject
	{
		RenderObject()
		{
			_texture = NULL;
			_x = 0;
			_y = 0;
			_renderpriority = 0;
		}
		RenderObject(SDL_Texture* Texture, int x, int y, int renderpriority)
		{
			_texture = Texture;
			_x = x;
			_y = y;
			_renderpriority = renderpriority;
		}
		SDL_Texture* _texture;
		int _x;
		int _y;
		//0 rendered first incrementally
		int _renderpriority;

		bool operator>(const RenderObject& other)
		{
			return _renderpriority > other._renderpriority;
		}
		bool operator<(const RenderObject& other)
		{
			return _renderpriority < other._renderpriority;
		}
		RenderObject operator=(const RenderObject& other)
		{
			this->_texture = other._texture;
			this->_x = other._x;
			this->_y = other._y;
			this->_renderpriority = other._renderpriority;
			return *this;
		}
	};

	class mRenderer
	{
	public:

		const std::string RendererVersion = "v0.1.0";

		mRenderer(const int new_SCREEN_WIDTH, const int new_SCREEN_HEIGHT, std::string windowName)
		{
			SCREEN_WIDTH = new_SCREEN_WIDTH;
			SCREEN_HEIGHT = new_SCREEN_HEIGHT;
			_windowName = windowName;
			_window = NULL;
			_renderer = NULL;
		}
		~mRenderer()
		{
			std::cout << "Renderer shutting down" << std::endl;
			cleanup(_renderer, _window);
			std::cout << "Renderer successfully shut down" << std::endl;
		}


		int SCREEN_WIDTH;
		int SCREEN_HEIGHT;

			/**
		* Draw an SDL_Texture to an SDL_Renderer at position x, y, preserving
		* the texture's width and height
		* @param tex The source texture we want to draw
		* @param ren The renderer we want to draw to
		* @param x The x coordinate to draw to
		* @param y The y coordinate to draw to
		*/
		void renderTexture(SDL_Texture* tex, int x, int y);

		void Render();

		/**
		* Loads a BMP image into a texture on the rendering device
		* @param file The BMP image file to load
		* @return the loaded texture, or nullptr if something went wrong.
		*/
		SDL_Texture* loadTexture(const std::string& file);
 
		void UpdateRenderState(std::string nodeName, RenderObject RenderInfo);
		void RemoveRenderState(std::string nodeName);

		// Initialise renderer
		bool init();

		void logSDLError(std::ostream& os, const std::string& msg);

	protected:
		void cleanup(SDL_Renderer* ren, SDL_Window* win);

		int _maxrenderlevel = -1;
		std::string _windowName;
		SDL_Window* _window;
		SDL_Renderer* _renderer;
		std::map<std::string, RenderObject> _nodeRenderInfo = {};
	};
}
