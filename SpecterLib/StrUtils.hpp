#pragma once
#include <codecvt>
#include <string>

#include "SyscallException.hpp"

class StrUtils
{
public:
	StrUtils() = delete;

	static std::wstring Widen(const std::string& str)
	{
		const auto output_size = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), str.size(), nullptr, 0);

		std::wstring wstring(output_size, 0);

		const auto result = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), str.size(), wstring.data(), output_size);
		if (result != output_size)
		{
			throw SyscallException("Failed to widen string, partial conversion");
		}

		return wstring;
	}
};

