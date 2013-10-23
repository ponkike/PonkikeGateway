#pragma once

#include "Types.h"
#include <cstring>

struct HttpRequest
{
	HttpRequest()
	{
		std::memset(&applicationId[0], 0, sizeof(this));
	}

	char applicationId[32];
	char orderId[32];
	char ccType[16];
	char ccBeholder[64];
	char ccNumber[16];
	char ccExpiryMonth[2];
	char ccExpiryYear[2];
	char ccCvv[7];
	char chargeAmount[13];
	char chargeCurrency[3];
	char securityKey[32];

	// for future use
	char reserved[256];

	u32 apiVersion;
};