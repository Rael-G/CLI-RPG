#include "InitialMenu.hpp"

    InitialMenu::InitialMenu() : UserInterface() 
    {
        subCommands.insert(
        {
            {"start", std::bind(&InitialMenu::Start, this)}
        });

        ConsoleUtils::ClearScreen();
        std::string str{"Welcome to TextRPG!\n\n"};
        ConsoleUtils::PrintTextSlowly(str, 200);

        std::cout << "You can type <help> anytime for instructions." << std::endl
            << "Type <start> to begin your adventure." << std::endl << std::endl;
    }
    void InitialMenu::Start()
    {
        ConsoleUtils::ClearScreen();

        UserInterface *ui = new CreationMenu();
        ui->Run();
        delete ui;
    }
