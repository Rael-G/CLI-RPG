#pragma once

#include "entities/Hero.hpp"
#include "locations/Location.hpp"

class SaveGame
{
    public:
        Hero *hero;
        Location *location;

        SaveGame(Hero *hero, Location *location);
};