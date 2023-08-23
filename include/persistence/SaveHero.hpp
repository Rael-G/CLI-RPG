#pragma once

#include <string>
#include <list>
#include "entities/Hero.hpp"
#include "persistence/SaveInventory.hpp"
#include "exceptions/CorruptedSaveGameException.hpp"
#include "external/nlohmann/json.hpp"

using json = nlohmann::json;

struct SaveHero
{
    Hero *hero;
    std::string name;
    Attributes *attributes;
    std::list<Item*> inventory;

    //Attributes
    int health, mana, strength, dexterity, intelligence, faith, charisma;

    //Inventory
    std::list<std::string> inventoryStr;
    
    SaveHero(Hero *hero);
    json ToJson() const;
    static SaveHero FromJson(json j);
};