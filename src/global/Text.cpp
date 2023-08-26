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
	Text* instance = GetInstance();
	auto it = instance->texts.find(id);
	if (it != instance->texts.end())
		return it->second;
	else
		return "";
	//provisorio
}


//Text::GetInstance()->GetText(id)