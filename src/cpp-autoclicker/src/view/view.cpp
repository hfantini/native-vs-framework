#include "windows.h";
#include "view.h";

namespace App
{
	App::View::View(HINSTANCE hInstance, const LPWSTR className)
	{
		this->hInstance = hInstance;
		this->className = std::wstring(className);
		this->hWnd = NULL;
		this->hMenu = NULL;
	}

	std::wstring App::View::getClassName()
	{
		return this->className;
	}

	HINSTANCE App::View::getInstance()
	{
		return this->hInstance;
	}

	HWND App::View::getHandle()
	{
		return this->hWnd;
	}

	LRESULT CALLBACK App::View::staticWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		View* pThis = NULL;

		if (message == WM_NCCREATE)
		{
			LPCREATESTRUCT lpcs = reinterpret_cast<LPCREATESTRUCT>(lParam);
			pThis = static_cast<View*>(lpcs->lpCreateParams);

			SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pThis));
		}
		else
		{
			pThis = reinterpret_cast<View*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
		}

		if (pThis)
		{
			pThis->wndProc(hWnd, message, wParam, lParam);
		}
		else
		{
			return DefWindowProcW(hWnd, message, wParam, lParam);
		}
	}

	LRESULT CALLBACK App::View::wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{
			case WM_CREATE:
				this->createControls(hWnd);
				break;

			case WM_CLOSE:
				PostQuitMessage(0);
				break;

			default:
				return DefWindowProcW(hWnd, message, wParam, lParam);
		}
	}
}