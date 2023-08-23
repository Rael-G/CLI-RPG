#include "locations/Village.hpp"

Village::Village(std::string id, std::string name, 
    std::vector<std::string> adjacentLocations, std::vector<std::string> npcs)
    : npcs(npcs)
{
    this->id = id;
    this->name = name;
    this->adjacentLocations = adjacentLocations;
    
    localCommands.push_back({"talk", std::bind(&Village::Talk, this)});
}

void Village::Talk()
{
    ConsoleUtils::ClearScreen();
    ConsoleUtils::PrintTextSlowly("Not Yet Implemented.\n\n", 1);
}
