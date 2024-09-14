#include "InitialConfig.h"

#include <iostream>
#include <shellapi.h>

#include <boost/program_options.hpp>
#include <boost/format.hpp>

#include "Cryptography.h"

std::string InitialConfig::Serialize(uint8_t obscrypto_key) const
{
	boost::format formatter("--%1%=\"%2%\" --%3%=%4% --%5%=%6%");
	formatter % server_url_option % m_server_url % server_port_option % m_server_port % guid_option % m_guid;

	return Cryptography::ToObscryptoB64(formatter.str(), obscrypto_key);
}

InitialConfig InitialConfig::BuildFromSerialized(const std::string& args)
{
	const auto args_string = Cryptography::FromObscryptoB64(args);

	return {boost::program_options::split_winmain(args_string)};
}

InitialConfig::InitialConfig(std::string server_url, std::string server_port, std::string guid) :
	m_server_url(std::move(server_url)),
	m_server_port(std::move(server_port)),
	m_guid(std::move(guid))
{
}

InitialConfig::InitialConfig(const std::vector<std::string>& args)
{
	namespace po = boost::program_options;

	try
	{
		po::options_description desc;
		desc.add_options()
			(server_url_option, po::value<std::string>()->default_value("localhost"))
			(server_port_option, po::value<std::string>()->default_value("8001"))
			(guid_option, po::value<std::string>());

		const auto parsed_options = po::command_line_parser(args).options(desc).run();

		po::variables_map vm;
		store(parsed_options, vm);
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
		std::cout << "Failed to parse command line, error: " << e.what() << '\n';
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

std::string InitialConfig::GetGuid() const
{
	return m_guid;
}
