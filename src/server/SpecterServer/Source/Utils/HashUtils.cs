using System.Security.Cryptography;
using System.Text;

namespace SpecterServer.Source.Utils
{
    class HashUtils
    {
        public static string StreamToMd5(Stream stream)
        {
            return Md5HashToString(MD5.HashData(stream));
        }

        private static string Md5HashToString(IEnumerable<byte> hash)
        {
            StringBuilder builder = new();

            foreach (var element in hash)
            {
                builder.Append(element.ToString("x2"));
            }

            return builder.ToString();
        }
    }
}
