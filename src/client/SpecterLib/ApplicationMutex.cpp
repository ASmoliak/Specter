#include "SpecterLib/ApplicationMutex.h"

#include <stdexcept>

ApplicationMutex::ApplicationMutex(const std::string& mutex_name)
{
	m_mutex.Attach(CreateMutexA(nullptr, FALSE, mutex_name.c_str()));

	if (!m_mutex.IsValid())
	{
		throw std::runtime_error("Failed to CreateMutexA");
	}

	m_has_ownership = GetLastError() != ERROR_ALREADY_EXISTS;
}

bool ApplicationMutex::HasOwnership() const
{
	return m_has_ownership;
}
