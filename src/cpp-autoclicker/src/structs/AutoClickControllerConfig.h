#define _CRTDBG_MAP_ALLOC
#ifdef _DEBUG
	#include<iostream>
	#include <crtdbg.h>
	#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
	#define new DEBUG_NEW
#endif

#ifndef STRUCT_AUTOCLICKCONTROLLERCONFIG
#define STRUCT_AUTOCLICKCONTROLLERCONFIG

namespace App
{
	struct AutoClickControllerConfig
	{
		int button;
		int interval;
	};
}

#endif
