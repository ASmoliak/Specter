#include "SpecterLib/InitialConfig.h"

TEST(InitialConfigTests, EncodesAndParsesObscryptoProperly)
{
	const InitialConfig original_config("SampleServerUrl", "SampleServerPort", "SampleGuid");
	constexpr uint8_t sample_key = 'x';

	const auto obscrypto_b64 = original_config.Serialize(sample_key);
	EXPECT_FALSE(obscrypto_b64.empty());

	const auto parsed_config = InitialConfig::BuildFromSerialized(obscrypto_b64);

	EXPECT_EQ(original_config.GetServerEndpoint(), parsed_config.GetServerEndpoint());
	EXPECT_EQ(original_config.GetServerPort(), parsed_config.GetServerPort());
	EXPECT_EQ(original_config.GetGuid(), parsed_config.GetGuid());
}
