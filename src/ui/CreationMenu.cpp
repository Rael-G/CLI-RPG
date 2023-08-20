#include "CreationMenu.hpp"

CreationMenu::CreationMenu() : UserInterface()
{
    subCommands.push_back({"name", std::bind(&CreationMenu::Name, this)});
    subCommands.push_back({"atributes", std::bind(&CreationMenu::Atributes, this)});
    subCommands.push_back({"finish", std::bind(&CreationMenu::Finish, this)});
}

void CreationMenu::Name()
{
    std::cout << "Choose yout name: ";
    std::cin >> name;
    ConsoleUtils::ClearScreen();

}

void CreationMenu::Atributes()
{
    std::cout << "Define your Atributes: ";
    std::cin >> atributes;
    ConsoleUtils::ClearScreen();

}

void CreationMenu::Finish()
{
    ConsoleUtils::ClearScreen();
}    
