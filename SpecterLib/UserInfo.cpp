#include "pch.h"
#include "UserInfo.hpp"
#include "SyscallException.hpp"

#include <lmcons.h>

std::string UserInfo::GetMachineName()
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

std::string UserInfo::GetUsername()
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
