using HFAutoClicker.controller;
using HFAutoClicker.model;
using System;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Text.RegularExpressions;
using System.Windows.Forms;

namespace HFAutoClicker.view
{
    public partial class WndMain : Form
    {
        // == DECLARATIONS

        private AutoClickerController controller = null;

        private const int WH_KEYBOARD_LL = 13;
        private const int WM_KEYDOWN = 0x0100;
        private const int VK_F9 = 0x78;
        private const int VK_F10 = 0x79;
        private IntPtr _hookID = IntPtr.Zero;

        [DllImport("user32.dll", CharSet = CharSet.Auto, SetLastError = true)]
        private static extern IntPtr SetWindowsHookEx(int idHook, LowLevelKeyboardProc lpfn, IntPtr hMod, uint dwThreadId);

        [DllImport("user32.dll", CharSet = CharSet.Auto, SetLastError = true)]
        [return: MarshalAs(UnmanagedType.Bool)] private static extern bool UnhookWindowsHookEx(IntPtr hhk);

        [DllImport("user32.dll", CharSet = CharSet.Auto, SetLastError = true)]
        private static extern IntPtr CallNextHookEx(IntPtr hhk, int nCode, IntPtr wParam, IntPtr lParam);

        [DllImport("kernel32.dll", CharSet = CharSet.Auto, SetLastError = true)]
        private static extern IntPtr GetModuleHandle(string lpModuleName);

        // == CONSTRUCTOR(S)

        public WndMain()
        {
            InitializeComponent();

            controller = AutoClickerController.getInstance();
            this.update();

            Process process = Process.GetCurrentProcess();
            ProcessModule module = process.MainModule;
            this._hookID = SetWindowsHookEx(WH_KEYBOARD_LL, hookKeyboardProc, GetModuleHandle(module.ModuleName), 0);
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

        private delegate IntPtr LowLevelKeyboardProc(int nCode, IntPtr wParam, IntPtr lParam);

        public IntPtr hookKeyboardProc(int nCode, IntPtr wParam, IntPtr lParam)
        {
            if (nCode >= 0 && wParam == (IntPtr) WM_KEYDOWN)
            {
                int VKCode = Marshal.ReadInt32(lParam);

                if(VKCode == VK_F9)
                {
                    this.controller.start();
                }
                else if(VKCode == VK_F10)
                {
                    this.controller.stop();
                }
            }

            return CallNextHookEx(_hookID, nCode, wParam, lParam);
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

        private void WndMain_FormClosing(object sender, FormClosingEventArgs e)
        {
            this.controller.stop();
            UnhookWindowsHookEx(this._hookID);
        }
    }
}
