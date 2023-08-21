#pragma once

#include <string>
#include <list>
#include "Attributes.hpp"
#include "Item.hpp"

class Hero{

    private:
        std::string name;
        Attributes *attributes;
        std::list<Item*> inventory;

    public:
        Hero(std::string name, Attributes *attributes);

        int GetHealth();
        int GetMana();
        bool Attack();

        std::string Status();
        std::string Inventory();
};