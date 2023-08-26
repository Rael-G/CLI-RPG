#pragma once

#include <map>
#include <string>
#include <persistence/TextData.hpp>
#include <global/DependencyInjector.hpp>

class Text
{
	private:
		static Text *instance;
		TextData* data;
		std::map<std::string, std::string> texts;
		Text()
		{
			data = DependencyInjector::GetTextData();
			texts = data->GetTextData();
			delete data;
		}

		Text(Text &other) = delete;
		void operator=(const Text&) = delete;

	public:
		static Text* GetInstance();
		static std::string GetText(std::string id);
};