#pragma once
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <string>

class ServerConnection
{
	boost::asio::io_context m_ioc;
	boost::asio::ip::tcp::resolver m_resolver;
	boost::asio::ip::tcp::socket m_socket;

	const std::string m_host = "localhost";
	const std::string m_port = "8001";
	const std::string m_target = "/registration/";

public:
	ServerConnection(const ServerConnection& other) = delete;
	ServerConnection& operator=(const ServerConnection& other) = delete;

	ServerConnection();

	void syncInfog(const std::string& hd_serial, const std::string& machine_name,
	               const std::string& user_name, const std::string& up_time,
	               const std::string& os_name);
};
