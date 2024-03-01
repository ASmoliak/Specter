using SpecterServer.Source.Utils;
using SpecterServerUnitTests.TestUtils;

namespace SpecterServerUnitTests.Tests
{
    public class GeolocatorTests
    {
        [Fact]
        public void CanDownloadFile()
        {
            TemporaryFile unused = new(Geolocator.DbZipFileName);

            Geolocator geolocator = new();
            GeolocatorDetectsGoogle(geolocator);
        }

        [Fact]
        public void CanUpdateFile()
        {
            TemporaryFile unused = new(Geolocator.DbZipFileName);

            Geolocator geolocatorOriginal = new();
            Geolocator geolocator = new();

            GeolocatorDetectsGoogle(geolocator);
        }

        private static void GeolocatorDetectsGoogle(Geolocator geolocator)
        {
            Assert.Equal("US", geolocator.IpToShortCountry("8.8.8.8"));
        }
    }
}