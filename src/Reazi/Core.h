#pragma once

#ifdef RZ_PLATFORM_WINDOWS
	#ifdef HZ_BUILD_DLL
		#define REAZI_API _declspec(dllexport)
	#else
		#define REAZI_API _declspec(dllimport)
	#endif

#else
	#error Reazi only support Windaube (yep, that's sad)
#endif