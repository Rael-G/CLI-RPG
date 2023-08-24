#include "persistence/SaveHeroJson.hpp"

SaveHeroJson::SaveHeroJson(Hero *hero) : hero(hero) 
{
    name = hero->GetName();
    level = hero->GetLevel();
    attributes = hero->GetAttributes();
    inventory = hero->GetInventory();

    health = attributes->GetHealth();
    mana = attributes->GetMana();
    strength = attributes->GetStrength();
    dexterity = attributes->GetDexterity();
    intelligence = attributes->GetIntelligence();
    faith = attributes->GetFaith();
    charisma = attributes->GetCharisma();

    inventoryStr = SaveInventoryJson::FromItemToStr(inventory);
}

json SaveHeroJson::ToJson() const 
{
    json hero;
    hero["name"] = name;
    hero["level"] = level;
        json attributes;
        attributes["health"] = health;
        attributes["mana"] = mana;
        attributes["strength"] = strength;
        attributes["dexterity"] = dexterity;
        attributes["intelligence"] = intelligence;
        attributes["faith"] = faith;
        attributes["charisma"] = charisma;
    hero["attributes"] = attributes;
    hero["inventory"] = inventoryStr;
    return hero;
}

SaveHeroJson SaveHeroJson::FromJson(json j)
{
    std::string name = j["name"];
    int level = j["level"];
    int health, mana, strength, dexterity, intelligence, faith, charisma;
    health = j["attributes"]["health"];
    mana =  j["attributes"]["mana"];
    strength =  j["attributes"]["strength"];
    dexterity =  j["attributes"]["dexterity"];
    intelligence =  j["attributes"]["intelligence"];
    faith =  j["attributes"]["faith"];
    charisma = j["attributes"]["charisma"];

    Attributes *attributes = new Attributes(health, mana, strength, dexterity, 
        intelligence, faith, charisma);

    std::list<std::string> inventory = j["inventory"];

    Hero *hero = new Hero(name, level, attributes, SaveInventoryJson::FromStrToItem(inventory));

    return SaveHeroJson(hero);
}