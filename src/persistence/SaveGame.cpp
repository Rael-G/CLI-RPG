#include "persistence/SaveGame.hpp"

SaveGame::SaveGame(SaveHero hero, SaveLocation location, std::string date)
    : saveHero(hero), saveLocation(location), date(date), hero(hero.hero), location(location.location)
    {}

json SaveGame::ToJson() const {
    json save;
    save["id"] = saveHero.name;
    save["hero"] = saveHero.ToJson();
    save["location"] = saveLocation.ToJson();
    save["date"] = date;
    return save;
}


SaveGame SaveGame::FromJson(json j)
{
    std::string idd = j["id"];
    json hr = j["hero"];
    json loc = j["location"];
    std::string dt = j["date"];

    return SaveGame(SaveHero::FromJson(hr), SaveLocation::FromJson(loc), dt);
}