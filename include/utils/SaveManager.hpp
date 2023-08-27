#pragma once

#include "persistence/Data.hpp"
#include "persistence/SaveGame.hpp"

namespace fs = std::filesystem;

class SaveManager
{
    private:
        Data *data;        

    public:
        SaveManager(Data *data);
        ~SaveManager();

        bool Save(Hero *hero, std::string location);
        std::list<SaveGame> Load();
        int GetCorrupt();
};