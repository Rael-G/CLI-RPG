#pragma once

#include <list>
#include "persistence/SaveGame.hpp"

class Data 
{
    protected:
    int corrupt;
        
    public:
        virtual bool SaveData(SaveGame saveGame) = 0;
        virtual std::list<SaveGame> LoadData()  = 0;
        virtual int GetCorrupt() = 0;
};