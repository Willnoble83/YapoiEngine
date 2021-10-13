#pragma once
#include <SDL.h>
#include <map>

namespace YapoiEngine
{
	class eSceneNode;

	class mInputManager
	{

	public:
		bool Initialise();

		bool RegisterInput(SDL_Keycode KeycodeToRegister, eSceneNode* RequestingSceneNode);
		bool RemoveInputRegistration(SDL_Keycode KeycodeToRemove);
		bool RemoveInputRegistration(eSceneNode* RequestingSceneNode);
	protected:

		std::map<SDL_Keycode, eSceneNode*> _KeyMap;
	};
}

