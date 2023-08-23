#pragma once

#include <string>
#include <list>
#include "entities/Attributes.hpp"
#include "entities/Item.hpp"

class Hero{

    private:
        std::string name;
        Attributes *attributes;
        std::list<Item*> inventory;
        int level;

    public:
        Hero(std::string name, int level, Attributes *attributes, std::list<Item *> inventory = {});

        //Hero(std::string name, Attributes *attributes, std::list<Item *> inventory);

        std::string GetName();
        int GetLevel();
        Attributes* GetAttributes();
        std::list<Item*> GetInventory();

        int GetHealth();
        int GetMana();
        bool Attack();

        std::string Status();
        std::string Inventory();
};