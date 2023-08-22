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
            this.grpShortcut = new System.Windows.Forms.GroupBox();
            this.label1 = new System.Windows.Forms.Label();
            this.btnStart = new System.Windows.Forms.Button();
            this.btnStop = new System.Windows.Forms.Button();
            this.lblSeparator = new System.Windows.Forms.Label();
            this.lblShortcutStop = new System.Windows.Forms.Label();
            this.grpShortcut.SuspendLayout();
            this.SuspendLayout();
            // 
            // grpConfig
            // 
            resources.ApplyResources(this.grpConfig, "grpConfig");
            this.grpConfig.Name = "grpConfig";
            this.grpConfig.TabStop = false;
            // 
            // grpShortcut
            // 
            this.grpShortcut.Controls.Add(this.lblShortcutStop);
            this.grpShortcut.Controls.Add(this.label1);
            resources.ApplyResources(this.grpShortcut, "grpShortcut");
            this.grpShortcut.Name = "grpShortcut";
            this.grpShortcut.TabStop = false;
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
            // 
            // btnStop
            // 
            resources.ApplyResources(this.btnStop, "btnStop");
            this.btnStop.Name = "btnStop";
            this.btnStop.UseVisualStyleBackColor = true;
            // 
            // lblSeparator
            // 
            this.lblSeparator.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            resources.ApplyResources(this.lblSeparator, "lblSeparator");
            this.lblSeparator.Name = "lblSeparator";
            // 
            // lblShortcutStop
            // 
            resources.ApplyResources(this.lblShortcutStop, "lblShortcutStop");
            this.lblShortcutStop.Name = "lblShortcutStop";
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
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "WndMain";
            this.TopMost = true;
            this.grpShortcut.ResumeLayout(false);
            this.grpShortcut.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox grpConfig;
        private System.Windows.Forms.GroupBox grpShortcut;
        private System.Windows.Forms.Button btnStart;
        private System.Windows.Forms.Button btnStop;
        private System.Windows.Forms.Label lblSeparator;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label lblShortcutStop;
    }
}