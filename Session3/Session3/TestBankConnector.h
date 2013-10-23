#pragma once

#include "IBankConnector.h"
#include "IMasterCardBank.h"

class TestMasterCardBank : public IMasterCardBank
{

};

class TestBankConnector : public IBankConnector
{
public:
	virtual std::shared_ptr<IMasterCardBank> ConnectToMastercardBank(const BankDefinition& bank) const
	{
		return std::shared_ptr<IMasterCardBank>(new TestMasterCardBank());
	}
};
