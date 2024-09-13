module;
#include <filesystem>
#include <string>
#include <boost/process/spawn.hpp>
#include <windows.h>
#include "AllHandleWrappers.h"
export module ProcessUtils;

export class ProcessUtils
{
public:
	ProcessUtils() = delete;

	static void RunProcess(const std::filesystem::path& exe_path, const std::wstring& args)
	{
		boost::process::spawn(exe_path.wstring(), args);
	}

	static bool IsProcessElevated(HANDLE process)
	{
		HTokenWrapper token;
		if (!OpenProcessToken(process, TOKEN_QUERY, token.Put()) || !token.IsValid())
		{
			return false;
		}

		TOKEN_ELEVATION elevation{};
		DWORD size;
		GetTokenInformation(token.Get(), TokenElevation, &elevation, sizeof(elevation), &size);
		return elevation.TokenIsElevated != 0;
	}
};