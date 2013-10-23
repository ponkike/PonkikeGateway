#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "HttpRequest.h"
#include "HttpResponse.h"
#include "Gateway.h"

TEST(a, a)
{
	HttpRequest request;
	HttpResponse response = ProcessHttpRequest(request);

	EXPECT_EQ(1, response.success);
	EXPECT_EQ(0, response.errorCode);
}