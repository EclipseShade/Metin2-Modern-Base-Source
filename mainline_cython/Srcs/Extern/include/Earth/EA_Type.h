#ifndef _EA_TYPE_H_
#define _EA_TYPE_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cpluscplus */

typedef signed char			s8;
typedef unsigned char		u8;
typedef signed short		s16;
typedef unsigned short		u16;
typedef signed int			s32;
typedef unsigned int		u32;

#ifdef _NTR_WINDOWS
typedef signed __int64		s64;
typedef unsigned __int64	u64;
typedef SSIZE_T				EA_SSIZE;	// ssize_t type
#else /* _SN_WINDOWS */
typedef signed long long	s64;
typedef unsigned long long	u64;
typedef ssize_t				EA_SSIZE;	// ssize_t type
#endif /* !_SN_WINDOWS */

typedef float				f32;		// 32-bit floating point type
typedef double				f64;		// 64-bit floating point type

typedef u8				EA_UCHAR;	// 8-bit unsigned type
typedef u8				EA_BYTE;	// 8-bit unsigned type
typedef s16				EA_SHORT;	// 16-bit signed type
typedef u16				EA_USHORT;	// 16-bit unsigned type
typedef u16				EA_WORD;	// 16-bit unsigned type
typedef s32				EA_INT;		// 32-bit signed type
typedef u32				EA_UINT;	// 32-bit unsigned type
typedef u32				EA_DWORD;	// 32-bit unsigned type
typedef s64				EA_LONG;	// long signed type
typedef u64				EA_ULONG;	// long unsigned type
typedef u64				EA_QWORD;	// 64-bit unsigned type
typedef f32				EA_FLOAT;	// 32-bit floating point type
typedef f64				EA_DOUBLE;	// 64-bit floating point type

typedef u32				EA_SIZE32;
typedef u64				EA_SIZE64;
typedef size_t			EA_SIZE;	// size_t type
//typedef errno_t		EA_ERRNO_T;	// errno_t type
typedef u32				EA_INDEX_T;	// index_t type
typedef unsigned int	EA_BOOL;	// 32-bit 

typedef	EA_BYTE			*EA_PBYTE,	*EA_LPBYTE;
typedef	EA_DWORD		*EA_PDWORD,	*EA_LPDWORD;
typedef	EA_QWORD		*EA_PQWORD,	*EA_LPQWORD;
typedef void			EA_VOID,	*EA_PVOID, *EA_LPVOID;
typedef const EA_PVOID	EA_PCVOID;

/* Define system types */
#ifdef _NTR_WINDOWS
typedef HANDLE			EA_THREAD_HANDLE;
typedef HANDLE			EA_DIRENT_HANDLE;
#else	// _NTR_WINDOWS
typedef pthread_t		EA_THREAD_HANDLE;
typedef DIR*			EA_DIRENT_HANDLE;	// or void*
#endif	// !_NTR_WINDOWS

#ifdef _NTR_STRICT
	typedef void *EA_HANDLE;
	//#define EA_DECLARE_HANDLE(name) struct name##__ { int unused; }; typedef struct name##__ *name
	#define EA_DECLARE_HANDLE(name) typedef struct name##__ { int unused; } *name
#else
	typedef void* EA_HANDLE;
	#define EA_DECLARE_HANDLE(name) typedef HANDLE name
#endif

#if defined(_NTR_WINDOWS)
typedef HMODULE			EA_HMODULE;
#endif
typedef EA_HANDLE		*EA_PHANDLE;
typedef	EA_INT			EA_RESULT;

// Time-related
#ifdef _NTR_WINDOWS
#include <time.h>
typedef FILETIME		EA_FILETIME, *EA_PFILETIME, *EA_LPFILETIME;
typedef SYSTEMTIME		EA_SYSTEMTIME, *EA_PSYSTEMTIME, *EA_LPSYSTEMTIME;
#ifdef _USE_32BIT_TIME_T
	#define	LocalTime	LocalTime32
	#define	EA_TIME_T	__time32_t
#else
	#define	LocalTime	LocalTime64
	#define	EA_TIME_T	__time64_t
#endif
#else
#include <sys/time.h>
typedef struct _EA_FILETIME {
	EA_DWORD dwLowDateTime;
	EA_DWORD dwHighDateTime;
} EA_FILETIME, *EA_PFILETIME, *EA_LPFILETIME;

typedef struct _EA_SYSTEMTIME {
	EA_WORD wYear;
	EA_WORD wMonth;
	EA_WORD wDayOfWeek;
	EA_WORD wDay;
	EA_WORD wHour;
	EA_WORD wMinute;
	EA_WORD wSecond;
	EA_WORD wMilliseconds;
} EA_SYSTEMTIME, *EA_PSYSTEMTIME, *EA_LPSYSTEMTIME;
#define	LocalTime		LocalTime32
#define	EA_TIME_T		__time32_t
#endif

#define	EA_INTERFACE		struct

#ifdef __cplusplus
};
#endif /* __cplusplus */

#endif /* !_EA_TYPE_H_ */
