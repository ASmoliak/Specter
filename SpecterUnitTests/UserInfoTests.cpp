#include "SpecterLib/UserInfo.hpp"

TEST(UserInfoTests, UsernameIsntEmpty)
{
	EXPECT_FALSE(UserInfo::getUsername().empty());
}

TEST(UserInfoTests, UsernameIsntTooBig)
{
	EXPECT_LT(UserInfo::getUsername().size(), UNLEN + 1);
}

TEST(UserInfoTests, MachineNameIsntEmpty)
{
	EXPECT_FALSE(UserInfo::getMachineName().empty());
}