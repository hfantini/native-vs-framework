#define _CRTDBG_MAP_ALLOC
#ifdef _DEBUG
	#include<iostream>
	#include <crtdbg.h>
	#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
	#define new DEBUG_NEW
#endif

#include <string>
#include <windows.h>
#include "win32Helpers.h";

namespace App
{
	std::wstring App::Win32Helpers::getLastErrorMessage()
	{
		std::wstring retValue;
		DWORD errorCode = GetLastError();

		if (errorCode)
		{
			LPWSTR message = nullptr;
			size_t size = FormatMessageW(
				FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
				NULL,
				errorCode,
				MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
				(LPWSTR)& message,
				0,
				NULL
			);

			retValue.append(message);
			LocalFree(message);
		}

		return retValue;
	}
}
