#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers
#include <windows.h>
#include <iostream>

#include "SpecterLib/ServerConnection.h"
#include "SpecterLib/UserInfo.h"
#include "SpecterLib/SystemInfo.h"

// Attempts to attach to a console, but only if process is run under one.
void TryToAttachConsole()
{
	if (!AttachConsole(ATTACH_PARENT_PROCESS))
	{
		return;
	}

	FILE* stream;
	freopen_s(&stream, "CONOUT$", "w", stderr);
	freopen_s(&stream, "CONOUT$", "w", stdout);
	freopen_s(&stream, "CONIN$", "r", stdin);

	std::cout << "Specter console-mode online" << std::endl;
}

int WINAPI wWinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPWSTR, _In_ int)
{
	try
	{
		TryToAttachConsole();

		ServerConnection connection("localhost", "8001");

		while (true)
		{
			connection.syncInfog(SystemInfo::GetHdSerial(), UserInfo::GetMachineName(),
			                     UserInfo::GetUsername(), SystemInfo::GetUptime(),
			                     SystemInfo::GetOsProductName());

			std::this_thread::sleep_for(std::chrono::seconds(10));
		}
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception occurred: " << e.what() << '\n';
	}
}
