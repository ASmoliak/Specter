#include "SpecterLib/TimeUtils.hpp"

TEST(TimeUtilsTests, EmptyTimeGivesEmptyFormat)
{
	static constexpr std::string_view kExpectedFormat = "0d 0h 0m 0s";
	EXPECT_EQ(TimeUtils::formatDuration(std::chrono::milliseconds(0)), kExpectedFormat);
}

TEST(TimeUtilsTests, OneSecondGivesProperFormat)
{
	static constexpr std::string_view kExpectedFormat = "0d 0h 0m 1s";
	EXPECT_EQ(TimeUtils::formatDuration(std::chrono::milliseconds(1000)), kExpectedFormat);
}

TEST(TimeUtilsTests, OneMinuteGivesProperFormat)
{
	static constexpr std::string_view kExpectedFormat = "0d 0h 1m 0s";
	EXPECT_EQ(TimeUtils::formatDuration(std::chrono::milliseconds(60'000)), kExpectedFormat);
}

TEST(TimeUtilsTests, OneHourGivesProperFormat)
{
	static constexpr std::string_view kExpectedFormat = "0d 1h 0m 0s";
	EXPECT_EQ(TimeUtils::formatDuration(std::chrono::milliseconds(3'600'000)), kExpectedFormat);
}

TEST(TimeUtilsTests, OneDayGivesProperFormat)
{
	static constexpr std::string_view kExpectedFormat = "1d 0h 0m 0s";
	EXPECT_EQ(TimeUtils::formatDuration(std::chrono::milliseconds(86'400'000)), kExpectedFormat);
}