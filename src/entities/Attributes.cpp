#include <entities/Attributes.hpp>
#include <global/Text.hpp>

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
        Text::GetText("ATB-HEALTH") + ": " + std::to_string(GetHealth())
        + ", " + Text::GetText("ATB-MANA") + ": " + std::to_string(GetMana())
        + ", " + Text::GetText("ATB-STRENGTH") + ": " + std::to_string(GetStrength())
        + ", " + Text::GetText("ATB-DEXTERITY") + ": " + std::to_string(GetDexterity())
        + ", " + Text::GetText("ATB-INTELLIGENCE") + ": " + std::to_string(GetIntelligence())
        + ", " + Text::GetText("ATB-FAITH") + ": " + std::to_string(GetFaith())
        + ", " + Text::GetText("ATB-CHARISMA") + ": " + std::to_string(GetCharisma());

    return str;
}