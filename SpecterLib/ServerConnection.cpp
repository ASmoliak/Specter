#include "ServerConnection.hpp"
#include <boost/beast.hpp>

ServerConnection::ServerConnection() : m_resolver(m_ioc), m_socket(m_ioc)
{
}

void ServerConnection::syncInfog(const std::string& hd_serial, const std::string& machine_name,
                                 const std::string& user_name, const std::string& up_time, const std::string& os_name)
{
	using namespace boost::beast;

	try
	{
		// Resolve and connect
		boost::system::error_code ec;
		do
		{
			boost::asio::connect(m_socket, m_resolver.resolve(m_host, m_port), ec);
		}
		while (ec);

		// Setup request
		http::request<http::string_body> req(http::verb::get, m_target, 11);
		req.set(http::field::host, m_host);
		req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
		req.set("hdserial", hd_serial);
		req.set("machinename", machine_name);
		req.set("username", user_name);
		req.set("uptime", up_time);
		req.set("osname", os_name);

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
		m_socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
	}
	catch (const std::exception& e)
	{
		OutputDebugStringA("Failed sync INFOG, exception occurred.");
		OutputDebugStringA(e.what());
	}
}
