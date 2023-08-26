#include <global/DependencyInjector.hpp>

SaveManager* DependencyInjector::GetSaveManager()
{
   return new SaveManager(new JsonData());
}

TextData* DependencyInjector::GetTextData()
{
	return new TextJson();
}
