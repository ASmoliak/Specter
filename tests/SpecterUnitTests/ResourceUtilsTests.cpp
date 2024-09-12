// ReSharper disable CppClangTidyBugproneUncheckedOptionalAccess
#include "resource.h"
import ResourceUtils;

TEST(ResourceUtilsTests, FailsToReadNonExistentResource)
{
	EXPECT_FALSE(ResourceUtils::ReadRawResource(INT_MAX).has_value());
}

TEST(ResourceUtilsTests, ReadsExistingResource)
{
	const auto potential_resource_content = ResourceUtils::ReadRawResource(IDR_TEST_RESOURCE);

	EXPECT_TRUE(potential_resource_content.has_value());
	EXPECT_FALSE(potential_resource_content->empty());
}
