#pragma once

#include "UserInterface.hpp"
#include "Hero.hpp"
#include "Location.hpp"

class Game : public UserInterface
{
    private:
        Hero *hero;
        Location *location;

    public:
        Game(Hero *hero, Location *location);
        std::string ToString() override;

    void Save();
};
