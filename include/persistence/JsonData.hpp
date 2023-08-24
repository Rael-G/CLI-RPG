#pragma once

#include <fstream>
#include <filesystem>
#include "persistence/Data.hpp"
#include "exceptions/EmptySaveFolderException.hpp"
#include "external/nlohmann/json.hpp"
#include "persistence/SaveHeroJson.hpp"
#include "persistence/SaveGameJson.hpp"
#include "persistence/SaveLocationJson.hpp"



using json = nlohmann::json;
namespace fs = std::filesystem;

class JsonData : public Data
{
    public:
        JsonData()
        {

        }

        bool SaveData(SaveGame saveGame) override;
        std::list<SaveGame> LoadData() override;
        int GetCorrupt() override;

    private:
        std::list<json> GetJsons();
};