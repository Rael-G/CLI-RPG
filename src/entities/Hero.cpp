#include "Hero.hpp"

Hero::Hero(std::string name, Attributes *attributes)
    : name(name), attributes(attributes), inventory{}
{}

int Hero::GetHealth()
{
    return attributes->GetHealth() * 10;
}

int Hero::GetMana()
{
    return attributes->GetMana();
}

bool Hero::Attack()
{
    return true;
}

std::string Hero::Status()
{
    return name + "\n\n"
        + attributes->ToString() + "\n"
        + (std::string)"Health: " + std::to_string(GetHealth()) + "\n"
        + (std::string)"Mana: " + std::to_string(GetMana()) + "\n";
}

std::string Hero::Inventory()
{
    std::string str;
    for(Item *item : inventory){
        str += item->ToString() + "\n";
    }
    return str;
}