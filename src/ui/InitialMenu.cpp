#include "InitialMenu.hpp"

    InitialMenu::InitialMenu() : UserInterface() {
        commands.insert({
            {"start", std::bind(&InitialMenu::Start, this)}
        });

        system("clear");
        std::cout << "Welcome to TextRPG!" << std::endl
            << "You can type <help> anytime for instructions." << std::endl
            << "Type <start> to begin your adventure." << std::endl;
    }
    void InitialMenu::Start(){
        system("clear");
    }
