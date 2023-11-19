#pragma once
#include <string>

class StrUtils
{
public:
	StrUtils() = delete;

	static std::wstring Widen(const std::string& narrow_str);
};

