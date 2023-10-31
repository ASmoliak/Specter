#pragma once
#include <windows.h>
#include <lmcons.h>
#include <stdexcept>
#include <string>
#include <sysinfoapi.h>

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
			throw std::runtime_error("GetComputerNameExA() didn't fail with ERROR_MORE_DATA as expected, error code: " + std::to_string(GetLastError()));
		}

		std::string qualifiedName(static_cast<uint64_t>(actualSize) + 1, 0);
		if (!GetComputerNameExA(ComputerNameDnsFullyQualified, qualifiedName.data(), &actualSize))
		{
			throw std::runtime_error("GetComputerNameExA() failed, error code: " + std::to_string(GetLastError()));
		}

		return qualifiedName;
	}

	static std::wstring GetUsername()
	{
		std::wstring username(UNLEN + 1, 0);
		DWORD actualSize = static_cast<DWORD>(username.size());

		if (!GetUserNameW(username.data(), &actualSize))
		{
			throw std::runtime_error("Failed to GetUserName, error code: " + std::to_string(GetLastError()));
		}

		username.resize(actualSize);
		return username;
	}
};