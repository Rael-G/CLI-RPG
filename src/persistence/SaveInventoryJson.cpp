#include "persistence/SaveInventoryJson.hpp"

std::list<Item*> SaveInventoryJson::FromStrToItem(std::list<std::string> inventoryStr)
{
    std::list<Item*> inventory;

    for (std::string str : inventoryStr)
    {
        Item * item = new Item(str);
        inventory.push_back(item);
    }

    return inventory;
}

std::list<std::string> SaveInventoryJson::FromItemToStr(std::list<Item*> inventory)
{
    std::list<std::string> inventoryStr;

    for (Item *item : inventory)
    {
        inventoryStr.push_back(item->ToString());
    }

    return inventoryStr;
} 