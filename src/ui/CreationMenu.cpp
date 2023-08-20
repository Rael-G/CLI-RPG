#include "CreationMenu.hpp"

CreationMenu::CreationMenu() : UserInterface()
{
    subCommands.insert(
    {
        {"name", std::bind(&CreationMenu::Name, this)},
        {"atributes", std::bind(&CreationMenu::Atributes, this)},
        {"finish", std::bind(&CreationMenu::Finish, this)}

    });
}

void CreationMenu::Name()
{
    std::cout << "Choose yout name: ";
    std::cin >> CreationMenu::name;
    system("clear");
}

void CreationMenu::Atributes()
{
    std::cout << "Define your Atributes: ";
    std::cin >> CreationMenu::atributes;
    system("clear");
}

void CreationMenu::Finish()
{
}    
