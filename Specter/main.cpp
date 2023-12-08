#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers
#include <windows.h>
#include <iostream>

#include "SpecterLib/ServerConnection.h"
#include "SpecterLib/UserInfo.h"
#include "SpecterLib/SystemInfo.h"

int main()
{
	try
	{
		ServerConnection connection;

		while(true)
		{
			connection.syncInfog(SystemInfo::GetHdSerial(), UserInfo::GetMachineName(),
								 UserInfo::GetUsername(), SystemInfo::GetUptime(), 
								 SystemInfo::GetOsProductName());

			std::this_thread::sleep_for(std::chrono::seconds(10));
		}
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception occurred: " << e.what() << std::endl;
	}
}

