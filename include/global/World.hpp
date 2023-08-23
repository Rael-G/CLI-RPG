#pragma once

#include <map>
#include "locations/Location.hpp"
#include "entities/Npc.hpp"
#include "locations/Village.hpp"

struct World
{
    static std::map<int, Location*> locations;
    static std::map<int, Npc*> npcs;

    static Location* GetLocation(int id);

    static Npc* GetNpc(int id);
};