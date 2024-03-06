#include "SpecterLib/Algorithm.h"

TEST(AlgorithmTests, EncodesAndDecodesBase64)
{
	const std::vector original = {'f', 'o', 'o'};
	const auto encoded = Algorithm::EncodeBase64(original);

	EXPECT_FALSE(std::equal(original.begin(), original.end(), encoded.begin(), encoded.end()));

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
