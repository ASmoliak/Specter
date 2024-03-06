#pragma once
#include "SpecterLib/InitialConfig.h"
#include "SpecterLib/ApplicationMutex.h"
#include "SpecterLib/ServerConnection.h"

class SpecterInstance
{
	InitialConfig m_initial_config;
	ApplicationMutex m_app_mutex;
	ServerConnection m_server_connection;

public:
	SpecterInstance();

	void RunLoop();

private:
	static void TryToAttachConsole();
};
