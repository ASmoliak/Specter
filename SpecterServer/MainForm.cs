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
            clientListView.View = View.Details;

            // Initialize the Main Client List ListView
            clientListView.Columns.Add("uuid_real", "", 0);
            clientListView.Columns.Add("uuid_virtual", "UUID", 100, HorizontalAlignment.Center, 0);
            clientListView.Columns.Add("ipv4", "IPv4", 100, HorizontalAlignment.Center, 0);
            clientListView.Columns.Add("os", "OS", 100, HorizontalAlignment.Center, 0);
            clientListView.Columns.Add("username", "Username", 100, HorizontalAlignment.Center, 0);
            clientListView.Columns.Add("machineName", "Machine Name", 100, HorizontalAlignment.Center, 0);
            clientListView.Columns.Add("uptime", "Uptime", 100, HorizontalAlignment.Center, 0);
            clientListView.AllowColumnReorder = true;
            clientListView.GridLines = true;
            clientListView.FullRowSelect = true;
            clientListView.Anchor = AnchorStyles.Top | AnchorStyles.Bottom | AnchorStyles.Left | AnchorStyles.Right;

            tabControl.Anchor = AnchorStyles.Top | AnchorStyles.Bottom | AnchorStyles.Left | AnchorStyles.Right;

            // Initialize the Listener
            m_listener = new Thread(StartServerLoop);
            m_listener.Start();
        }

        private void StartServerLoop()
        {
            string[] prefixes = { "http://localhost:8001/registration/" };

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
            foreach (var s in prefixes)
            {
                listener.Prefixes.Add(s);
            }

            listener.Start();

            while (true)
            {
                var context = listener.GetContext();

                UpdateOrAddEndpoint(context.Request);

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

        private void UpdateOrAddEndpoint(HttpListenerRequest request)
        {
            if (!request.Headers.AllKeys.Contains("hdserial"))
            {
                return; // Request doesn't contain an hdserial, malformed request..
            }

            var uuid = request.Headers["hdserial"];
            if (uuid == null)
            {
                return; // Can't be null
            }

            clientListView.Invoke(() =>
            {
                // Your code to modify the ListView goes here
                var existingItem = FindItemByUuid(uuid);
                if (existingItem != null)
                {
                    // Update existing item
                    existingItem.SubItems["ipv4"]!.Text = request.UserHostAddress;
                    existingItem.SubItems["machinename"]!.Text = request.Headers["machinename"];
                    existingItem.SubItems["username"]!.Text = request.Headers["username"];
                    existingItem.SubItems["uptime"]!.Text = request.Headers["uptime"];
                    existingItem.SubItems["os"]!.Text = request.Headers["osname"];
                }
                else
                {
                    // Add completely new item
                    var newItem = new ListViewItem(uuid);
                    newItem.SubItems.Add(new ListViewItem.ListViewSubItem { Name = @"uuid_virtual", Text = uuid });
                    newItem.SubItems.Add(new ListViewItem.ListViewSubItem { Name = @"ipv4", Text = request.UserHostAddress });
                    newItem.SubItems.Add(new ListViewItem.ListViewSubItem { Name = @"os", Text = request.Headers["osname"] });
                    newItem.SubItems.Add(new ListViewItem.ListViewSubItem { Name = @"username", Text = request.Headers["username"] });
                    newItem.SubItems.Add(new ListViewItem.ListViewSubItem { Name = @"machinename", Text = request.Headers["machinename"] });
                    newItem.SubItems.Add(new ListViewItem.ListViewSubItem { Name = @"uptime", Text = request.Headers["uptime"] });
                    clientListView.Items.Add(newItem);
                }
            });
        }

        private ListViewItem? FindItemByUuid(string uuid)
        {
            foreach (ListViewItem? item in clientListView.Items)
            {
                if (item?.Text == uuid)
                {
                    return item;
                }
            }
            return null; // UUID not found
        }
    }
}