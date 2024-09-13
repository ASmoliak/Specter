#pragma once
#include <string>

class UserInfo
{
public:
	UserInfo() = delete;

	static std::string GetMachineName();

	static std::string GetUsername();
};