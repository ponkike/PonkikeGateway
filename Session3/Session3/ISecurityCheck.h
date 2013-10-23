#pragma once

class HttpRequest;

class ISecurityCheck
{
public:
	ISecurityCheck() {}
	virtual ~ISecurityCheck() {}

	virtual bool Check(const HttpRequest& httpRequest) const = 0;
};