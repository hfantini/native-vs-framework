using HFAutoClicker.model;
using System;
using System.Runtime.InteropServices;
using System.Threading;
using System.Windows.Forms;

namespace HFAutoClicker.controller
{
    internal class AutoClickerController
    {
        // == DECLARATIONS

        private static AutoClickerController _instance = null;
        private Boolean _isRunning = false;
        private AutoClickerConfiguration _configuration = null;
        private Thread _thread = null;

        [DllImport("user32.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
        public static extern void mouse_event(uint dwFlags, uint dx, uint dy, uint cButtons, uint dwExtraInfo);

        private const int MOUSEEVENTF_LEFTDOWN = 0x0002;
        private const int MOUSEEVENTF_LEFTUP = 0x0004;
        private const int MOUSEEVENTF_MIDDLEDOWN = 0x0020;
        private const int MOUSEEVENTF_MIDDLEUP = 0x0040;
        private const int MOUSEEVENTF_RIGHTDOWN = 0x0008;
        private const int MOUSEEVENTF_RIGHTUP = 0x0010;

        public AutoClickerController()
        {
            this._configuration = new AutoClickerConfiguration();
        }

        // == METHODS

        public static AutoClickerController getInstance()
        {
            if(AutoClickerController._instance == null)
            {
                AutoClickerController._instance = new AutoClickerController();
            }

            return AutoClickerController._instance;
        }

        private void run()
        {
            try
            {
                while(true)
                {
                    if(this.isRunning)
                    {
                        uint x = (uint) Cursor.Position.X;
                        uint y = (uint) Cursor.Position.Y;
                        uint action = 0;

                        switch(this.configuration.mouseButton)
                        {
                            case MouseButton.LEFT:
                                action = MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP;
                                break;

                            case MouseButton.MIDDLE:
                                action = MOUSEEVENTF_MIDDLEDOWN | MOUSEEVENTF_MIDDLEUP;
                                break;

                            case MouseButton.RIGHT:
                                action = MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP;
                                break;
                        }

                        mouse_event(action, x, y, 0, 0);

                        Thread.Sleep(this.configuration.interval);
                    }
                }
            }
            catch (Exception ex) 
            {
                Console.Error.WriteLine(ex.Message);
            }
        }

        public void updateConfiguration(AutoClickerConfiguration value)
        {
            // DELAY

            if(value.interval < 0)
            {
                value.interval = 0;
            }
            
            if(value.interval > 999999)
            {
                value.interval = 999999;
            }

            this._configuration = value;
        }

        public void start()
        {
            if(!isRunning)
            {
                this._thread = new Thread(this.run);
                this._thread.Start();
            }
        }

        public void stop()
        {
            if (isRunning)
            {
                this._thread.Abort();
                this._thread = null;
            }
        }

        // == GETTERS & SETTERS

        public Boolean isRunning
        {
            get { return this._thread != null; }
        }

        public AutoClickerConfiguration configuration
        {
            get { return new AutoClickerConfiguration(this._configuration); }
        }
    }
}
