#pragma once
#include "InitialConfig.h"
#include "SpecterLib/ServerConnection.h"
#include "SpecterLib/ApplicationMutex.h"

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
