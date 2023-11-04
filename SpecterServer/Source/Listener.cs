using System.Net;
using System.Text;

namespace SpecterServer.Source
{
    public class Listener
    {
        private Thread? m_listener;

        public Listener()
        {
            m_listener = new Thread(StartServerLoop);
            m_listener.Start();
        }

        private void StartServerLoop()
        {
            string[] prefixes = { "http://localhost:8001/registration/" };

            if (!HttpListener.IsSupported)
            {
                throw new ArgumentException(@"Windows XP SP2 or Server 2003 is required to use the HttpListener class.");
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
            foreach (var s in prefixes)
            {
                listener.Prefixes.Add(s);
            }

            listener.Start();

            while (true)
            {
                var context = listener.GetContext();

                //UpdateOrAddEndpoint(context.Request);

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
    }
}
