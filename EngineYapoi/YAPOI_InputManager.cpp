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
    if (_KeybindMap[KeycodeToRegister] != NULL)
    {
        _KeybindMap[KeycodeToRegister] = RequestingSceneNode;
        return true;
    }
    else {
        std::cout << ("Cannot register keybind: ", KeycodeToRegister, ", it has already been registered") << std::endl;
    }



}

bool YapoiEngine::mInputManager::RemoveInputRegistration(SDL_Keycode KeycodeToRemove)
{
    _KeybindMap.erase(KeycodeToRemove);
    return true;
}

bool YapoiEngine::mInputManager::RemoveInputRegistration(eSceneNode* RequestingSceneNode)
{
    std::vector<SDL_Keycode> Keycodes = {};
    for (const auto& entry : _KeybindMap)
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

void YapoiEngine::mInputManager::ProcessKeyEvent(SDL_Keycode KeyPressed, bool bKeyUp)
{
    if (!bKeyUp)
    {
        // If this is a repeated keydown press - Ignore it.
        if (_KeyDownMap[KeyPressed])
        {
            return;
        }
    }
    else {
        // If this is an up event without any corresponding down.
        if (_KeyDownMap[KeyPressed])
        {
            return;
        }
    }
    _KeyDownMap[KeyPressed] = !bKeyUp;
    //std::cout << "Key Input Detected: " << KeyPressed << " bIsUp: " << bKeyUp << std::endl;
    if (_KeybindMap.count(KeyPressed) == 1)
    {
        _KeybindMap[KeyPressed]->ReceiveInput(KeyPressed, bKeyUp);

    }
}

void YapoiEngine::mInputManager::PurgeInputRegistration()
{
    _KeyDownMap.clear();
}
