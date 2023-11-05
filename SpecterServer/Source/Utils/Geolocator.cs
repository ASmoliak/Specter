using System.IO.Compression;
using System.Security.Cryptography;
using System.Text;
using IP2Location;

namespace SpecterServer.Source.Utils
{
    public class Geolocator
    {
        public const string DbZipFileName = $"{DbBinFileName}.ZIP";

        private readonly Component m_component = new();
        private const string DbBinFileName = "IP2LOCATION-LITE-DB1.BIN";
        private const string LatestDbUri = "https://download.ip2location.com/lite/IP2LOCATION-LITE-DB1.BIN.ZIP";
        private const string LatestDbMd5Uri = $"{LatestDbUri}.md5";

        public Geolocator()
        {
            if (!EnsureLatestDbOnDisk())
            {
                DumpResourceDbToDisk();
            }

            if (!LoadDatabase())
            {
                // If we fail to load the DB, we dump our in-memory resource copy as a fallback and try to load again
                DumpResourceDbToDisk();
                LoadDatabase();
            }
        }

        private static bool EnsureLatestDbOnDisk()
        {
            if (HasLatestDb())
            {
                return true;
            }

            using HttpClient client = new();
            var latestDb = client.GetByteArrayAsync(LatestDbUri);
            latestDb.Wait();

            if (!latestDb.IsCompletedSuccessfully)
            {
                return false;
            }

            using FileStream newDbStream = new(DbZipFileName, FileMode.OpenOrCreate, FileAccess.Write);
            newDbStream.Write(latestDb.Result);
            return true;
        }

        private static bool HasLatestDb()
        {
            if (new FileInfo(DbZipFileName) is not {Exists: true, Length: > 0})
            {
                return false;
            }

            using HttpClient client = new();
            var latestDbMd5 = client.GetStringAsync(LatestDbMd5Uri);

            // Hash our existing current DB
            using FileStream existingDbStream = new(DbZipFileName, FileMode.Open, FileAccess.Read);
            var existingDbHash = Md5HashToString(MD5.HashData(existingDbStream));
            if (existingDbHash.Length <= 0)
            {
                return false;
            }

            latestDbMd5.Wait(1000);

            return latestDbMd5.IsCompletedSuccessfully && latestDbMd5.Result[..32] != existingDbHash;
        }

        static string Md5HashToString(byte[] hash)
        {
            StringBuilder builder = new();

            // Loop through each byte of the hashed hash and format each one as a lowercase hexadecimal string.
            foreach (var element in hash)
            {
                builder.Append(element.ToString("x2"));
            }

            return builder.ToString();
        }

        private void DumpResourceDbToDisk()
        {
            using FileStream fileStream = new(DbZipFileName, FileMode.Create, FileAccess.Write);
            fileStream.Write(Resources.Resources.IP2LOCATION_LITE_DB1_BIN);
        }

        private bool LoadDatabase()
        {
            try
            {
                using var zipFile = ZipFile.Open(DbZipFileName, ZipArchiveMode.Read);

                var ipDbFile = zipFile.GetEntry(DbBinFileName);
                if (ipDbFile == null)
                {
                    return false;
                }

                using var entryStream = ipDbFile.Open();
                MemoryStream memoryStream = new();
                entryStream.CopyTo(memoryStream);

                m_component.Open(memoryStream);
                return true;
            }
            catch
            {
                return false;
            }
        }

        public string IpToShortCountry(string ip)
        {
            var result = m_component.IPQuery(ip);
            return result.Status != "OK" ? "" : result.CountryShort;
        }

        public string IpToLongCountry(string ip)
        {
            var result = m_component.IPQuery(ip);
            return result.Status != "OK" ? "" : result.CountryLong;
        }
    }
}