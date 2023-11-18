#pragma once
#include <chrono>

class TimeUtils
{
public:
	TimeUtils() = delete;

	static std::string FormatDuration(std::chrono::milliseconds ms);
};