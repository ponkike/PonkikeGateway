#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "HttpRequest.h"
#include "HttpResponse.h"
#include "Gateway.h"
#include "TestBankConnector.h"
#include "ErrorCode.h"

TEST(GatewayTests, TestInvalidApplication)
{
	TestBankConnector bankConnector;
	Gateway gateway(&bankConnector);

	HttpRequest request;
	HttpResponse response = gateway.ProcessHttpRequest(request);

	EXPECT_EQ(0, response.success);
	EXPECT_EQ(ErrorCode::INVALID_APPLICATION_ID, response.errorCode);
}

TEST(GatewayTests, TestBadApiVersion)
{
	TestBankConnector bankConnector;
	Gateway gateway(&bankConnector);

	HttpRequest request;
	strcpy(request.applicationId, "cc");
	HttpResponse response = gateway.ProcessHttpRequest(request);

	EXPECT_EQ(0, response.success);
	EXPECT_EQ(ErrorCode::INVALID_API_VERSION, response.errorCode);
}

TEST(GatewayTests, TestApiVersion1)
{
	TestBankConnector bankConnector;
	Gateway gateway(&bankConnector);

	HttpRequest request;
	request.apiVersion = 1;
	strcpy(request.applicationId, "cc");
	HttpResponse response = gateway.ProcessHttpRequest(request);

	EXPECT_EQ(0, response.success);
	EXPECT_EQ(ErrorCode::BASIC_SECURITY_CHECK_FAILED, response.errorCode);
}