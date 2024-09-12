module;
#include <string>
#include <chrono>
#include <windows.h>
#include <winreg/WinReg.hpp>
export module SystemInfo;

import StrUtils;
import SyscallException;
import TimeUtils;

export class SystemInfo
{
public:
	SystemInfo() = delete;

	static std::string GetUptime()
	{
		return TimeUtils::FormatDuration(std::chrono::milliseconds(GetTickCount64()));
	}

	static std::string GetHdSerial()
	{
		DWORD volume_serial_number;
		if (!GetVolumeInformationW(L"C:\\", nullptr, 0, &volume_serial_number, nullptr, nullptr, nullptr, 0))
		{
			throw SyscallException("Failed to acquire hdserial via GetVolumeInformationW()");
		}
		return std::to_string(volume_serial_number);
	}

	static std::string GetOsProductName()
	{
		try
		{
			const winreg::RegKey key(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion", KEY_READ);
			return StrUtils::Shorten(key.GetStringValue(L"ProductName"));
		}
		catch (...)
		{
			return {};
		}
	}
};
