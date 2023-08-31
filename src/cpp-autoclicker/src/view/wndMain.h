#ifndef CLASS_WNDMAIN
#define CLASS_WNDMAIN

#include "view.h";

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
		private:
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
		protected:
			virtual void createControls(HWND parent);
			void openAboutDialog();
			virtual LRESULT CALLBACK wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	};
}

#endif
