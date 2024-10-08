﻿using System.IO.Compression;
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
            if (new FileInfo(DbZipFileName) is not {Exists: true, Length: > 0})
            {
                DumpResourceDbToDisk();
            }

            if (!LoadDatabase())
            {
                DumpResourceDbToDisk();

                if (!LoadDatabase())
                {
                    MessageBox.Show(@"Failed to load IP DB, geolocation services offline", @"Error", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
            }

            Task.Run(EnsureLatestDbOnDisk);
        }

        private static void EnsureLatestDbOnDisk()
        {
            if (HasLatestDb())
            {
                return;
            }

            var choice = MessageBox.Show(@"Geolocation database has an update, download now?", @"IP-DB updates available", MessageBoxButtons.YesNo, MessageBoxIcon.Question);

            if (choice == DialogResult.No)
            {
                return;
            }

            using HttpClient client = new();
            var latestDb = client.GetByteArrayAsync(LatestDbUri);
            latestDb.Wait();

            if (!latestDb.IsCompletedSuccessfully)
            {
                return;
            }

            using FileStream newDbStream = new(DbZipFileName, FileMode.OpenOrCreate, FileAccess.Write);
            newDbStream.Write(latestDb.Result);

            choice = MessageBox.Show(@"Geolocation database successfully updated, restart now?", @"IP-DB updated", MessageBoxButtons.YesNo, MessageBoxIcon.Question);

            if (choice == DialogResult.No)
            {
                return;
            }

            ApplicationUtils.RestartApplication();
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
            var existingDbHash = HashUtils.StreamToMd5(existingDbStream);
            if (existingDbHash.Length <= 0)
            {
                return false;
            }

            latestDbMd5.Wait();

            return latestDbMd5.IsCompletedSuccessfully && latestDbMd5.Result[..32] == existingDbHash;
        }

        private static void DumpResourceDbToDisk()
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