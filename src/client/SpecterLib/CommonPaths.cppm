module;
#include <filesystem>
#include <Shlobj.h>
#include "AllHandleWrappers.h"
export module CommonPaths;

export class CommonPaths
{
public:
	CommonPaths() = delete;

	static std::filesystem::path GetLocalPath()
	{
		HMemTaskWrapper mem_task;

		if (S_OK != SHGetKnownFolderPath(FOLDERID_LocalAppData, 0, nullptr, mem_task.Put()) || !mem_task.IsValid())
		{
			return {};
		}

		std::filesystem::path folder_path(mem_task.Get());

		return folder_path;
	}
};
