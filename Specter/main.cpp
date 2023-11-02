#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers
#include <windows.h>
#include <iostream>

#include "SpecterLib/ServerConnection.hpp"
#include "SpecterLib/UserInfo.hpp"
#include "SpecterLib/SystemInfo.hpp"

int main()
{
	try
	{
		ServerConnection connection;

		while(true)
		{
			connection.syncInfog(SystemInfo::getHdSerial(), UserInfo::getMachineName(),
								 UserInfo::getUsername(), SystemInfo::getUptime(), 
								 SystemInfo::getOsProductName());

			std::this_thread::sleep_for(std::chrono::seconds(10));
		}
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception occurred: " << e.what() << std::endl;
	}
}

