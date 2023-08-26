#pragma once

#include <utils/SaveManager.hpp>
#include <persistence/JsonData.hpp>
#include <persistence/TextData.hpp>
#include <persistence/TextJson.hpp>


struct DependencyInjector
{
    static SaveManager* GetSaveManager();
    static TextData* GetTextData();
};