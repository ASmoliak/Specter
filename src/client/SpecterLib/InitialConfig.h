#pragma once
#include <string>
#include <vector>

class InitialConfig
{
	std::string m_server_url;
	std::string m_server_port;
	std::string m_guid;

	inline static const auto server_url_option = "server_url";
	inline static const auto server_port_option = "server_port";
	inline static const auto guid_option = "guid";

public:
	// Builds from the "obscrypto" protocol: a string xor'd with a key and the key appended to the start,
	// finally a base64 over it so that we can pass it over registry.
	static InitialConfig BuildFromSerialized(const std::string& args);

	// Builds directly from parameters
	InitialConfig(std::string server_url, std::string server_port, std::string guid);

	// Serializes the config into the "obscrypto" protocol.
	std::string Serialize(uint8_t obscrypto_key) const;

	std::string GetServerEndpoint() const;

	std::string GetServerPort() const;

	std::string GetGuid() const;

private:
	InitialConfig(const std::vector<std::string>& args);
};
