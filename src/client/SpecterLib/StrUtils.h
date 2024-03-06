#pragma once
#include <string>

class StrUtils
{
public:
	StrUtils() = delete;

	static std::string Shorten(const std::wstring& wide_str);
	static std::wstring Widen(const std::string& narrow_str);
};
