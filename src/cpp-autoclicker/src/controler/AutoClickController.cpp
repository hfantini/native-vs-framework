#include <windows.h>
#include <sstream>
#include <iostream>
#include "AutoClickController.h";

App::AutoClickController* App::AutoClickController::_instance = nullptr;

App::AutoClickController::AutoClickController()
{
	App::AutoClickController::_instance = NULL;
}

App::AutoClickController::~AutoClickController()
{
	if (App::AutoClickController::_instance != NULL)
	{
		delete App::AutoClickController::_instance;
	}
}

App::AutoClickController* App::AutoClickController::getInstance()
{
	if (App::AutoClickController::_instance == NULL)
	{
		App::AutoClickController::_instance = new App::AutoClickController();
	}

	return App::AutoClickController::_instance;
}

void App::AutoClickController::start()
{
	if (!this->isRunning)
	{
		this->isRunning = TRUE;
		this->_thread = std::make_unique<std::thread>( [this]() {this->run(); });
	}
}

void App::AutoClickController::stop()
{
	if (this->isRunning)
	{
		this->isRunning = false;
		this->_thread->join();
		this->_thread.reset(nullptr);
	};
}

void App::AutoClickController::run()
{
	while (this->isRunning)
	{
		try
		{
			std::cout << L"Pulando amarelinha...";
		}
		catch (std::exception& e)
		{
			std::stringstream ss = std::stringstream();
			ss << L"An error occured while running auto clicker thread: " << e.what();
			throw std::exception(ss.str().c_str());
		}
	}
}

BOOL App::AutoClickController::getIsRunning()
{
	return this->isRunning;
}