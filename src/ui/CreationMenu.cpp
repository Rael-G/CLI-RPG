#include "ui/CreationMenu.hpp"

CreationMenu::CreationMenu() : UserInterface()
{
    subCommands.push_back({"name", std::bind(&CreationMenu::DefName, this)});
    subCommands.push_back({"attributes", std::bind(&CreationMenu::DefAttributes, this)});
    subCommands.push_back({"finish", std::bind(&CreationMenu::Finish, this)});
    
    attributes = new Attributes();
    points = 20;
}

std::string CreationMenu::ToString()
{
    return "Who Are You?\n"
        + name + "\n"
        + attributes->ToString();
}

void CreationMenu::Help()
{
    ConsoleUtils::ClearScreen();

    std::string msg {"Not yet implemented.\n\n"};
    ConsoleUtils::PrintTextSlowly(msg);
}

void CreationMenu::DefName()
{
    std::string msg {"Tell your name: "};
    ConsoleUtils::PrintTextSlowly(msg);
    name = ConsoleUtils::ScanLine();
    ConsoleUtils::ClearScreen();
}

void CreationMenu::DefAttributes()
{   
    ConsoleUtils::ClearScreen();
    UserInterface *ui = new AttributesDefinition(attributes, points);
    ui->Run();
    delete ui;
}

void CreationMenu::Finish()
{
    ConsoleUtils::ClearScreen();
    if (name == "" || name == " ")
    {
        std::string msg {"You need to choose a valid name.\n\n"};
        ConsoleUtils::PrintTextSlowly(msg);
        return;
    }
    else if (points != 0)
    {
        std::string msg {"You still have points to spent on attributes.\n\n"};
        ConsoleUtils::PrintTextSlowly(msg);
        return;
    }

    Hero *hero = new Hero(name, 0, attributes);

    UserInterface *ui = new Game(hero, World::GetLocation("V01")->GetId());
    ui->Run();
    delete ui;
}