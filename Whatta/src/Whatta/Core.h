#pragma once

#ifdef WH_PLATFORM_WINDOWS
	#ifdef WH_BUILD_DLL
		#define WHATTA_API _declspec(dllexport)
	#else
		#define WHATTA_API _declspec(dllimport)
	#endif // DEBUG
#else
	#error Whatta only supports Windows!!!
#endif // WH_PLATFORM_WINDOWS

#define BIT(x) (1 << x)
