#include "pch.h"
#include "SyscallException.hpp"
#include "StrUtils.hpp"

SyscallException::SyscallException(const std::string& error_msg, DWORD error_code):
	std::system_error(static_cast<int>(error_code), std::system_category(), error_msg + ", error")
{
}

SyscallException::SyscallException(const std::wstring& error_msg, DWORD error_code):
	SyscallException(StrUtils::Shorten(error_msg), error_code)
{
}
