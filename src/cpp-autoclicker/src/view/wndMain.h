#ifndef CLASS_WNDMAIN
#define CLASS_WNDMAIN

#include "view.h";

namespace App
{
	class WndMain : App::View
	{
		public:
			WndMain(HINSTANCE hInstance);
			virtual void reg();
			virtual void createMenu();
			virtual void createWindow();
			virtual void show();
			virtual void update();
			virtual void hide() {};
			virtual void destroy() {};
		private:
			HMENU hMenuHelp;
			HWND hWndGroupBoxConfig;
			HWND hWndGroupBoxShortcut;
			HWND hWndBtnStop;
			HWND hWndBtnStart;
		protected:
			virtual void createControls(HWND parent);
			void openAboutDialog();
			virtual LRESULT CALLBACK wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	};
}

#endif
