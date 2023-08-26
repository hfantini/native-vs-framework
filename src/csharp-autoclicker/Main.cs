using HFAutoClicker.view;
using System;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace HFAutoClicker
{
    internal static class Program
    {
        [STAThread]
        static void Main()
        {
            // STARTING APPLICATION

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new WndMain());
        }
    }
}
