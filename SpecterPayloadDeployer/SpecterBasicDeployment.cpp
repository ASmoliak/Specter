#include "SpecterBasicDeployment.hpp"
#include "SpecterLib/SyscallException.h"
#include "SpecterLib/CommonPaths.h"

#include "3rdPartyLibs/WinReg/WinReg.hpp"

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
	const winreg::RegKey key(HKEY_CURRENT_USER, kTargetRegistry);

	const auto result = key.TryGetStringValue(m_program_name);

	return result.IsValid() && result.GetValue() == m_target_file;
}

bool SpecterBasicDeployment::DoesFileExist() const
{
	return exists(m_target_file);
}
