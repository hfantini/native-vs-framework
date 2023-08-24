using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HFAutoClicker.model
{
    internal class AutoClickerConfiguration
    {
        private MouseButton _mouseButton = MouseButton.LEFT;
        private int _interval = 100;

        public AutoClickerConfiguration() { }
        public AutoClickerConfiguration(AutoClickerConfiguration origin)
        {
            this.mouseButton = origin.mouseButton;
            this.interval = origin.interval;
        }

        // == GETTERS & SETTERS

        public MouseButton mouseButton
        {
            get { return _mouseButton; }
            set { this._mouseButton = value; }
        }

        public int interval
        {
            get { return _interval; }
            set { this._interval = value; }
        }
    }
}
