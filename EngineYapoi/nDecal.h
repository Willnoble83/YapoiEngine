#pragma once
#include "YAPOI_SceneNode.h"

namespace YapoiEngine
{
    /*
    * Class to render a specified image in the world
    */
    class nDecal : public eSceneNode
    {
    public:
        nDecal(std::string name, std::string imagepath);
        virtual bool Initialise() override;

    protected:
        
        virtual bool getDoesRender() override { return true; }
    };
}

