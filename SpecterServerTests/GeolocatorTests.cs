using SpecterServer.Source.Utils;

namespace SpecterServerTests
{
    public class GeolocatorTests
    {
        [Fact]
        public void CanDumpFile()
        {
            Geolocator geolocator = new();

            geolocator.CheckForUpdates();
        }
    }
}