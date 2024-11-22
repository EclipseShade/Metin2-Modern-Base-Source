/**
 * @file	EA_Constant.h
 * @brief	Galaxy constants header
 * @author	Standil (cpascal@cpascal.net)
 *
 * @version	2008/04/24 cpascal - First release
 */

#ifndef _EA_CONSTANT_H_
#define _EA_CONSTANT_H_

#define EA_VOID				void
#define EA_NULL				0
#define EA_FALSE			0
#define EA_TRUE				1

#define EA_INVALID_INDEX64		0xFFFFFFFFFFFFFFFFUL
#define EA_INVALID_INDEX32		0xFFFFFFFF
#define GL_INVALID_INDEX16		0xFFFF
#define GL_INVALID_INDEX8		0xFF

#ifdef _NTR_WINDOWS
	#define EA_INVALID_SOCKET			INVALID_SOCKET
	#define EA_INVALID_HANDLE			INVALID_HANDLE_VALUE
	#define EA_INVALID_DIRENT			INVALID_HANDLE_VALUE
	#define EA_INVALID_FILE_ATTRIBUTES		INVALID_FILE_ATTRIBUTES
	#define EA_INVALID_FILE_SIZE			INVALID_FILE_SIZE
	#define EA_INVALID_SET_FILE_POINTER		INVALID_SET_FILE_POINTER

	#define EA_SOCKET_ERROR				SOCKET_ERROR
	#define EA_WSA_FLAG_OVERLAPPED			WSA_FLAG_OVERLAPPED

	#define EA_RESULT_NOT_ENOUGH_MEMORY		ERROR_NOT_ENOUGH_MEMORY
	#define EA_RESULT_SHARING_VIOLATION		ERROR_SHARING_VIOLATION
	#define EA_RESULT_FILE_EXISTS			ERROR_FILE_EXISTS
	#define EA_RESULT_ALREADY_EXISTS		ERROR_ALREADY_EXISTS
	#define EA_RESULT_PATH_NOT_FOUND		ERROR_PATH_NOT_FOUND

	#define EA_IO_PENDING				ERROR_IO_PENDING
	#define EA_SOCKETERROR_WOULDBLOCK		WSAEWOULDBLOCK
	#define EA_SOCKETERROR_CONNRESET		WSAECONNRESET
#else
	#define EA_INVALID_SOCKET			(-1)
	#define EA_INVALID_HANDLE			(-1)
	#define EA_INVALID_DIRENT			NULL
	#define EA_INVALID_FILE_ATTRIBUTES		(-1)
	#define EA_INVALID_FILE_SIZE			(-1)
	#define EA_INVALID_SET_FILE_POINTER		(-1)

	#define EA_SOCKET_ERROR				(-1)
	#define EA_WSA_FLAG_OVERLAPPED			(-1)

	#define EA_RESULT_NOT_ENOUGH_MEMORY		ENOMEM
	#define EA_RESULT_SHARING_VIOLATION		EACCES
	#define EA_RESULT_FILE_EXISTS			EEXIST
	#define EA_RESULT_ALREADY_EXISTS		EEXIST
	#define EA_RESULT_PATH_NOT_FOUND		ENOENT

	#define EA_IO_PENDING				EINTR
	#define EA_SOCKETERROR_WOULDBLOCK		EWOULDBLOCK
	#define EA_SOCKETERROR_CONNRESET		ECONNRESET
#endif

#define	EA_S8_BIT_COUNT			8
#define	EA_S16_BIT_COUNT		16
#define	EA_S32_BIT_COUNT		32
#define	EA_S64_BIT_COUNT		64

#define	EA_U8_BIT_COUNT			EA_S8_BIT_COUNT
#define	EA_U16_BIT_COUNT		EA_S16_BIT_COUNT
#define	EA_U32_BIT_COUNT		EA_S32_BIT_COUNT
#define	EA_U64_BIT_COUNT		EA_S64_BIT_COUNT

// --------------------------------------------
// Constant of characters
// --------------------------------------------
#define	EA_EOS_A			'\0'		// Multibyte end-of-string
#define	EA_EOS_W			L'\0'		// UTF-16 end-of-string
#define	EA_EOS_UTF8			'\0'		// UTF-8 end-of-string
#define	EA_EOS_T			_T('\0')	// TCHAR end-of-string
// ASTERISK
#define	EA_ASTERISK_A			'*'		// Multibyte Asterisk
#define	EA_ASTERISK_W			L'*'		// UTF-16 Asterisk
#define	EA_ASTERISK_UTF8		'*'		// UTF-8 Asterisk
#define	EA_ASTERISK_T			_T('*')		// TCHAR Asterisk
// CR(Carrage Return)
#define	EA_CR_A				'\r'		// Multibyte carrage return
#define	EA_CR_W				L'\r'		// UTF-16 carrage return
#define	EA_CR_UTF8			'\r'		// UTF-8 carrage return
#define	EA_CR_T				_T('\r')	// TCHAR carrage return
// LF(Line Feed)
#define	EA_LF_A				'\n'		// Multibyte line feed
#define	EA_LF_W				L'\n'		// UTF-16 line feed
#define	EA_LF_UTF8			'\n'		// UTF-8 line feed
#define	EA_LF_T				_T('\n')	// TCHAR line feed
// CR String(Carrage Return String)
#define	EA_CR_STR			"\r"		// Multibyte carrage return
#define	EA_CR_WSTR			L"\r"		// UTF-16 carrage return
#define	EA_CR_USTR			"\r"		// UTF-8 carrage return
#define	EA_CR_TSTR			_T("\r")	// TCHAR carrage return
// LF String(Line Feed String)
#define	EA_LF_STR			"\n"		// Multibyte line feed
#define	EA_LF_WSTR			L"\n"		// UTF-16 line feed
#define	EA_LF_USTR			"\n"		// UTF-8 line feed
#define	EA_LF_TSTR			_T("\n")	// TCHAR line feed
// CR & LF(Carrage Return And Line Feed)
#define	EA_CRLF_STR			"\r\n"		// Multibyte carrage return and line feed
#define	EA_CRLF_WSTR			L"\r\n"		// UTF-16 carrage return and line feed
#define	EA_CRLF_USTR			"\r\n"		// UTF-8 carrage return and line feed
#define	EA_CRLF_TSTR			_T("\r\n")	// TCHAR carrage return and line feed
// LF & CR(Line Feed And Carrage Return)
#define	EA_LFCR_STR			"\n\r"		// Multibyte line feed and carrage return
#define	EA_LFCR_WSTR			L"\n\r"		// UTF-16 line feed and carrage return
#define	EA_LFCR_USTR			"\n\r"		// UTF-8 line feed and carrage return
#define	EA_LFCR_TSTR			_T("\n\r")	// TCHAR line feed and carrage return

#ifdef _NTR_WINDOWS
	#define EA_CHAR_MAX		SCHAR_MIN
	#define EA_UCHAR_MAX		UCHAR_MAX
	#define EA_SHORT_MAX		SHRT_MIN
	#define EA_USHORT_MAX		USHRT_MAX
	#define EA_WCHAR_MAX		USHRT_MAX
	#define EA_INT_MAX		INT_MAX
	#define EA_UINT_MAX		UINT_MAX
	#define EA_LONGLONG_MAX		LLONG_MAX
	#define EA_ULONGLONG_MAX	ULLONG_MAX
#else
	#define EA_CHAR_MAX		127
	#define EA_UCHAR_MAX		0xFF
	#define EA_SHORT_MAX		32767
	#define EA_USHORT_MAX		0xFFFF
	#define EA_WCHAR_MAX		0xFFFF
	#define EA_INT_MAX		2147483647L
	#define EA_UINT_MAX		0xFFFFFFFF
	#define EA_LONGLONG_MAX		9223372036854775807i64
	#define EA_ULONGLONG_MAX	0xFFFFFFFFFFFFFFFFUi64
#endif

#define EA_CHAR_MIN			(-EA_CHAR_MAX - 1)
#define EA_UCHAR_MIN			0
#define EA_SHORT_MIN			(-EA_SHORT_MAX - 1)
#define EA_USHORT_MIN			0
#define EA_WCHAR_MIN			0
#define EA_INT_MIN			0
#define EA_UINT_MIN			EA_UINT_MIN
#define EA_LONGLONG_MIN			(-EA_LONGLONG_MAX - 1)
#define EA_ULONGLONG_MIN		0
#define EA_WORD_MAX			EA_USHORT_MAX
#define	EA_WORD_MIN			EA_USHORT_MIN
#define EA_DWORD_MAX			EA_UINT_MAX
#define EA_DWORD_MIN			EA_UINT_MIN
#define EA_QWORD_MAX			0
#define EA_QWORD_MIN			EA_ULONGLONG_MAX

#define EA_FLOAT_PRECISION		10
#define EA_DOUBLE_PRECISION		20

#define	EA_RESULT_INVALID_ARGUMENT	-2
#define	EA_RESULT_FAIL			-1
#define	EA_RESULT_OK			0

#define EA_INVALID_INDEX		-1
#define EA_INVALID_INDEX_T		(EA_INDEX_T)(~0)
#define EA_INVALID_SIZE_T		(EA_SIZE)(~0)
#define EA_NOT_FOUND			(EA_SIZE)(~0)

#ifdef _NTR_WINDOWS
	#define EA_TLS_OUTOFINDEXES	TLS_OUT_OF_INDEXES
#else
	#define EA_TLS_OUTOFINDEXES	0xFFFFFFFF
#endif

#endif // !_EA_CONSTANT_H_

