/**
 * @file	NTR_OSFamilyWindows.h
 * @brief	Nature windows platform header file
 * @author	Standil (cpascal@cpascal.net)
 *
 * @version	2009/08/19 cpascal - First release
 */

#ifndef _NTR_OSFAMILYWINDOWS_H_
#define _NTR_OSFAMILYWINDOWS_H_

// OSFamily header must define _NTR_DATAMODEL, [_NTR_32BIT or _NTR_64BIT]

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifndef NOMINMAX
#define NOMINMAX
#endif

#define _NTR_LITTLE_ENDIAN			1

#if defined(_WIN32_WCE)
#include "NTR_OSFamilyWindowsCE.h"
#else
#include "NTR_OSFamilyWindowsWin32.h"
#endif

#define _NTR_WINDOWS				1

/* Character set definition */
#if defined( _UNICODE )
#define _NTR_UNICODE				1
#elif !defined( _NTR_UTF8 )
#define _NTR_ASCII					1
#endif

#define _NTR_W64					_W64

#ifdef _WIN64
#define _NTR_WINDOWS64BIT			1
#define _NTR_64BIT					1
#define _NTR_DATAMODEL				_NTR_DATAMODEL_LLP64
#else
#define _NTR_WINDOWS32BIT			1
#define _NTR_32BIT					1
#define _NTR_DATAMODEL				_NTR_DATAMODEL_ILP32
#endif

#if _MSC_VER
#define _NTR_SUPPORTS_PRAGMA_PACK	1
#endif

/* Debug Definition */
#if defined( _DEBUG ) || defined( DEBUG )
#define	_NTR_DEBUG					1
#endif

#define NTR_DECLARE_ULONG(x)				x

// Project Configuration Full strings
#if defined( _NTR_UNICODE )
	#if defined( _MT )
		#if defined( _DLL )
			#define _NTR_MD												1
			#if defined( _NTR_DEBUG )
				#define _NTR_RUNTIME_LIBRARY							"MDd"
				#define _NTR_CONFIGURATION								"WMDd"
				#if defined( _NTR_64BIT )
					#define _NTR_CONFIGURATION_ARCHITECTURE				"WMDdx64"
					#define	_NTR_CONFIGURATION_ARCHITECTURE_FULLSTRING	"Unicode Multi-threaded DLL Debug(x64)"
				#else
					#define _NTR_CONFIGURATION_ARCHITECTURE				"WMDdx86"
					#define	_NTR_CONFIGURATION_ARCHITECTURE_FULLSTRING	"Unicode Multi-threaded DLL Debug(x86)"
				#endif
			#else
				#define _NTR_RUNTIME_LIBRARY							"MD"
				#define _NTR_CONFIGURATION								"WMD"
				#if defined( _NTR_64BIT )
					#define _NTR_CONFIGURATION_ARCHITECTURE				"WMDx64"
					#define	_NTR_CONFIGURATION_ARCHITECTURE_FULLSTRING	"Unicode Multi-threaded DLL(x64)"
				#else
					#define _NTR_CONFIGURATION_ARCHITECTURE				"WMDx86"
					#define	_NTR_CONFIGURATION_ARCHITECTURE_FULLSTRING	"Unicode Multi-threaded DLL(x86)"
				#endif
			#endif
		#else	// _DLL
			#define _NTR_MT												1
			#if defined( _NTR_DEBUG )
				#define _NTR_RUNTIME_LIBRARY							"MTd"
				#define _NTR_CONFIGURATION								"WMTd"
				#if defined( _NTR_64BIT )
					#define _NTR_CONFIGURATION_ARCHITECTURE				"WMTdx64"
					#define	_NTR_CONFIGURATION_ARCHITECTURE_FULLSTRING	"Unicode Multi-threaded Debug(x64)"
				#else
					#define _NTR_CONFIGURATION_ARCHITECTURE				"WMTdx86"
					#define	_NTR_CONFIGURATION_ARCHITECTURE_FULLSTRING	"Unicode Multi-threaded Debug(x86)"
				#endif
			#else
				#define _NTR_RUNTIME_LIBRARY							"MT"
				#define _NTR_CONFIGURATION								"WMT"
				#if defined( _NTR_64BIT )
					#define _NTR_CONFIGURATION_ARCHITECTURE				"WMTx64"
					#define	_NTR_CONFIGURATION_ARCHITECTURE_FULLSTRING	"Unicode Multi-threaded(x64)"
				#else
					#define _NTR_CONFIGURATION_ARCHITECTURE				"WMTx86"
					#define	_NTR_CONFIGURATION_ARCHITECTURE_FULLSTRING	"Unicode Multi-threaded(x86)"
				#endif
			#endif
		#endif	// !_DLL
	#else	// _MT
		#define	_NTR_ST													1
		#if defined( _NTR_DEBUG )
			#define _NTR_RUNTIME_LIBRARY								"STd"
			#define _NTR_CONFIGURATION									"WSTd"
			#if defined( _NTR_64BIT )
				#define _NTR_CONFIGURATION_ARCHITECTURE					"WSTdx64"
				#define	_NTR_CONFIGURATION_ARCHITECTURE_FULLSTRING		"Unicode Single-threaded Debug(x64)"
			#else	// _NTR_64BIT
				#define _NTR_CONFIGURATION_ARCHITECTURE					"WSTdx86"
				#define	_NTR_CONFIGURATION_ARCHITECTURE_FULLSTRING		"Unicode Single-threaded Debug(x86)"
			#endif	// !_NTR_64BIT
		#else	// _NTR_DEBUG
			#define _NTR_RUNTIME_LIBRARY								"ST"
			#define _NTR_CONFIGURATION									"WST"
			#if defined( _NTR_64BIT )
				#define _NTR_CONFIGURATION_ARCHITECTURE					"WSTx64"
				#define	_NTR_CONFIGURATION_ARCHITECTURE_FULLSTRING		"Unicode Single-threaded(x64)"
			#else	// _NTR_64BIT
				#define _NTR_CONFIGURATION_ARCHITECTURE					"WSTx86"
				#define	_NTR_CONFIGURATION_ARCHITECTURE_FULLSTRING		"Unicode Single-threaded(x86)"
			#endif	// !_NTR_64BIT
		#endif	// !_NTR_DEBUG
	#endif	// !_MT
#else	// _NTR_UNICODE
	#if defined( _MT )
		#if defined( _DLL )
			#define _NTR_MD						1
			#if defined( _NTR_DEBUG )
				#define _NTR_RUNTIME_LIBRARY							"MDd"
				#define _NTR_CONFIGURATION								"AMDd"
				#if defined( _NTR_64BIT )
					#define _NTR_CONFIGURATION_ARCHITECTURE				"AMDdx64"
					#define	_NTR_CONFIGURATION_ARCHITECTURE_FULLSTRING	"Multi-byte Multi-threaded DLL Debug(x64)"
				#else
					#define _NTR_CONFIGURATION_ARCHITECTURE				"AMDdx86"
					#define	_NTR_CONFIGURATION_ARCHITECTURE_FULLSTRING	"Multi-byte Multi-threaded DLL Debug(x86)"
				#endif
			#else
				#define _NTR_RUNTIME_LIBRARY							"MD"
				#define _NTR_CONFIGURATION								"AMD"
				#if defined( _NTR_64BIT )
					#define _NTR_CONFIGURATION_ARCHITECTURE				"AMDx64"
					#define	_NTR_CONFIGURATION_ARCHITECTURE_FULLSTRING	"Multi-byte Multi-threaded DLL(x64)"
				#else
					#define _NTR_CONFIGURATION_ARCHITECTURE				"AMDx86"
					#define	_NTR_CONFIGURATION_ARCHITECTURE_FULLSTRING	"Multi-byte Multi-threaded DLL(x86)"
				#endif
			#endif
		#else	// _DLL
			#define _NTR_MT												1
			#if defined( _NTR_DEBUG )
				#define _NTR_RUNTIME_LIBRARY							"MTd"
				#define _NTR_CONFIGURATION								"AMTd"
				#if defined( _NTR_64BIT )
					#define _NTR_CONFIGURATION_ARCHITECTURE				"AMTdx64"
					#define	_NTR_CONFIGURATION_ARCHITECTURE_FULLSTRING	"Multi-byte Multi-threaded Debug(x64)"
				#else
					#define _NTR_CONFIGURATION_ARCHITECTURE				"AMTdx86"
					#define	_NTR_CONFIGURATION_ARCHITECTURE_FULLSTRING	"Multi-byte Multi-threaded Debug(x86)"
				#endif
			#else
				#define _NTR_RUNTIME_LIBRARY							"MT"
				#define _NTR_CONFIGURATION								"AMT"
				#if defined( _NTR_64BIT )
					#define _NTR_CONFIGURATION_ARCHITECTURE				"AMTx64"
					#define	_NTR_CONFIGURATION_ARCHITECTURE_FULLSTRING	"Multi-byte Multi-threaded(x64)"
				#else
					#define _NTR_CONFIGURATION_ARCHITECTURE				"AMTx86"
					#define	_NTR_CONFIGURATION_ARCHITECTURE_FULLSTRING	"Multi-byte Multi-threaded(x86)"
				#endif
			#endif
		#endif	// !_DLL
	#else	// _MT
		#define	_NTR_ST													1
		#if defined( _NTR_DEBUG )
			#define _NTR_RUNTIME_LIBRARY								"STd"
			#define _NTR_CONFIGURATION									"ASTd"
			#if defined( _NTR_64BIT )
				#define _NTR_CONFIGURATION_ARCHITECTURE					"ASTdx64"
				#define	_NTR_CONFIGURATION_ARCHITECTURE_FULLSTRING		"Multi-byte Single-threaded Debug(x64)"
			#else	// _NTR_64BIT
				#define _NTR_CONFIGURATION_ARCHITECTURE					"ASTdx86"
				#define	_NTR_CONFIGURATION_ARCHITECTURE_FULLSTRING		"Multi-byte Single-threaded Debug(x86)"
			#endif	// !_NTR_64BIT
		#else	// _NTR_DEBUG
			#define _NTR_RUNTIME_LIBRARY								"ST"
			#define _NTR_CONFIGURATION									"AST"
			#if defined( _NTR_64BIT )
				#define _NTR_CONFIGURATION_ARCHITECTURE					"ASTx64"
				#define	_NTR_CONFIGURATION_ARCHITECTURE_FULLSTRING		"Multi-byte Single-threaded(x64)"
			#else	// _NTR_64BIT
				#define _NTR_CONFIGURATION_ARCHITECTURE					"ASTx86"
				#define	_NTR_CONFIGURATION_ARCHITECTURE_FULLSTRING		"Multi-byte Single-threaded(x86)"
			#endif	// !_NTR_64BIT
		#endif	// !_NTR_DEBUG
	#endif	// !_MT
#endif	// !_NTR_UNICODE

// Configuraiton for current character set
#if defined( _NTR_UNICODE )
	#define _NTR_LOCALED_CONFIGURATION									L ## _NTR_CONFIGURATION
	#define	_NTR_LOCALED_CONFIGURATION_ARCHITECTURE						L ## _NTR_CONFIGURATION_ARCHITECTURE
	#define	_NTR_LOCALED_CONFIGURATION_ARCHITECTURE_FULLSTRING			L ## _NTR_CONFIGURATION_ARCHITECTURE_FULLSTRING
#else	// _NTR_UNICODE
	#define _NTR_LOCALED_CONFIGURATION									_NTR_CONFIGURATION
	#define	_NTR_LOCALED_CONFIGURATION_ARCHITECTURE						_NTR_CONFIGURATION_ARCHITECTURE
	#define	_NTR_LOCALED_CONFIGURATION_ARCHITECTURE_FULLSTRING			_NTR_CONFIGURATION_ARCHITECTURE_FULLSTRING
#endif	// !_NTR_UNICODE

#ifdef  __cplusplus
extern "C" {
#endif

#ifdef  __cplusplus
}
#endif

#endif /* !_NTR_OSFAMILYWINDOWS_H_ */

