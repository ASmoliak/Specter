#pragma once
#include <vector>
#include <string>

class Cryptography
{
public:
	static std::string ToObscryptoB64(const std::string& str, uint8_t obscrypto_key);

	static std::string FromObscryptoB64(const std::string& args);

	static std::vector<uint8_t> Xor(const uint8_t* content, size_t size, uint8_t key);

	static std::vector<uint8_t> Xor(const std::string& content, uint8_t key);

	static std::vector<uint8_t> Xor(const std::vector<uint8_t>& content, uint8_t key);
};
