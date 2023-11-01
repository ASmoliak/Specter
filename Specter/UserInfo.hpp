#pragma once
#include <windows.h>
#include <lmcons.h>
#include <sysinfoapi.h>

#include "SyscallException.hpp"

class UserInfo
{
public:
	UserInfo() = delete;

	static std::string GetQualifiedUsername()
	{
		DWORD actualSize = 0;
		GetComputerNameExA(ComputerNameDnsFullyQualified, nullptr, &actualSize);

		if (GetLastError() != ERROR_MORE_DATA)
		{
			throw SyscallException("GetComputerNameExA() didn't fail with ERROR_MORE_DATA as expected");
		}

		std::string qualifiedName(static_cast<uint64_t>(actualSize) + 1, 0);
		if (!GetComputerNameExA(ComputerNameDnsFullyQualified, qualifiedName.data(), &actualSize))
		{
			throw SyscallException("GetComputerNameExA() failed");
		}

		return qualifiedName;
	}

	static std::string GetUsername()
	{
		std::string username(UNLEN + 1, 0);
		DWORD actualSize = static_cast<DWORD>(username.size());

		if (!GetUserNameA(username.data(), &actualSize))
		{
			throw SyscallException("Failed to GetUserName()");
		}

		username.resize(actualSize);
		return username;
	}
};