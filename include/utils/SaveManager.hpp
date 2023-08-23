#pragma once

#include "persistence/Data.hpp"
#include "persistence/SaveGame.hpp"

namespace fs = std::filesystem;

class SaveManager
{
    private:
        Data *data;        

    public:
        SaveManager(Data *data) : data(data) {}

        bool Save(Hero *hero, Location *location);
        std::list<SaveGame> Load();
};