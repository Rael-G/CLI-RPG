#pragma once

#include <string>
#include <vector>
#include "ConsoleUtils.hpp"

class Npc 
{
    private:
        std::string name;
        std::vector<std::pair<std::string, std::string>> dialogs;

    public:
        std::string GetName();
        void Talk();
};