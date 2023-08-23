#include "ui/StartMenu.hpp"

StartMenu::StartMenu() : UserInterface() 
{
    subCommands.push_back({"new", std::bind(&StartMenu::New, this)});
    subCommands.push_back({"load", std::bind(&StartMenu::Load, this)});
    subCommands.push_back({"options", std::bind(&StartMenu::Options, this)});
    subCommands.push_back({"help", std::bind(&StartMenu::Help, this)});
}

std::string StartMenu::ToString()
{
    return "Welcome to TextRPG!";
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

    std::unique_ptr<SaveManager> sm = DependencyInjector::GetSaveManager();
    std::list<SaveGame> saves = sm->Load();

    std::string msg {"<return>\n"};

    for (SaveGame save : saves)
    {
        msg += "<" + save.hero->GetName() + "> ";
    }

    std::string input {""};
    while(input != "return")
    {
        if (input == "return")
        {
            break;
        }

        ConsoleUtils::PrintTextSlowly("\n" + msg + "\n: ", 50);
        input = ConsoleUtils::ScanInput();

        for (SaveGame save: saves)
        {
            if(input == save.hero->GetName())
            {
                ConsoleUtils::ClearScreen();
                UserInterface *ui = new Game(save.hero, save.location);
                ui->Run();
                delete ui;
                return;
            }
        }
        
        ConsoleUtils::ClearScreen();
        ConsoleUtils::PrintTextSlowly("Type Exactly the name of the hero you want to load\n", 50);
    }
}

void StartMenu::Options()
{
    ConsoleUtils::ClearScreen();
    ConsoleUtils::PrintTextSlowly("Not Yet Implemented\n\n", 1);
}

void StartMenu::Help()
{
    ConsoleUtils::ClearScreen();

    std::string msg {"This is a  Command-Text based RPG. Type your command at the command line and magic happens!\n\n"};
    ConsoleUtils::PrintTextSlowly(msg, 50);
}
