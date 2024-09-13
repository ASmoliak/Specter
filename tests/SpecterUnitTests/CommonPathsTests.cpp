#include "SpecterLib/CommonPaths.h"

TEST(CommonPathsTests, GetsNonEmptyLocalPath)
{
	EXPECT_FALSE(CommonPaths::GetLocalPath().empty());
}

TEST(CommonPathsTests, GetsExistingLocalPath)
{
	EXPECT_TRUE(exists(CommonPaths::GetLocalPath()));
}
