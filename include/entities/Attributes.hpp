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
        Attributes(int health = 10, int mana = 10, int strength = 10, 
            int dexterity = 10, int intelligence = 10, int faith = 10, int charisma = 10);
        int GetHealth();
        int GetMana();
        int GetStrength();
        int GetDexterity();
        int GetIntelligence();
        int GetFaith();
        int GetCharisma();
        std::string ToString();
};