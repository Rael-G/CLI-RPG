#pragma once

#include <string>
#include <vector>
#include "locations/Location.hpp"
#include "entities/Npc.hpp"

class Village : public Location
{
    private:
        std::vector<std::string> npcs;

    public:
        Village(std::string id, std::string name, 
            std::vector<std::string> adjacentLocations, 
            std::vector<std::string> npcs);

        void Talk();
};