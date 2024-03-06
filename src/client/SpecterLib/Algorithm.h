#pragma once
#include <vector>
#include <string>

class Algorithm
{
public:
	Algorithm() = delete;

	static std::string EncodeBase64(const std::vector<uint8_t>& raw_content);

	static std::vector<uint8_t> DecodeBase64(const std::string& base64);

	static std::string BuildUuid();
};
