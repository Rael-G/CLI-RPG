#pragma once

#include <string>
#include <list>
#include <entities/Hero.hpp>
#include <exceptions/CorruptedSaveGameException.hpp>
#include <nlohmann/json.hpp>
#include <persistence/SaveInventoryJson.hpp>

using json = nlohmann::json;

struct SaveHeroJson
{
    Hero *hero;
    std::string name;
    int level;
    Attributes *attributes;
    std::list<Item*> inventory;

    //Attributes
    int health, mana, strength, dexterity, intelligence, faith, charisma;

    //Inventory
    std::list<std::string> inventoryStr;
    
    SaveHeroJson(Hero *hero);
    json ToJson() const;
    static SaveHeroJson FromJson(json j);
};