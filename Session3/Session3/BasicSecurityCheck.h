#pragma once

#include <sstream>
#include "HttpRequest.h"
#include "ErrorCode.h"

class BasicSecurityCheck
{
public:
	static ErrorCode Check(const HttpRequest& httpRequest)
	{
		//first character of Application ID + Order ID + CC Type + CC Beholder + CC Number + CC Expiry Month + CC Expiry year + CC CVV + Charge Amount

		std::stringstream securityKey;

		securityKey <<
			httpRequest.applicationId[0] <<
			httpRequest.orderId[0] <<
			httpRequest.ccType[0] <<
			httpRequest.ccBeholder[0] <<
			httpRequest.ccNumber[0] <<
			httpRequest.ccExpiryMonth[0] <<
			httpRequest.ccExpiryYear[0] <<
			httpRequest.ccCvv[0] <<
			httpRequest.chargeAmount[0];
		
		const bool securityKeyMatch = (securityKey.str() == httpRequest.securityKey);

		return securityKeyMatch ? ErrorCode::SUCCESS : ErrorCode::BASIC_SECURITY_CHECK_FAILED;
	}
};