#ifndef _MA_LIBLINK_H_
#define _MA_LIBLINK_H_

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

#define _MA_RUNTIME_LIBRARY			_NTR_RUNTIME_CHARSET _NTR_RUNTIME_THREADMODEL _NTR_RUNTIME_DEBUG
#define _MA_RUNTIME_CONFIGURATION	_NTR_RUNTIME_CHARSET _NTR_RUNTIME_THREADMODEL _NTR_RUNTIME_DEBUG

#pragma comment( lib, "Mantle" _MA_RUNTIME_LIBRARY ".lib" )

#endif /* !_MA_LIBLINK_H_ */
