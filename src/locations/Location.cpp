#include "locations/Location.hpp"
#include "global/World.hpp"

std::string Location::GetId()
{
    return id;
}

std::string Location::GetName()
{
    return name;
}

std::string Location::ToString()
{
    return "You are in " + name + ".";
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
        //Supposed to never happen
        msg = "There is no Adjacent Location.\n\n";
    }
    else
    {
        for (int i = 1; i <= adjacentLocations.size(); i++)
        {
            numLocations += "<" + std::to_string(i) + "> ";
        }

        locations = "You can travel to " + World::GetLocation(adjacentLocations[0])->GetName();
        if (adjacentLocations.size() > 2)
        {
            for (int i = 1; i < adjacentLocations.size() - 1; i++)
            {
                locations += ", " + World::GetLocation(adjacentLocations[i])->GetName();
            }
        }
        if (adjacentLocations.size() > 1)
        {
            locations += " and " + World::GetLocation(adjacentLocations.back())->GetName() + "\n";
        }

        msg = locations + "\n" + numLocations + "\n";
    }
    
    ConsoleUtils::PrintTextSlowly(msg, 50);
}

std::vector<std::pair<std::string, std::function<void ()>>>Location::GetCommands() 
{
    return localCommands;
}