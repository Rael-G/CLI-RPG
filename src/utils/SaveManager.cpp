#include "utils/SaveManager.hpp"

SaveManager::SaveManager(Data *data)
    : data(data) {}

SaveManager::~SaveManager()
{
    delete data;
}

bool SaveManager::Save(Hero *hero, std::string location)
{
    SaveGame save = SaveGame(hero, location);

    return data->SaveData(save);;
}

std::list<SaveGame> SaveManager::Load()
{
    return data->LoadData();
}

int SaveManager::GetCorrupt()
{
    return data->GetCorrupt();
}