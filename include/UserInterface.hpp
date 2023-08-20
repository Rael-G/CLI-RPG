#pragma once

#include <vector>
#include <string>
#include <functional>
#include <iostream>
#include <algorithm>
#include "ConsoleUtils.hpp"

class UserInterface 
{
    protected:
        std::vector<std::pair<std::string, std::function<void()>>> commands {};
        std::vector<std::pair<std::string, std::function<void()>>> subCommands {};

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