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
        Attributes(int health = 5, int mana = 5, int strength = 5, 
            int dexterity = 5, int intelligence = 5, int faith = 5, int charisma = 5);

        int GetSum();
        int GetHealth();
        int GetMana();
        int GetStrength();
        int GetDexterity();
        int GetIntelligence();
        int GetFaith();
        int GetCharisma();

        void UpHealth(int quantity);
        void UpMana(int quantity);
        void UpStrenght(int quantity);
        void UpDexterity(int quantity);
        void UpIntelligence(int quantity);
        void UpFaith(int quantity);
        void UpCharisma(int quantity);

        std::string ToString();
};