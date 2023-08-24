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
    return " _______                                __\n" 
           "|   _   |.--.--..----..-----..-----..--|  |\n"
           "|.   ___||  |  ||   _||__ --||  -__||  _  |\n"
           "|.  |___ |_____||__|  |_____||_____||_____|\n"
           "|:      |\n"
           "|::.. . |\n"
           "`-------'\n"
           " ___                       __\n"
           "|   |    .---.-..-----..--|  |.-----.\n"
           "|.  |    |  _  ||     ||  _  ||__ --|\n"
           "|.  |___ |___._||__|__||_____||_____|\n"
           "|:  |   |\n"
           "|::.. . |\n"
           "`-------'\n"
           " ___                                   __\n"
           "|   |.-----..----..--.--..----..-----.|__|.-----..-----.\n"
           "|.  ||     ||  __||  |  ||   _||__ --||  ||  _  ||     |\n"
           "|.  ||__|__||____||_____||__|  |_____||__||_____||__|__|\n"
           "|:  |\n"
           "|::.|\n"
           "`---'\n";
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

    std::list<SaveGame> saves;
    int corrupt {0};

    SaveManager *sm = DependencyInjector::GetSaveManager();
    try
    {
        saves = sm->Load();

        corrupt = sm->GetCorrupt();
        if (corrupt > 0)
        {
            throw CorruptedSaveGameException(corrupt);
        }
    }
    catch(const EmptySaveFolderException& e)
    {

       ConsoleUtils::PrintTextSlowly(e.Message() + "\n");
       return;
    }
    catch(const CorruptedSaveGameException& e)
    {

        ConsoleUtils::PrintTextSlowly(e.Message() + "\n");
    }

    std::string msg {"<return>\n"};

    for (SaveGame save : saves)
    {
        msg += "<" + save.hero->GetName() + "> ";
    }

    std::string input {""};
    while(input != "return")
    {
        ConsoleUtils::PrintTextSlowly("\n" + msg + "\n: ", 50);

        input = ConsoleUtils::ScanLine();
        if (input == "return")
        {
            break;
        }

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

    delete sm;
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
