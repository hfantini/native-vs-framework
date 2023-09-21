#include "view.h";

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
			virtual void updateControls(HWND parent);
			virtual LRESULT CALLBACK wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
			void onMnuAboutClick();
			void onBtnStartClick();
			void onBtnStopClick();
	};
}

#endif
