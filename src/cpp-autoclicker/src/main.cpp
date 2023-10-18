#include <sstream>
#include <windows.h>
#include "./helpers/win32Helpers.h";
#include "./view/wndMain.h";

HHOOK keyboardHookId;
std::unique_ptr<App::WndMain> wndMain;

LRESULT CALLBACK hookKeyboardProc(const int code, const WPARAM wParam, const LPARAM lParam)
{
	if (wndMain)
	{
		wndMain->keyboardHookProc(code, wParam, lParam);
	}

	return CallNextHookEx(keyboardHookId, code, wParam, lParam);
}

int run(HINSTANCE instance)
{
	try
	{
		wndMain = std::make_unique<App::WndMain>(instance);
		wndMain->reg();
		wndMain->createMenu();
		wndMain->createWindow();
		wndMain->show();
		wndMain->update();

		// CREATING KEYBOARD HOOK
		keyboardHookId = SetWindowsHookEx(WH_KEYBOARD_LL, hookKeyboardProc, instance, 0);

		MSG message;
		while (GetMessage(&message, NULL, 0, 0) > 0)
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		wndMain->destroy();
		return 0;
	}
	catch (std::exception e)
	{
		std::wstring errorMessage = App::Win32Helpers::getLastErrorMessage();

		std::wstringstream wss;
		wss << L"Fatal Error: " << errorMessage;

		MessageBoxW(NULL, wss.str().c_str(), L"Error!", MB_OK);
		return 1;
	}

	// REMOVING WINDOW HOOK
	if (keyboardHookId)
	{
		UnhookWindowsHookEx(keyboardHookId);
	}
}

int APIENTRY wWinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	PWSTR pCmdLine,
	int cmdShow)
{	
	int retValue = 0;

	try
	{
		run(hInstance);
	}
	catch (int code)
	{
		retValue = code;
	}

	return retValue;
}