#include <string>
#include "ui/UserInterface.hpp"
#include "entities/Attributes.hpp"
#include "entities/Hero.hpp"
#include "global/World.hpp"
#include "ui/Game.hpp"

#pragma once

class CreationMenu : public UserInterface 
{
    public:
        std::string name;
        Attributes *attributes;
        int points;
        std::string ToString() override;
        CreationMenu();
        void DefName();
        void DefAttributes();
        void Finish();
};