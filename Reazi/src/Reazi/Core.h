#pragma once

#ifdef RZ_PLATFORM_WINDOWS
	#ifdef RZ_BUILD_DLL
		#define REAZI_API _declspec(dllexport)
	#else
		#define REAZI_API _declspec(dllimport)
	#endif

#else
	#error Reazi only support Windaube (yep, that's sad)
#endif

#ifdef RZ_ENABLE_ASSERTS
#define RZ_ASSERT(x, ...) { if(!(x)) { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define HZ_CORE_ASSERT(x, ...) { if(!(x)) { HZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define RZ_ASSERT(x, ...)
#define RZ_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)