#define _CRTDBG_MAP_ALLOC
#ifdef _DEBUG
	#include<iostream>
	#include <crtdbg.h>
	#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
	#define new DEBUG_NEW
#endif

#include "view.h";

#ifndef CLASS_WNDABOUT
#define CLASS_WNDABOUT

#define BTN_CLOSE 0x301

namespace App
{
	class WndAbout : public::App::View
	{
		public:

			WndAbout(HINSTANCE hInstance, HWND hWndParent);
			~WndAbout();

			virtual void reg();
			virtual void createWindow();
			virtual void createControls(HWND hWnd);
			virtual void paint();
			virtual void destroy();

		private:

			HBITMAP imgMouse = NULL;

			HWND hWndLblTitle = NULL;
			HWND hWndLblAuthor = NULL;
			HWND hWndLblLink = NULL;
			HWND hWndbtnClose = NULL;

			HFONT hFontLblTitle = NULL;
			HFONT hFontLblContent = NULL;

		protected:

			HWND hWndParent;

			virtual LRESULT CALLBACK wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
			virtual void onCreateWindow();

			void close();
			void onBtnCloseClick();
	};
}

#endif
