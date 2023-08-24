#include "global/DependencyInjector.hpp"

SaveManager* DependencyInjector::GetSaveManager()
{
   return new SaveManager(new JsonData());
}