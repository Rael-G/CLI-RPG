#pragma once

#include "locations/Location.hpp"
#include "global/World.hpp"
#include "external/nlohmann/json.hpp"
#include "exceptions/CorruptedSaveGameException.hpp"
using json = nlohmann::json;

struct SaveLocationJson
{
    Location *location;

    SaveLocationJson(Location *location);
    json ToJson() const;
    static SaveLocationJson FromJson(json j);

};