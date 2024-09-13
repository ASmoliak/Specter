import ProcessUtils;

TEST(ProcessUtilsTests, TestRun)
{
	//ProcessUtils::RunProcess("C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe", L" 127.0.0.1");
	//Sleep(51000);
}

TEST(ProcessUtilsTests, DetectsElevation)
{
	EXPECT_FALSE(ProcessUtils::IsProcessElevated(GetCurrentProcess()));
}
