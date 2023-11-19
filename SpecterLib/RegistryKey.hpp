#pragma once
#include <minwindef.h>
#include <optional>
#include <string>

class RegistryKey
{
	HKEY m_key;
	bool m_is_open;

public:
	enum class RegistryValueType
	{
		binary,
		dword,
		dword_big_endian,
		expand_sz,
		link,
		multi_sz,
		none,
		qword,
		sz,
		unknown = 999999
	};

	RegistryKey(const RegistryKey& other) = delete;
	RegistryKey& operator=(const RegistryKey& other) = delete;

	RegistryKey(HKEY root_key, const std::wstring& key_path);
	~RegistryKey();

	bool IsOpen() const;

	std::optional<RegistryValueType> GetValueType(const std::wstring& value_name) const;

private:
	static RegistryValueType InternalValueTypeToEnum(DWORD type);
};