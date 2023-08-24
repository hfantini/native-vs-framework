using HFAutoClicker.controller;
using HFAutoClicker.model;
using System;
using System.Text.RegularExpressions;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace HFAutoClicker.view
{
    public partial class WndMain : Form
    {
        // == DECLARATIONS

        private AutoClickerController controller = null;

        // == CONSTRUCTOR(S)

        public WndMain()
        {
            InitializeComponent();

            controller = AutoClickerController.getInstance();
            this.update();
        }

        // == METHODS

        public void update()
        {
            // VALUES

            AutoClickerConfiguration config = this.controller.configuration;

            cmdMouseButton.SelectedIndex = (int) config.mouseButton;
            txtInterval.Text = config.interval.ToString();
            txtInterval.SelectionStart = txtInterval.Text.Length;
            txtInterval.SelectionLength = 0;

            // STATE

            if (controller.isRunning)
            {
                cmdMouseButton.Enabled = false;
                txtInterval.Enabled = false;

                btnStart.Enabled = false;
                btnStop.Enabled = true;
            }
            else
            {
                cmdMouseButton.Enabled = true;
                txtInterval.Enabled = true;

                btnStart.Enabled = true;
                btnStop.Enabled = false;
            }
        }

        // == EVENTS

        private void mItemAbout_Click(object sender, EventArgs e)
        {
            WndAbout wndAbout = new WndAbout();
            wndAbout.ShowDialog();
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            this.controller.start();
            update();
        }

        private void btnStop_Click(object sender, EventArgs e)
        {
            this.controller.stop();
            update();
        }

        private void cmdMouseButton_SelectedIndexChanged(object sender, EventArgs e)
        {
            AutoClickerConfiguration config = this.controller.configuration;
            config.mouseButton = (MouseButton) cmdMouseButton.SelectedIndex;

            this.controller.updateConfiguration(config);
            this.update();
        }

        private void txtInterval_TextChanged(object sender, EventArgs e)
        {
            AutoClickerConfiguration config = this.controller.configuration;

            String value = txtInterval.Text;
            value = Regex.Replace(value, "^!\\d+$", "");

            try
            {
                config.interval = int.Parse(value);
            }
            catch(Exception ex)
            {
                if(value == "")
                {
                    config.interval = 0;
                }
            }

            this.controller.updateConfiguration(config);
            this.update();
        }
    }
}
