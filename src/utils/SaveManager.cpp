#include "utils/SaveManager.hpp"

bool SaveManager::Save(Hero *hero, Location *location)
{
    SaveHero sh = SaveHero(hero);
    SaveLocation sl = SaveLocation(location);
    SaveGame save = SaveGame(sh, sl);

    return data->SaveData(save);
}

std::list<SaveGame> SaveManager::Load()
{
    return data->LoadData();
}