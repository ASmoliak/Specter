#pragma once
#include <string>

class StrUtils
{
public:
	StrUtils() = delete;

	// Converts a UTF-16 string into a UTF-8 string
	static std::string Shorten(const std::wstring& wide_str);

	// Converts a UTF-8 string into a UTF-16 string
	static std::wstring Widen(const std::string& narrow_str);

	// Constructs a string out of a buffer of bytes.
	// Make sure your entire buffer is a valid string before doing this.
	static std::string FromBuffer(const std::vector<uint8_t>& binary);
};
