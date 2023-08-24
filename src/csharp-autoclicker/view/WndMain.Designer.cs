namespace HFAutoClicker.view
{
    partial class WndMain
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(WndMain));
            this.grpConfig = new System.Windows.Forms.GroupBox();
            this.lblMs = new System.Windows.Forms.Label();
            this.txtInterval = new System.Windows.Forms.TextBox();
            this.lblInterval = new System.Windows.Forms.Label();
            this.lblMouseButton = new System.Windows.Forms.Label();
            this.cmdMouseButton = new System.Windows.Forms.ComboBox();
            this.grpShortcut = new System.Windows.Forms.GroupBox();
            this.lblShortcutStop = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.btnStart = new System.Windows.Forms.Button();
            this.btnStop = new System.Windows.Forms.Button();
            this.lblSeparator = new System.Windows.Forms.Label();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.aboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.mItemAbout = new System.Windows.Forms.ToolStripMenuItem();
            this.grpConfig.SuspendLayout();
            this.grpShortcut.SuspendLayout();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // grpConfig
            // 
            this.grpConfig.Controls.Add(this.lblMs);
            this.grpConfig.Controls.Add(this.txtInterval);
            this.grpConfig.Controls.Add(this.lblInterval);
            this.grpConfig.Controls.Add(this.lblMouseButton);
            this.grpConfig.Controls.Add(this.cmdMouseButton);
            resources.ApplyResources(this.grpConfig, "grpConfig");
            this.grpConfig.Name = "grpConfig";
            this.grpConfig.TabStop = false;
            // 
            // lblMs
            // 
            resources.ApplyResources(this.lblMs, "lblMs");
            this.lblMs.Name = "lblMs";
            // 
            // txtInterval
            // 
            resources.ApplyResources(this.txtInterval, "txtInterval");
            this.txtInterval.Name = "txtInterval";
            this.txtInterval.TextChanged += new System.EventHandler(this.txtInterval_TextChanged);
            // 
            // lblInterval
            // 
            resources.ApplyResources(this.lblInterval, "lblInterval");
            this.lblInterval.Name = "lblInterval";
            // 
            // lblMouseButton
            // 
            resources.ApplyResources(this.lblMouseButton, "lblMouseButton");
            this.lblMouseButton.Name = "lblMouseButton";
            // 
            // cmdMouseButton
            // 
            this.cmdMouseButton.DisplayMember = "1";
            this.cmdMouseButton.FormattingEnabled = true;
            this.cmdMouseButton.Items.AddRange(new object[] {
            resources.GetString("cmdMouseButton.Items"),
            resources.GetString("cmdMouseButton.Items1"),
            resources.GetString("cmdMouseButton.Items2"),
            resources.GetString("cmdMouseButton.Items3"),
            resources.GetString("cmdMouseButton.Items4")});
            resources.ApplyResources(this.cmdMouseButton, "cmdMouseButton");
            this.cmdMouseButton.Name = "cmdMouseButton";
            this.cmdMouseButton.SelectedIndexChanged += new System.EventHandler(this.cmdMouseButton_SelectedIndexChanged);
            // 
            // grpShortcut
            // 
            this.grpShortcut.Controls.Add(this.lblShortcutStop);
            this.grpShortcut.Controls.Add(this.label1);
            resources.ApplyResources(this.grpShortcut, "grpShortcut");
            this.grpShortcut.Name = "grpShortcut";
            this.grpShortcut.TabStop = false;
            // 
            // lblShortcutStop
            // 
            resources.ApplyResources(this.lblShortcutStop, "lblShortcutStop");
            this.lblShortcutStop.Name = "lblShortcutStop";
            // 
            // label1
            // 
            resources.ApplyResources(this.label1, "label1");
            this.label1.Name = "label1";
            // 
            // btnStart
            // 
            resources.ApplyResources(this.btnStart, "btnStart");
            this.btnStart.Name = "btnStart";
            this.btnStart.UseVisualStyleBackColor = true;
            this.btnStart.Click += new System.EventHandler(this.btnStart_Click);
            // 
            // btnStop
            // 
            resources.ApplyResources(this.btnStop, "btnStop");
            this.btnStop.Name = "btnStop";
            this.btnStop.UseVisualStyleBackColor = true;
            this.btnStop.Click += new System.EventHandler(this.btnStop_Click);
            // 
            // lblSeparator
            // 
            this.lblSeparator.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            resources.ApplyResources(this.lblSeparator, "lblSeparator");
            this.lblSeparator.Name = "lblSeparator";
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(24, 24);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.aboutToolStripMenuItem});
            resources.ApplyResources(this.menuStrip1, "menuStrip1");
            this.menuStrip1.Name = "menuStrip1";
            // 
            // aboutToolStripMenuItem
            // 
            this.aboutToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mItemAbout});
            this.aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
            resources.ApplyResources(this.aboutToolStripMenuItem, "aboutToolStripMenuItem");
            // 
            // mItemAbout
            // 
            this.mItemAbout.Name = "mItemAbout";
            resources.ApplyResources(this.mItemAbout, "mItemAbout");
            this.mItemAbout.Click += new System.EventHandler(this.mItemAbout_Click);
            // 
            // WndMain
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.lblSeparator);
            this.Controls.Add(this.btnStop);
            this.Controls.Add(this.btnStart);
            this.Controls.Add(this.grpShortcut);
            this.Controls.Add(this.grpConfig);
            this.Controls.Add(this.menuStrip1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.MainMenuStrip = this.menuStrip1;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "WndMain";
            this.grpConfig.ResumeLayout(false);
            this.grpConfig.PerformLayout();
            this.grpShortcut.ResumeLayout(false);
            this.grpShortcut.PerformLayout();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox grpConfig;
        private System.Windows.Forms.GroupBox grpShortcut;
        private System.Windows.Forms.Button btnStart;
        private System.Windows.Forms.Button btnStop;
        private System.Windows.Forms.Label lblSeparator;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label lblShortcutStop;
        private System.Windows.Forms.Label lblMs;
        private System.Windows.Forms.TextBox txtInterval;
        private System.Windows.Forms.Label lblInterval;
        private System.Windows.Forms.Label lblMouseButton;
        private System.Windows.Forms.ComboBox cmdMouseButton;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem aboutToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem mItemAbout;
    }
}