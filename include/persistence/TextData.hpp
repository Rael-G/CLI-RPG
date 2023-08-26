#pragma once

#include <map>
#include <string>

class TextData
{
	public:
		virtual ~TextData() = default;
		virtual std::map<std::string, std::string> GetTextData() = 0;
};
