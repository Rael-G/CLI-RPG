#include <map>
#include <string>
#include <functional>
#include <iostream>

#pragma once

class UserInterface {
    protected:
        std::map<std::string, std::function<void()>> commands {};
    public:
        UserInterface();
        void ShowCommands();
        void Input(std::string input);
        void Exit();
        void Help();
};