#pragma once
#include <string>

class SystemInfo
{
public:
	SystemInfo() = delete;

	static std::string GetUptime();

	static std::string GetHdSerial();

	static std::string GetOsProductName();
};