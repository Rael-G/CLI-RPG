#include "persistence/SaveLocationJson.hpp"

SaveLocationJson::SaveLocationJson(Location *location) : location(location) {}

json SaveLocationJson::ToJson() const
{
    json location;
    location["id"] = this->location->GetId();

    return location;
}

SaveLocationJson SaveLocationJson::FromJson(json j)
{
    std::string id = j["id"];

    return SaveLocationJson(World::GetLocation(id));
}
