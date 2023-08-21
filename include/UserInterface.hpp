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
        virtual ~UserInterface() {}
        virtual void Run();
        void ShowCommands();
        void Input(std::string input);
        virtual std::string ToString() = 0;
        void Exit();
        void Return();
};