#ifndef _MA_CCOMMANDLINE_H_
#define _MA_CCOMMANDLINE_H_

#define _MA_INTERNAL_CHARSET	_NTR_CHARSET_UNICODE
#include "MA_StringHeader.inl"
#include "MA_CCommandLine.inl"
#include "MA_StringFooter.inl"
#undef _MA_INTERNAL_CHARSET

#define _MA_INTERNAL_CHARSET	_NTR_CHARSET_UTF8
#include "MA_StringHeader.inl"
#include "MA_CCommandLine.inl"
#include "MA_StringFooter.inl"
#undef	_MA_INTERNAL_CHARSET

#define _MA_INTERNAL_CHARSET	_NTR_CHARSET_ASCII
#include "MA_StringHeader.inl"
#include "MA_CCommandLine.inl"
#include "MA_StringFooter.inl"
#undef	_MA_INTERNAL_CHARSET

_MA_NAMESPACE_BEGIN

#if defined( _NTR_UNICODE )
typedef MA_CCommandLineW			MA_CCommandLine;
#elif defined( _NTR_ASCII )
typedef MA_CCommandLineA			MA_CCommandLine;
#else
typedef MA_CCommandLineE			MA_CCommandLine;
#endif

_MA_NAMESPACE_END

#endif /* !_MA_CCOMMANDLINE_H_ */
