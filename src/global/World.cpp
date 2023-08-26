#include <global/World.hpp>

std::map<std::string, Location*> World::locations = {
    { 
        "V01", new Village("V01", "Strange Village", 
        std::vector<std::string> 
            {
                "R01"
            }, 
        std::vector<std::string> 
            {
                
            })
    },
    { 
        "R01", new Village("R01", "Bad Village", 
        std::vector<std::string> 
            {
                "V01"
            }, 
        std::vector<std::string> 
            {
                
            })
    }
};

std::map<std::string, Npc*> World::npcs = {

};

Location* World::GetLocation(std::string id)
{
    auto it = locations.find(id);

    if (it == locations.end())
    {
        throw WorldObjectException("Location not found: " + id + ". ");
    }
    else
    {
        return it->second;
    }
}

Npc* World::GetNpc(std::string id)
{
    auto it = npcs.find(id);

    if (it == npcs.end())
    {
        throw WorldObjectException("NPC not found: " + id + ". ");
    }
    else
    {
        return it->second;
    }
}