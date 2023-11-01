#pragma once
#include <system_error>
#include <errhandlingapi.h>

// Use this when bad things happen after a Windows syscall.
// Error codes will be converted to proper text
class SyscallException : std::system_error
{
public:
	SyscallException(const std::string& error_msg, DWORD error_code = GetLastError()) :
		std::system_error(error_code, std::system_category(), error_msg + ", error: ")
	{
	}
};