#include "persistence/SaveGameJson.hpp"

SaveGameJson::SaveGameJson(Hero *hero, Location *location, std::string date)
    : SaveGame(hero, location), date(date), 
    saveHeroJson(SaveHeroJson(hero)), saveLocationJson(SaveLocationJson(location))
    {

    }

json SaveGameJson::ToJson() const {
    json save;
    save["id"] = saveHeroJson.name;
    save["hero"] = saveHeroJson.ToJson();
    save["location"] = saveLocationJson.ToJson();
    save["date"] = date;
    return save;
}


SaveGameJson SaveGameJson::FromJson(json j)
{
    std::string idd = j["id"];
    json hr = j["hero"];
    json loc = j["location"];
    std::string dt = j["date"];

    return SaveGameJson(SaveHeroJson::FromJson(hr).hero, SaveLocationJson::FromJson(loc).location, dt);
}
