#pragma once
#include <filesystem>

class ProcessUtils
{
public:
	ProcessUtils() = delete;

	static void RunProcess(const std::filesystem::path& exe_path, const std::wstring& args);
};
