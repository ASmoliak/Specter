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
