#define _CRTDBG_MAP_ALLOC
#ifdef _DEBUG
	#include<iostream>
	#include <crtdbg.h>
	#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
	#define new DEBUG_NEW
#endif

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
			~View();
			virtual void reg() {};
			virtual void createMenu() {};
			virtual void createWindow() {};
			virtual void paint() {};
			virtual void show();
			virtual void update();
			virtual void hide();
			virtual void destroy();
			std::wstring getClassName();
			HINSTANCE getInstance();
			HWND getHandle();
		private:
		protected:
			std::wstring className;
			HMENU hMenu;
			HINSTANCE hInstance;
			HWND hWnd;

			virtual void onCreateWindow() {};
			virtual void createControls(HWND parent) {};
			virtual void updateControls(HWND parent) {};

			virtual LRESULT CALLBACK wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
			static LRESULT CALLBACK staticWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	};
}

#endif