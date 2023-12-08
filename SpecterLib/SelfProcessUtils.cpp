#include "pch.h"
#include "SelfProcessUtils.h"

bool SelfProcessUtils::IsProcessElevated()
{
	HANDLE token = nullptr;
	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &token)) 
	{
		return false;
	}

	TOKEN_ELEVATION elevation{};
	DWORD size;
	GetTokenInformation(token, TokenElevation, &elevation, sizeof(elevation), &size);
	CloseHandle(token);

	return elevation.TokenIsElevated != 0;
}
