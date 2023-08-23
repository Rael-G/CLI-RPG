#pragma once

#include "locations/Location.hpp"
#include "global/World.hpp"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

struct SaveLocation
{
    Location *location;
    int id;

    SaveLocation(Location *location);
    json ToJson() const;
    static SaveLocation FromJson(json j);

};