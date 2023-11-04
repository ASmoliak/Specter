using System.Net;
using System.Text;

namespace SpecterServer.Source.Comms
{
    public class Listener
    {
        private readonly Thread m_listenerThread;
        private readonly HttpListener m_listener = new();
        private readonly EndpointManager m_endpointManager;

        public Listener(EndpointManager endpointManager)
        {
            string[] prefixes = { "http://localhost:8001/registration/" };

            // URI prefixes are required
            if (prefixes == null || prefixes.Length == 0)
            {
                throw new ArgumentException("prefixes are empty");
            }

            foreach (var s in prefixes)
            {
                m_listener.Prefixes.Add(s);
            }

            m_listenerThread = new Thread(ListenerLoop);
            m_endpointManager = endpointManager;
        }

        public void Start()
        {
            m_listenerThread.Start();
        }

        private void ListenerLoop()
        {
            m_listener.Start();

            while (true)
            {
                var context = m_listener.GetContext();

                if (!context.Request.Headers.AllKeys.Contains("hdserial"))
                {
                    // TODO send status code to fuck off? how do we do that?
                    continue;
                }

                var args = new EndpointInfo(context.Request.Headers["hdserial"]!, context.Request.UserHostAddress,
                                               context.Request.Headers["osname"], context.Request.Headers["machinename"],
                                               context.Request.Headers["username"], context.Request.Headers["uptime"]);

                m_endpointManager.AddOrUpdateEndpoint(args);

                var response = context.Response;

                // Construct a response.
                const string responseString = "<HTML><BODY> Hello world!</BODY></HTML>";
                var buffer = Encoding.UTF8.GetBytes(responseString);
                response.ContentLength64 = buffer.Length;
                var output = response.OutputStream;
                output.Write(buffer, 0, buffer.Length);
                output.Close();
            }
        }
    }
}
