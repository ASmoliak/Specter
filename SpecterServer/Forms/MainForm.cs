using System.Net;
using SpecterServer.Forms;
using SpecterServer.Source;

namespace SpecterServer
{
    public partial class MainForm : Form
    {
        private Listener m_listener;

        private enum LogSeverity
        {
            Trace,
            Debug,
            Information,
            Warning,
            Error
        }

        public MainForm()
        {
            InitializeComponent();
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            // Initialize the Main Client List ListView
            clientListView.View = View.Details;
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
            clientListView.ItemActivate += clientListView_ItemActivate;

            clientListView.Anchor = AnchorStyles.Top | AnchorStyles.Bottom | AnchorStyles.Left | AnchorStyles.Right;
            tabControl.Anchor = AnchorStyles.Top | AnchorStyles.Bottom | AnchorStyles.Left | AnchorStyles.Right;
            richLogBox.Anchor = AnchorStyles.Top | AnchorStyles.Bottom | AnchorStyles.Left | AnchorStyles.Right;

            FormClosing += MainForm_FormClosing;

            m_listener = new Listener();
        }

        private static void MainForm_FormClosing(object? sender, FormClosingEventArgs e)
        {
            System.Diagnostics.Process.GetCurrentProcess().Kill();
        }

        private void clientListView_ItemActivate(object? sender, EventArgs e)
        {
            if (clientListView.SelectedItems.Count <= 0)
            {
                return;
            }

            var form = new EndpointForm(clientListView.SelectedItems[0].Text);
            form.ShowDialog();
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

                    LogText(LogSeverity.Information, $"Updated an existing Client Row for UUID: {uuid}");
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

                    LogText(LogSeverity.Information, $"Added a client row for UUID: {uuid}");
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

        private void LogText(LogSeverity severity, string message)
        {
            if (richLogBox.InvokeRequired)
            {
                richLogBox.Invoke(() =>
                {
                    richLogBox.AppendText($@"[{severity}][{DateTime.Now}] {message}" + Environment.NewLine);
                });
            }
            else
            {
                richLogBox.AppendText($@"[{severity}][{DateTime.Now}] {message}" + Environment.NewLine);
            }
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.GetCurrentProcess().Kill();
        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var aboutBox = new AboutBox();
            aboutBox.ShowDialog();
        }
    }
}