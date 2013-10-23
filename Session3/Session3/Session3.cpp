#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "HttpRequest.h"
#include "HttpResponse.h"
#include "Gateway.h"
#include "TestBankConnector.h"

TEST(a, a)
{
	TestBankConnector bankConnector;
	Gateway gateway(&bankConnector);

	HttpRequest request;
	HttpResponse response = gateway.ProcessHttpRequest(request);

	EXPECT_EQ(1, response.success);
	EXPECT_EQ(0, response.errorCode);
}