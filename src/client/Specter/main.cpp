#include <iostream>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "SpecterInstance.h"

// Attempts to attach to a console, but only if process is run under one.
int WINAPI wWinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPWSTR, _In_ int)
{
	try
	{
		SpecterInstance specter;

		specter.RunLoop();
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception occurred: " << e.what() << '\n';
	}
}
