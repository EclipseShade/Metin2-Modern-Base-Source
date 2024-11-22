/////////////////////////////////////////////////////////////////////////////
// Name:        msvc/wx/msw/setup.h
// Purpose:     wrapper around the real wx/setup.h for Visual C++
// Author:      Vadim Zeitlin
// Modified by:
// Created:     2004-12-12
// RCS-ID:      $Id: setup.h 43687 2006-11-27 15:03:59Z VZ $
// Copyright:   (c) 2004 Vadim Zeitlin <vadim@wxwindows.org>
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

// VC++ IDE predefines _DEBUG and _UNICODE for the new projects itself, but
// the other symbols (WXUSINGDLL, __WXUNIVERSAL__, ...) should be defined
// explicitly!

#ifdef _MSC_VER

#ifndef _RUNTIME_LIBRARY

#if defined( _UNICODE )
#define _RUNTIME_CHARSET				"W"
#else
#define _RUNTIME_CHARSET				"A"
#endif

#if defined( _MT )
	#if defined( _DLL )
		#define _RUNTIME_THREADMODEL	"MD"
	#else
		#define _RUNTIME_THREADMODEL	"MT"
	#endif
#else
	#define _RUNTIME_THREADMODEL		"ST"
#endif

#if defined( _DEBUG ) || defined( DEBUG )
#define _RUNTIME_DEBUG					"d"
#else
#define _RUNTIME_DEBUG					""
#endif

#endif

#if defined( WXUSINGDLL ) || defined( _DLL )
#define	_WX_RUNTIME_DLL					"DLL"
#else
#define	_WX_RUNTIME_DLL					""
#endif
#define _WX_RUNTIME_LIBRARY				_WX_RUNTIME_DLL _RUNTIME_THREADMODEL _RUNTIME_DEBUG
#define _WX_RUNTIME_CONFIGURATION		_WX_RUNTIME_DLL _RUNTIME_CHARSET _RUNTIME_THREADMODEL _RUNTIME_DEBUG

#include "msw/setup.h"

#define WX_LIBNAME		"wx-2.8.10"
#define WX_LIBPREFIX	WX_LIBNAME "_"

#ifndef WX_MANUALLINK
#pragma comment( lib, WX_LIBPREFIX "base" _WX_RUNTIME_CONFIGURATION ".lib" )
#pragma comment( lib, WX_LIBPREFIX "net" _WX_RUNTIME_CONFIGURATION ".lib" )
#pragma comment( lib, WX_LIBPREFIX "xml" _WX_RUNTIME_CONFIGURATION ".lib" )
#if wxUSE_REGEX
    #pragma comment( lib, WX_LIBPREFIX "wxregex" _WX_RUNTIME_CONFIGURATION ".lib" )
#endif

#if wxUSE_GUI
    #if wxUSE_XML
        #pragma comment( lib, WX_LIBPREFIX "wxexpat" _WX_RUNTIME_CONFIGURATION ".lib" )
    #endif
    #if wxUSE_LIBJPEG
        #pragma comment( lib, WX_LIBPREFIX "wxjpeg" _WX_RUNTIME_CONFIGURATION ".lib" )
    #endif
    #if wxUSE_LIBPNG
        #pragma comment( lib, WX_LIBPREFIX "wxpng" _WX_RUNTIME_CONFIGURATION ".lib" )
    #endif
    #if wxUSE_LIBTIFF
        #pragma comment( lib, WX_LIBPREFIX "wxtiff" _WX_RUNTIME_CONFIGURATION ".lib" )
    #endif
    #if wxUSE_ZLIB
        #pragma comment( lib, WX_LIBPREFIX "wxzlib" _WX_RUNTIME_CONFIGURATION ".lib" )
    #endif
    #pragma comment( lib, WX_LIBPREFIX "adv" _WX_RUNTIME_CONFIGURATION ".lib" )
    #pragma comment( lib, WX_LIBPREFIX "core" _WX_RUNTIME_CONFIGURATION ".lib" )
    #pragma comment( lib, WX_LIBPREFIX "html" _WX_RUNTIME_CONFIGURATION ".lib" )
    #if wxUSE_GLCANVAS
        #pragma comment( lib, WX_LIBPREFIX "gl" _WX_RUNTIME_CONFIGURATION ".lib" )
    #endif
    #if wxUSE_DEBUGREPORT
        #pragma comment( lib, WX_LIBPREFIX "qa" _WX_RUNTIME_CONFIGURATION ".lib" )
    #endif
    #if wxUSE_XRC
        #pragma comment( lib, WX_LIBPREFIX "xrc" _WX_RUNTIME_CONFIGURATION ".lib" )
    #endif
    #if wxUSE_AUI
        #pragma comment( lib, WX_LIBPREFIX "aui" _WX_RUNTIME_CONFIGURATION ".lib" )
    #endif
    #if wxUSE_RICHTEXT
        #pragma comment( lib, WX_LIBPREFIX "richtext" _WX_RUNTIME_CONFIGURATION ".lib" )
    #endif
    #if wxUSE_MEDIACTRL
        #pragma comment( lib, WX_LIBPREFIX "media" _WX_RUNTIME_CONFIGURATION ".lib" )
    #endif
    #if wxUSE_ODBC
        #pragma comment( lib, WX_LIBPREFIX "odbc" _WX_RUNTIME_CONFIGURATION ".lib" )
    #endif
#endif // wxUSE_GUI
#endif // !WX_MANUALLINK

#else
    #error "This file should only be included when using Microsoft Visual C++"
#endif

