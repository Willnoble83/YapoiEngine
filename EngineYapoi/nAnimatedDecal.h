#pragma once
#include "nDecal.h"
namespace YapoiEngine
{
    class nAnimatedDecal : public nDecal
    {
    public:
        nAnimatedDecal(std::string name, std::vector<std::string> images, float timeBetweenAnimations) : nDecal(name, images[0])
        {
            _animationframes = images;
            _timeBetweenAnims = timeBetweenAnimations;
        }
        virtual void Tick() override;

        void nextFrame();

    protected:
        double  _currentFrame = 0;
        std::vector<std::string> _animationframes = {};
        float _timeBetweenAnims = 0;
        float _timeSinceLastSwitch = 0;
    };
}

