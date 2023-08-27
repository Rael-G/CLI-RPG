#pragma once

#include <list>
#include "persistence/SaveGame.hpp"

class Data 
{
    protected:
        int corrupt {0};
        
    public:
        virtual ~Data() = default;
        virtual bool SaveData(SaveGame saveGame) = 0;
        virtual std::list<SaveGame> LoadData()  = 0;
        virtual int GetCorrupt() = 0;
};