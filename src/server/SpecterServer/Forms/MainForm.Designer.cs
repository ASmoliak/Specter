namespace SpecterServer
{
    partial class MainForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            tabControl = new TabControl();
            tabPage1 = new TabPage();
            clientListView = new ListView();
            UUID_real = new ColumnHeader();
            UUID_virtual = new ColumnHeader();
            Country = new ColumnHeader();
            IPv4 = new ColumnHeader();
            OS = new ColumnHeader();
            Username = new ColumnHeader();
            MachineName = new ColumnHeader();
            uptime = new ColumnHeader();
            tabPage2 = new TabPage();
            richLogBox = new RichTextBox();
            menuStrip1 = new MenuStrip();
            fileToolStripMenuItem = new ToolStripMenuItem();
            exitToolStripMenuItem = new ToolStripMenuItem();
            helpToolStripMenuItem = new ToolStripMenuItem();
            aboutToolStripMenuItem = new ToolStripMenuItem();
            tabControl.SuspendLayout();
            tabPage1.SuspendLayout();
            tabPage2.SuspendLayout();
            menuStrip1.SuspendLayout();
            SuspendLayout();
            // 
            // tabControl
            // 
            tabControl.Anchor = AnchorStyles.Top | AnchorStyles.Bottom | AnchorStyles.Left | AnchorStyles.Right;
            tabControl.Controls.Add(tabPage1);
            tabControl.Controls.Add(tabPage2);
            tabControl.Location = new Point(12, 27);
            tabControl.Name = "tabControl";
            tabControl.SelectedIndex = 0;
            tabControl.Size = new Size(776, 394);
            tabControl.TabIndex = 1;
            // 
            // tabPage1
            // 
            tabPage1.Controls.Add(clientListView);
            tabPage1.Location = new Point(4, 24);
            tabPage1.Name = "tabPage1";
            tabPage1.Padding = new Padding(3);
            tabPage1.Size = new Size(768, 366);
            tabPage1.TabIndex = 0;
            tabPage1.Text = "Clients";
            tabPage1.UseVisualStyleBackColor = true;
            // 
            // clientListView
            // 
            clientListView.AllowColumnReorder = true;
            clientListView.Anchor = AnchorStyles.Top | AnchorStyles.Bottom | AnchorStyles.Left | AnchorStyles.Right;
            clientListView.Columns.AddRange(new ColumnHeader[] { UUID_real, UUID_virtual, Country, IPv4, OS, Username, MachineName, uptime });
            clientListView.FullRowSelect = true;
            clientListView.GridLines = true;
            clientListView.Location = new Point(6, 6);
            clientListView.Name = "clientListView";
            clientListView.Size = new Size(756, 354);
            clientListView.TabIndex = 0;
            clientListView.UseCompatibleStateImageBehavior = false;
            clientListView.View = View.Details;
            // 
            // UUID_real
            // 
            UUID_real.Text = "";
            UUID_real.Width = 0;
            // 
            // UUID_virtual
            // 
            UUID_virtual.Text = "UUID";
            UUID_virtual.TextAlign = HorizontalAlignment.Center;
            UUID_virtual.Width = 100;
            // 
            // Country
            // 
            Country.Text = "Country";
            Country.TextAlign = HorizontalAlignment.Center;
            Country.Width = 150;
            // 
            // IPv4
            // 
            IPv4.Text = "IPv4";
            IPv4.TextAlign = HorizontalAlignment.Center;
            IPv4.Width = 100;
            // 
            // OS
            // 
            OS.Text = "OS";
            OS.TextAlign = HorizontalAlignment.Center;
            OS.Width = 100;
            // 
            // Username
            // 
            Username.Text = "Username";
            Username.TextAlign = HorizontalAlignment.Center;
            Username.Width = 100;
            // 
            // MachineName
            // 
            MachineName.Text = "Machine Name";
            MachineName.TextAlign = HorizontalAlignment.Center;
            MachineName.Width = 100;
            // 
            // uptime
            // 
            uptime.Text = "Uptime";
            uptime.TextAlign = HorizontalAlignment.Center;
            uptime.Width = 100;
            // 
            // tabPage2
            // 
            tabPage2.Controls.Add(richLogBox);
            tabPage2.Location = new Point(4, 24);
            tabPage2.Name = "tabPage2";
            tabPage2.Padding = new Padding(3);
            tabPage2.Size = new Size(721, 366);
            tabPage2.TabIndex = 1;
            tabPage2.Text = "Logs";
            tabPage2.UseVisualStyleBackColor = true;
            // 
            // richLogBox
            // 
            richLogBox.Anchor = AnchorStyles.Top | AnchorStyles.Bottom | AnchorStyles.Left | AnchorStyles.Right;
            richLogBox.BackColor = SystemColors.Window;
            richLogBox.BorderStyle = BorderStyle.FixedSingle;
            richLogBox.Location = new Point(6, 6);
            richLogBox.Name = "richLogBox";
            richLogBox.ReadOnly = true;
            richLogBox.Size = new Size(709, 354);
            richLogBox.TabIndex = 0;
            richLogBox.Text = "";
            // 
            // menuStrip1
            // 
            menuStrip1.Items.AddRange(new ToolStripItem[] { fileToolStripMenuItem, helpToolStripMenuItem });
            menuStrip1.Location = new Point(0, 0);
            menuStrip1.Name = "menuStrip1";
            menuStrip1.Size = new Size(800, 24);
            menuStrip1.TabIndex = 2;
            menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            fileToolStripMenuItem.DropDownItems.AddRange(new ToolStripItem[] { exitToolStripMenuItem });
            fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            fileToolStripMenuItem.Size = new Size(37, 20);
            fileToolStripMenuItem.Text = "File";
            // 
            // exitToolStripMenuItem
            // 
            exitToolStripMenuItem.DisplayStyle = ToolStripItemDisplayStyle.Text;
            exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            exitToolStripMenuItem.ShowShortcutKeys = false;
            exitToolStripMenuItem.Size = new Size(86, 22);
            exitToolStripMenuItem.Text = "Exit";
            exitToolStripMenuItem.Click += exitToolStripMenuItem_Click;
            // 
            // helpToolStripMenuItem
            // 
            helpToolStripMenuItem.DropDownItems.AddRange(new ToolStripItem[] { aboutToolStripMenuItem });
            helpToolStripMenuItem.Name = "helpToolStripMenuItem";
            helpToolStripMenuItem.Size = new Size(44, 20);
            helpToolStripMenuItem.Text = "Help";
            // 
            // aboutToolStripMenuItem
            // 
            aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
            aboutToolStripMenuItem.Size = new Size(107, 22);
            aboutToolStripMenuItem.Text = "About";
            aboutToolStripMenuItem.Click += aboutToolStripMenuItem_Click;
            // 
            // MainForm
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 433);
            Controls.Add(tabControl);
            Controls.Add(menuStrip1);
            Icon = (Icon)resources.GetObject("$this.Icon");
            MainMenuStrip = menuStrip1;
            Name = "MainForm";
            Text = "Specter C&C Server";
            Load += MainForm_Load;
            tabControl.ResumeLayout(false);
            tabPage1.ResumeLayout(false);
            tabPage2.ResumeLayout(false);
            menuStrip1.ResumeLayout(false);
            menuStrip1.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion
        private TabControl tabControl;
        private TabPage tabPage1;
        private TabPage tabPage2;
        private ListView clientListView;
        private RichTextBox richLogBox;
        private MenuStrip menuStrip1;
        private ToolStripMenuItem fileToolStripMenuItem;
        private ToolStripMenuItem exitToolStripMenuItem;
        private ToolStripMenuItem helpToolStripMenuItem;
        private ToolStripMenuItem aboutToolStripMenuItem;
        private ColumnHeader UUID_real;
        private ColumnHeader UUID_virtual;
        private ColumnHeader IPv4;
        private ColumnHeader OS;
        private ColumnHeader Username;
        private ColumnHeader MachineName;
        private ColumnHeader uptime;
        private ColumnHeader Country;
    }
}