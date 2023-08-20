#include "Attributes.hpp"

Attributes::Attributes()
{
    health = 10;
    mana = 10;
    strength = 10;
    dexterity = 10;
    intelligence = 10;
    faith = 10;
    charisma = 10;
}

int Attributes::GetHealth()
{
    return health;
}
int Attributes::GetMana()
{
    return mana;
}
int Attributes::GetStrength()
{
    return strength;
}
int Attributes::GetDexterity()
{
    return dexterity;
}
int Attributes::GetIntelligence()
{
    return intelligence;
}
int Attributes::GetFaith()
{
    return faith;
}
int Attributes::GetCharisma()
{
    return charisma;
}

std::string Attributes::ToString()
{
std::string str = 
    "HP: " + std::to_string(GetHealth()) + "\n"
    + "MANA: " + std::to_string(GetMana()) + "\n"
    + "STR: " + std::to_string(GetStrength()) + "\n"
    + "DXT: " + std::to_string(GetDexterity()) + "\n"
    + "INT: " + std::to_string(GetDexterity()) + "\n"
    + "FT: " + std::to_string(GetDexterity()) + "\n"
    + "CHA: " + std::to_string(GetCharisma()) + "\n";

    return str;
}