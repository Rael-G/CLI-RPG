#include "StartMenu.hpp"

    StartMenu::StartMenu() : UserInterface() 
    {
        subCommands.insert(
        {
            {"new", std::bind(&StartMenu::New, this)},
            {"load", std::bind(&StartMenu::Load, this)}
        });

        ConsoleUtils::ClearScreen();
        std::string str{"Welcome to TextRPG!\n\n"};
        ConsoleUtils::PrintTextSlowly(str, 200);

        std::cout << "You can type <help> anytime for instructions." << std::endl
            << "Type <start> to begin your adventure." << std::endl << std::endl;
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
