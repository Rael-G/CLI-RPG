#include "persistence/SaveLocation.hpp"

SaveLocation::SaveLocation(Location *location) : location(location)
{
    id = location->GetId();
}

json SaveLocation::ToJson() const
{
    json location;
    location["id"] = id;

    return location;
}

SaveLocation SaveLocation::FromJson(json j)
{
    int id = j["id"];

    return SaveLocation(World::GetLocation(id));
}
