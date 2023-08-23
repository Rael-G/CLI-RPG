#pragma once

#include "locations/Location.hpp"
#include "global/World.hpp"
#include "external/nlohmann/json.hpp"
#include "exceptions/CorruptedSaveGameException.hpp"
using json = nlohmann::json;

struct SaveLocation
{
    Location *location;
    int id;

    SaveLocation(Location *location);
    json ToJson() const;
    static SaveLocation FromJson(json j);

};