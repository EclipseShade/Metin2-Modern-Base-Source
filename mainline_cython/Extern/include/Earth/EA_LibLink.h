#ifndef _EA_LIBLINK_H_
#define _EA_LIBLINK_H_

#include <Mantle/MA_LibLink.h>

#ifndef _NTR_RUNTIME_CHARSET
	#if defined( _UNICODE )
		#define _NTR_RUNTIME_CHARSET			"W"
	#else
		#define _NTR_RUNTIME_CHARSET			"A"
	#endif
#endif

#ifndef _NTR_RUNTIME_THREADMODEL
	#if defined( _MT )
		#if defined( _DLL )
			#define _NTR_RUNTIME_THREADMODEL	"MD"
		#else
			#define _NTR_RUNTIME_THREADMODEL	"MT"
		#endif
	#else
		#define _NTR_RUNTIME_THREADMODEL		"ST"
	#endif
#endif

#ifndef _NTR_RUNTIME_DEBUG
	#if defined( _DEBUG ) || defined( DEBUG )
		#define _NTR_RUNTIME_DEBUG			"d"
	#else
		#define _NTR_RUNTIME_DEBUG			""
	#endif
#endif

#define _EA_RUNTIME_LIBRARY			_NTR_RUNTIME_CHARSET _NTR_RUNTIME_THREADMODEL _NTR_RUNTIME_DEBUG
#define _EA_RUNTIME_CONFIGURATION	_NTR_RUNTIME_CHARSET _NTR_RUNTIME_THREADMODEL _NTR_RUNTIME_DEBUG

#pragma comment( lib, "Earth" _EA_RUNTIME_LIBRARY ".lib" )

#include <Mantle/MA_LibLink.h>

#endif /* !_EA_LIBLINK_H_ */
