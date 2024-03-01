#include "SpecterLib/SyscallException.h"

TEST(SyscallExceptionTests, ProperlyFormatsError)
{
	const SyscallException exception("Test error message", 0);
	static constexpr std::string_view kExpectedWhat = "Test error message, error: The operation completed successfully.";

	EXPECT_EQ(exception.what(), kExpectedWhat);
}
