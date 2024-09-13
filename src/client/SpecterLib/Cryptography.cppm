module;
#include <vector>
#include <string>
export module Cryptography;

import ProcessUtils;

export class Cryptography
{
public:
	static std::vector<uint8_t> Xor(const std::string& content, uint8_t key)
	{
		return Xor(reinterpret_cast<const uint8_t*>(content.data()), content.size(), key);
	}

	static std::vector<uint8_t> Xor(const std::vector<uint8_t>& content, uint8_t key)
	{
		ProcessUtils::RunProcess("test", L"test2");

		return Xor(content.data(), content.size(), key);
	}

	static std::vector<uint8_t> Xor(const uint8_t* content, size_t size, uint8_t key)
	{
		std::vector<uint8_t> output(size);

		for (size_t i = 0; i < size; ++i)
		{
			output[i] = static_cast<uint8_t>(content[i] ^ key);
		}

		return output;
	}
};