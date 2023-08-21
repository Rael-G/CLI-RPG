#include "StartMenu.hpp"

StartMenu::StartMenu() : UserInterface() 
{
    subCommands.push_back({"new", std::bind(&StartMenu::New, this)});
    subCommands.push_back({"load", std::bind(&StartMenu::Load, this)});
    subCommands.push_back({"options", std::bind(&StartMenu::Options, this)});
    subCommands.push_back({"help", std::bind(&StartMenu::Help, this)});

    ConsoleUtils::ClearScreen();
    std::string str{"Welcome to TextRPG!\n\n"};
    ConsoleUtils::PrintTextSlowly(str, 100);

}
void StartMenu::New()
{
    ConsoleUtils::ClearScreen();

    UserInterface *ui = new CreationMenu();
    ui->Run();
    delete ui;
}

void StartMenu::Load()
{
    ConsoleUtils::ClearScreen();

}

void StartMenu::Options()
{
    ConsoleUtils::ClearScreen();
}

void StartMenu::Help()
{
    ConsoleUtils::ClearScreen();

    std::string msg {"This is a  Command-Text based RPG. Type your command at the command line and magic happens!\n"};
    ConsoleUtils::PrintTextSlowly(msg, 50);
}
