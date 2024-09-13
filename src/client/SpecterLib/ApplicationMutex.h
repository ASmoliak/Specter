#pragma once
#include "AllHandleWrappers.h"

#include <string>

class ApplicationMutex
{
public:
	explicit ApplicationMutex(const std::string& mutex_name);

	bool HasOwnership() const;

private:
	HMutexWrapper m_mutex;
	bool m_has_ownership = false;
};
