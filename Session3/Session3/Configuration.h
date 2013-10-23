#pragma once

#include <map>
#include <utility>

enum class ApplicationId
{
	CANDY_CRUSH,
	PAPA_PEAR,
	BUBBLE_WITCH2,

	INVALID
};

class Configuration
{
public:
	Configuration()
	{
		mapping.insert(std::make_pair("cc", ApplicationId::CANDY_CRUSH));
		mapping.insert(std::make_pair("pp", ApplicationId::PAPA_PEAR));
		mapping.insert(std::make_pair("bws2", ApplicationId::BUBBLE_WITCH2));
	}

	ApplicationId GetApplication(const char* name) const
	{
		auto iter = mapping.find(name);
		if(iter != mapping.end())
		{
			return iter->second;
		}
		return ApplicationId::INVALID;
	}

private:
	std::map<std::string, ApplicationId> mapping;
};