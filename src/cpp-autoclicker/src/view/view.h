#include <string>
#include <windows.h>
#include <memory>

#ifndef CLASS_VIEW
#define CLASS_VIEW

namespace App
{
	class View
	{
		public:
			View(HINSTANCE hInstance, const LPWSTR className);
			virtual void reg() {};
			virtual void createMenu() {};
			virtual void createWindow() {};
			virtual void show() {};
			virtual void update() {};
			virtual void hide() {};
			virtual void destroy() {};
			std::wstring getClassName();
			HINSTANCE getInstance();
			HWND getHandle();
		private:
		protected:
			virtual void createControls(HWND parent) {};
			static LRESULT CALLBACK staticWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
			virtual LRESULT CALLBACK wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
			std::wstring className;
			HMENU hMenu;
			HINSTANCE hInstance;
			HWND hWnd;
	};
}

#endif