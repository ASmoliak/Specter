#include "pch.h"
#include "CommonPaths.h"
#include "AllHandleWrappers.h"

#include <Shlobj.h>

std::filesystem::path CommonPaths::GetLocalPath()
{
	HMemTaskWrapper mem_task;

	if (S_OK != SHGetKnownFolderPath(FOLDERID_LocalAppData, 0, nullptr, mem_task.Put()) || !mem_task.IsValid())
	{
		return {};
	}

	std::filesystem::path folder_path(mem_task.Get());

	return folder_path;
}
