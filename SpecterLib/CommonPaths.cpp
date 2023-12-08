#include "pch.h"
#include "CommonPaths.h"

#include <Shlobj.h>

std::filesystem::path CommonPaths::GetLocalPath()
{
	wchar_t* path_ptr = nullptr;
	if (S_OK != SHGetKnownFolderPath(FOLDERID_LocalAppData, 0, nullptr, &path_ptr) && !path_ptr)
	{
		CoTaskMemFree(path_ptr);
		return {};
	}

	std::filesystem::path folder_path(path_ptr);
	CoTaskMemFree(path_ptr);

	return folder_path;
}
