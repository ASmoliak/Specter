#include "SpecterLib/SystemInfo.hpp"

TEST(SystemInfoTests, GetsNonEmptyHdSerial)
{
	EXPECT_FALSE(SystemInfo::getHdSerial().empty());
}

TEST(SystemInfoTests, HdSerialNumeric)
{
	uint64_t hdSerial = 0;

	EXPECT_NO_THROW(hdSerial = std::stoll(SystemInfo::getHdSerial()));
	EXPECT_GT(hdSerial, 0);
}

TEST(SystemInfoTests, UptimeIsntEmpty)
{
	EXPECT_FALSE(SystemInfo::getUptime().empty());
}

TEST(SystemInfoTests, OsProductNameIsntEmpty)
{
	EXPECT_FALSE(SystemInfo::getOsProductName().empty());
}

TEST(SystemInfoTests, OsProductNameContainsWindows)
{
	EXPECT_NE(SystemInfo::getOsProductName().find("Windows"), std::string::npos);
}