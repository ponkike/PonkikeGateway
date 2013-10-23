#pragma once

#include "HttpRequest.h"
#include "HttpResponse.h"
#include "BankDefinition.h"
#include "Configuration.h"
#include <memory>

class IBankConnector;
class IMasterCardBank;

class Gateway
{
public:
	Gateway(const IBankConnector* bankConnector);

	bool ConnectToBank(const BankDefinition& bank);
	HttpResponse ProcessHttpRequest(const HttpRequest& httpRequest);

private:
	Configuration configuration;
	const IBankConnector* bankConnector;
	std::shared_ptr<IMasterCardBank> masterCardBank;
};