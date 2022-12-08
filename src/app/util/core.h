#pragma once

// Os specific
//========================================================================
//Linuxand Linux - derived          __linux__
//Android                           __ANDROID__(implies __linux__)
//Linux(non - Android)              __linux__ && !__ANDROID__
//Darwin(Mac OS X and iOS)          __APPLE__
//Akaros(http://akaros.org)         __ros__
//Windows                           _WIN32
//Windows 64 bit                    _WIN64(implies _WIN32)
//NaCL                              __native_client__
//AsmJS                             __asmjs__
//Fuschia                           __Fuchsia__
//========================================================================

// Compiler specific
#if defined _MSVC_LANG || defined _MSC_VER
#	define FORCEINLINE __forceinline
#elif defined __GNUC__
	__atribute__((always_inline))
#	define FORCEINLINE 
#elif __clang__
	__atribute__((always_inline))
#	define FORCEINLINE 
#endif

#if defined SFML_VERSION_MAJOR | defined SFML_VERSION_MINOR
#	define VZ_SFML
#endif

#if defined IMGUI_API
#	define VZ_IMGUI
#endif

#define CONCAT_TEXT3(begin, text, end)	begin##text##end
#define CONCAT_TEXT2(val1, val2)		val1##val2
#define TOSTR(val)						#val

#if defined _DEBUG || !defined NDEBUG
#	define DO_IN_DEBUG(things) things
#	define DEBUG_OR_RELEASE(deb, rel)	deb
#	define VASSERT(cond, str)		assert(cond && str)
#include <iostream>

	template<typename... Arg>
	void Print(const Arg&... args)
	{
		// TODO : Add forward declaration
		((std::cout << args << ' '), ...);

		std::cout << '\n' << std::flush;
	}

#	define DEBUG_PRINT(...)				Print("[DEBUG] --",__VA_ARGS__)
#	define DEBUG_PRINTH(header, ...)	DEBUG_PRINT(CONCAT_TEXT3("[[", header, "]]"),__VA_ARGS__)
#	define DEBUG_PARAM_END(...)			,__VA_ARGS__
#	define DEBUG_PARAM_START(...)		__VA_ARGS__,
#else
#	define DO_IN_DEBUG(things)
#	define DEBUG_OR_RELEASE(deb, rel)	rel
#	define DEBUG_PRINT(...)	
#	define DEBUG_PRINTH(header, ...)	
#	define DEBUG_PARAM_END(...)			
#	define DEBUG_PARAM_START(...)		
#	define VASSERT(cond, str)		cond
#endif
