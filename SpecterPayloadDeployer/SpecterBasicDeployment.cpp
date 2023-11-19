#include "SpecterBasicDeployment.hpp"
#include "SpecterLib/SyscallException.hpp"
#include "SpecterLib/CommonPaths.hpp"

SpecterBasicDeployment::SpecterBasicDeployment(std::wstring program_name, const std::wstring& target_file_name):
	m_program_name(std::move(program_name)),
	m_target_file(CommonPaths::GetLocalPath() / target_file_name)
{
}

bool SpecterBasicDeployment::IsInstalled() const
{
	return DoesRegistryEntryExist() && DoesFileExist();
}

bool SpecterBasicDeployment::Install()
{
	// TODO WIP
	return false;
}

bool SpecterBasicDeployment::DoesRegistryEntryExist() const
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

bool SpecterBasicDeployment::DoesFileExist() const
{
	return exists(m_target_file);
}
