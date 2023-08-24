using HFAutoClicker.model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms.VisualStyles;

namespace HFAutoClicker.controller
{
    internal class AutoClickerController
    {
        // == DECLARATIONS

        private static AutoClickerController _instance = null;
        private Boolean _isRunning = false;
        private AutoClickerConfiguration _configuration = null;

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
            if(!this._isRunning)
            {
                this._isRunning = true;
            }
        }

        public void stop()
        {
            if (this._isRunning)
            {
                this._isRunning = false;
            }
        }

        // == GETTERS & SETTERS

        public Boolean isRunning
        {
            get { return _isRunning; }
        }

        public AutoClickerConfiguration configuration
        {
            get { return new AutoClickerConfiguration(this._configuration); }
        }
    }
}
