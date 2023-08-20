#include "InitialMenu.hpp"

int main(){

    UserInterface *ui = new InitialMenu();
    ui->Run();
    delete ui;

    return 0;
}