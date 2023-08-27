#include "persistence/SaveGameJson.hpp"

SaveGameJson::SaveGameJson(Hero *hero, std::string location, std::string date)
    : SaveGame(hero, location), date(date), 
    saveHeroJson(SaveHeroJson(hero))
    {

    }

json SaveGameJson::ToJson() const 
{
    json save;
    save["hero"] = saveHeroJson.ToJson();
    save["location"] = location;
    save["date"] = date;
    return save;
}


SaveGameJson SaveGameJson::FromJson(json j)
{
    json hr = j["hero"];
    std::string loc = j["location"];
    std::string dt = j["date"];

    return SaveGameJson(SaveHeroJson::FromJson(hr).hero, loc, dt);
}
