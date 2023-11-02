#pragma once
#include "TimeUtils.hpp"
#include "SyscallException.hpp"

class SystemInfo
{
public:
	SystemInfo() = delete;

	static std::string GetUptime()
	{
		return TimeUtils::FormatDuration(std::chrono::milliseconds(GetTickCount64()));
	}

	static std::string GetHdSerial()
	{
		// TODO this implementation takes the Volume serial number which is easy to change, 
		// it doesn't acquire the Hard Disk serial number, which is hardcoded.
		DWORD volumeSerialNumber;
		if (!GetVolumeInformationW(L"C:\\", nullptr, 0, &volumeSerialNumber, nullptr, nullptr, nullptr, 0))
		{
			throw SyscallException("Failed to acquire hdserial via GetVolumeInformationW()");
		}

		return std::to_string(volumeSerialNumber);
	}

	static std::string GetOsProductName()
	{
		HKEY key;
		if (ERROR_SUCCESS != RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion", 0, KEY_READ, &key))
		{
			throw SyscallException("Failed to get OS product version via RegOpenKeyExW()");
		}

		DWORD sizeInBytes;
		if (ERROR_SUCCESS != RegQueryValueExA(key, "ProductName", nullptr, nullptr, nullptr, &sizeInBytes))
		{
			RegCloseKey(key);
			throw SyscallException("Failed to get ProductName length via RegQueryValueExA()");
		}

		std::string productName(sizeInBytes, 0);

		RegQueryValueExA(key, "ProductName", nullptr, nullptr, reinterpret_cast<LPBYTE>(productName.data()), &sizeInBytes);
		RegCloseKey(key);
		productName.resize(sizeInBytes);

		return productName;
	}
};