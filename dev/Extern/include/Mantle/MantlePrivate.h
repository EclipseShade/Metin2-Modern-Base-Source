/**
 * @file	Mantle.h
 * @brief	Mantle String library (Divided from Earth library)
 * @author	Standil (cpascal@cpascal.net)
 *
 * @version	2009/08/19 cpascal - First release
 */

#ifndef _MANTLEPRIVATE_H_
#define _MANTLEPRIVATE_H_

#include "Mantle.h"

#define MA_NULL							0
#define MA_FALSE						0
#define MA_TRUE							1

#define MA_ISNULL(p)					( MA_NULL == (p) )
#define MA_ISNOTNULL(p)					( MA_NULL != (p) )

#define MA_XMIN( LHS, RHS )				( (LHS) < (RHS) ? (LHS) : (RHS) )						/* returns smaller of LHS and RHS. */
#define MA_XMAX( LHS, RHS )				( (LHS) > (RHS) ? (LHS) : (RHS) )						/* returns larger of LHS and RHS. */
#define MA_SWAP( LHS, RHS )				{ (LHS) ^= (RHS); (RHS) ^= (LHS); (LHS) ^= (RHS); }		/* change value LHR and RHS */

#ifdef _NTR_WINDOWS
	#define MA_CHAR_MAX					SCHAR_MIN
	#define MA_UCHAR_MAX				UCHAR_MAX
	#define MA_XSHORT_MAX				SHRT_MIN
	#define MA_XUSHORT_MAX				USHRT_MAX
	#define MA_WCHAR_MAX				USHRT_MAX
	#define MA_XINT_MAX					INT_MAX
	#define MA_XUINT_MAX				UINT_MAX
	#define MA_XLONG_MAX				LLONG_MAX
	#define MA_XULONG_MAX				ULLONG_MAX
#else
	#define MA_CHAR_MAX					127
	#define MA_UCHAR_MAX				0xFF
	#define MA_XSHORT_MAX				32767
	#define MA_XUSHORT_MAX				0xFFFF
	#define MA_WCHAR_MAX				0xFFFF
	#define MA_XINT_MAX					2147483647L
	#define MA_XUINT_MAX				0xFFFFFFFF
	#define MA_XLONG_MAX				9223372036854775807LL
	#define MA_XULONG_MAX				0xFFFFFFFFFFFFFFFFULL
#endif

#define MA_CHAR_MIN						(-MA_CHAR_MAX - 1)
#define MA_UCHAR_MIN					0
#define MA_WCHAR_MIN					0
#define MA_XSHORT_MIN					(-MA_XSHORT_MAX - 1)
#define MA_XUSHORT_MIN					0
#define MA_XINT_MIN						(-MA_XINT_MAX - 1)
#define MA_XUINT_MIN					MA_XUINT_MIN
#define MA_XLONG_MIN					(-MA_XLONG_MAX - 1)
#define MA_XULONG_MIN					0
//#define MA_WORD_MAX						MA_USHORT_MAX
//#define	MA_WORD_MIN						MA_USHORT_MIN
//#define MA_DWORD_MAX					MA_UINT_MAX
//#define MA_DWORD_MIN					MA_UINT_MIN
//#define MA_QWORD_MAX					0
//#define MA_QWORD_MIN					MA_ULONGLONG_MAX


#endif /* !_MANTLEPRIVATE_H_ */
