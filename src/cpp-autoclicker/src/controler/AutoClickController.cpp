#include <windows.h>
#include <sstream>
#include <iostream>
#include <thread>
#include <chrono>
#include "AutoClickController.h";

App::AutoClickController::AutoClickController()
{
	this->config = {
		0,
		100
	};
}

App::AutoClickController::~AutoClickController()
{
	this->stop();
}

void App::AutoClickController::start()
{
	if (!this->getIsRunning())
	{
		this->isRunning = TRUE;
		this->_thread = new std::thread( [this]() { this->run(); });
	}
}

void App::AutoClickController::stop()
{
	if (this->getIsRunning())
	{
		this->isRunning = FALSE;

		if (this->_thread->joinable())
		{
			this->_thread->join();
		}

		if (this->_thread != NULL)
		{
			delete this->_thread;
			this->_thread = NULL;
		}
	};
}

void App::AutoClickController::run()
{
	while (this->getIsRunning())
	{
		try
		{
			// CLICK

			POINT cursor;
			
			if (GetCursorPos(&cursor))
			{
				DWORD action = 0;

				if (this->getConfig().button == 0)
				{
					action = MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP;
				}
				else if (this->getConfig().button == 1)
				{
					action = MOUSEEVENTF_MIDDLEDOWN | MOUSEEVENTF_MIDDLEUP;
				}
				else if (this->getConfig().button == 2)
				{
					action = MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP;
				}

				mouse_event(action, cursor.x, cursor.y, 0, 0);
			}
			
			// INTERVAL

			std::this_thread::sleep_for(std::chrono::milliseconds(this->getConfig().interval));
		}
		catch (std::exception& e)
		{
			std::stringstream ss = std::stringstream();
			ss << L"An error occured while running auto clicker thread: " << e.what();
			throw std::exception(ss.str().c_str());
		}
	}
}

App::AutoClickControllerConfig App::AutoClickController::getConfig()
{
	App::AutoClickControllerConfig retValue = this->config;
	return retValue;
}

void App::AutoClickController::setConfig(App::AutoClickControllerConfig config)
{
	if (config.button < 0 || config.button > 2)
	{
		return;
	}

	if (config.interval < 0 || config.interval > 999999)
	{
		return;
	}

	this->config = config;
}

BOOL App::AutoClickController::getIsRunning()
{
	return this->isRunning;
}