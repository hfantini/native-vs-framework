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
			virtual void destroy();

		private:

			HWND hWndLblTitle = NULL;
			HFONT hFontLblTitle = NULL;
			HWND hWndbtnClose = NULL;

		protected:

			HWND hWndParent;

			virtual LRESULT CALLBACK wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

			void close();
			void onBtnCloseClick();
	};
}

#endif
