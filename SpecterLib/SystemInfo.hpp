#pragma once
#include "TimeUtils.hpp"
#include "SyscallException.hpp"

class SystemInfo
{
public:
	SystemInfo() = delete;

	static std::string getUptime()
	{
		return TimeUtils::formatDuration(std::chrono::milliseconds(GetTickCount64()));
	}

	static std::string getHdSerial()
	{
		// TODO this implementation takes the Volume serial number which is easy to change, 
		// it doesn't acquire the Hard Disk serial number, which is hardcoded.
		DWORD volume_serial_number;
		if (!GetVolumeInformationW(L"C:\\", nullptr, 0, &volume_serial_number, nullptr, nullptr, nullptr, 0))
		{
			throw SyscallException("Failed to acquire hdserial via GetVolumeInformationW()");
		}

		return std::to_string(volume_serial_number);
	}

	static std::string getOsProductName()
	{
		HKEY key;
		if (ERROR_SUCCESS != RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion", 0, KEY_READ, &key))
		{
			throw SyscallException("Failed to get OS product version via RegOpenKeyExW()");
		}

		DWORD size_in_bytes;
		if (ERROR_SUCCESS != RegQueryValueExA(key, "ProductName", nullptr, nullptr, nullptr, &size_in_bytes))
		{
			RegCloseKey(key);
			throw SyscallException("Failed to get ProductName length via RegQueryValueExA()");
		}

		std::string product_name(size_in_bytes, 0);

		RegQueryValueExA(key, "ProductName", nullptr, nullptr, reinterpret_cast<LPBYTE>(product_name.data()), &size_in_bytes);
		RegCloseKey(key);
		product_name.resize(size_in_bytes);

		return product_name;
	}
};