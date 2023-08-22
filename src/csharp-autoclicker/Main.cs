using HFAutoClicker.view;
using System;
using System.Windows.Forms;

namespace HFAutoClicker
{
    internal static class Program
    {
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new WndMain());
        }
    }
}
