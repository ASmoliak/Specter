#pragma once
#include <windows.h>
#include <comdef.h>
#include <Wbemidl.h>
#include <chrono>

#include "TimeUtils.hpp"
#include "SyscallException.hpp"

class SystemInfo
{
public:
	SystemInfo() = delete;

	static std::string GetSystemUptime()
	{
		return TimeUtils::FormatDuration(std::chrono::milliseconds(GetTickCount64()));
	}

	static std::string GetHdSerial()
	{
		// TODO this implementation takes the Volume serial number which is easy to change, 
		// it doesn't acquire the Hard Disk serial number, which is hardcoded.
		DWORD volumeSerialNumber = 0;
		if (!GetVolumeInformationW(L"C:\\", nullptr, 0, &volumeSerialNumber, nullptr, nullptr, nullptr, 0))
		{
			throw SyscallException("Failed to acquire hdserial via GetVolumeInformationW()");
		}

		return std::to_string(volumeSerialNumber);
	}
};