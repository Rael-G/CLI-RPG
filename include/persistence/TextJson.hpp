#pragma once

#include <filesystem>
#include <string>
#include <fstream>
#include <persistence/TextData.hpp>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
namespace fs = std::filesystem;


class TextJson : public TextData
{
	public:
		TextJson(){}
		std::map<std::string, std::string> GetTextData() override;
		json GetJson();
};