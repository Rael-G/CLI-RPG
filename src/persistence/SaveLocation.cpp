#include "persistence/SaveLocation.hpp"

SaveLocation::SaveLocation(Location *location) : location(location) {}

json SaveLocation::ToJson() const
{
    json location;
    location["id"] = this->location->GetId();

    return location;
}

SaveLocation SaveLocation::FromJson(json j)
{
    std::string id = j["id"];

    return SaveLocation(World::GetLocation(id));
}
