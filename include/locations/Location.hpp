#pragma once

#include <string>
#include <vector>
#include <functional>
#include "utils/ConsoleUtils.hpp"

class Location 
{
    protected:
        int id;
        std::string name;
        std::vector<Location*> adjacentLocations;
        std::vector<std::pair<std::string, std::function<void ()>>> localCommands
        {
            {"travel", std::bind(&Location::Travel, this)}
        };
    public:
        virtual ~Location() {}
        std::string GetName();
        int GetId();
        virtual std::string ToString();
        virtual std::vector<std::pair<std::string, std::function<void ()>>>GetCommands();
        void Travel();
};