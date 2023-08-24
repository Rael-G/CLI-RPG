#pragma once

#include "utils/SaveManager.hpp"
#include "persistence/JsonData.hpp"

struct DependencyInjector
{
    static SaveManager* GetSaveManager();
};