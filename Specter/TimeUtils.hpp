#pragma once
#include <chrono>

class TimeUtils
{
public:
	TimeUtils() = delete;

	static std::string FormatDuration(std::chrono::milliseconds ms)
	{
		using namespace std::chrono;
		std::string result;

		const auto elapsedDays = duration_cast<days>(ms);
		result += std::to_string(elapsedDays.count()) + "d ";
		ms -= elapsedDays;

		const auto elapsedHours = duration_cast<hours>(ms);
		result += std::to_string(elapsedHours.count()) + "h ";
		ms -= elapsedHours;

		const auto elapsedMinutes = duration_cast<minutes>(ms);
		result += std::to_string(elapsedMinutes.count()) + "m ";
		ms -= elapsedMinutes;

		return result + std::to_string(duration_cast<seconds>(ms).count()) + "s";
	}
};