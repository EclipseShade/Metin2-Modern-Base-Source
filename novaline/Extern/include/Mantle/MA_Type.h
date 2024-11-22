/**
 * @file	MA_Type.h
 * @brief	Mantle type definitions
 * @author	Standil (cpascal@cpascal.net)
 *
 * @version	2009/08/19 cpascal - First release
 */

#ifndef _MA_TYPE_H_
#define _MA_TYPE_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cpluscplus */

typedef signed char			MA_S8;
typedef unsigned char		MA_U8;
typedef signed short		MA_S16;
typedef unsigned short		MA_U16;
typedef signed int			MA_S32;
typedef unsigned int		MA_U32;
#ifdef _NTR_WINDOWS
typedef signed __int64		MA_S64;
typedef unsigned __int64	MA_U64;
#else /* _SN_WINDOWS */
typedef signed long long	MA_S64;
typedef unsigned long long	MA_U64;
#endif /* !_SN_WINDOWS */
typedef float				MA_F32;		// 32-bit floating point type
typedef double				MA_F64;		// 64-bit floating point type

typedef char				MA_CHAR;					// 8-bit signed type
typedef	MA_CHAR				MA_ACHAR;					// 8-bit signed type
typedef wchar_t				MA_WCHAR;					// 16-bit unicode type
typedef size_t				MA_SIZE;
typedef MA_S64				MA_FSIZE;
//typedef unsigned int		MA_SIZE;					// size type for string (32-bit)

#if defined( _NTR_UNICODE )
	typedef MA_WCHAR		MA_TCHAR; 
#else  
	typedef MA_CHAR			MA_TCHAR; 
#endif

typedef MA_TCHAR			*MA_PTSTR, *MA_LPTSTR;
typedef	const MA_TCHAR		*MA_PCTSTR, *MA_LPCTSTR;
typedef unsigned char		MA_UTF8;					// UTF-8 character
typedef unsigned short		MA_UTF16;					// UTF-16 character
typedef unsigned int		MA_UTF32;					// UTF-32 character

// MultiByte (A/MB)
typedef	MA_CHAR				*MA_PSTR,	*MA_LPSTR;
typedef	const MA_CHAR		*MA_PCSTR,	*MA_LPCSTR;
typedef	MA_ACHAR			*MA_PASTR,	*MA_LPASTR;
typedef	const MA_CHAR		*MA_PCASTR,	*MA_LPCASTR;

// ASCII (N/NS)
typedef	MA_CHAR				*MA_PNSTR,	*MA_LPNSTR;
typedef	const MA_CHAR		*MA_PCNSTR,	*MA_LPCNSTR;

// UTF-8 (U/UC)
typedef MA_UTF8				MA_ECHAR;
typedef	MA_UTF8				*MA_PESTR,	*MA_LPESTR;
typedef	const MA_UTF8		*MA_PCESTR,	*MA_LPCESTR;

// UTF-16 (W/WC)
typedef	MA_WCHAR			*MA_PWSTR,	*MA_LPWSTR;
typedef	const MA_WCHAR		*MA_PCWSTR,	*MA_LPCWSTR;

// UTF-32 (D/DW)
typedef	MA_UTF32			*MA_PDSTR,	*MA_LPDSTR;
typedef	const MA_UTF32		*MA_PCDSTR,	*MA_LPCDSTR;

typedef int					MA_BOOL;
typedef MA_BOOL				*MA_PBOOL;

typedef MA_U8				MA_BYTE;	// 8-bit unsigned type
typedef MA_S16				MA_SHORT;	// 16-bit signed type
typedef MA_U16				MA_USHORT;	// 16-bit unsigned type
typedef MA_U16				MA_WORD;	// 16-bit unsigned type
typedef MA_S32				MA_INT;		// 32-bit signed type
typedef MA_U32				MA_UINT;	// 32-bit unsigned type
typedef MA_U32				MA_DWORD;	// 32-bit unsigned type
typedef MA_S64				MA_LONG;	// long signed type
typedef MA_U64				MA_ULONG;	// long unsigned type
typedef MA_U64				MA_QWORD;	// 64-bit unsigned type
typedef MA_F32				MA_FLOAT;	// 32-bit floating point type
typedef MA_F64				MA_DOUBLE;	// 64-bit floating point type
typedef void				MA_VOID;

typedef	MA_BYTE				*MA_PBYTE,	*MA_LPBYTE;
typedef	MA_WORD				*MA_PWORD,	*MA_LPWORD;
typedef	MA_DWORD			*MA_PDWORD,	*MA_LPDWORD;
typedef	MA_QWORD			*MA_PQWORD,	*MA_LPQWORD;
typedef MA_VOID				*MA_PVOID, *MA_LPVOID;
typedef const MA_BYTE		*MA_PCBYTE, *MA_LPCBYTE;
typedef const MA_WORD		*MA_PCWORD, *MA_LPCWORD;
typedef const MA_DWORD		*MA_PCDWORD, *MA_LPCDWORD;
typedef const MA_PVOID		MA_PCVOID;

typedef unsigned char		MA_XBYTE;

typedef int					MA_XINT;
typedef unsigned int		MA_XUINT;

#ifdef _NTR_WINDOWS
typedef signed __int64		MA_XLONG;
typedef unsigned __int64	MA_XULONG;
typedef HANDLE			MA_HANDLE;
#else /* _NTR_WINDOWS */
typedef signed long long	MA_XLONG;
typedef unsigned long long	MA_XULONG;
typedef int			MA_HANDLE;
#endif /* !_NTR_WINDOWS */

#ifdef __cplusplus
};
#endif /* __cplusplus */

#endif /* !_MA_TYPE_H_ */
