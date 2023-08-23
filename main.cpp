#include "ui/StartMenu.hpp"

int main(){
    
    ConsoleUtils::ClearScreen();
    UserInterface *ui = new StartMenu();
    ui->Run();
    delete ui;

    return 0;
}