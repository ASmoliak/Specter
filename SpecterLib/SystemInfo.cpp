#include "pch.h"
#include "SystemInfo.h"
#include "TimeUtils.h"
#include "SyscallException.h"
#include "StrUtils.h"
#include "WinReg.hpp"

std::string SystemInfo::GetUptime()
{
	return TimeUtils::FormatDuration(std::chrono::milliseconds(GetTickCount64()));
}

std::string SystemInfo::GetHdSerial()
{
	DWORD volume_serial_number;
	if (!GetVolumeInformationW(L"C:\\", nullptr, 0, &volume_serial_number, nullptr, nullptr, nullptr, 0))
	{
		throw SyscallException("Failed to acquire hdserial via GetVolumeInformationW()");
	}

	return std::to_string(volume_serial_number);
}

std::string SystemInfo::GetOsProductName()
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
