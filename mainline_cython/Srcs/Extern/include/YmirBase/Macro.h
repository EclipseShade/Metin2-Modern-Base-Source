#pragma once

#define EL_MAX_PATH					512

#define EL_UNUSED(x)	

#define EL_UNUSED_ARG(x)			( (void)(x) )

// conversion x to string
#define _EL_QUOTE(x)				#x
#define EL_QUOTE(x)					_EL_QUOTE(x)

// return " full file name(line number) : "
#define EL__FILE__LINE__				__FILE__ "(" EL_QUOTE(__LINE__) ") : "

// Compiler message
#define EL_NOTE(x) message(	"---------------------------------------------------------------------------------------------------------------------------------------------------\n" \
							"\n" EL__FILE__LINE__ \
							"\nNOTE :" x "\n" \
							"---------------------------------------------------------------------------------------------------------------------------------------------------\n" )

#define EL_TODO(x) message( EL__FILE__LINE__ "TODO : " x )


#define EL_ALLOC(xSize)						malloc( xSize );
#define EL_FREE(xBuffer)					free( xBuffer );

// Safe Deletions
#define EL_SAFE_FREE(p)						{ if( p )					{ free( (void *) p);			(p) = NULL; 		 } }
#define EL_SAFE_FREESTRING(p)				{ if( p )					{ free( (void *) p);			(p) = NULL; 		 } }
#define EL_SAFE_DELETE(p)					{							{ delete (p);					(p) = NULL; 		 } }
#define EL_SAFE_DELETE_EX(p,method)			{ if( p )					{ (p)->method; delete (p);		(p) = NULL; 		 } }
#define EL_SAFE_DELETE_ARRAY(p)				{							{ delete[] (p);					(p) = NULL; 		 } }
#define EL_SAFE_RELEASE(p)					{ if( p )					{ (p)->Release();				(p) = NULL; 		 } }
#define EL_SAFE_SYSFREESTRING(p)			{ if( p )					{ ::SysFreeString(p);			(p) = NULL; 		 } }
#define EL_SAFE_UNMAPVIEWOFFILE(p)			{ if( p )					{ ::UnmapViewOfFile(p);			(p) = NULL; 		 } }
#define EL_SAFE_CLOSEHANDLE(h)				{ if( (h == NULL) || (INVALID_HANDLE_VALUE != h) )	{ ::CloseHandle(h);				(h) = INVALID_HANDLE_VALUE; } }
#define EL_SAFE_CLOSEFINDHANDLE(h)			{ if( INVALID_HANDLE_VALUE != h )	{ ::FindClose(h);				(h) = INVALID_HANDLE_VALUE; } }
#define EL_SAFE_CLOSESOCKET(h)				{ if( INVALID_SOCKET != h )	{ ::closesocket(h);				(h) = INVALID_SOCKET; } }
#define	EL_SAFE_FREELIBRARY(h)				{ if( h )					{ ::FreeLibrary(h);				(h) = NULL;			} }
#define EL_SAFE_DESTROYWINDOW(h)			{ if( h )					{ ::DestroyWindow(h);			(h) = NULL;			} }
#define EL_SAFE_DESTROYMENU(h)				{ if( h )					{ ::DestroyMenu(h);				(h) = NULL;			} }
#define	EL_SAFE_GLOBALFREE(h)				{ if( h )					{ ::GlobalFree(h);				(h) = NULL;			} }
#define EL_SAFE_FCLOSE(x)					{ if( x )					{ fclose(x);					(x) = NULL;			} }

#ifdef _WIN32
	#define EL_SAFE_CLOSEDIRENT(h)			EL_SAFE_CLOSEFINDHANDLE( h );
#else	// _WIN32
	#define EL_SAFE_CLOSEDIRENT(h)			EL_SAFE_DELETE( h );
#endif	// !_WIN32

#if defined(__cplusplus)
template<typename T>
inline T EL_MIN( T tLeft, T tRight )		{ return (tLeft > tRight) ? tRight : tLeft; }

template<typename T>
inline T EL_MAX( T tLeft, T tRight )		{ return (tLeft > tRight) ? tLeft : tRight; }

template<typename T>
inline T EL_MINMAX( T tMin, T tVal, T tMax)	{ if (tMin > tMax) return EL_MAX(tMin, tVal); return EL_MAX(tMin, EL_MIN(tMax, tVal)); }
#endif

// FourCC
#define EL_MAKEFOURCC(ch0, ch1, ch2, ch3) \
                        ((DWORD)(BYTE) (ch0       ) | ((DWORD)(BYTE) (ch1) <<  8) | \
                        ((DWORD)(BYTE) (ch2) << 16) | ((DWORD)(BYTE) (ch3) << 24))
