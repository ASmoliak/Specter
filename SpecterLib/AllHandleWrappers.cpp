// ReSharper disable CppParameterMayBeConstPtrOrRef
#include "pch.h"
#include "AllHandleWrappers.h"

#include <Shlobj.h>

bool SimpleHandleWrapper::IsValidImp(HANDLE handle)
{
	return handle != nullptr && handle != INVALID_HANDLE_VALUE;
}

void SimpleHandleWrapper::ReleaseImp(HANDLE handle)
{
	CloseHandle(handle);
}

bool HMemTaskWrapper::IsValidImp(wchar_t* handle)
{
	return handle != nullptr;
}

void HMemTaskWrapper::ReleaseImp(wchar_t* handle)
{
	CoTaskMemFree(handle);
}
