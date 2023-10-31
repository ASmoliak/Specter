#pragma once
#include <windows.h>
#include <chrono>

#include "TimeUtils.hpp"

class SystemInfo
{
public:
	SystemInfo() = delete;

	static std::string GetSystemUptime()
	{
		using namespace std::chrono;
		return TimeUtils::FormatDuration(milliseconds(GetTickCount64()));
	}
};