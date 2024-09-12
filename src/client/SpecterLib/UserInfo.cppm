module;
#include <string>
#include <lmcons.h>
export module UserInfo;

import SyscallException;

export class UserInfo
{
public:
	UserInfo() = delete;

	static std::string GetMachineName()
	{
		DWORD actual_size = 0;
		GetComputerNameExA(ComputerNameDnsFullyQualified, nullptr, &actual_size);

		if (GetLastError() != ERROR_MORE_DATA)
		{
			throw SyscallException("GetComputerNameExA() didn't fail with ERROR_MORE_DATA as expected");
		}

		std::string qualified_name(static_cast<size_t>(actual_size) + sizeof(char), 0);
		if (!GetComputerNameExA(ComputerNameDnsFullyQualified, qualified_name.data(), &actual_size))
		{
			throw SyscallException("GetComputerNameExA() failed");
		}

		qualified_name.resize(actual_size + 1);
		return qualified_name;
	}

	static std::string GetUsername()
	{
		DWORD size = UNLEN + 1;
		std::string username(size, 0);

		if (!GetUserNameA(username.data(), &size))
		{
			throw SyscallException("Failed to GetUserName()");
		}

		username.resize(size);
		return username;
	}

	static uint32_t GetUsernameMaxLen()
	{
		return UNLEN + 1;
	}
};
