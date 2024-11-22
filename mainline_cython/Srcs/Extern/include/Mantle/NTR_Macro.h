/**
 * @file	NTR_Macro.h
 * @brief	Nature macro header file
 * @author	Standil (cpascal@cpascal.net)
 *
 * @version	2009/08/19 cpascal - First release
 */

#ifndef _NTR_MACRO_H_
#define _NTR_MACRO_H_

/* Macro shorthands for conditional C++ extern block delimiters. */
#if defined( __cplusplus )
#define _NTR_EXTERN_C_BEGIN		extern "C" {
#define	_NTR_EXTERN_C_END		}
#else
#define _NTR_EXTERN_C_BEGIN
#define	_NTR_EXTERN_C_END
#endif

// Argument types
#ifndef IN
#define IN							// input argument type
#endif
#ifndef OUT
#define OUT							// output argument type
#endif
#ifndef INOUT
#define INOUT						// input & output argument type
#endif
#ifndef OPTIONAL
#define OPTIONAL					// optional argument type
#endif

// conversion x to string
#define _NTR_QUOTE(x)				#x
#define NTR_QUOTE(x)				_NTR_QUOTE(x)

// unused
#define	NTR_UNUSED(x)				(x)

// return " full file name(line number) : "
#define NTR__FILE__LINE__			__FILE__ "(" NTR_QUOTE(__LINE__) ") : "

#define NTR_TODO( x )				message( NTR__FILE__LINE__ "TODO : " x )
#define NTR_NOTE( x )				message( "---------------------------------------------------------------------------------------------------------------------------------------------------\n" \
									 "\n" NTR__FILE__LINE__ \
									 "\nNOTE :" x "\n" \
									 "---------------------------------------------------------------------------------------------------------------------------------------------------\n" )

// Inline keyword
#ifdef _NTR_WINDOWS
	#define NTR_INLINE				__inline
	#define NTR_FORCEINLINE			__forceinline
	#define NTR_FASTCALL			__fastcall
#else	// _NTR_WINDOWS
	#define NTR_INLINE				inline
	#define NTR_FORCEINLINE			inline
	#define NTR_FASTCALL
#endif	// !_NTR_WINDOWS

// Array Macro
// The count of the array
#define NTR_COUNTOF(a)				( sizeof(a) / sizeof(a[0]) )

#endif /* !_NTR_MACRO_H_ */
