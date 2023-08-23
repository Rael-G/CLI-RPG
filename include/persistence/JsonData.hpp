#pragma once

#include <fstream>
#include <filesystem>
#include "persistence/Data.hpp"

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