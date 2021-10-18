#include "YAPOI_Character.h"
#include "SDL.h"

bool YapoiEngine::nCharacter::Initialise()
{
	_renderPriority = 3;
	_currentimage = "Resources/smiley.bmp";
	nPawn::Initialise();
	if (!_inputmanageRef->RegisterInput(SDLK_w, this) || !_inputmanageRef->RegisterInput(SDLK_d, this) || !_inputmanageRef->RegisterInput(SDLK_s, this) || !_inputmanageRef->RegisterInput(SDLK_a, this) || !_inputmanageRef->RegisterInput(SDLK_q, this))
	{
		std::cout << "Failed to register all keybinds for character - It may not behave correctly" << std::endl;
	}
	UpdateRenderer(_currentimage);
	return true;
}

void YapoiEngine::nCharacter::Tick()
{
	nPawn::Tick();
}

void YapoiEngine::nCharacter::ReceiveInput(SDL_Keycode Key, bool bKeyUp)
{
	if (bKeyUp) // Key up
	{
		switch (Key)
		{
			case SDLK_w:
				Move(vector2D(0, 1));
				return;
			case SDLK_d:
				Move(vector2D(-1, 0));
				return;
			case SDLK_s:
				Move(vector2D(0, -1));
				return;
			case SDLK_a:
				Move(vector2D(1, 0));
		}
	}
	else { // Key down

		switch (Key)
		{
			case SDLK_w:
				Move(vector2D(0,-1));
				return;

			case SDLK_d:
				Move(vector2D(1, 0));
				return;

			case SDLK_s:
				Move(vector2D(0, 1));
				return;

			case SDLK_a:
				Move(vector2D(-1, 0));
				return;
			case SDLK_q:
				_engineRef->TravelNewWorld("Worlds/testworld.xml");
				return;
		}
	}
}
