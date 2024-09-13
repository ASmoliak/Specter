#include "SpecterLib/Cryptography.h"

static constexpr char key = 'x';

TEST(CryptographyTests, XorsSimpleString)
{
	const std::string original = "foobar";

	const auto encrypted = Cryptography::Xor(original, key);
	EXPECT_FALSE(std::equal(encrypted.begin(), encrypted.end(), original.begin()));

	const auto decrypted = Cryptography::Xor(encrypted, key);
	EXPECT_TRUE(std::equal(decrypted.begin(), decrypted.end(), original.begin()));
}

TEST(CryptographyTests, XorsHighValuedVector)
{
	const std::vector<uint8_t> original = {0, 10, 20, 255};

	const auto encrypted = Cryptography::Xor(original, key);
	EXPECT_FALSE(std::equal(encrypted.begin(), encrypted.end(), original.begin()));

	const auto decrypted = Cryptography::Xor(encrypted, key);
	EXPECT_TRUE(std::equal(decrypted.begin(), decrypted.end(), original.begin()));
}
