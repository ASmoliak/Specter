#include "pch.h"
#include "SelfProcessUtils.h"
#include "AllHandleWrappers.h"

bool SelfProcessUtils::IsProcessElevated()
{
	HTokenWrapper token;
	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, token.Put()) || !token.IsValid())
	{
		return false;
	}

	TOKEN_ELEVATION elevation{};
	DWORD size;
	GetTokenInformation(token.Get(), TokenElevation, &elevation, sizeof(elevation), &size);
	return elevation.TokenIsElevated != 0;
}
