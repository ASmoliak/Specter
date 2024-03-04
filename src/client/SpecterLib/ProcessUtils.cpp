#include "pch.h"
#include "ProcessUtils.h"

#include <boost/process/spawn.hpp>

void ProcessUtils::RunProcess(const std::filesystem::path& exe_path)
{
	boost::process::spawn(exe_path.string());
}
