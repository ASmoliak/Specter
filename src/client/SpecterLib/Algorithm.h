#pragma once
#include <vector>
#include <string>

class Algorithm
{
public:
	Algorithm() = delete;

	static std::string EncodeBase64(const std::vector<char>& raw_content);

	static std::vector<char> DecodeBase64(const std::string& base64);

	static std::string BuildUuid();
};
