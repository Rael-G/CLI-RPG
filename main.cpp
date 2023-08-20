#include <algorithm>
#include <iostream>
#include <string>
#include "InitialMenu.hpp"

int main(){

    UserInterface *ui = new InitialMenu();

    std::string input;
    while (true)
    {
        ui->ShowCommands();
        std::cout << "> ";
        std::cin >> input;

        std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c) {
            return std::tolower(c);
        });

        ui->Input(input);
    }

    return 0;
}