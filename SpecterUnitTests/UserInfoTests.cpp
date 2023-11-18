#include <lmcons.h>

#include "SpecterLib/UserInfo.hpp"

TEST(UserInfoTests, UsernameIsntEmpty)
{
	EXPECT_FALSE(UserInfo::GetUsername().empty());
}

TEST(UserInfoTests, UsernameIsntTooBig)
{
	EXPECT_LT(UserInfo::GetUsername().size(), UNLEN + 1);
}

TEST(UserInfoTests, MachineNameIsntEmpty)
{
	EXPECT_FALSE(UserInfo::GetMachineName().empty());
}