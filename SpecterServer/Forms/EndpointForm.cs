namespace SpecterServer.Forms
{
    public partial class EndpointForm : Form
    {
        private string m_endpointUuid;

        public EndpointForm(string endpointUuid)
        {
            m_endpointUuid = endpointUuid;

            InitializeComponent();
        }

        private void EndpointForm_Load(object sender, EventArgs e)
        {
            Text = m_endpointUuid;
        }
    }
}