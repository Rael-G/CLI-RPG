#pragma once

#include <map>
#include <locations/Location.hpp>
#include <entities/Npc.hpp>
#include <locations/Village.hpp>
#include <exceptions/WorldObjectException.hpp>


struct World
{
    static std::map<std::string, Location*> locations;
    static std::map<std::string, Npc*> npcs;

    static Location* GetLocation(std::string id);
    static Npc* GetNpc(std::string id);
};