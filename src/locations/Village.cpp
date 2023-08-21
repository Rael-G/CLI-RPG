#include "Village.hpp"

Village::Village(std::string name, 
    std::vector<Location*> adjacentLocations, std::vector<Npc> npcs)
{
    this->name = name;
    this->adjacentLocations = adjacentLocations;
    this->npcs = npcs;

    localCommands.push_back({"talk", std::bind(&Village::Talk, this)});
}

void Village::Talk()
{
    ConsoleUtils::ClearScreen();
    ConsoleUtils::PrintTextSlowly("Not Yet Implemented.\n\n", 1);
}
