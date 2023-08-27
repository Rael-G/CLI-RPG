#pragma once

#include "entities/Hero.hpp"
#include "locations/Location.hpp"

class SaveGame
{
    public:
        Hero *hero;
        std::string location;

        SaveGame(){}
        SaveGame(Hero *hero, std::string location);
};