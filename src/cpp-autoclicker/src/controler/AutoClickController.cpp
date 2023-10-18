#include <windows.h>
#include <sstream>
#include <iostream>
#include <thread>
#include <chrono>
#include "AutoClickController.h";

App::AutoClickController* App::AutoClickController::_instance = nullptr;

App::AutoClickController::AutoClickController()
{
	App::AutoClickController::_instance = NULL;

	this->config = {
		0,
		100
	};
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
	if (!this->getIsRunning())
	{
		this->isRunning = TRUE;
		this->_thread = std::make_unique<std::thread>( [this]() { this->run(); });
	}
}

void App::AutoClickController::stop()
{
	if (this->getIsRunning())
	{
		this->isRunning = FALSE;
		this->_thread->join();
		this->_thread.reset(nullptr);
	};
}

void App::AutoClickController::run()
{
	while (this->getIsRunning())
	{
		try
		{
			OutputDebugStringW(L"Pulando Amarelinha...");
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
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