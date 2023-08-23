#include "persistence/SaveInventory.hpp"

std::list<Item*> SaveInventory::FromStrToItem(std::list<std::string> inventoryStr)
{
    std::list<Item*> inventory;

    for (std::string str : inventoryStr)
    {
        Item * item = new Item(str);
        inventory.push_back(item);
    }

    return inventory;
}

std::list<std::string> SaveInventory::FromItemToStr(std::list<Item*> inventory)
{
    std::list<std::string> inventoryStr;

    for (Item *item : inventory)
    {
        inventoryStr.push_back(item->ToString());
    }

    return inventoryStr;
} 