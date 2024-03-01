namespace SpecterServer.Source.Utils
{
    public class ApplicationUtils
    {
        public static void RestartApplication()
        {
            var startInfo = new System.Diagnostics.ProcessStartInfo
            {
                FileName = System.Diagnostics.Process.GetCurrentProcess().MainModule?.FileName,
                UseShellExecute = true
            };

            System.Diagnostics.Process.Start(startInfo);
            Environment.Exit(0);
        }
    }
}
