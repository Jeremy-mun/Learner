#pragma once

#ifdef PLATFORM_WINDOWS
	#ifdef BUILD_DLL
		#define API __declspec(dllexport)
	#else
		#define API __declspec(dllimport)
	#endif
#else
	#error Only Supports Windows!
#endif