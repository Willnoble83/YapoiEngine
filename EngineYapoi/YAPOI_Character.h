#pragma once
#include "YAPOI_Pawn.h"

namespace YapoiEngine
{
    class nCharacter : public nPawn
    {
    public:
        nCharacter(std::string name) : nPawn(name) {};

        virtual bool Initialise() override;
        virtual void Tick() override;

        virtual void ReceiveInput(SDL_Keycode Key, bool bKeyUp) override;
    };
}

