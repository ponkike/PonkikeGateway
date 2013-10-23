#pragma once

#include "Configuration.h"
#include "ErrorCode.h"

struct HttpRequest;

class SecurityEngine
{
public:
	SecurityEngine() {}

	ErrorCode Check(const HttpRequest& httpRequest);
};