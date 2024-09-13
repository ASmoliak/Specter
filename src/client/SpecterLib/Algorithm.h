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

	// Generates random number, you can specify the minimum and maximum
	// Or not specify anything if you want the full possible range for that integer type.
	template <typename T>
	static T GenerateRandomUInt(T min = std::numeric_limits<T>::min(), T max = std::numeric_limits<T>::max())
	{
		return static_cast<T>(GenerateRandomUIntImpl(min, max));
	}

private:
	static uint64_t GenerateRandomUIntImpl(uint64_t min, uint64_t max);
};
