#pragma once

#include <Mantle/MA_LibLink.h>
#include <minilzo-2.03/minilzoLibLink.h>

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

#if defined( EL_BASE_IMPORTS )
	#define _EL_BASE_RUNTIME_DLL            "DLL"
#else
	#define _EL_BASE_RUNTIME_DLL            ""
#endif

#ifndef _EL_RUNTIME_LIBRARY
#define _EL_RUNTIME_LIBRARY			_EL_RUNTIME_THREADMODEL _EL_RUNTIME_DEBUG
#endif
#ifndef _EL_RUNTIME_CONFIGURATION
#define _EL_RUNTIME_CONFIGURATION	_EL_LOCALE_RUNTIME_DLL _EL_RUNTIME_THREADMODEL _EL_RUNTIME_DEBUG
#endif

#if defined( EL_BASE_EXPORTS )
	#error "YmirBaseLink.h can't be included that is compiling on YmirBase projects"
#elif defined( EL_BASE_IMPORTS )
	#pragma comment( lib, "YmirBase" _EL_BASE_RUNTIME_DLL _EL_RUNTIME_CHARSET "MD" _EL_RUNTIME_DEBUG ".lib" )
#else
	#pragma comment( lib, "YmirBase" _EL_BASE_RUNTIME_DLL _EL_RUNTIME_CHARSET _EL_RUNTIME_LIBRARY ".lib" )
#endif

