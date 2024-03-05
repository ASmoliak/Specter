#pragma once
#include "BaseHandleWrapper.h"

class SimpleHandleWrapper : public BaseHandleWrapper<HANDLE, SimpleHandleWrapper>
{
public:
	static bool IsValidImp(HANDLE handle);
	static void ReleaseImp(HANDLE handle);
};

using HFileWrapper = SimpleHandleWrapper;
using HTokenWrapper = SimpleHandleWrapper;

class HMemTaskWrapper : public BaseHandleWrapper<wchar_t*, HMemTaskWrapper>
{
public:
	static bool IsValidImp(wchar_t* handle);
	static void ReleaseImp(wchar_t* handle);
};

class HMutexWrapper : public BaseHandleWrapper<HANDLE, HMutexWrapper>
{
public:
	static bool IsValidImp(HANDLE handle);
	static void ReleaseImp(HANDLE handle);
};
