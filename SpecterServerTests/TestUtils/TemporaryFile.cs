namespace SpecterServerUnitTests.TestUtils
{
    internal class TemporaryFile
    {
        private readonly string m_path;

        public TemporaryFile(string path)
        {
            m_path = path;

            File.Create(m_path).Dispose(); 
        }

        ~TemporaryFile()
        {
            File.Delete(m_path);
        }
    }
}
