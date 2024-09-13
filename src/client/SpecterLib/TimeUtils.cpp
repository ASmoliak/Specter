#include "TimeUtils.h"

std::string TimeUtils::FormatDuration(std::chrono::milliseconds ms)
{
	using namespace std::chrono;
	std::string result;

	const auto elapsed_days = duration_cast<days>(ms);
	result += std::to_string(elapsed_days.count()) + "d ";
	ms -= elapsed_days;

	const auto elapsed_hours = duration_cast<hours>(ms);
	result += std::to_string(elapsed_hours.count()) + "h ";
	ms -= elapsed_hours;

	const auto elapsed_minutes = duration_cast<minutes>(ms);
	result += std::to_string(elapsed_minutes.count()) + "m ";
	ms -= elapsed_minutes;

	return result + std::to_string(duration_cast<seconds>(ms).count()) + "s";
}
