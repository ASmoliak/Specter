module;
#include <optional>
#include <vector>
export module ResourceUtils;

export class ResourceUtils
{
public:
	ResourceUtils() = delete;

	static std::optional<std::vector<char>> ReadRawResource(int resource_id)
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

		const char* resource_ptr = static_cast<char*>(LockResource(resource));
		if (!resource_ptr)
		{
			return {};
		}

		return {{resource_ptr, resource_ptr + resource_size}};
	}
};
