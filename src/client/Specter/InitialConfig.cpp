#include "InitialConfig.h"

#include <shellapi.h>

#include <boost/program_options.hpp>


InitialConfig::InitialConfig(const wchar_t* command_line)
{
	namespace po = boost::program_options;

	try
	{
		const auto server_url_option = "server_url";
		const auto server_port_option = "server_port";
		const auto guid_option = "guid";

		po::options_description desc;
		desc.add_options()
			(server_url_option, po::value<std::string>()->default_value("localhost"))
			(server_port_option, po::value<std::string>()->default_value("8001"))
			(guid_option, po::value<std::string>());

		int argc;
		wchar_t** argv = CommandLineToArgvW(command_line, &argc);
		po::variables_map vm;
		store(parse_command_line(argc, argv, desc), vm);
		notify(vm);

		if (!vm.contains(guid_option))
		{
			throw std::runtime_error("No instance GUID specified");
		}

		m_server_url = vm[server_url_option].as<std::string>();
		m_server_port = vm[server_port_option].as<std::string>();
		m_guid = vm[guid_option].as<std::string>();
	}
	catch (const po::error& e)
	{
		std::cout << "Failed to parse command line, error: " << e.what() << std::endl;
		std::_Exit(1);
	}
}

std::string InitialConfig::GetServerEndpoint() const
{
	return m_server_url;
}

std::string InitialConfig::GetServerPort() const
{
	return m_server_port;
}

std::string InitialConfig::GetInstanceGuid() const
{
	return m_guid;
}
