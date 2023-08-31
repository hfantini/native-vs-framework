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