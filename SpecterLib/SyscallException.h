#pragma once
#include <system_error>
#include <string>
#include <minwindef.h>
// Use this when bad things happen after a Windows syscall.
// Error codes will be converted to proper text
class SyscallException : public std::system_error
{
public:
	SyscallException(const std::string& error_msg, DWORD error_code = GetLastError());

	SyscallException(const std::wstring& error_msg, DWORD error_code = GetLastError());
};
