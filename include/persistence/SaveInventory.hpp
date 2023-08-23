#pragma once

#include <list>
#include <string>
#include "entities/Item.hpp"

struct SaveInventory
{
    std::list<Item*> inventory;
    std::list<std::string> inventoryStr;

    static std::list<Item*> FromStrToItem(std::list<std::string> inventoryStr);
    static std::list<std::string> FromItemToStr(std::list<Item*> inventory);
};