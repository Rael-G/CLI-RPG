#include "entities/Attributes.hpp"

Attributes::Attributes(int health, int mana, int strength, 
    int dexterity, int intelligence, int faith, int charisma)
        : health(health), mana(mana), strength(strength), dexterity(dexterity), 
        intelligence(intelligence), faith(faith), charisma(charisma)
{

}
int Attributes::GetSum()
{
    return health + mana + strength + dexterity + intelligence
        + faith + charisma;
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

void Attributes::UpHealth(int quantity)
{
    health += quantity;
}
void Attributes::UpMana(int quantity)
{
    mana += quantity;
}
void Attributes::UpStrength(int quantity)
{
    strength += quantity;
}
void Attributes::UpDexterity(int quantity)
{
    dexterity += quantity;
}
void Attributes::UpIntelligence(int quantity)
{
    intelligence += quantity;
}
void Attributes::UpFaith(int quantity)
{
    faith += quantity;
}
void Attributes::UpCharisma(int quantity)
{
    charisma += quantity;
}

std::string Attributes::ToString()
{
    std::string str =
        "HP: " + std::to_string(GetHealth())
        + ", MANA: " + std::to_string(GetMana())
        + ", STR: " + std::to_string(GetStrength())
        + ", DXT: " + std::to_string(GetDexterity())
        + ", INT: " + std::to_string(GetDexterity())
        + ", FT: " + std::to_string(GetDexterity())
        + ", CHA: " + std::to_string(GetCharisma());

    return str;
}