#define _CRTDBG_MAP_ALLOC
#ifdef _DEBUG
	#include<iostream>
	#include <crtdbg.h>
	#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
	#define new DEBUG_NEW
#endif

#include "wndAbout.h";
#include <sstream>;

App::WndAbout::WndAbout(HINSTANCE hInstance, HWND hWndParent) : App::View(hInstance, L"WndAbout")
{
	this->hWndParent = hWndParent;
}

App::WndAbout::~WndAbout()
{
	this->destroy();
}

void App::WndAbout::reg()
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

void App::WndAbout::createWindow()
{
	if (this->hWnd == NULL)
	{
		const wchar_t* className = this->className.c_str();

		this->hWnd = CreateWindowExW(
			WS_EX_CLIENTEDGE,
			className,
			L"About",
			WS_CAPTION,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			295,
			342,
			this->hWndParent,
			this->hMenu,
			this->getInstance(),
			this
		);
	}
}

void App::WndAbout::createControls(HWND hWnd)
{
	this->hWndLblTitle = CreateWindowExW
	(
		NULL,
		L"STATIC",
		L"Autoclicker V1.0.0",
		WS_CHILD | WS_VISIBLE | SS_CENTER,
		8,
		9,
		265,
		27,
		hWnd,
		NULL,
		(HINSTANCE) GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL
	);

	this->hFontLblTitle = CreateFont
	(
		18,
		0, 
		0, 
		0, 
		FW_DONTCARE, 
		FALSE, 
		FALSE, 
		FALSE, 
		ANSI_CHARSET, 
		OUT_DEFAULT_PRECIS, 
		CLIP_DEFAULT_PRECIS, 
		DEFAULT_QUALITY, 
		DEFAULT_PITCH | FF_SWISS, 
		"Microsoft Sans Serif"
	);

	if (this->hFontLblTitle != NULL)
	{
		SendMessage(this->hWndLblTitle, WM_SETFONT, (WPARAM)this->hFontLblTitle, TRUE);
	}

	this->hWndLblAuthor = this->hWndLblTitle = CreateWindowExW
	(
		NULL,
		L"STATIC",
		L"By Henrique Fantini",
		WS_CHILD | WS_VISIBLE | SS_CENTER,
		5,
		204,
		273,
		20,
		hWnd,
		NULL,
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL
	);

	this->hWndLblLink = this->hWndLblTitle = CreateWindowExW
	(
		NULL,
		L"STATIC",
		L"https://github.com/hfantini/native-vs-framework",
		WS_CHILD | WS_VISIBLE | SS_CENTER,
		5,
		224,
		273,
		20,
		hWnd,
		NULL,
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL
	);

	this->hFontLblContent = CreateFont
	(
		14,
		0,
		0,
		0,
		FW_DONTCARE,
		FALSE,
		FALSE,
		FALSE,
		ANSI_CHARSET,
		OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_SWISS,
		"Microsoft Sans Serif"
	);

	if (this->hFontLblContent != NULL)
	{
		SendMessage(this->hWndLblAuthor, WM_SETFONT, (WPARAM)this->hFontLblContent, TRUE);
		SendMessage(this->hWndLblLink, WM_SETFONT, (WPARAM)this->hFontLblContent, TRUE);
	}

	this->hWndbtnClose = CreateWindowExW
	(
		0,
		L"BUTTON",
		L"CLOSE",
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		92,
		265,
		100,
		27,
		hWnd,
		(HMENU) BTN_CLOSE,
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL
	);
}

void App::WndAbout::paint()
{
	PAINTSTRUCT     ps;
	HDC             hdc;
	BITMAP          bitmap;
	HDC             hdcMem;
	HGDIOBJ         oldBitmap;

	hdc = BeginPaint(hWnd, &ps);

	hdcMem = CreateCompatibleDC(hdc);
	oldBitmap = SelectObject(hdcMem, this->imgMouse);
	
	GetObject(this->imgMouse, sizeof(bitmap), &bitmap);

	BitBlt(hdc, 50, 47, bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY);

	SelectObject(hdcMem, oldBitmap);
	DeleteDC(hdcMem);

	EndPaint(hWnd, &ps);
}

void App::WndAbout::destroy()
{
	DestroyWindow(this->hWndLblTitle);
	DestroyWindow(this->hWndLblAuthor);
	DestroyWindow(this->hWndLblLink);
	DestroyWindow(this->hWndbtnClose);

	DeleteObject(this->hFontLblTitle);
	DeleteObject(this->hFontLblContent);

	DeleteObject(this->imgMouse);

	App::View::destroy();
}

LRESULT CALLBACK App::WndAbout::wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_CREATE:
			EnableWindow(this->hWndParent, FALSE);
			View::wndProc(hWnd, message, wParam, lParam);
			break;

		case WM_CLOSE:
			this->close();
			break;

		case WM_COMMAND:
			if (LOWORD(wParam) == BTN_CLOSE)
			{
				this->onBtnCloseClick();
			}
			break;

		default:
			return View::wndProc(hWnd, message, wParam, lParam);
	}
}

void App::WndAbout::close()
{
	CloseWindow(this->hWnd);
	EnableWindow(this->hWndParent, TRUE);
	UpdateWindow(this->hWndParent);
}

void App::WndAbout::onCreateWindow()
{
	this->imgMouse = (HBITMAP)LoadImageW
	(
		this->getInstance(),
		L"./res/images/mouse.bmp",
		IMAGE_BITMAP,
		0,
		0,
		LR_LOADFROMFILE
	);
}

void App::WndAbout::onBtnCloseClick()
{
	this->close();
}