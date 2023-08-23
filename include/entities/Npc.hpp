#pragma once

#include <string>
#include <vector>
#include "utils/ConsoleUtils.hpp"

class Npc 
{
    private:
        int id;
        std::string name;
        std::vector<std::pair<std::string, std::string>> dialogs;

    public:
        int GetId();
        std::string GetName();
        void Talk();
};