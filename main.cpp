#include "StartMenu.hpp"

int main(){

    UserInterface *ui = new StartMenu();
    ui->Run();
    delete ui;

    return 0;
}