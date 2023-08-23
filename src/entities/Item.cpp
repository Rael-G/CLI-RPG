#include "entities/Item.hpp"

Item::Item(std::string name) : name(name)
{

}
std::string Item::ToString()
{
    return name;
}