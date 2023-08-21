#include "CreationMenu.hpp"
#include "Game.hpp"
#include "Hero.hpp"
#include "Village.hpp"

CreationMenu::CreationMenu() : UserInterface()
{
    subCommands.push_back({"name", std::bind(&CreationMenu::Name, this)});
    subCommands.push_back({"finish", std::bind(&CreationMenu::Finish, this)});
}

std::string CreationMenu::ToString()
{
    return "Who are You?";
}

void CreationMenu::Name()
{
    std::string msg {"Tell your name: "};
    ConsoleUtils::PrintTextSlowly(msg, 25);
    name = ConsoleUtils::ScanInput();
    ConsoleUtils::ClearScreen();

}

void CreationMenu::Finish()
{
    ConsoleUtils::ClearScreen();
    if (name == "" || name == " ")
    {   std::string msg {"You need to choose a valid name.\n\n"};
        ConsoleUtils::PrintTextSlowly(msg, 25);
        return;
    }

    Hero *hero = new Hero(name, new Attributes());
    Village *location = new Village("Strange Village");

    UserInterface *ui = new Game(hero, location);
    ui->Run();
    delete ui;
}