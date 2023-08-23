#include "global/DependencyInjector.hpp"

std::unique_ptr<SaveManager> DependencyInjector::GetSaveManager()
{
   return std::make_unique<SaveManager>(new JsonData());
}