#pragma once
#include <chrono>
#include <string>

class TimeUtils
{
public:
	TimeUtils() = delete;

	static std::string FormatDuration(std::chrono::milliseconds ms);
};