using SpecterServer.Source;

namespace SpecterServer.Forms
{
    public partial class EndpointForm : Form
    {
        private readonly EndpointInfo m_endpointInfo;

        public EndpointForm(EndpointInfo endpointInfo)
        {
            m_endpointInfo = endpointInfo;

            InitializeComponent();
        }

        private void EndpointForm_Load(object sender, EventArgs e)
        {
            Text = $@"Endpoint Info for {m_endpointInfo.UserHostAddress}";

            textBox_uuid.Text = "N/A";
            textBox_country.Text = "N/A";
            textBox_cpu.Text = "N/A";
            textBox_ipAddress.Text = m_endpointInfo.UserHostAddress;
            textBox_machineName.Text = m_endpointInfo.MachineName;
            textBox_machineType.Text = "N/A";
            textBox_operatingSystem.Text = m_endpointInfo.OperatingSystem;
            textBox_ram.Text = "N/A";
            textBox_uptime.Text = "N/A";
        }
    }
}