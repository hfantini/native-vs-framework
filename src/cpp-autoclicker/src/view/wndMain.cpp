#include <iostream>;
#include <sstream>;
#include "windows.h"
#include "wndMain.h";
#include "../controler/AutoClickController.h";

namespace App
{
	App::WndMain::WndMain(HINSTANCE hInstance) : App::View(hInstance, L"WndMain")
	{

	}

	App::WndMain::~WndMain()
	{
		this->destroy();
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

			AppendMenuW(this->hMenuHelp, MF_STRING, MNU_ABOUT, L"About");
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

	void App::WndMain::destroy()
	{
		DestroyMenu(this->hMenuHelp);
		DestroyWindow(this->hWndGroupBoxConfig);
		DestroyWindow(this->hWndGroupBoxShortcut);
		DestroyWindow(this->hWndBtnStop);
		DestroyWindow(this->hWndBtnStart);
		DestroyWindow(this->hWndLabelShortcutF9);
		DestroyWindow(this->hWndLabelShortcutF10);
		DestroyWindow(this->hWndLabelButton);
		DestroyWindow(this->hWndComboButton);
		DestroyWindow(this->hWndLabelInterval);
		DestroyWindow(this->hWndEditInterval);
		DestroyWindow(this->hWndLabelMS);
		DestroyWindow(this->hWndHorizontalLine);

		App::View::destroy();
	}

	void App::WndMain::createControls(HWND hWnd)
	{
		// == GROUP BOX: Configuration

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

		// == GROUP BOX: Shortcuts

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
			(HINSTANCE) GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
			NULL
		);

		// == BUTTON: Start

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
			(HMENU) BTN_START,
			(HINSTANCE) GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
			NULL
		);
		
		// == BUTTON: Stop

		this->hWndBtnStop = CreateWindowExW(
			0,
			L"BUTTON",
			L"STOP",
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			248,
			168,
			52,
			22,
			hWnd,
			(HMENU)BTN_STOP,
			(HINSTANCE) GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
			NULL
		);

		// == LABEL: Start

		this->hWndLabelShortcutF9 = CreateWindowExW
		(
			NULL,
			L"STATIC",
			L"F9 - Start",
			WS_CHILD | WS_VISIBLE | SS_LEFT | SS_CENTERIMAGE,
			255,
			35,
			80,
			16,
			hWnd,
			NULL,
			(HINSTANCE) GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
			NULL
		);

		// == LABEL: Stop

		this->hWndLabelShortcutF10 = CreateWindowExW
		(
			NULL,
			L"STATIC",
			L"F10 - Stop",
			WS_CHILD | WS_VISIBLE | SS_LEFT | SS_CENTERIMAGE,
			255,
			55,
			80,
			16, 
			hWnd,
			NULL,
			(HINSTANCE) GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
			NULL
		);

		// == LABEL: Button

		this->hWndLabelButton = CreateWindowExW
		(
			NULL,
			L"STATIC",
			L"Button:",
			WS_CHILD | WS_VISIBLE | SS_LEFT | SS_CENTERIMAGE,
			30,
			35,
			80,
			16,
			hWnd,
			NULL,
			(HINSTANCE) GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
			NULL
		);

		// == COMBOBOX: Button

		this->hWndComboButton = CreateWindowExW(
			WS_EX_CLIENTEDGE, 
			L"COMBOBOX",
			L"Button",
			CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,
			30, 
			55, 
			130, 
			22, 
			hWnd, 
			NULL, 
			(HINSTANCE) GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
			NULL);

		// ADDING DEFAULT VALUES

		TCHAR aux[16];
		memset(&aux, 0, sizeof(aux));

		for (int count = 0; count < sizeof(this->cmbButtonValues) / sizeof(this->cmbButtonValues[0]) ; count++)
		{
			strcpy_s(aux, sizeof(aux) / sizeof(TCHAR), (TCHAR*)this->cmbButtonValues[count]);
			SendMessage(this->hWndComboButton, (UINT) CB_ADDSTRING, (WPARAM) 0, (LPARAM) aux);
		}

		// SETTING INITIAL VALUE

		SendMessage(this->hWndComboButton, (UINT) CB_SETCURSEL, (WPARAM) 0, (LPARAM) 0);

		// == LABEL: Interval

		this->hWndLabelInterval = CreateWindowExW
		(
			NULL,
			L"STATIC",
			L"Interval:",
			WS_CHILD | WS_VISIBLE | SS_LEFT | SS_CENTERIMAGE,
			30,
			85,
			80,
			16,
			hWnd,
			NULL,
			(HINSTANCE) GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
			NULL
		);

		// == EDIT: Interval

		this->hWndEditInterval = CreateWindowExW
		(
			WS_EX_CLIENTEDGE | WS_EX_LEFT | WS_EX_LTRREADING,
			L"EDIT",
			L"",
			ES_LEFT | ES_RIGHT | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,
			30,
			105,
			70,
			26,
			hWnd,
			NULL,
			(HINSTANCE) GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
			NULL
		);

		// ADDING DEFAULT VALUE

		SetWindowTextW(this->hWndEditInterval, L"100");

		// == LABEL: Ms

		this->hWndLabelMS = CreateWindowExW
		(
			NULL,
			L"STATIC",
			L"Ms",
			WS_CHILD | WS_VISIBLE | SS_LEFT | SS_CENTERIMAGE,
			107,
			112,
			80,
			16,
			hWnd,
			NULL,
			(HINSTANCE) GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
			NULL
		);

		// == LABEL: Horizontal Line

		this->hWndHorizontalLine = CreateWindowExW
		(
			WS_EX_STATICEDGE,
			L"STATIC",
			L"",
			WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,
			10,
			160,
			348,
			2,
			hWnd,
			NULL,
			(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
			NULL
		);
	}

	void App::WndMain::updateControls(HWND parent)
	{
		if (App::AutoClickController::getInstance()->getIsRunning())
		{
			EnableWindow(this->hWndBtnStart, FALSE);
			EnableWindow(this->hWndBtnStop, TRUE);
		}
		else
		{
			EnableWindow(this->hWndBtnStart, TRUE);
			EnableWindow(this->hWndBtnStop, FALSE);
		}
	}


	LRESULT CALLBACK App::WndMain::wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		OutputDebugStringW(std::to_wstring(message).append(L" ").c_str());
		switch (message)
		{
			case WM_COMMAND:
				if (LOWORD(wParam) == MNU_ABOUT)
				{
					this->onMnuAboutClick();
				}
				else if (LOWORD(wParam) == BTN_START)
				{
					this->onBtnStartClick();
				}
				else if (LOWORD(wParam) == BTN_STOP)
				{
					this->onBtnStopClick();
				}
				break;

			default:
				return View::wndProc(hWnd, message, wParam, lParam);
		}
	}

	void App::WndMain::onMnuAboutClick()
	{
		App::AutoClickController::getInstance()->start();
	}

	void App::WndMain::onBtnStartClick()
	{
		App::AutoClickController::getInstance()->start();
		this->updateControls(this->getHandle());
	}

	void App::WndMain::onBtnStopClick()
	{
		App::AutoClickController::getInstance()->stop();
		this->updateControls(this->getHandle());
	}
}