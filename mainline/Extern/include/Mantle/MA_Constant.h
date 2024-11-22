/**
 * @file	MA_Type.h
 * @brief	Mantle Constants
 * @author	Standil (cpascal@cpascal.net)
 *
 * @version	2009/08/19 cpascal - First release
 */

#ifndef _MA_CONSTANT_H_
#define _MA_CONSTANT_H_

#define MA_VOID				void
#define MA_NULL				0
#define MA_FALSE			0
#define MA_TRUE				1

// --------------------------------------------
// Constant of characters
// --------------------------------------------
#define	MA_EOS_A			'\0'		// Multibyte end-of-string
#define	MA_EOS_W			L'\0'		// UTF-16 end-of-string
#define	MA_EOS_UTF8			'\0'		// UTF-8 end-of-string
#define	MA_EOS_T			_T('\0')	// TCHAR end-of-string
// ASTERISK
#define	MA_ASTERISK_A		'*'		// Multibyte Asterisk
#define	MA_ASTERISK_W		L'*'		// UTF-16 Asterisk
#define	MA_ASTERISK_UTF8	'*'		// UTF-8 Asterisk
#define	MA_ASTERISK_T		_T('*')		// TCHAR Asterisk
// CR(Carrage Return)
#define	MA_CR_A				'\r'		// Multibyte carrage return
#define	MA_CR_W				L'\r'		// UTF-16 carrage return
#define	MA_CR_UTF8			'\r'		// UTF-8 carrage return
#define	MA_CR_T				_T('\r')	// TCHAR carrage return
// LF(Line Feed)
#define	MA_LF_A				'\n'		// Multibyte line feed
#define	MA_LF_W				L'\n'		// UTF-16 line feed
#define	MA_LF_UTF8			'\n'		// UTF-8 line feed
#define	MA_LF_T				_T('\n')	// TCHAR line feed
// CR String(Carrage Return String)
#define	MA_CR_STR			"\r"		// Multibyte carrage return
#define	MA_CR_WSTR			L"\r"		// UTF-16 carrage return
#define	MA_CR_USTR			"\r"		// UTF-8 carrage return
#define	MA_CR_TSTR			_T("\r")	// TCHAR carrage return
// LF String(Line Feed String)
#define	MA_LF_STR			"\n"		// Multibyte line feed
#define	MA_LF_WSTR			L"\n"		// UTF-16 line feed
#define	MA_LF_USTR			"\n"		// UTF-8 line feed
#define	MA_LF_TSTR			_T("\n")	// TCHAR line feed
// CR & LF(Carrage Return And Line Feed)
#define	MA_CRLF_STR			"\r\n"		// Multibyte carrage return and line feed
#define	MA_CRLF_WSTR		L"\r\n"		// UTF-16 carrage return and line feed
#define	MA_CRLF_USTR		"\r\n"		// UTF-8 carrage return and line feed
#define	MA_CRLF_TSTR		_T("\r\n")	// TCHAR carrage return and line feed
// LF & CR(Line Feed And Carrage Return)
#define	MA_LFCR_STR			"\n\r"		// Multibyte line feed and carrage return
#define	MA_LFCR_WSTR		L"\n\r"		// UTF-16 line feed and carrage return
#define	MA_LFCR_USTR		"\n\r"		// UTF-8 line feed and carrage return
#define	MA_LFCR_TSTR		_T("\n\r")	// TCHAR line feed and carrage return

#define MA_INVALID_SIZE		(MA_SIZE)(~0)
#define MA_INVALID_FILESIZE	(MA_FSIZE)(-1LL)
#define MA_MAX_PATH			512

#ifdef _NTR_WINDOWS
	#define MA_INVALID_SOCKET			INVALID_SOCKET
	#define MA_INVALID_HANDLE			INVALID_HANDLE_VALUE
#else
	#define MA_INVALID_SOCKET			(-1)
	#define MA_INVALID_HANDLE			(-1)
#endif

#endif // !_MA_CONSTANT_H_
