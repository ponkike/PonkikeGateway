#pragma once
#include <string>

struct BankDefinition
{
	enum Type
	{
		VISA,
		MASTERCARD,
		AMEX
	};

	Type type;
	std::string url;
};