#if _MA_INTERNAL_CHARSET == _NTR_CHARSET_UNICODE
#define	_MA_ITCHAR						MA_WCHAR
#define	_MA_ITLPSTR						MA_PWSTR
#define	_MA_ITLPCSTR					MA_PCWSTR
#define	_MA_IT(x)						L ## x
#define	_MA_ITFUNCTION(func)			func ## W
#define	_MA_ITMACRO(macro)				macro ## W
#define	_MA_ITSTRICTCHECK				MA_SECURE_FILL_STRING_W
#define	_MA_ITEOS						_MA_IT('\0')
#define	_MA_DEFAULT_PATH_DELIMITER		MA_DEFAULT_PATH_DELIMITERW
#define	_MA_ITIsEOS						MA_CharIsEOSW
#define	_MA_ITStringLength				MA_StringLengthW
#define	_MA_ITTEMPLATECLASS( t )		t<MA_WCHAR>
#if __STDC_WANT_SECURE_LIB__ && defined( _NTR_WINDOWS_INTEL )
#define	_MA_ITVSNPRINTF					_vsnwprintf_s
#else
#define	_MA_ITVSNPRINTF					_vsnwprintf
#endif
#elif _MA_INTERNAL_CHARSET == _NTR_CHARSET_UTF8
#define	_MA_ITCHAR						MA_ECHAR
#define	_MA_ITLPSTR						MA_PESTR
#define	_MA_ITLPCSTR					MA_PCESTR
#define	_MA_IT(x)						x
#define	_MA_ITFUNCTION(func)			func##E
#define	_MA_ITMACRO(macro)				macro##E
#define	_MA_ITSTRICTCHECK				MA_SECURE_FILL_STRING_A
#define	_MA_ITEOS						_MA_IT('\0')
#define	_MA_DEFAULT_PATH_DELIMITER		MA_DEFAULT_PATH_DELIMITERA
#define	_MA_ITIsEOS						MA_CharIsEOSE
#define	_MA_ITStringLength				MA_StringLengthE
#define	_MA_ITTEMPLATECLASS( t )		t<MA_ECHAR>
#if __STDC_WANT_SECURE_LIB__ && defined( _NTR_WINDOWS_INTEL )
#define	_MA_ITVSNPRINTF					_vsnprintf_s
#else
#define	_MA_ITVSNPRINTF					_vsnprintf
#endif
#elif _MA_INTERNAL_CHARSET == _NTR_CHARSET_ASCII
#define	_MA_ITCHAR						MA_CHAR
#define	_MA_ITLPSTR						MA_PASTR
#define	_MA_ITLPCSTR					MA_PCASTR
#define	_MA_IT(x)						x
#define	_MA_ITFUNCTION(func)			func##A
#define	_MA_ITMACRO(macro)				macro##A
#define	_MA_ITSTRICTCHECK				MA_SECURE_FILL_STRING_A
#define	_MA_ITEOS						_MA_IT('\0')
#define	_MA_DEFAULT_PATH_DELIMITER		MA_DEFAULT_PATH_DELIMITERA
#define	_MA_ITIsEOS						MA_CharIsEOSA
#define	_MA_ITStringLength				MA_StringLengthA
#define	_MA_ITTEMPLATECLASS( t )		t<MA_ACHAR>
#if __STDC_WANT_SECURE_LIB__ && defined( _NTR_WINDOWS_INTEL )
#define	_MA_ITVSNPRINTF					_vsnprintf_s
#else
#define	_MA_ITVSNPRINTF					_vsnprintf
#endif
#else
#error "_MA_INTERNAL_CHARSET is unknown"
#endif

#ifndef _MA_MY_CHAR
#define	_MA_MY_CHAR( class )			typename _MA_ITTEMPLATECLASS( class )::MY_CHAR
#define	_MA_MY_PSTR( class )			typename _MA_ITTEMPLATECLASS( class )::MY_PSTR
#define	_MA_MY_PCSTR( class )			typename _MA_ITTEMPLATECLASS( class )::MY_PCSTR
#define	_MA_MY_SIZE( class )			typename _MA_ITTEMPLATECLASS( class )::MY_SIZE
#endif
