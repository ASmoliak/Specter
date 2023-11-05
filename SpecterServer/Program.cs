using SpecterServer.Source.Utils;

namespace SpecterServer;

internal static class Program
{
    [STAThread]
    static void Main()
    {
        Geolocator geolocator = new Geolocator();

        var retval = geolocator.TranslateIpToCountry("8.8.8.8");

        ApplicationConfiguration.Initialize();
        Application.Run(new MainForm());
    }
}