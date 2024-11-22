/**
 * @file	EA_Macro.h
 * @brief	Galaxy Macro header file
 * @author	Standil (cpascal@cpascal.net)
 *
 * @version	2008/04/24 cpascal - First release
 */

#ifndef _EA_MACRO_H_
#define _EA_MACRO_H_

#ifdef  __cplusplus
extern "C" {
#endif

#ifndef EXTERN_C
#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C
#endif
#endif // !EXTERN_C

/* Macro shorthands for conditional C++ extern block delimiters. */
#if defined( __cplusplus )
#define _NTR_EXTERN_C_BEGIN		extern "C" {
#define	_NTR_EXTERN_C_END		}
#else
#define _NTR_EXTERN_C_BEGIN
#define	_NTR_EXTERN_C_END
#endif

#if defined( __cplusplus )
	#define	_EA_NAMESPACE_BEGIN		namespace Earth {
	#define _EA_NAMESPACE_END		};
#else
	#define	_EA_NAMESPACE_BEGIN
	#define _EA_NAMESPACE_END
#endif

// Argument types
#define IN				// input argument type
#define OUT				// output argument type
#define INOUT				// input & output argument type
#define OPTIONAL			// optional argument type

// Export and import functions, data, and objects to and from a dll
#define	EA_EXPORT_DLL								__declspec( dllexport )
#define	EA_IMPORT_DLL								__declspec( dllimport )

#define EA_FASTCALL									__fastcall
#define EA_THREADLOCAL								__declspec( thread )

#define EA_SET_ACCESSOR( x, y )							inline void Set##y( x t )				{ m_##y = t; };
#define EA_GET_ACCESSOR( x, y )							inline x Get##y()						{ return m_##y; };
#define EA_GET_SET_ACCESSOR( x, y )						EA_SET_ACCESSOR( x, y ) EA_GET_ACCESSOR( x, y )

#define EA_SETP_ACCESSOR( x, y )						inline void Set##y( x* t )				{ m_##y = *t; };
#define EA_GETP_ACCESSOR( x, y )						inline x* Get##y()						{ return &m_##y; };
#define EA_GETP_SETP_ACCESSOR( x, y )					EA_SETP_ACCESSOR( x, y ) EA_GETP_ACCESSOR( x, y )

#define EA_SET_HUNGARIAN_ACCESSOR( x, y, z )			inline void Set##y( x t )				{ m_##z##y = t; };
#define EA_GET_HUNGARIAN_ACCESSOR( x, y, z )			inline x Get##y()						{ return m_##z##y; };
#define EA_GET_SET_HUNGARIAN_ACCESSOR( x, y, z )		EA_SET_HUNGARIAN_ACCESSOR( x, y, z ) EA_GET_HUNGARIAN_ACCESSOR( x, y, z )

#define EA_SETP_HUNGARIAN_ACCESSOR( x, y, z )			inline void Set##y( x* t )				{ m_##z##y = *t; };
#define EA_GETP_HUNGARIAN_ACCESSOR( x, y, z )			inline x* Get##y()						{ return &m_##z##y; };
#define EA_GETP_SETP_HUNGARIAN_ACCESSOR( x, y, z )		EA_SET_HUNGARIAN_ACCESSOR( x, y, z ) EA_GET_HUNGARIAN_ACCESSOR( x, y, z )

#define EA_SETSZ_HUNGARIAN_ACCESSOR( x )				inline void Set##x( LPCSTR sz##x )		{ strncpy_s( m_sz##x, sz##x, strlen(sz##x) ); };
#define EA_GETSZ_HUNGARIAN_ACCESSOR( x )				inline LPCSTR Get##x()					{ return m_sz##x; };
#define EA_GETSZ_SETSZ_HUNGARIAN_ACCESSOR( x )			EA_SETSZ_HUNGARIAN_ACCESSOR( x ) EA_GETSZ_HUNGARIAN_ACCESSOR( x )

#define EA_SETWSZ_HUNGARIAN_ACCESSOR( x )				inline void Set##x( LPCWSTR wsz##x )	{ _wcsncpy_s( m_wsz##x, wsz##x, wcslen(wsz##x) ); };
#define EA_GETWSZ_HUNGARIAN_ACCESSOR( x )				inline LPCWSTR Get##x()					{ return m_wsz##x; };
#define EA_GETWSZ_SETWSZ_HUNGARIAN_ACCESSOR( x )		EA_SETWSZ_HUNGARIAN_ACCESSOR( x ) EA_GETWSZ_HUNGARIAN_ACCESSOR( x )

#define EA_SETASZ_HUNGARIAN_ACCESSOR( x )				inline void Set##x( LPCSTR asz##x )		{ strncpy_s( m_asz##x, asz##x, strlen(asz##x) ); };
#define EA_GETASZ_HUNGARIAN_ACCESSOR( x )				inline LPCSTR Get##x()					{ return m_asz##x; };
#define EA_GETASZ_SETASZ_HUNGARIAN_ACCESSOR( x )		EA_SETASZ_HUNGARIAN_ACCESSOR( x ) EA_GETASZ_HUNGARIAN_ACCESSOR( x )

#define EA_SETTSZ_HUNGARIAN_ACCESSOR( x )				inline void Set##x( LPCTSTR tsz##x )	{ _tcsncpy_s( m_tsz##x, tsz##x, _tcslen(tsz##x) ); };
#define EA_GETTSZ_HUNGARIAN_ACCESSOR( x )				inline LPCTSTR Get##x()					{ return m_tsz##x; };
#define EA_GETTSZ_SETTSZ_HUNGARIAN_ACCESSOR( x )		EA_SETTSZ_HUNGARIAN_ACCESSOR( x ) EA_GETTSZ_HUNGARIAN_ACCESSOR( x )

#define EA_MIN( LHS, RHS )				( (LHS) < (RHS) ? (LHS) : (RHS) )			/* returns smaller of LHS and RHS. */
#define EA_MAX( LHS, RHS )				( (LHS) > (RHS) ? (LHS) : (RHS) )			/* returns larger of LHS and RHS. */
#define EA_ABS( HS )					( (HS) >= 0 ? (HS) : -(HS) )				/* returns absolute value of HS (|HS|) */
#define EA_SIGN( HS )					( (HS) > 0 ? 1 : ((HS) < 0 ? -1 : 0) )			/* return +1 for HS > 0, -1 for HS < 0 */
#define EA_SWAP( LHS, RHS )				{ (LHS) ^= (RHS); (RHS) ^= (LHS); (LHS) ^= (RHS); }	/* change value LHR and RHS */
#define	EA_ISINRANGE( MIN, MAX, ARG )			( ((MIN) < (ARG)) && ((ARG) < (MAX)) )
#define	EA_ISINRANGE_INC( MIN, MAX, ARG )		( ((MIN) <= (ARG)) && ((ARG) <= (MAX)) )

// conversion x to string
#define _EA_QUOTE(x)					#x
#define EA_QUOTE(x)					_EA_QUOTE(x)

// unused
#define	EA_UNUSED(x)					(x)

// return " full file name(line number) : "
#define EA__FILE__LINE__				__FILE__ "(" EA_QUOTE(__LINE__) ") : "

// Compiler message
#define EA_NOTE( x )					message( "---------------------------------------------------------------------------------------------------------------------------------------------------\n" \
								 "\n" EA__FILE__LINE__ \
								 "\nNOTE :" x "\n" \
								 "---------------------------------------------------------------------------------------------------------------------------------------------------\n" )
#define EA_todo( x )					message( EA__FILE__LINE__ "TODO : " x )
#define EA_TODO( x )					EA_todo( x )

#define EA_CHECK_STRING_BUFFER( pszBuffer, sizeSize )	memset( pszBuffer, 0, (sizeSize + 1) * sizeof(MA_TCHAR) )
#define EA_CHECK_STRING_BUFFERA( pszBuffer, sizeSize )	memset( pszBuffer, 0, sizeSize + 1 )
#define EA_CHECK_STRING_BUFFERW( pszBuffer, sizeSize )	memset( pszBuffer, 0, (sizeSize + 1) * sizeof(MA_WCHAR) )

// Compare with NULL
#define EA_ISNULL(p)					( EA_NULL == (p) )
#define EA_ISNOTNULL(p)					( EA_NULL != (p) )
	
#define EA_LODWORD(i)					((EA_DWORD)(i))
#define EA_HIDWORD(i)					((EA_DWORD)(((u64)(i) >> 32) & 0xFFFFFFFF))

#define	EA_LOWORD(i)					((EA_WORD)((EA_DWORD)(i) & 0xFFFF))
#define	EA_HIWORD(i)					((EA_WORD)((EA_DWORD)(i) >> 16))

#define EA_MAKEFOURCC( c0, c1, c2, c3 )			((u32)(u8)(c0) | ((u32)(u8)(c1) << 8) | ((u32)(u8)(c2) << 16) | ((u32)(u8)(c3) << 24))

#define EA_MAKEU16( a, b )				((u16)(((BYTE)((EA_DWORD_PTR)(a) & 0xff))	| ((u16)((BYTE)((EA_DWORD_PTR)(b) & 0xff))) << 8))
#define EA_MAKEU32( a, b )				((u32)(((WORD)((EA_DWORD_PTR)(a) & 0xFFFF))	| ((DWORD)((WORD)((EA_DWORD_PTR)(b) & 0xFFFF))) << 16))
#define EA_MAKEU64( lo, hi )				((u64)(((DWORD)(lo))				| ((u64)((DWORD)(hi))) << 32))

#define EA_IS_INVALID_HANDLE(h)				( ((h) == EA_INVALID_HANDLE) || ((h) == 0) )
#define EA_IS_INVALID_SOCKET(s)				( EA_INVALID_SOCKET == s )
#define EA_IS_NOT_PENDING(e)				( EA_IO_PENDING != e )
#define EA_IS_NOT_WOULDBLOCK(e)				( EA_SOCKETERROR_WOULDBLOCK != e )
#define EA_IS_NOT_CONNRESET(e)				( EA_SOCKETERROR_CONNRESET != e )

// Inline keyword
#ifdef _NTR_WINDOWS
	#define NTR_INLINE				__inline
	#define NTR_FORCEINLINE				__forceinline
#else	// _NTR_WINDOWS
	#define NTR_INLINE				inline
	#define NTR_FORCEINLINE				inline
#endif	// !_NTR_WINDOWS

// Pointer Conversions
#define EA_HANDLE_TO_U32(h)				((u32)(EA_ULONG_PTR)(h))
#define EA_HANDLE_TO_S32(h)				((s32)(EA_LONG_PTR)(h))
#define EA_U32_TO_HANDLE(ul)				((HANDLE)(EA_ULONG_PTR)(ul))
#define EA_S32_TO_HANDLE(sl)				((HANDLE)(EA_LONG_PTR)(sl))

#define EA_POINTER_TO_U32(p)				((u32)(EA_ULONG_PTR)(p))
#define EA_POINTER_TO_S32(p)				((s32)(EA_LONG_PTR)(p))
#define EA_POINTER_TO_U16(p)				((u16)(EA_ULONG_PTR)(p))
#define EA_POINTER_TO_S16(p)				((s16)(EA_LONG_PTR)(p))
#define EA_S32_TO_POINTER(i)				((LPVOID)(EA_LONG_PTR)((s32)i))
#define EA_U32_TO_POINTER(ui)				((LPVOID)(EA_ULONG_PTR)((u32)ui))
#define EA_S32_TO_POINTER_TYPE(type, i)			((type)(EA_LONG_PTR)((s32)i))
#define EA_U32_TO_POINTER_TYPE(type, ui)		((type)(EA_ULONG_PTR)((u32)ui))

// Safe Deletions
#define EA_SAFE_FREE(p)					{ if( p )			{ free( (void *) p);				(p) = EA_NULL; 		 } }
#define EA_SAFE_FREESTRING(p)				{ if( p )			{ free( (void *) p);				(p) = EA_NULL; 		 } }
#define EA_SAFE_DELETE(p)				{ if( p )			{ delete (p);					(p) = EA_NULL; 		 } }
#define EA_SAFE_DELETE_ARRAY(p)				{ if( p )			{ delete[] (p);					(p) = EA_NULL; 		 } }
#define EA_SAFE_RELEASE(p)				{ if( p )			{ (p)->Release();				(p) = EA_NULL; 		 } }
#define EA_SAFE_FREEHEAP(e,p)				{ if( p )			{ EA_MemoryHeapFree( e, (EA_LPVOID) p );	(p) = EA_NULL; 		 } }
#define EA_SAFE_SYSFREESTRING(p)			{ if( p )			{ ::SysFreeString(p);				(p) = EA_NULL; 		 } }
#define EA_SAFE_CLOSEHANDLE(h)				{ if( EA_INVALID_HANDLE != h )	{ ::CloseHandle(h);				(h) = EA_INVALID_HANDLE; } }
#define EA_SAFE_CLOSEFINDHANDLE(h)			{ if( EA_INVALID_HANDLE != h )	{ ::FindClose(h);				(h) = EA_INVALID_HANDLE; } }
#define EA_SAFE_CLOSESOCKET(h)				{ if( EA_INVALID_SOCKET != h )	{ ::closesocket(h);				(h) = EA_INVALID_SOCKET; } }
#define	EA_SAFE_FREELIBRARY(h)				{ if( h )			{ ::FreeLibrary(h);				(h) = EA_NULL;		 } }
#define EA_SAFE_DESTROYWINDOW(h)			{ if( h )			{ ::DestroyWindow(h);				(h) = EA_NULL;		 } }
#define EA_SAFE_DESTROYMENU(h)				{ if( h )			{ ::DestroyMenu(h);				(h) = EA_NULL;		 } }
#define	EA_SAFE_GLOBALFREE(h)				{ if( h )			{ ::GlobalFree(h);				(h) = EA_NULL;		 } }

#ifdef _NTR_WINDOWS
	#define EA_SAFE_CLOSEDIRENT(h)			EA_SAFE_CLOSEFINDHANDLE( h );
#else	// _NTR_WINDOWS
	#define EA_SAFE_CLOSEDIRENT(h)			EA_SAFE_DELETE( h );
#endif	// !_NTR_WINDOWS

// Array Macro
// The count of the array
#define EA_COUNTOF(a)					( sizeof(a) / sizeof(a[0]) )

#define	EA_OFFSETOF( parent, member )			(EA_DWORD_PTR)(&reinterpret_cast<const volatile char&>( ( ((parent*)EA_NULL)->member ) ))

#define EA_MAKE_ACCESS(type, name)			public: \
								void Set##name( const type& name ) \
								{ \
									m_##name = name; \
								} \
								type Get##name( void ) const \
								{ \
									return m_##name; \
								} \
							protected: \
								type m_##name;

#ifdef _NTR_WINDOWS
	#define EA_WSAGetLastError()		::WSAGetLastError()
	#define EA_GetLastError()		::GetLastError()
	#define EA_SetLastError(dwLastError)	::SetLastError( dwLastError )
#else	// _NTR_WINDOWS
	#define EA_WSAGetLastError()		errno
	#define EA_GetLastError()		errno
	#define EA_SetLastError(dwLastError)	errno=dwLastError
#endif	// !_NTR_WINDOWS

//#ifdef _NTR_WINDOWS
//// MSVC's way of declaring large integer constants
//// If you define these in one step, without the _HELPER macros, you get extra whitespace when composing these with other concatenating macros.
//#define S64_HELPER(x)	x ## i64
//#define S64(x)		S64_HELPER(x)
//#define U64_HELPER(x)	x ## ui64
//#define U64(x)		U64_HELPER(x)
//#else // _MSC_VER
//// GCC's way of declaring large integer constants
//// If you define these in one step, without the _HELPER macros, you get extra whitespace when composing these with other concatenating macros.
//#define S64_HELPER(x)	x ## LL
//#define S64(x)		S64_HELPER(x)
//#define U64_HELPER(x)	x ## ULL
//#define U64(x)		U64_HELPER(x)
//#endif // _MSC_VER

// LPSTR, LPTSTR, LPWSTR
#define UNSET_LPTSTR(x)		EA_SAFE_FREE(x)
#define UNSET_LPSTR(x)		EA_SAFE_FREE(x)
#define UNSET_LPWSTR(x)		EA_SAFE_FREE(x)
#define SET_LPTSTR(x,y)		{ (x) = (LPTSTR) _tcsdup(y);		}
#define SET_LPSTR(x,y)		{ (x) = (LPSTR) _strdup(y);		}
#define SET_LPWSTR(x,y)		{ (x) = (LPWSTR) _wcsdup(y);		}
#define RESET_LPTSTR(x,y)	{ UNSET_LPTSTR(x);	SET_LPTSTR(x,y)	}
#define RESET_LPSTR(x,y)	{ UNSET_LPSTR(x);	SET_LPSTR(x,y);	}
#define RESET_LPWSTR(x,y)	{ UNSET_LPWSTR(x);	SET_LPWSTR(x,y)	}

#if _NTR_ASSERT
#define EA_ASSERT(exp)
#define EA_ASSERTMSG(exp,msg)
//#define EA_ASSERT(exp)		{ if( !(exp) ) { __asm int 3; } }
//#define EA_ASSERTMSG(exp,msg)	{ if( !(exp) ) { __asm int 3; } }
#else
#define EA_ASSERT(exp)
#define EA_ASSERTMSG(exp,msg)
#endif

#ifdef  __cplusplus
}
#endif

#endif /* !_EA_MACRO_H_ */

