#include "SpecterLib/SystemInfo.hpp"

TEST(SystemInfoTests, GetsNonEmptyHdSerial)
{
	EXPECT_FALSE(SystemInfo::GetHdSerial().empty());
}

TEST(SystemInfoTests, HdSerialNumeric)
{
	uint64_t hdSerial = 0;

	EXPECT_NO_THROW(hdSerial = std::stoll(SystemInfo::GetHdSerial()));
	EXPECT_GT(hdSerial, 0);
}

TEST(SystemInfoTests, UptimeIsntEmpty)
{
	EXPECT_FALSE(SystemInfo::GetUptime().empty());
}