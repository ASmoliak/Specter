#pragma once
#include <optional>
#include <vector>

class ResourceUtils
{
public:
	ResourceUtils() = delete;

	static std::optional<std::vector<char>> ReadRawResource(int resource_id);
};