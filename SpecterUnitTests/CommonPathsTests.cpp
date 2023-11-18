#include "SpecterLib/CommonPaths.hpp"

TEST(CommonPathsTests, GetsNonEmptyLocalPath)
{
	EXPECT_FALSE(CommonPaths::GetLocalPath().empty());
}

TEST(CommonPathsTests, GetsExistingLocalPath)
{
	EXPECT_TRUE(exists(CommonPaths::GetLocalPath()));
}
