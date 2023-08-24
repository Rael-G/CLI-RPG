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
    return "Who Are You?\n\n"
       "Name: " + name + "\n"
       + "Atributes:\n"
       + "Health: " + std::to_string(attributes->GetHealth())
       + ", Mana: " + std::to_string(attributes->GetMana())
       + ", Strength: " + std::to_string(attributes->GetStrength())
       + ", Dexterity: " + std::to_string(attributes->GetDexterity())
       + ", Intelligence: " + std::to_string(attributes->GetIntelligence())
       + ", Faith: " + std::to_string(attributes->GetFaith())
       + ", Charisma: " + std::to_string(attributes->GetCharisma());
}

void CreationMenu::DefName()
{
    std::string msg {"Tell your name: "};
    ConsoleUtils::PrintTextSlowly(msg, 25);
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
        ConsoleUtils::PrintTextSlowly(msg, 25);
        return;
    }
    else if (points != 0)
    {
        std::string msg {"You still have points to spent on attributes.\n\n"};
        ConsoleUtils::PrintTextSlowly(msg, 25);
        return;
    }

    Hero *hero = new Hero(name, 0, attributes);

    UserInterface *ui = new Game(hero, World::GetLocation("V01"));
    ui->Run();
    delete ui;
}