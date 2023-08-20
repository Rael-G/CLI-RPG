#include "StartMenu.hpp"

StartMenu::StartMenu() : UserInterface() 
{
    subCommands.push_back({"new", std::bind(&StartMenu::New, this)});
    subCommands.push_back({"load", std::bind(&StartMenu::Load, this)});

    ConsoleUtils::ClearScreen();
    std::string str{"Welcome to TextRPG!\n\n"};
    ConsoleUtils::PrintTextSlowly(str, 200);

    std::cout << "You can type <help> anytime for instructions." << std::endl;
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
