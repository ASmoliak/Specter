using SpecterServer.Forms;
using SpecterServer.Source;
using SpecterServer.Source.Comms;
using SpecterServer.Source.Utils;
using static System.Runtime.InteropServices.JavaScript.JSType;

namespace SpecterServer
{
    public partial class MainForm : Form
    {
        private readonly EndpointManager m_endpointManager = new();
        private readonly Listener m_listener;

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
            m_listener = new Listener(m_endpointManager);
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

            m_endpointManager.OnEndpointUpdated += info => clientListView.Invoke(() => UpdateEndpointTable(info));

            m_listener.Start();
        }

        private void clientListView_ItemActivate(object? sender, EventArgs e)
        {
            if (clientListView.SelectedItems.Count <= 0)
            {
                return;
            }

            var desiredEndpointUuid = clientListView.SelectedItems[0].Text;
            var endpointInfo = m_endpointManager.FindEndpoint(desiredEndpointUuid);
            if (endpointInfo == null)
            {
                MessageBox.Show($@"Failed to open extended Endpoint Info, failed to find endpoint UUID {desiredEndpointUuid} in internal database",
                                @"Error", MessageBoxButtons.OK, MessageBoxIcon.Error);

                return;
            }

            var form = new EndpointForm(endpointInfo);
            form.ShowDialog();
        }

        private static void MainForm_FormClosing(object? sender, FormClosingEventArgs e) => System.Diagnostics.Process.GetCurrentProcess().Kill();

        private void UpdateEndpointTable(EndpointInfo newClientEvent)
        {

            // Your code to modify the ListView goes here
            var existingItem = FindItemByUuid(newClientEvent.Uuid);
            if (existingItem != null)
            {
                // Update existing item
                existingItem.SubItems["ipv4"]!.Text = newClientEvent.UserHostAddress;
                existingItem.SubItems["machinename"]!.Text = newClientEvent.MachineName;
                existingItem.SubItems["username"]!.Text = newClientEvent.Username;
                existingItem.SubItems["uptime"]!.Text = newClientEvent.Uptime;
                existingItem.SubItems["os"]!.Text = newClientEvent.OperatingSystem;

                LogText(LogSeverity.Information, $"Updated an existing Client Row for UUID: {newClientEvent.Uuid}");
            }
            else
            {
                // Add completely new item
                var newItem = new ListViewItem(newClientEvent.Uuid);
                newItem.SubItems.Add(new ListViewItem.ListViewSubItem { Name = @"uuid_virtual", Text = newClientEvent.Uuid });
                newItem.SubItems.Add(new ListViewItem.ListViewSubItem { Name = @"ipv4", Text = newClientEvent.UserHostAddress });
                newItem.SubItems.Add(new ListViewItem.ListViewSubItem { Name = @"os", Text = newClientEvent.OperatingSystem });
                newItem.SubItems.Add(new ListViewItem.ListViewSubItem { Name = @"username", Text = newClientEvent.Username });
                newItem.SubItems.Add(new ListViewItem.ListViewSubItem { Name = @"machinename", Text = newClientEvent.MachineName });
                newItem.SubItems.Add(new ListViewItem.ListViewSubItem { Name = @"uptime", Text = newClientEvent.Uptime });
                clientListView.Items.Add(newItem);

                LogText(LogSeverity.Information, $"Added a client row for UUID: {newClientEvent.Uuid}");
            }
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

        private void exitToolStripMenuItem_Click(object sender, EventArgs e) => System.Diagnostics.Process.GetCurrentProcess().Kill();

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
        }
    }
}