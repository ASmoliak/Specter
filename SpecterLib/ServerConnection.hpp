#pragma once
#include <boost/beast.hpp>

class ServerConnection : boost::noncopyable
{
	boost::asio::io_context m_ioc;
	boost::asio::ip::tcp::resolver m_resolver;
	boost::asio::ip::tcp::socket m_socket;

	const std::string m_host = "localhost";
	const std::string m_port = "8001";
	const std::string m_target = "/registration/";

public:
	ServerConnection() : m_resolver(m_ioc), m_socket(m_ioc)
	{
	}

	void syncInfog(const std::string& hd_serial, const std::string& machine_name,
	               const std::string& user_name, const std::string& up_time,
	               const std::string& os_name)
	{
		using namespace boost::beast;

		// Resolve and connect
		boost::asio::connect(m_socket, m_resolver.resolve(m_host, m_port));

		// Setup request
		http::request<http::string_body> req(http::verb::get, m_target, 11);
		req.set(http::field::host, m_host);
		req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
		req.set("hdserial", hd_serial);
		req.set("computername", machine_name);
		req.set("username", user_name);
		req.set("uptime", up_time);
		req.set("osName", os_name);

		// Write, read and buffer the request
		http::write(m_socket, req);
		flat_buffer buffer;
		http::response<http::dynamic_body> res;
		read(m_socket, buffer, res);

		// Print response
		std::stringstream ss;
		ss << res;
		OutputDebugStringA(ss.str().c_str());

		// Cleanup (optional, handled automatically on object destruction)
		error_code ec;
		m_socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both, ec);

		// Check and handle any errors
		if (ec && ec != errc::not_connected)
		{
			throw system_error{ec};
		}
	}
};
