#include <map>
#include <string>
#include <functional>
#include <iostream>
#include <algorithm>
#include "ConsoleUtils.hpp"

#pragma once

class UserInterface 
{
    protected:
        std::map<std::string, std::function<void()>> commands {};
        std::map<std::string, std::function<void()>> subCommands {};

    public:
        UserInterface();
        void Run();
        void ShowCommands();
        void Input(std::string input);
        void Exit();
        void Help();
        void Return();
        void Options();
};