#pragma once

#include <string>
#include <vector>
#include <functional>
#include "ConsoleUtils.hpp"

class Location 
{
    protected:
        std::string name;
        std::vector<Location*> adjacentLocations;
        std::vector<std::pair<std::string, std::function<void ()>>> localCommands
        {
            {"travel", std::bind(&Location::Travel, this)}
        };
    public:
        virtual ~Location() {}
        std::string GetName();
        virtual std::string ToString();
        virtual std::vector<std::pair<std::string, std::function<void ()>>>GetCommands();
        void Travel();
};