#include "pch.h"
#include "ResourceUtils.h"


std::optional<std::string> ResourceUtils::ReadRawResource(int resource_id)
{
	const auto resource_info = FindResourceW(nullptr, MAKEINTRESOURCEW(resource_id), RT_RCDATA);
	if (!resource_info)
	{
		return {};
	}

	const auto resource_size = SizeofResource(nullptr, resource_info);
	if (!resource_size)
	{
		return {};
	}

	const auto resource = LoadResource(nullptr, resource_info);
	if (!resource)
	{
		return {};
	}

	const auto* resource_ptr = LockResource(resource);
	if (!resource_ptr)
	{
		return {};
	}

	return std::string(static_cast<const char*>(resource_ptr), resource_size);
}
