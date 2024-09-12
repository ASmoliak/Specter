import ApplicationMutex;

TEST(ApplicationMutexTests, GetsOwnershipOfUniqueMutex)
{
	static const std::string sample_guid = "e5f3a187-e3a9-48f0-b6c5-457a2b46c08d";
	const ApplicationMutex app_mutex(sample_guid);

	EXPECT_TRUE(app_mutex.HasOwnership());
}

TEST(ApplicationMutexTests, FailsToOwnDuplicateMutex)
{
	static const std::string sample_guid = "7c4f6774-894b-47c3-8603-8714ba59374e";
	const ApplicationMutex app_mutex(sample_guid);
	const ApplicationMutex duplicate_app_mutex(sample_guid);

	EXPECT_FALSE(duplicate_app_mutex.HasOwnership());
}
