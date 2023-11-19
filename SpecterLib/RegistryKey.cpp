#include "pch.h"
#include "RegistryKey.hpp"

RegistryKey::RegistryKey(HKEY root_key, const std::wstring& key_path)
{
	m_is_open = ERROR_SUCCESS == RegOpenKeyW(root_key, key_path.c_str(), &m_key);
}

RegistryKey::~RegistryKey()
{
	if (m_is_open)
	{
		RegCloseKey(m_key);
	}
}

bool RegistryKey::IsOpen() const
{
	return m_is_open;
}

std::optional<RegistryKey::RegistryValueType> RegistryKey::GetValueType(const std::wstring& value_name) const
{
    DWORD type;
    if (ERROR_SUCCESS != RegQueryValueExW(m_key, value_name.c_str(), nullptr, &type, nullptr, nullptr))
    {
		return {};
    }

	return InternalValueTypeToEnum(type);
}

RegistryKey::RegistryValueType RegistryKey::InternalValueTypeToEnum(DWORD type)
{
	switch (type)
	{
		case REG_BINARY:
			return RegistryValueType::binary;
		case REG_DWORD:
			return RegistryValueType::dword;
		case REG_DWORD_BIG_ENDIAN:
			return RegistryValueType::dword_big_endian;
		case REG_EXPAND_SZ:
			return RegistryValueType::expand_sz;
		case REG_LINK:
			return RegistryValueType::link;
		case REG_MULTI_SZ:
			return RegistryValueType::multi_sz;
		case REG_NONE:
			return RegistryValueType::none;
		case REG_QWORD:
			return RegistryValueType::qword;
		case REG_SZ:
			return RegistryValueType::sz;
		default: 
			return RegistryValueType::unknown;
	}
}
