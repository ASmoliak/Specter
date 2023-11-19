#include "pch.h"
#include "StrUtils.hpp"
#include "SyscallException.hpp"

#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/lexical_cast.hpp>

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

std::string StrUtils::BuildUuid()
{
	const auto uuid = boost::uuids::random_generator()();

	return boost::lexical_cast<std::string>(uuid);
}