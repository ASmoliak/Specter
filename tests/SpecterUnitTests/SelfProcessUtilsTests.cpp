#include "SpecterLib/SelfProcessUtils.h"

TEST(SelfProcessUtilsTests, DetectsElevation)
{
	EXPECT_FALSE(SelfProcessUtils::IsProcessElevated());
}
