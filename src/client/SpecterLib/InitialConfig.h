#pragma once
#include <string>

class InitialConfig
{
	std::string m_server_url;
	std::string m_server_port;
	std::string m_guid;

public:
	InitialConfig(const wchar_t* command_line);

	std::string GetServerEndpoint() const;

	std::string GetServerPort() const;

	std::string GetInstanceGuid() const;
};
