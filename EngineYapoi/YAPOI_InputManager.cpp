#include <iostream>
#include <vector>
#include "YAPOI_InputManager.h"
#include "YAPOI_SceneNode.h"

bool YapoiEngine::mInputManager::Initialise()
{
    return true;
}

bool YapoiEngine::mInputManager::RegisterInput(SDL_Keycode KeycodeToRegister, eSceneNode* RequestingSceneNode)
{
    if (_KeyMap.count(KeycodeToRegister) == 0)
    {
        _KeyMap[KeycodeToRegister] = RequestingSceneNode;
        return true;
    }
    else {
        std::cout << RequestingSceneNode->GetName() << " Requested a key already registered - Registration has failed." << std::endl;
        return false;
    }
}

bool YapoiEngine::mInputManager::RemoveInputRegistration(SDL_Keycode KeycodeToRemove)
{
    _KeyMap.erase(KeycodeToRemove);
    return true;
}

bool YapoiEngine::mInputManager::RemoveInputRegistration(eSceneNode* RequestingSceneNode)
{
    std::vector<SDL_Keycode> Keycodes = {};
    for (const auto& entry : _KeyMap)
    {
        if (entry.second == RequestingSceneNode)
        {
            Keycodes.push_back(entry.first);
        }
    }
    for (size_t i = 0; i < Keycodes.size(); i++)
    {
        RemoveInputRegistration(Keycodes[i]);
    }
    return true;
}
