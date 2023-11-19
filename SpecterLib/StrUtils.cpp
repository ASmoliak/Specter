#include "pch.h"
#include "StrUtils.hpp"
#include "SyscallException.hpp"

std::wstring StrUtils::Widen(const std::string& narrow_str)
{
	const auto output_size = MultiByteToWideChar(CP_UTF8, 0, narrow_str.c_str(), static_cast<int>(narrow_str.size()), nullptr, 0);

	std::wstring wide_str(output_size, 0);

	const auto result = MultiByteToWideChar(CP_UTF8, 0, narrow_str.c_str(), static_cast<int>(narrow_str.size()), wide_str.data(), output_size);
	if (result != output_size)
	{
		throw SyscallException("Failed to widen string, partial conversion");
	}

	return wide_str;
}
