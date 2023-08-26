#include <persistence/TextJson.hpp>

std::map<std::string, std::string> TextJson::GetTextData()
{
	json textJ = GetJson();
	std::map<std::string, std::string> textMap;

	try
	{
		for (const auto& [id, text] : textJ.items()) {
			textMap[id] = text;
		}
	}
	catch (const std::exception&)
	{
		throw std::exception("You Messed up the Language file.");
	}

	return textMap;
}

json TextJson::GetJson()
{
	fs::path path = "./res/language/en.json";
	json j;

	try
	{
		std::ifstream inputFile(path);
		inputFile >> j;
	}
	catch (const std::exception& e)
	{
		throw std::exception("You messed up the language file.");
	}

	return j;
}