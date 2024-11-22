/**
 * @file	MA_Macro.h
 * @brief	Mantle macro definitions
 * @author	Standil (cpascal@cpascal.net)
 *
 * @version	2009/08/19 cpascal - First release
 */

#ifndef _MA_MACRO_H_
#define _MA_MACRO_H_

#if defined( __cplusplus )
	#define	_MA_NAMESPACE_BEGIN		namespace Mantle {
	#define _MA_NAMESPACE_END		};
#else
	#define	_MA_NAMESPACE_BEGIN
	#define _MA_NAMESPACE_END
#endif

#define MA_W(x)						L ## x
#define MA_A(x)						x
#define MA_E(x)						(MA_LPCESTR) x
#if _NTR_UNICODE
#define MA_T(x)						MA_W(x)
#else
#define MA_T(x)						MA_A(x)
#endif

#define MA_ALLOC(xSize)						malloc( xSize )
#define MA_FREE(xBuffer)					free( xBuffer )

#define MA_SAFE_FREE(p)						{ if( p )					{ free( (void *) p);			(p) = NULL; 		 } }
#define MA_SAFE_FREESTRING(p)				{ if( p )					{ free( (void *) p);			(p) = NULL; 		 } }
#define MA_SAFE_DELETE(p)					{ if( p )					{ delete (p);					(p) = NULL; 		 } }
#define MA_SAFE_DELETE_ARRAY(p)				{ if( p )					{ delete[] (p);					(p) = NULL; 		 } }
#define MA_SAFE_RELEASE(p)					{ if( p )					{ (p)->Release();				(p) = NULL; 		 } }
#define MA_SAFE_CLOSEHANDLE(h)				{ if( MA_INVALID_HANDLE != h )	{ ::CloseHandle(h);				(h) = MA_INVALID_HANDLE; } }
#define MA_SAFE_CLOSEFINDHANDLE(h)			{ if( MA_INVALID_HANDLE != h )	{ ::FindClose(h);				(h) = MA_INVALID_HANDLE; } }
#define MA_SAFE_CLOSESOCKET(h)				{ if( MA_INVALID_SOCKET != h )	{ ::closesocket(h);				(h) = MA_INVALID_SOCKET; } }
#define	MA_SAFE_FREELIBRARY(h)				{ if( h )			{ ::FreeLibrary(h);				(h) = MA_NULL;		 } }
#define MA_SAFE_DESTROYWINDOW(h)			{ if( h )			{ ::DestroyWindow(h);				(h) = MA_NULL;		 } }
#define MA_SAFE_DESTROYMENU(h)				{ if( h )			{ ::DestroyMenu(h);				(h) = MA_NULL;		 } }
#define	MA_SAFE_GLOBALFREE(h)				{ if( h )			{ ::GlobalFree(h);				(h) = MA_NULL;		 } }

#if defined(_countof)
#define MA_ARRAYCOUNT(x)			_countof(x)
#else
#define MA_ARRAYCOUNT(x)			(sizeof(x)/sizeof(x[0]))
#endif

#if _NTR_ASSERT
#define MA_ASSERT(exp)
#define MA_ASSERTMSG(exp,msg)
#else
#define MA_ASSERT(exp)
#define MS_ASSERTMSG(exp,msg)
#endif

#if defined( __cplusplus )
template <typename T>
const T& MA_MIN( const T& tLHS, const T& tRHS )
{
	return (tLHS < tRHS) ? tLHS : tRHS;
}

template <typename T>
const T& MA_MAX( const T& tLHS, const T& tRHS )
{
	return (tLHS > tRHS) ? tLHS : tRHS;
}

template <typename T>
void MA_SWAP( T& tLHS, T& tRHS )
{
	T tTMP = tLHS;
	tLHS = tRHS;
	tRHS = tTMP;
}
#endif

#endif /* !_MA_MACRO_H_ */
