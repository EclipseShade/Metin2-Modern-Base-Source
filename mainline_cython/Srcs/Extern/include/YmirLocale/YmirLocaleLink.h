#pragma once

#ifndef _EL_RUNTIME_CHARSET
	#if defined( _UNICODE )
		#define _EL_RUNTIME_CHARSET			"W"
	#else
		#define _EL_RUNTIME_CHARSET			"A"
	#endif
#endif

#ifndef _EL_RUNTIME_THREADMODEL
	#if defined( _MT )
		#if defined( _DLL )
			#define _EL_RUNTIME_THREADMODEL	"MD"
		#else
			#define _EL_RUNTIME_THREADMODEL	"MT"
		#endif
	#else
		#define _EL_RUNTIME_THREADMODEL		"ST"
	#endif
#endif

#ifndef _EL_RUNTIME_DEBUG
	#if defined( _DEBUG ) || defined( DEBUG )
		#define _EL_RUNTIME_DEBUG			"d"
	#else
		#define _EL_RUNTIME_DEBUG			""
	#endif
#endif

#if defined( EL_LOCALE_IMPORTS )
	#define _EL_LOCALE_RUNTIME_DLL                                      "DLL"
#else
	#define _EL_LOCALE_RUNTIME_DLL                                      ""
#endif

#define _EL_LOCALE_RUNTIME_LIBRARY			_EL_RUNTIME_CHARSET _EL_RUNTIME_THREADMODEL _EL_RUNTIME_DEBUG
#define _EL_LOCALE_RUNTIME_CONFIGURATION	_EL_LOCALE_RUNTIME_DLL _EL_RUNTIME_THREADMODEL _EL_RUNTIME_DEBUG

#if defined( EL_LOCALE_EXPORTS )
	#error "YmirLocaleLink.h can't be included that is compiling on YmirLocale projects"
#elif defined( EL_LOCALE_IMPORTS )
	#pragma comment( lib, "YmirLocale" _EL_LOCALE_RUNTIME_DLL "MD" _EL_RUNTIME_DEBUG ".lib" )
#else
	#pragma comment( lib, "YmirLocale" _EL_LOCALE_RUNTIME_DLL _EL_LOCALE_RUNTIME_LIBRARY ".lib" )
#endif

#pragma comment(lib, "version.lib")
#pragma comment(lib, "imm32.lib")
#pragma comment(lib, "advapi32.lib")
