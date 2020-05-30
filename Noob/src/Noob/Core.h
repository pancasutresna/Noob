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