#include "ProcessUtils.h"

#include <boost/process/spawn.hpp>

void ProcessUtils::RunProcess(const std::filesystem::path& exe_path, const std::wstring& args)
{
	boost::process::spawn(exe_path.wstring(), args);
}
