#include "StrUtils.h"
#include "SyscallException.h"

std::wstring StrUtils::Widen(const std::string& narrow_str)
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

std::string StrUtils::Shorten(const std::wstring& wide_str)
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

std::string StrUtils::FromBuffer(const std::vector<uint8_t>& binary)
{
	return {reinterpret_cast<const char*>(binary.data()), binary.size()};
}
