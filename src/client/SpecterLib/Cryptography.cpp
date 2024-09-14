#include "Cryptography.h"

#include <boost/format.hpp>

#include "Algorithm.h"
#include "StrUtils.h"

std::string Cryptography::ToObscryptoB64(const std::string& str, uint8_t obscrypto_key)
{
	// Xor the args, and push the key into the start of the buffer so that we can decrypt it later
	auto obscrypto_args = Xor(str, obscrypto_key);
	obscrypto_args.insert(obscrypto_args.begin(), obscrypto_key);
	return Algorithm::EncodeBase64(obscrypto_args);
}

std::string Cryptography::FromObscryptoB64(const std::string& args)
{
	auto decoded = Algorithm::DecodeBase64(args);

	// Grab the key and remove it from the vector
	const auto key = decoded.front();
	decoded.erase(decoded.begin());

	// Decrypt all but the null terminator
	const auto decrypted_bytes = Xor(decoded.data(), decoded.size() - 1, key);

	return StrUtils::FromBuffer(decrypted_bytes);
}

std::vector<uint8_t> Cryptography::Xor(const std::vector<uint8_t>& content, uint8_t key)
{
	return Xor(content.data(), content.size(), key);
}

std::vector<uint8_t> Cryptography::Xor(const std::string& content, uint8_t key)
{
	return Xor(reinterpret_cast<const uint8_t*>(content.data()), content.size(), key);
}

std::vector<uint8_t> Cryptography::Xor(const uint8_t* content, size_t size, uint8_t key)
{
	std::vector output(content, content + size);

	for (auto& element : output)
	{
		element ^= key;
	}

	return output;
}
