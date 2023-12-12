#pragma once
#include <optional>
#include <string>

class ResourceUtils
{
public:
	ResourceUtils() = delete;

	static std::optional<std::string> ReadRawResource(int resource_id);
};