#pragma once

#include <string>
#include "utils/Utility.hpp"
#include "persistence/SaveLocation.hpp"
#include "persistence/SaveHero.hpp"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class SaveGame
{
    public:
        Hero *hero;
        Location *location;
        SaveHero saveHero;
        SaveLocation saveLocation;
        std::string date;
        
        SaveGame(SaveHero hero, SaveLocation location, std::string date = Utility::GetTime());
        json ToJson() const;
        static SaveGame FromJson(json j);
};