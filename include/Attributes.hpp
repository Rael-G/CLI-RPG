#pragma once

#include <string>

class Attributes 
{
    private:
    int health;
    int mana;
    int strength;
    int dexterity;
    int intelligence;
    int faith;
    int charisma;

    public:

    Attributes();
    int GetHealth();
    int GetMana();
    int GetStrength();
    int GetDexterity();
    int GetIntelligence();
    int GetFaith();
    int GetCharisma();
    std::string ToString();
};