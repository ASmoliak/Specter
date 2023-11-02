using System.Net;
using System.Text;

namespace SpecterServer
{
    public partial class MainForm : Form
    {
        private Thread? m_listener;

        public MainForm()
        {
            InitializeComponent();
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            m_listener = new Thread(StartServerLoop);
            m_listener.Start();
        }

        private static void StartServerLoop()
        {
            string[] prefixes = {"http://localhost:8001/registration/"};

            if (!HttpListener.IsSupported)
            {
                Console.WriteLine(@"Windows XP SP2 or Server 2003 is required to use the HttpListener class.");
                return;
            }

            // URI prefixes are required,
            // for example "http://127.0.0.1:8080/index/".
            if (prefixes == null || prefixes.Length == 0)
            {
                throw new ArgumentException("prefixes are empty");
            }

            // Create a listener.
            HttpListener listener = new HttpListener();

            // Add the prefixes.
            foreach (string s in prefixes)
            {
                listener.Prefixes.Add(s);
            }

            listener.Start();
            Console.WriteLine(@"Listening...");

            while (true)
            {
                var context = listener.GetContext();
                var request = context.Request;

                Console.WriteLine($@"Received reg request from address: {request.UserHostAddress}");
                if (request.Headers.Count > 0)
                {
                    PrintHeaderIfExists(request, "hdserial");
                    PrintHeaderIfExists(request, "username");
                    PrintHeaderIfExists(request, "computername");
                }

                var response = context.Response;

                // Construct a response.
                const string responseString = "<HTML><BODY> Hello world!</BODY></HTML>";
                var buffer = Encoding.UTF8.GetBytes(responseString);
                response.ContentLength64 = buffer.Length;
                var output = response.OutputStream;
                output.Write(buffer, 0, buffer.Length);
                output.Close();
            }

            //listener.Stop();
        }

        private static void PrintHeaderIfExists(HttpListenerRequest request, string headerKey)
        {
            if (request.Headers.AllKeys.Contains(headerKey))
            {
                Console.WriteLine($@"{headerKey}: {request.Headers[headerKey]}");
            }
        }
    }
}