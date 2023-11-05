using System.IO.Compression;
using System.Reflection;
using System.Xml.Linq;
using IP2Location;

namespace SpecterServer.Source.Utils
{
    public class Geolocator
    {
        private readonly Component m_component = new();
        private const string DbBinFileName = "IP2LOCATION-LITE-DB1.BIN";
        private const string DbZipFileName = $"{DbBinFileName}.ZIP";

        public Geolocator()
        {
            EnsureDbOnDisk();

            if (!LoadDatabase())
            {

            }
        }

        public void CheckForUpdates()
        {
            // MD5 our current copy (the entire ZIP file!)

            // GET https://download.ip2location.com/lite/IP2LOCATION-LITE-DB1.BIN.ZIP.md5

            // Compare MD5s, if not equal, updates available.

            // If choosing to download updates, store in disk
        }

        private void EnsureDbOnDisk()
        {
            FileInfo dbFileInfo = new(DbZipFileName);
            if (dbFileInfo is {Exists: true, Length: > 0})
            {
                return;
            }

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

        public string TranslateIpToCountry(string ip)
        {
            var result = m_component.IPQuery(ip);

            return result.Status != "OK" ? "" : result.CountryShort;
        }
    }
}