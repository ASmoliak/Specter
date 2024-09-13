module;
#include <string>
#include <vector>
#include <windows.h>
export module StrUtils;

import SyscallException;

export class StrUtils
{
public:
	StrUtils() = delete;

	// Converts a UTF-16 string into a UTF-8 string
	static std::string Shorten(const std::wstring& wide_str)
	{
		const auto output_size = WideCharToMultiByte(CP_UTF8, 0, wide_str.c_str(), static_cast<int>(wide_str.size()), nullptr, 0, nullptr, nullptr);

		std::string short_str(output_size, 0);

		const int actual_size = WideCharToMultiByte(CP_UTF8, 0, wide_str.c_str(), static_cast<int>(wide_str.size()), short_str.data(), output_size, nullptr, nullptr);
		if (output_size != actual_size)
		{
			throw SyscallException("Failed to convert wide string to multi-byte string, partial conversion");
		}

		return short_str;
	}

	// Converts a UTF-8 string into a UTF-16 string
	static std::wstring Widen(const std::string& narrow_str)
	{
		const auto output_size = MultiByteToWideChar(CP_UTF8, 0, narrow_str.c_str(), static_cast<int>(narrow_str.size()), nullptr, 0);

		std::wstring wide_str(output_size, 0);

		const auto result = MultiByteToWideChar(CP_UTF8, 0, narrow_str.c_str(), static_cast<int>(narrow_str.size()), wide_str.data(), output_size);
		if (result != output_size)
		{
			throw SyscallException("Failed to convert multi-byte string to wide string, partial conversion");
		}

		return wide_str;
	}

	// Constructs a string out of a buffer of bytes.
	// Make sure your entire buffer is a valid string before doing this.
	static std::string FromBuffer(const std::vector<uint8_t>& binary)
	{
		return { reinterpret_cast<const char*>(binary.data()), binary.size() };
	}

};