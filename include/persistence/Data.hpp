#pragma once

#include <list>
#include "persistence/SaveGame.hpp"

class Data 
{
    public:
        virtual bool SaveData(SaveGame saveGame) = 0;
        virtual std::list<SaveGame> LoadData()  = 0;
};