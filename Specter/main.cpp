#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers
#include <windows.h>
#include <iostream>

#include "SpecterLib/UserInfo.hpp"
#include "SpecterLib/SystemInfo.hpp"


void PrintEndpointInfo()
{
	// User-info
	std::cout << "Username: " << UserInfo::getUsername() << std::endl;

	// System info
	std::cout << "Computer name: " << UserInfo::getMachineName() << std::endl;
	std::cout << "System uptime: " << SystemInfo::getUptime() << std::endl;
	std::cout << "HdSerial: " << SystemInfo::getHdSerial() << std::endl;
}

int main()
{
	try
	{
		PrintEndpointInfo();
		//RegisterWithServer();

		return 0;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception occurred: " << e.what() << std::endl;
	}
}

