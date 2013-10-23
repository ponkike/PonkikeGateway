#include "Gateway.h"
#include "IBankConnector.h"
#include "ErrorCode.h"

Gateway::Gateway(const IBankConnector* bankConnector) : bankConnector(bankConnector)
{

}

bool Gateway::ConnectToBank(const BankDefinition& bank)
{
	masterCardBank = bankConnector->ConnectToMastercardBank(bank);
	return masterCardBank.get() != nullptr;
}

HttpResponse Gateway::ProcessHttpRequest(const HttpRequest& httpRequest)
{
	//do stuff
	// send data to bank
	//interpret response

	ApplicationId applicationId = configuration.GetApplication(httpRequest.applicationId);
	if(applicationId == ApplicationId::INVALID)
	{
		return HttpResponse(ErrorCode::INVALID_APPLICATION_ID);
	}

	ErrorCode errorCode = securityEngine.Check(httpRequest);
	if (errorCode != ErrorCode::SUCCESS)
	{
		return HttpResponse(errorCode);
	}

	HttpResponse response;
	response.success = 1;
	return response;
}