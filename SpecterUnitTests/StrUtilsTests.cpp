#include "SpecterLib/StrUtils.hpp"

TEST(StringUtilsTests, WidensString)
{
	EXPECT_EQ(StrUtils::Widen("foo"), L"foo");
}

TEST(StringUtilsTests, WidensEmptyWstring)
{
	EXPECT_EQ(StrUtils::Widen({}), std::wstring());
}

TEST(StringUtilsTests, ShortensString)
{
	EXPECT_EQ(StrUtils::Shorten(L"foo"), "foo");
}

TEST(StringUtilsTests, ShortensEmptyString)
{
	EXPECT_EQ(StrUtils::Shorten({}), std::string());
}

TEST(StringUtilsTests, WidenedStringReturnsToSameForm)
{
	const std::string original("foo");
	const auto widened = StrUtils::Widen(original);

	EXPECT_EQ(original, StrUtils::Shorten(widened));
}

TEST(StringUtilsTests, ShortenedStringReturnsToSameForm)
{
	const std::wstring original(L"שלום");
	const auto shortened = StrUtils::Shorten(original);

	EXPECT_EQ(original, StrUtils::Widen(shortened));
}