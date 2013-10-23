#pragma once

#include "Types.h"

struct HttpResponse
{
	HttpResponse() : success(0), transactionId(0), errorCode(0)
	{

	}

	u32 success;
	u32 transactionId;
	u32 errorCode;
};