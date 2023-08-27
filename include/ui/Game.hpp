#pragma once

#include "ui/UserInterface.hpp"
#include "entities/Hero.hpp"
#include "locations/Location.hpp"
#include "utils/SaveManager.hpp"
#include "global/DependencyInjector.hpp"
#include <global/World.hpp>

class Game : public UserInterface
{
    private:
        Hero *hero;
        Location *location;
        std::string locationId;

    public:
        Game(Hero *hero, std::string locationId);
        std::string ToString() override;
        void Help() override;

    void Save();
};
