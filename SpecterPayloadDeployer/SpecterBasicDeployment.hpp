#pragma once
#include "SpecterLib/CommonPaths.hpp"
#include "SpecterLib/SyscallException.hpp"

#include <filesystem>
#include <string>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <boost/core/noncopyable.hpp>


// This class is responsible for deploying the Specter binary into the machine without any admin privileges
// Deploy to the AppData/Local folder, and ensures persistence by using the HKCU persistence method and 
class SpecterBasicDeployment : boost::noncopyable
{
	static constexpr HKEY kTargetRegistryRoot = HKEY_CURRENT_USER;
	static inline const std::wstring kTargetRegistry = L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";

	std::wstring m_program_name;
	std::filesystem::path m_target_file;

public:
	SpecterBasicDeployment(std::wstring program_name, const std::wstring& target_file_name) :
		m_program_name(std::move(program_name)),
		m_target_file(CommonPaths::GetLocalPath() / target_file_name)
	{
	}

	bool IsInstalled() const
	{
		return DoesRegistryEntryExist() && DoesFileExist();
	}

	static bool Install()
	{
		// TODO WIP
		return false;
	}

private:
	bool DoesRegistryEntryExist() const
	{
		HKEY result;
		if (ERROR_SUCCESS != RegOpenKeyW(kTargetRegistryRoot, kTargetRegistry.c_str(), &result))
		{
			throw SyscallException(L"Failed to open the registry key: " + kTargetRegistry);
		}

		LONG value_size;
		if (ERROR_SUCCESS != RegQueryValueW(result, m_program_name.c_str(), nullptr, &value_size))
		{
			RegCloseKey(result);
			return false;
		}

		std::wstring target_path(static_cast<size_t>(value_size), 0);
		if (ERROR_SUCCESS != RegQueryValueW(result, m_program_name.c_str(), target_path.data(), &value_size))
		{
			RegCloseKey(result);
			return false;
		}

		RegCloseKey(result);
		return target_path == m_target_file;
	}

	bool DoesFileExist() const
	{
		return exists(m_target_file);
	}
};

// TODO ShouldUpgrade = IsInstalled && IsOutdatedVersion
// TODO what happens if the targetFileName isn't the one already installed? Need to flesh out the edge cases...