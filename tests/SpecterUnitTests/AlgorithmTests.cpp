#include "SpecterLib/Algorithm.h"

TEST(AlgorithmTests, EncodesDecodesBase64)
{
	const std::vector<uint8_t> original = {0, 125, 255};
	const auto encoded = Algorithm::EncodeBase64(original);

	EXPECT_FALSE(std::equal(original.begin(), original.end(), encoded.begin()));

	const auto decoded = Algorithm::DecodeBase64(encoded);
	EXPECT_EQ(decoded, original);
}

TEST(AlgorithmTests, GeneratesNonEmptyUuid)
{
	EXPECT_FALSE(Algorithm::BuildUuid().empty());
}

TEST(AlgorithmTests, GeneratesRandomUuid)
{
	EXPECT_NE(Algorithm::BuildUuid(), Algorithm::BuildUuid());
}

TEST(AlgorithmTests, GeneratesRandomUintInRange)
{
	constexpr uint64_t minmax = 1'000'000;

	// Checking that our ranges work.
	// Astronomical chances that it'll generate minmax without the range working 
	// This is due to the sheer size of uint64_t
	EXPECT_EQ(Algorithm::GenerateRandomUInt<uint64_t>(minmax, minmax), minmax);
}

TEST(AlgorithmTests, GeneratesRandomUint)
{
	// Astronomical chances that it'll generate the same number twice
	EXPECT_NE(Algorithm::GenerateRandomUInt<uint64_t>(), Algorithm::GenerateRandomUInt<uint64_t>());
}
