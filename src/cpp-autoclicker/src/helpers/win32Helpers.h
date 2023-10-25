#define _CRTDBG_MAP_ALLOC
#ifdef _DEBUG
	#include<iostream>
	#include <crtdbg.h>
	#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
	#define new DEBUG_NEW
#endif

#include <string>
#include <windows.h>

#ifndef CLASS_WIN32HELPERS
#define CLASS_WIN32HELPERS

namespace App
{
	class Win32Helpers
	{
		public:
			static std::wstring getLastErrorMessage();
		private:
		protected:
	};
}

#endif