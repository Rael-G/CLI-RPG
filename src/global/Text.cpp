#include <global/Text.hpp>

Text* Text::instance = nullptr;

Text* Text::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new Text();
	}

	return instance;
}

std::string Text::GetText(std::string id)
{
	auto it = texts.find(id);
	if (it != texts.end())
		return it->second;
	else
		return "";
	//provisorio
}