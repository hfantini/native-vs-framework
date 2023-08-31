#include <iostream>;
#include <sstream>;
#include "windows.h"
#include "wndMain.h";

namespace App
{
	App::WndMain::WndMain(HINSTANCE hInstance) : App::View(hInstance, L"WndMain")
	{

	}

	void App::WndMain::reg()
	{
		const wchar_t* className = this->className.c_str();

		if (GetClassInfoW(this->getInstance(), className, NULL) == NULL)
		{
			WNDCLASSEXW wc;
			wc.cbSize = sizeof(WNDCLASSEXW);
			wc.style = 0;
			wc.lpfnWndProc = this->staticWndProc;
			wc.cbClsExtra = 0;
			wc.cbWndExtra = 0;
			wc.hInstance = this->hInstance;
			wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
			wc.hCursor = LoadCursor(NULL, IDC_ARROW);
			wc.hbrBackground = (HBRUSH)(COLOR_WINDOW);
			wc.lpszMenuName = NULL;
			wc.lpszClassName = className;
			wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

			if (!RegisterClassExW(&wc))
			{
				std::stringstream ss = std::stringstream();
				ss << L"An error occured while registering class: " << className;
				throw std::exception(ss.str().c_str());
			}
		}
	}

	void App::WndMain::createMenu()
	{
		if (this->hMenu == NULL)
		{
			this->hMenu = CreateMenu();
			this->hMenuHelp = CreateMenu();

			AppendMenuW(this->hMenuHelp, MF_STRING, 100, L"About");
			AppendMenuW(this->hMenu, MF_POPUP, (UINT_PTR)this->hMenuHelp, L"Help");
		}
	}

	void App::WndMain::createWindow()
	{
		if (this->hWnd == NULL)
		{
			const wchar_t* className = this->className.c_str();

			this->hWnd = CreateWindowExW(
				WS_EX_CLIENTEDGE,
				className,
				L"HF - Autoclicker",
				WS_OVERLAPPED | WS_SYSMENU,
				CW_USEDEFAULT,
				CW_USEDEFAULT,
				389,
				262,
				NULL,
				this->hMenu,
				this->getInstance(),
				this
			);
		}
	}

	void App::WndMain::show()
	{
		if (this->hWnd)
		{
			ShowWindow(this->hWnd, SW_NORMAL);
		}
	}

	void App::WndMain::update()
	{
		if (this->hWnd)
		{
			UpdateWindow(this->hWnd);
		}
	}

	void App::WndMain::openAboutDialog()
	{

	}

	void App::WndMain::createControls(HWND hWnd)
	{
		this->hWndGroupBoxConfig = CreateWindowExW(
			0,
			L"BUTTON", 
			L"Configuration",
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_GROUPBOX,
			10,
			10,
			226,
			131,
			hWnd,
			NULL,
			(HINSTANCE) GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
			NULL
		);

		this->hWndGroupBoxShortcut = CreateWindowExW(
			0,
			L"BUTTON",
			L"Shortcuts",
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_GROUPBOX,
			241,
			10,
			118,
			131,
			hWnd,
			NULL,
			(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
			NULL
		);

		this->hWndBtnStart = CreateWindowExW(
			0,
			L"BUTTON",
			L"START",
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			307,
			168,
			52,
			22,
			hWnd,
			NULL,
			(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
			NULL
		);

		this->hWndBtnStart = CreateWindowExW(
			0,
			L"BUTTON",
			L"STOP",
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			248,
			168,
			52,
			22,
			hWnd,
			NULL,
			(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
			NULL
		);
	}

	LRESULT CALLBACK App::WndMain::wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{
			case WM_COMMAND:
				
				if (HIWORD(wParam) == 0)
				{
					// MENU COMMANDS

					if (LOWORD(wParam) == 100)
					{
						this->openAboutDialog();
					}
				}

				break;

			default:
				return View::wndProc(hWnd, message, wParam, lParam);
		}
	}
}