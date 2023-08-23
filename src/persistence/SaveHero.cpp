#include "persistence/SaveHero.hpp"

SaveHero::SaveHero(Hero *hero) : hero(hero) 
{
    name = hero->GetName();
    attributes = hero->GetAttributes();
    inventory = hero->GetInventory();

    health = attributes->GetHealth();
    mana = attributes->GetMana();
    strength = attributes->GetStrength();
    dexterity = attributes->GetDexterity();
    intelligence = attributes->GetIntelligence();
    faith = attributes->GetFaith();
    charisma = attributes->GetCharisma();

    inventoryStr = SaveInventory::FromItemToStr(inventory);
}

json SaveHero::ToJson() const 
{
    json hero;
    hero["name"] = name;
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

SaveHero SaveHero::FromJson(json j)
{
    try
    {
    std::string name = j["name"];
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

    Hero *hero = new Hero(name, attributes, SaveInventory::FromStrToItem(inventory));

    return SaveHero(hero);
    }
    catch(const json::exception& e)
    {
        std::string msg {"\nError In SaveHero: \nSaveHero FromJson(json j)\n" 
            + std::string(e.what()) + j.dump() + "\n"};
        throw std::runtime_error(msg);
    }
}