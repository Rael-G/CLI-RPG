#include "Location.hpp"

    std::string Location::GetName()
    {
        return name;
    }

    std::string Location::ToString()
    {
        return "You are in " + name + ".\n";
    }

    void Location::Travel()
    {
        //BUG
        //Printa mas a tela é limpa logo apos
        ConsoleUtils::ClearScreen();

        std::string msg {""};
        std::string locations {""};
        std::string numLocations {""};

        if (adjacentLocations.empty())
        {
            msg = "There is no Adjacent Location.\n\n";
        }
        else
        {
            for (int i = 1; i <= adjacentLocations.size(); i++)
            {
                numLocations += "<" + std::to_string(i) + "> ";
            }

            locations = "You can travel to " + adjacentLocations[0]->name;
            for (int i = 1; i < adjacentLocations.size() - 1; i++)
            {
                locations += ", " + adjacentLocations[i]->name;
            }
            locations += " and " + adjacentLocations.back()->name + "\n";

            msg = locations + numLocations + "\n";
        }
        
        ConsoleUtils::PrintTextSlowly(msg, 50);
    }

    std::vector<std::pair<std::string, std::function<void ()>>>Location::GetCommands() 
    {
        return localCommands;
    }