#include "pch.h"
#include "SpecterLib/SelfProcessUtils.hpp"

TEST(SelfProcessUtilsTests, DetectsElevation)
{
	EXPECT_FALSE(SelfProcessUtils::IsProcessElevated());
}
