// See https://aka.ms/new-console-template for more information
using System.Net;


string[] prefixes = new string[] { "http://localhost:8001/registration/" };

SimpleListenerExample(prefixes);

static void PrintHeaderIfExists(HttpListenerRequest request, string headerKey)
{
    if (request.Headers.AllKeys.Contains(headerKey))
    {
        Console.WriteLine($"{headerKey}: {request.Headers[headerKey]}");
    }
}

static void SimpleListenerExample(string[] prefixes)
{
    if (!HttpListener.IsSupported)
    {
        Console.WriteLine("Windows XP SP2 or Server 2003 is required to use the HttpListener class.");
        return;
    }

    // URI prefixes are required,
    // for example "http://127.0.0.1:8080/index/".
    if (prefixes == null || prefixes.Length == 0)
    {
        throw new ArgumentException("prefixes");
    }

    // Create a listener.
    HttpListener listener = new HttpListener();

    // Add the prefixes.
    foreach (string s in prefixes)
    {
        listener.Prefixes.Add(s);
    }
    listener.Start();
    Console.WriteLine("Listening...");

    while (true)
    {
        HttpListenerContext context = listener.GetContext();

        HttpListenerRequest request = context.Request;
        Console.WriteLine($"Received reg request from address: {request.UserHostAddress}");

        if (request.Headers.Count > 0) 
        {
            PrintHeaderIfExists(request, "hdserial");
            PrintHeaderIfExists(request, "username");
            PrintHeaderIfExists(request, "computername");
        }
        
        HttpListenerResponse response = context.Response;

        // Construct a response.
        string responseString = "<HTML><BODY> Hello world!</BODY></HTML>";
        byte[] buffer = System.Text.Encoding.UTF8.GetBytes(responseString);
        // Get a response stream and write the response to it.
        response.ContentLength64 = buffer.Length;
        System.IO.Stream output = response.OutputStream;
        output.Write(buffer, 0, buffer.Length);
        // You must close the output stream.
        output.Close();
    }

    //listener.Stop();
}