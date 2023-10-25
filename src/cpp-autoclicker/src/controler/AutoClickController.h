#define _CRTDBG_MAP_ALLOC
#ifdef _DEBUG
	#include<iostream>
	#include <crtdbg.h>
	#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
	#define new DEBUG_NEW
#endif

#include <thread>
#include "../structs/AutoClickControllerConfig.h";

#ifndef CLASS_AUTOCLICKCONTROLLER
#define CLASS_AUTOCLICKCONTROLLER

namespace App
{
	static class AutoClickController
	{
		public:

			AutoClickController();
			~AutoClickController();

			void start();
			void stop();

			App::AutoClickControllerConfig getConfig();
			void setConfig(App::AutoClickControllerConfig config);
			BOOL getIsRunning();

		private:

			BOOL isRunning = FALSE;
			std::thread* _thread = NULL;

		protected:

			App::AutoClickControllerConfig config;
			void run();
	};
}

#endif