#include "global/World.hpp"

std::map<int, Location*> World::locations = {
    { 
        0, new Village("Strange Village", std::vector<Location*> {}, std::vector<Npc*> {})
    }
};

std::map<int, Npc*> World::npcs = {

};

Location* World::GetLocation(int id)
{
    auto it = locations.find(id);

    if (it == locations.end())
    {
        throw std::runtime_error("ERROR: Location not found. " + std::to_string(id));
    }
    else
    {
        return it->second;
    }
}

Npc* World::GetNpc(int id)
{
    auto it = npcs.find(id);

    if (it == npcs.end())
    {
        throw std::runtime_error("ERROR: NPC not found. " + std::to_string(id));
    }
    else
    {
        return it->second;
    }
}