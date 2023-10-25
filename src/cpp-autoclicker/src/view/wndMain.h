#define _CRTDBG_MAP_ALLOC
#ifdef _DEBUG
	#include<iostream>
	#include <crtdbg.h>
	#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
	#define new DEBUG_NEW
#endif

#include "view.h";
#include "wndAbout.h";
#include "../controler/AutoClickController.h";
#include "../structs/AutoClickControllerConfig.h";

#define MNU_ABOUT 0x100
#define BTN_START 0x200
#define BTN_STOP 0x201

#ifndef CLASS_WNDMAIN
#define CLASS_WNDMAIN

namespace App
{
	class WndMain : public App::View
	{
		public:
			WndMain(HINSTANCE hInstance);
			~WndMain();

			virtual void reg();
			virtual void createMenu();
			virtual void createWindow();
			virtual void destroy();
			void keyboardHookProc(int nCode, WPARAM wParam, LPARAM lParam);

		private:

			HICON hIcon = NULL;
			HMENU hMenuHelp = NULL;
			HWND hWndGroupBoxConfig = NULL;
			HWND hWndGroupBoxShortcut = NULL;
			HWND hWndBtnStop = NULL;
			HWND hWndBtnStart = NULL;
			HWND hWndLabelShortcutF9 = NULL;
			HWND hWndLabelShortcutF10 = NULL;
			HWND hWndLabelButton = NULL;
			HWND hWndComboButton = NULL;
			HWND hWndLabelInterval = NULL;
			HWND hWndEditInterval = NULL;
			HWND hWndLabelMS = NULL;
			HWND hWndHorizontalLine = NULL;

			TCHAR cmbButtonValues[3][10] =
			{
				"LEFT",
				"MIDDLE",
				"RIGHT"
			};

		protected:

			App::AutoClickController* controller = NULL;
			WndAbout* wndAbout;

			virtual void createControls(HWND parent);
			virtual void updateControls(HWND parent);
			virtual LRESULT CALLBACK wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
			App::AutoClickControllerConfig createControllerConfig();
			void onMnuAboutClick();
			void onBtnStartClick();
			void onBtnStopClick();
	};
}

#endif
