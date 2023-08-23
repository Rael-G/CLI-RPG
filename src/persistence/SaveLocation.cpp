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
    try
    {
        int id = j["id"];

        return SaveLocation(World::GetLocation(id));
    }
    catch(const json::exception& e)
    {
        std::string msg {"\nError In SaveLocation: \nSaveLocation FromJson(json j)\n" 
            + std::string(e.what()) + "\n" + j.dump() + "\n"};
        throw std::runtime_error(msg);
    }
}