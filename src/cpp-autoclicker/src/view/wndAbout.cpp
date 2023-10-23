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

void App::WndAbout::destroy()
{
	App::View::destroy();
	DeleteObject(this->hFontLblTitle);
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
}

void App::WndAbout::onBtnCloseClick()
{
	this->close();
}