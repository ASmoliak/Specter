#include "pch.h"
#include "CommonPaths.h"
#include "AllHandleWrappers.h"

#include <Shlobj.h>

std::filesystem::path CommonPaths::GetLocalPath()
{
	HMemTaskWrapper memTask;

	if (S_OK != SHGetKnownFolderPath(FOLDERID_LocalAppData, 0, nullptr, memTask.Put()) || !memTask.IsValid())
	{
		return {};
	}

	std::filesystem::path folder_path(memTask.Get());

	return folder_path;
}
