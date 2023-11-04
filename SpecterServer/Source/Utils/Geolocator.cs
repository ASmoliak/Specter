using IP2Location;
using System.IO.Compression;

namespace SpecterServer.Source.Geolocator
{
    class Geolocator
    {
        private readonly Component m_component = new();
        private readonly string m_dbFileName;
        
        public Geolocator(string db_ip_filename)
        {
            // 

            UpdateDatabase(db_ip_filename);
        }

        public void CheckForUpdates()
        {
            // MD5 our current copy (the entire ZIP file!)

            // GET https://download.ip2location.com/lite/IP2LOCATION-LITE-DB1.BIN.ZIP.md5

            // Compare MD5s, if not equal, updates available.

            // If choosing to download updates, store in resource or some memory place!
        }

        public void UpdateDatabase(string db_ip_filename)
        {
            // FILENAME must be the bin.zip , so you must decompress here.

            // use the zip decompressor 
            ZipFile zipFile = ZipFile.Read(zippedFileStream);
            
            // then decompress to memory
            MemoryStream reader = new();

            // pass memory to the component
            m_component.Open(reader);
        }

        public string TranslateIpToCountry(string ip)
        {
            var result = m_component.IPQuery(ip);

            return result.Status != "OK" ? "" : result.CountryShort;
        }
    }
}

//Geolocator geoloc = new("C:\\Users\\Alex\\Source\\Repos\\Specter\\SpecterServer\\Resources\\IP2LOCATION-LITE-DB1.BIN");
//var res1 = geoloc.TranslateIpToCountry("8.8.8.8");
//var res2 = geoloc.TranslateIpToCountry("11.22.33.44");
//var res3 = geoloc.TranslateIpToCountry("192.168.1.1");
//var res4 = geoloc.TranslateIpToCountry("127.0.0.1");