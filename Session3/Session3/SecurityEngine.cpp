#include "SecurityEngine.h"
#include "BasicSecurityCheck.h"
#include "ErrorCode.h"

ErrorCode SecurityEngine::Check(const HttpRequest& httpRequest)
{
	switch(httpRequest.apiVersion)
	{
		case 1:
		{
			return BasicSecurityCheck::Check(httpRequest);
		}
	}

	return ErrorCode::INVALID_API_VERSION;
}