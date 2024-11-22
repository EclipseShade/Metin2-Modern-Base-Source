#pragma once

#define EL_TRUE				true
#define EL_FALSE			false

typedef bool				EL_BOOL;
typedef unsigned int		EL_ENUM;
typedef unsigned int		EL_BITS;

typedef int					EL_INT;		// 크기가 중요하지 않는 정수
typedef unsigned int		EL_UINT;	// 크기가 중요하지 않는 크기수
typedef float				EL_FLOAT;	// 크기가 중요하지 않는 부동소숫점

typedef char				EL_INT8;
typedef unsigned char		EL_UINT8;

typedef short				EL_INT16;
typedef unsigned short		EL_UINT16;

typedef int					EL_INT32;
typedef unsigned int		EL_UINT32;

typedef __int64				EL_INT64;
typedef unsigned __int64	EL_UINT64;

typedef float				EL_FLOAT32;
typedef double				EL_FLOAT64;

typedef void			EL_VOID;
typedef void*			EL_VOID_P;
typedef const void*		EL_C_VOID_P;

typedef char			EL_ACHAR;
typedef EL_ACHAR*		EL_ACHAR_P;
typedef const EL_ACHAR*	EL_C_ACHAR_P;

typedef wchar_t			EL_WCHAR;
typedef EL_WCHAR*		EL_WCHAR_P;
typedef const EL_WCHAR*	EL_C_WCHAR_P;

typedef unsigned char	EL_ECHAR; // EL_ACHAR 와 구분하기 위해 unsigned 사용
typedef EL_ECHAR*		EL_ECHAR_P;
typedef const EL_ECHAR*	EL_C_ECHAR_P;

#ifdef _UNICODE
typedef EL_WCHAR		EL_TCHAR;
typedef EL_WCHAR*		EL_TCHAR_P;
typedef const EL_WCHAR*	EL_C_TCHAR_P;
#else
typedef EL_ACHAR		EL_TCHAR;
typedef EL_ACHAR*		EL_TCHAR_P;
typedef const EL_ACHAR*	EL_C_TCHAR_P;
#endif

typedef EL_INT8				EL_BYTE;
typedef EL_INT8*			EL_BYTE_P;
typedef const EL_INT8*		EL_C_BYTE_P;

typedef EL_UINT8			EL_UBYTE;
typedef EL_UINT8*			EL_UBYTE_P;
typedef const EL_UINT8*		EL_C_UBYTE_P;

typedef EL_INT16			EL_SHORT;
typedef EL_INT16*			EL_SHORT_P;
typedef const EL_INT16*		EL_C_SHORT_P;

typedef EL_UINT16			EL_USHORT;
typedef EL_UINT16*			EL_USHORT_P;
typedef const EL_UINT16*	EL_C_USHORT_P;

typedef EL_INT32			EL_LONG;
typedef EL_INT32*			EL_LONG_P;
typedef const EL_INT32*		EL_C_LONG_P;

typedef EL_UINT32			EL_ULONG;
typedef EL_UINT32*			EL_ULONG_P;
typedef const EL_UINT32*	EL_C_ULONG_P;

typedef size_t				EL_SIZE;

typedef EL_UINT32			EL_VFS_SIZE_T;

struct EL_BGRA
{
	EL_BITS b:8;
	EL_BITS g:8;
	EL_BITS r:8;
	EL_BITS a:8;
};

struct EL_RGBA
{
	EL_BITS r:8;
	EL_BITS g:8;
	EL_BITS b:8;
	EL_BITS a:8;
};

struct EL_ARGB
{
	EL_BITS a:8;
	EL_BITS r:8;
	EL_BITS g:8;
	EL_BITS b:8;
};

#define EL_TEXTA(s)		EL_ACHAR_P(s)
#define EL_TEXTE(s)		EL_ECHAR_P(s)
#define EL_TEXTW(s)		EL_WCHAR_P(L ## s)

#ifdef _UNICODE
#define EL_TTEXT		EL_TEXTW
#else
#define EL_TTEXT		EL_TEXTA
#endif

#define EL_TEXT			EL_TTEXT

#define EL_FORCEINLINE	__forceinline
