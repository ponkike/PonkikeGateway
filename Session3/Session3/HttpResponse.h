#pragma once

#include "Types.h"
#include "ErrorCode.h"

struct HttpResponse
{
	HttpResponse() : success(0), transactionId(0), errorCode(ErrorCode::INVALID_ERROR_CODE)
	{

	}

	HttpResponse(ErrorCode errorCode) : success(0), transactionId(0), errorCode(errorCode)
	{

	}

	u32 success;
	u32 transactionId;
	ErrorCode errorCode;
};