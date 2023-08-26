#pragma once

#include <string>
#include <utils/Utility.hpp>
#include <persistence/SaveLocationJson.hpp>
#include <persistence/SaveHeroJson.hpp>
#include <exceptions/CorruptedSaveGameException.hpp>
#include <persistence/SaveGame.hpp>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class SaveGameJson : public SaveGame
{
    public:
        Hero *hero;
        Location *location;
        SaveHeroJson saveHeroJson;
        SaveLocationJson saveLocationJson;
        std::string date;
        
        SaveGameJson(Hero *hero, Location *location, std::string date = Utility::GetTime());
        json ToJson() const;
        static SaveGameJson FromJson(json j);
};