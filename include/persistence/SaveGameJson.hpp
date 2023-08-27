#pragma once

#include <string>
#include "utils/Utility.hpp"
#include "persistence/SaveLocationJson.hpp"
#include "persistence/SaveHeroJson.hpp"
#include "nlohmann/json.hpp"
#include "exceptions/CorruptedSaveGameException.hpp"
#include "persistence/SaveGame.hpp"

using json = nlohmann::json;

class SaveGameJson : public SaveGame
{
    public:

        SaveHeroJson saveHeroJson;
        std::string date;
        
        SaveGameJson(Hero *hero, std::string location, std::string date = Utility::GetTime());
        json ToJson() const;
        static SaveGameJson FromJson(json j);
};