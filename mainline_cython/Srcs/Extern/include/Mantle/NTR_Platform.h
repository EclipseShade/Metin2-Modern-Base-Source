/**
 * @file	NTR_Platform.h
 * @brief	Nature platform header file
 * @author	Standil (cpascal@cpascal.net)
 *
 * @version	2009/08/19 cpascal - First release
 */

#ifndef _NTR_PLATFORM_H_
#define _NTR_PLATFORM_H_

#define _NTR_OSFAMILY_UNIX						1
#define _NTR_OSFAMILY_WINDOWS					2
#define _NTR_OSFAMILY_MACOS						3

#define _NTR_DATAMODEL_LP32						1		/* MS-DOS, Windows 3.1, MacOS */
#define _NTR_DATAMODEL_ILP32					2		/* Windows (32-bit), Unix (32-bit) */
#define _NTR_DATAMODEL_L64						3		/* PS2 */
#define _NTR_DATAMODEL_LP64						4		/* Unix (64-bit) */
#define _NTR_DATAMODEL_ILP64					5		/* (Abandoned ~ '95) */
#define _NTR_DATAMODEL_LLP64					6		/* Windows (64-bit */

// Windows family
#if defined( _WIN32 )
#define _NTR_OSFAMILY	_NTR_OSFAMILY_WINDOWS
#include "NTR_OSFamilyWindows.h"
#endif

// Unix family
#if defined(__FreeBSD__) || defined(linux) || defined(__linux) || defined(__linux__)
#define _NTR_OSFAMILY	_NTR_OSFAMILY_UNIX
#include "NTR_OSFamilyUnix.h"
#endif

/* Mac family */
#if defined( macintosh )
#define _NTR_OSFAMILY	_NTR_OSFAMILY_MACOS
#include "NTR_OSFamilyMacOS.h"
#endif

#if !defined(_NTR_OSFAMILY)
#error "Not supported OS"
#endif

#ifndef _NTR_W64
#define _NTR_W64
#endif

///* Support check */
//#if _MSC_VER || __ICC || _NTR_LINUX
//	#define _NTR_SUPPORTS_PRAGMA_PACK			1
//#else
//	#define _NTR_SUPPORTS_PRAGMA_PACK			0
//#endif

#define _NTR_CHARSET_ASCII						1
#define _NTR_CHARSET_UNICODE					2
#define _NTR_CHARSET_UTF8						3

#if defined( _NTR_UNICODE )
#define _NTR_CHARSET							_NTR_CHARSET_UNICODE
#elif defined( _NTR_ASCII )
#define _NTR_CHARSET							_NTR_CHARSET_ASCII
#elif defined( _NTR_UTF8 )
#define _NTR_CHARSET							_NTR_CHARSET_UTF8
#else
#pragma error "Must define CharacterSet"
#endif

#ifdef _NTR_DEBUG
#define _NTR_ASSERT								1
#endif

#endif /* !_NTR_PLATFORM_H_ */
