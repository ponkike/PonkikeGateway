#pragma once

#include <memory>
#include "IMasterCardBank.h"
#include "BankDefinition.h"

class IBankConnector
{
public:
	virtual std::shared_ptr<IMasterCardBank> ConnectToMastercardBank(const BankDefinition& bank) const = 0;
	virtual ~IBankConnector() {};
};