#pragma once

#ifdef NB_PLATFORM_WINDOWS
	#ifdef NB_BUILD_DLL
		#define NOOB_API __declspec(dllexport)
	#else
		#define NOOB_API __declspec(dllimport)
	#endif
#else
	#error Noob only supports Windows!
#endif

#ifdef NB_ENABLE_ASSERTS
	#define NB_ASSERT(x, ...) {if(!(x)) {NB_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();} }
	#define NB_CORE_ASSERT(x, ...) {if(!(x)) {NB_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
	#define NB_ASSERT(x, ...)
	#define NB_CORE_ASSERT(x, ...)
#endif // NB_ENABLE_ASSERTS

#define BIT(x) (1 << x)