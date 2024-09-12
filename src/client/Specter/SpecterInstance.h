#pragma once
#include "SpecterLib/InitialConfig.h"
#include "SpecterLib/ServerConnection.h"

import ApplicationMutex;

class SpecterInstance
{
	InitialConfig m_initial_config;
	ApplicationMutex m_app_mutex;
	ServerConnection m_server_connection;

public:
	SpecterInstance(InitialConfig initial_config);

	void RunLoop();

private:
	static void TryToAttachConsole();
};
