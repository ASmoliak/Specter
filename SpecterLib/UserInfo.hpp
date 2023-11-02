#pragma once
#include <lmcons.h>
#include <sysinfoapi.h>

#include "SyscallException.hpp"

class UserInfo
{
public:
	UserInfo() = delete;

	static std::string getMachineName()
	{
		DWORD actual_size = 0;
		GetComputerNameExA(ComputerNameDnsFullyQualified, nullptr, &actual_size);

		if (GetLastError() != ERROR_MORE_DATA)
		{
			throw SyscallException("GetComputerNameExA() didn't fail with ERROR_MORE_DATA as expected");
		}

		std::string qualified_name(static_cast<uint64_t>(actual_size) + 1, 0);
		if (!GetComputerNameExA(ComputerNameDnsFullyQualified, qualified_name.data(), &actual_size))
		{
			throw SyscallException("GetComputerNameExA() failed");
		}

		qualified_name.resize(actual_size + 1);
		return qualified_name;
	}

	static std::string getUsername()
	{
		std::string username(UNLEN + 1, 0);
		DWORD actual_size = static_cast<DWORD>(username.size());

		if (!GetUserNameA(username.data(), &actual_size))
		{
			throw SyscallException("Failed to GetUserName()");
		}

		username.resize(actual_size);
		return username;
	}
};