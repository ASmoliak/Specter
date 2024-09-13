#include "SpecterLib/ProcessUtils.h"

TEST(ProcessUtilsTests, TestRun)
{
	ProcessUtils::RunProcess("C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe", L" 127.0.0.1");
	Sleep(51000);
}
