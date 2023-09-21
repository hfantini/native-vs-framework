#include <thread>

#ifndef CLASS_AUTOCLICKCONTROLLER
#define CLASS_AUTOCLICKCONTROLLER

namespace App
{
	static class AutoClickController
	{
		public:
			AutoClickController();
			~AutoClickController();

			static AutoClickController* getInstance();

			void start();
			void stop();
			BOOL getIsRunning();

		private:

			static AutoClickController* _instance;
			BOOL isRunning = FALSE;
			std::unique_ptr<std::thread> _thread;

		protected:

			void run();
	};
}

#endif