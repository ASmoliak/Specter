module;
#include <windows.h>
#include <system_error>
#include <string>
export module SyscallException;

// Use this when bad things happen after a Windows syscall.
// Error codes will be converted to proper text
export class SyscallException : public std::system_error
{
public:
	SyscallException(const std::string& error_msg, DWORD error_code = GetLastError()) :
		std::system_error(static_cast<int>(error_code), std::system_category(), error_msg + ", error")
	{
	}
};
