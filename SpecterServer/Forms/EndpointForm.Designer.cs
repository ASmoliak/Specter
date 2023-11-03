namespace SpecterServer.Forms
{
    partial class EndpointForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            tabControl = new TabControl();
            tabPage1 = new TabPage();
            groupBox1 = new GroupBox();
            tabPage2 = new TabPage();
            textBox_machineName = new TextBox();
            label_machineName = new Label();
            label_operatingSystem = new Label();
            textBox_operatingSystem = new TextBox();
            textBox_cpu = new TextBox();
            label_cpu = new Label();
            textBox_ram = new TextBox();
            label_ram = new Label();
            textBox_ipAddress = new TextBox();
            label_ipAddress = new Label();
            textBox_country = new TextBox();
            label_country = new Label();
            label_machineType = new Label();
            textBox_machineType = new TextBox();
            textBox_uptime = new TextBox();
            label_uptime = new Label();
            textBox_uuid = new TextBox();
            label_uuid = new Label();
            tabControl.SuspendLayout();
            tabPage1.SuspendLayout();
            groupBox1.SuspendLayout();
            SuspendLayout();
            // 
            // tabControl
            // 
            tabControl.Controls.Add(tabPage1);
            tabControl.Controls.Add(tabPage2);
            tabControl.Location = new Point(12, 12);
            tabControl.Name = "tabControl";
            tabControl.SelectedIndex = 0;
            tabControl.Size = new Size(372, 329);
            tabControl.TabIndex = 0;
            // 
            // tabPage1
            // 
            tabPage1.Controls.Add(groupBox1);
            tabPage1.Location = new Point(4, 24);
            tabPage1.Name = "tabPage1";
            tabPage1.Padding = new Padding(3);
            tabPage1.Size = new Size(364, 301);
            tabPage1.TabIndex = 0;
            tabPage1.Text = "Information";
            tabPage1.UseVisualStyleBackColor = true;
            // 
            // groupBox1
            // 
            groupBox1.Controls.Add(label_uuid);
            groupBox1.Controls.Add(textBox_uuid);
            groupBox1.Controls.Add(label_uptime);
            groupBox1.Controls.Add(textBox_uptime);
            groupBox1.Controls.Add(textBox_machineType);
            groupBox1.Controls.Add(label_machineType);
            groupBox1.Controls.Add(label_country);
            groupBox1.Controls.Add(textBox_country);
            groupBox1.Controls.Add(label_ipAddress);
            groupBox1.Controls.Add(textBox_ipAddress);
            groupBox1.Controls.Add(label_ram);
            groupBox1.Controls.Add(textBox_ram);
            groupBox1.Controls.Add(label_cpu);
            groupBox1.Controls.Add(textBox_cpu);
            groupBox1.Controls.Add(textBox_operatingSystem);
            groupBox1.Controls.Add(label_operatingSystem);
            groupBox1.Controls.Add(label_machineName);
            groupBox1.Controls.Add(textBox_machineName);
            groupBox1.Location = new Point(6, 6);
            groupBox1.Name = "groupBox1";
            groupBox1.Size = new Size(352, 291);
            groupBox1.TabIndex = 0;
            groupBox1.TabStop = false;
            groupBox1.Text = "General Information";
            // 
            // tabPage2
            // 
            tabPage2.Location = new Point(4, 24);
            tabPage2.Name = "tabPage2";
            tabPage2.Padding = new Padding(3);
            tabPage2.Size = new Size(364, 314);
            tabPage2.TabIndex = 1;
            tabPage2.Text = "tabPage2";
            tabPage2.UseVisualStyleBackColor = true;
            // 
            // textBox_machineName
            // 
            textBox_machineName.Location = new Point(113, 51);
            textBox_machineName.Name = "textBox_machineName";
            textBox_machineName.ReadOnly = true;
            textBox_machineName.Size = new Size(233, 23);
            textBox_machineName.TabIndex = 2;
            // 
            // label_machineName
            // 
            label_machineName.AutoSize = true;
            label_machineName.Location = new Point(16, 54);
            label_machineName.Name = "label_machineName";
            label_machineName.Size = new Size(91, 15);
            label_machineName.TabIndex = 3;
            label_machineName.Text = "Machine Name:";
            // 
            // label_operatingSystem
            // 
            label_operatingSystem.AutoSize = true;
            label_operatingSystem.Location = new Point(3, 170);
            label_operatingSystem.Name = "label_operatingSystem";
            label_operatingSystem.Size = new Size(104, 15);
            label_operatingSystem.TabIndex = 4;
            label_operatingSystem.Text = "Operating System:";
            // 
            // textBox_operatingSystem
            // 
            textBox_operatingSystem.Location = new Point(113, 167);
            textBox_operatingSystem.Name = "textBox_operatingSystem";
            textBox_operatingSystem.ReadOnly = true;
            textBox_operatingSystem.Size = new Size(233, 23);
            textBox_operatingSystem.TabIndex = 5;
            // 
            // textBox_cpu
            // 
            textBox_cpu.Location = new Point(113, 196);
            textBox_cpu.Name = "textBox_cpu";
            textBox_cpu.ReadOnly = true;
            textBox_cpu.Size = new Size(233, 23);
            textBox_cpu.TabIndex = 6;
            // 
            // label_cpu
            // 
            label_cpu.AutoSize = true;
            label_cpu.Location = new Point(71, 199);
            label_cpu.Name = "label_cpu";
            label_cpu.Size = new Size(36, 15);
            label_cpu.TabIndex = 7;
            label_cpu.Text = "CPU: ";
            // 
            // textBox_ram
            // 
            textBox_ram.Location = new Point(113, 225);
            textBox_ram.Name = "textBox_ram";
            textBox_ram.ReadOnly = true;
            textBox_ram.Size = new Size(233, 23);
            textBox_ram.TabIndex = 8;
            // 
            // label_ram
            // 
            label_ram.AutoSize = true;
            label_ram.Location = new Point(68, 228);
            label_ram.Name = "label_ram";
            label_ram.Size = new Size(39, 15);
            label_ram.TabIndex = 9;
            label_ram.Text = "RAM: ";
            // 
            // textBox_ipAddress
            // 
            textBox_ipAddress.Location = new Point(113, 109);
            textBox_ipAddress.Name = "textBox_ipAddress";
            textBox_ipAddress.ReadOnly = true;
            textBox_ipAddress.Size = new Size(233, 23);
            textBox_ipAddress.TabIndex = 10;
            // 
            // label_ipAddress
            // 
            label_ipAddress.AutoSize = true;
            label_ipAddress.Location = new Point(39, 112);
            label_ipAddress.Name = "label_ipAddress";
            label_ipAddress.Size = new Size(68, 15);
            label_ipAddress.TabIndex = 11;
            label_ipAddress.Text = "IP Address: ";
            label_ipAddress.Click += label5_Click;
            // 
            // textBox_country
            // 
            textBox_country.Location = new Point(113, 138);
            textBox_country.Name = "textBox_country";
            textBox_country.ReadOnly = true;
            textBox_country.Size = new Size(233, 23);
            textBox_country.TabIndex = 12;
            // 
            // label_country
            // 
            label_country.AutoSize = true;
            label_country.Location = new Point(54, 141);
            label_country.Name = "label_country";
            label_country.Size = new Size(53, 15);
            label_country.TabIndex = 13;
            label_country.Text = "Country:";
            // 
            // label_machineType
            // 
            label_machineType.AutoSize = true;
            label_machineType.Location = new Point(24, 83);
            label_machineType.Name = "label_machineType";
            label_machineType.Size = new Size(83, 15);
            label_machineType.TabIndex = 14;
            label_machineType.Text = "Machine Type:";
            // 
            // textBox_machineType
            // 
            textBox_machineType.Location = new Point(113, 80);
            textBox_machineType.Name = "textBox_machineType";
            textBox_machineType.ReadOnly = true;
            textBox_machineType.Size = new Size(233, 23);
            textBox_machineType.TabIndex = 15;
            // 
            // textBox_uptime
            // 
            textBox_uptime.Location = new Point(113, 254);
            textBox_uptime.Name = "textBox_uptime";
            textBox_uptime.ReadOnly = true;
            textBox_uptime.Size = new Size(233, 23);
            textBox_uptime.TabIndex = 16;
            // 
            // label_uptime
            // 
            label_uptime.AutoSize = true;
            label_uptime.Location = new Point(17, 257);
            label_uptime.Name = "label_uptime";
            label_uptime.Size = new Size(90, 15);
            label_uptime.TabIndex = 17;
            label_uptime.Text = "System Uptime:";
            // 
            // textBox_uuid
            // 
            textBox_uuid.Location = new Point(113, 22);
            textBox_uuid.Name = "textBox_uuid";
            textBox_uuid.ReadOnly = true;
            textBox_uuid.Size = new Size(233, 23);
            textBox_uuid.TabIndex = 18;
            // 
            // label_uuid
            // 
            label_uuid.AutoSize = true;
            label_uuid.Location = new Point(19, 25);
            label_uuid.Name = "label_uuid";
            label_uuid.Size = new Size(88, 15);
            label_uuid.TabIndex = 19;
            label_uuid.Text = "Endpoint UUID:";
            // 
            // EndpointForm
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(396, 353);
            Controls.Add(tabControl);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            Name = "EndpointForm";
            Text = "EndpointForm";
            Load += EndpointForm_Load;
            tabControl.ResumeLayout(false);
            tabPage1.ResumeLayout(false);
            groupBox1.ResumeLayout(false);
            groupBox1.PerformLayout();
            ResumeLayout(false);
        }

        #endregion

        private TabControl tabControl;
        private TabPage tabPage1;
        private TabPage tabPage2;
        private GroupBox groupBox1;
        private TextBox textBox_operatingSystem;
        private Label label_operatingSystem;
        private Label label_machineName;
        private TextBox textBox_machineName;
        private Label label_country;
        private TextBox textBox_country;
        private Label label_ipAddress;
        private TextBox textBox_ipAddress;
        private Label label_ram;
        private TextBox textBox_ram;
        private Label label_cpu;
        private TextBox textBox_cpu;
        private TextBox textBox_machineType;
        private Label label_machineType;
        private Label label_uptime;
        private TextBox textBox_uptime;
        private Label label_uuid;
        private TextBox textBox_uuid;
    }
}