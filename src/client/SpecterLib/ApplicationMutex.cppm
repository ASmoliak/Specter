module;
#include <stdexcept>
#include <string>
#include <windows.h>
#include "AllHandleWrappers.h"
export module ApplicationMutex;

import SyscallException;

export class ApplicationMutex
{
public:
	explicit ApplicationMutex(const std::string& mutex_name)
	{
		m_mutex.Attach(CreateMutexA(nullptr, FALSE, mutex_name.c_str()));

		if (!m_mutex.IsValid())
		{
			throw SyscallException("Failed to CreateMutex");
		}

		m_has_ownership = GetLastError() != ERROR_ALREADY_EXISTS;
	}

	bool HasOwnership() const
	{
		return m_has_ownership;
	}

private:
	HMutexWrapper m_mutex;
	bool m_has_ownership = false;
};
