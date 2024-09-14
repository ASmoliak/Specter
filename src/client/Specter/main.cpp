#include "SpecterInstance.h"
#include "SpecterLib/StrUtils.h"

#include <iostream>

#include <windows.h>
#include <shellapi.h>


// Attempts to attach to a console, but only if process is run under one.
int WINAPI wWinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPWSTR, _In_ int)
{
	try
	{
		int argc;
		wchar_t** argv = CommandLineToArgvW(GetCommandLineW(), &argc);

		if (argc != 2)
		{
			return 0;
		}

		auto initial_config = InitialConfig::BuildFromSerialized(StrUtils::Shorten(argv[1]));

		SpecterInstance specter(std::move(initial_config));

		specter.RunLoop();
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception occurred: " << e.what() << '\n';
	}

	return 0;
}
