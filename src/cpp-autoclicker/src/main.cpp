#include <sstream>
#include <windows.h>
#include "./helpers/win32Helpers.h";
#include "./view/wndMain.h";

std::unique_ptr<App::WndMain> wndMain;

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

		MSG message;
		while (GetMessage(&message, NULL, 0, 0) > 0)
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}

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