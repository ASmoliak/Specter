#include <boost/beast.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>

#include "UserInfo.hpp"
#include "SystemInfo.hpp"

#include <iostream>

void RegisterWithServer()
{
	namespace http = boost::beast::http;

	// Create I/O context, resolver, and socket
	boost::asio::io_context ioc;
	boost::asio::ip::tcp::resolver resolver(ioc);
	boost::asio::ip::tcp::socket socket(ioc);

	// Define target
	auto const host = "localhost";
	auto const port = "8001";
	auto const target = "/registration/";

	// Resolve and connect
	boost::asio::connect(socket, resolver.resolve(host, port));

	// Setup request
	http::request<http::string_body> req(http::verb::get, target, 11);
	req.set(http::field::host, host);
	req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
	req.set("hdserial", SystemInfo::GetHdSerial());
	req.set("computername", UserInfo::GetQualifiedUsername());
	req.set("username", UserInfo::GetUsername());

	// Write, read and buffer the request
	http::write(socket, req);
	boost::beast::flat_buffer buffer;
	http::response<http::dynamic_body> res;
	http::read(socket, buffer, res);

	// Print response
	std::cout << res << std::endl;

	// Cleanup (optional, handled automatically on object destruction)
	boost::beast::error_code ec;
	socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both, ec);

	// Check and handle any errors
	if (ec && ec != boost::beast::errc::not_connected)
	{
		throw boost::beast::system_error{ ec };
	}
}

void PrintEndpointInfo()
{
	// User-info
	std::cout << "Username: " << UserInfo::GetUsername() << std::endl;

	// System info
	std::cout << "Computer name: " << UserInfo::GetQualifiedUsername() << std::endl;
	std::cout << "System uptime: " << SystemInfo::GetSystemUptime() << std::endl;
	std::cout << "HdSerial: " << SystemInfo::GetHdSerial() << std::endl;
}

int main()
{
	try
	{
		PrintEndpointInfo();
		RegisterWithServer();

		return 0;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception occurred: " << e.what() << std::endl;
	}
}
