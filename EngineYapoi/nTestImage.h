#pragma once
#include "YAPOI_SceneNode.h"

namespace YapoiEngine
{
    class nTestImage : public eSceneNode
    {
    public:
        nTestImage(std::string name) : eSceneNode(name) {}; 
        virtual bool Initialise(mRenderer* Renderer) override;
    };
}

