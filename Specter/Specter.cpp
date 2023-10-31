#include <iostream>

#include "UserInfo.hpp"
#include "SystemInfo.hpp"

int main()
{
	try
	{
		// User-info
		std::wcout << L"Username: " << UserInfo::GetUsername() << std::endl;

		// System info
		std::cout << "Computer name: " << UserInfo::GetQualifiedUsername() << std::endl;
		std::cout << "System uptime: " << SystemInfo::GetSystemUptime() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception occurred: " << e.what() << std::endl;
	}
}
