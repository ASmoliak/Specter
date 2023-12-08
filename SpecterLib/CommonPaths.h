#pragma once
#include <filesystem>

class CommonPaths
{
public:
	CommonPaths() = delete;

	static std::filesystem::path GetLocalPath();
};

