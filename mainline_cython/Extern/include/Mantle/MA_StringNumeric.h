#ifndef	_MA_STRINGNUMERIC_H_
#define	_MA_STRINGNUMERIC_H_

#include "MA_Character.h"

#define MA_MAX_32BIT_DEC						10+1+1				// 2^32, sign, null character
#define MA_MAX_64BIT_DEC						20+1+1				// 2^64, sign, null character

_NTR_EXTERN_C_BEGIN

#if defined( _NTR_UNICODE )
#define	MA_Int32ToRadixString				MA_Int32ToRadixStringW
#define	MA_UInt32ToRadixString				MA_UInt32ToRadixStringW
#define	MA_Int64ToRadixString				MA_Int64ToRadixStringW
#define	MA_UInt64ToRadixString				MA_UInt64ToRadixStringW
#define	MA_RadixStringToInt32				MA_RadixStringToInt32W
#define	MA_RadixStringToUInt32				MA_RadixStringToUInt32W
#define	MA_RadixStringToInt64				MA_RadixStringToInt64W
#define	MA_RadixStringToUInt64				MA_RadixStringToUInt64W
#define	MA_FloatToString					MA_FloatToStringW
#define	MA_DoubleToString					MA_DoubleToStringW
#define	MA_StringToFloat					MA_StringToFloatW
#define	MA_StringToDouble					MA_StringToDoubleW

#define	MA_Int32ToString					MA_Int32ToStringW
#define	MA_UInt32ToString					MA_UInt32ToStringW
#define	MA_Int64ToString					MA_Int64ToStringW
#define	MA_UInt64ToString					MA_UInt64ToStringW

#define	MA_StringToInt32					MA_StringToInt32W
#define	MA_StringToUInt32					MA_StringToUInt32W
#define	MA_StringToInt64					MA_StringToInt64W
#define	MA_StringToUInt64					MA_StringToUInt64W

#define	MA_IntToBinString					MA_IntToBinStringW
#define	MA_IntToOctString					MA_IntToOctStringW
#define	MA_IntToDecString					MA_IntToDecStringW
#define	MA_IntToHexString					MA_IntToHexStringW

#define	MA_BinStringToInt					MA_BinStringToIntW
#define	MA_OctStringToInt					MA_OctStringToIntW
#define	MA_DecStringToInt					MA_DecStringToIntW
#define	MA_HexStringToInt					MA_HexStringToIntW

#define	MA_IntToString						MA_IntToStringW
#define	MA_StringToInt						MA_StringToIntW

#define	MA_HexStringToInt32					MA_HexStringToInt32W
#define	MA_HexStringToUInt32				MA_HexStringToUInt32W
#define	MA_HexStringToInt64					MA_HexStringToInt64W
#define	MA_HexStringToUInt64				MA_HexStringToUInt64W
								
#define	MA_Int32ToHexString					MA_Int32ToHexStringW
#define	MA_UInt32ToHexString				MA_UInt32ToHexStringW
#define	MA_Int64ToHexString					MA_Int64ToHexStringW
#define	MA_UInt64ToHexString				MA_UInt64ToHexStringW
								
#define	MA_DecStringToInt32					MA_DecStringToInt32W
#define	MA_DecStringToUInt32				MA_DecStringToUInt32W
#define	MA_DecStringToInt64					MA_DecStringToInt64W
#define	MA_DecStringToUInt64				MA_DecStringToUInt64W
								
#define	MA_Int32ToDecString					MA_Int32ToDecStringW
#define	MA_UInt32ToDecString				MA_UInt32ToDecStringW
#define	MA_Int64ToDecString					MA_Int64ToDecStringW
#define	MA_UInt64ToDecString				MA_UInt64ToDecStringW
								
#define	MA_OctStringToInt32					MA_OctStringToInt32W
#define	MA_OctStringToUInt32				MA_OctStringToUInt32W
#define	MA_OctStringToInt64					MA_OctStringToInt64W
#define	MA_OctStringToUInt64				MA_OctStringToUInt64W
								
#define	MA_Int32ToOctString					MA_Int32ToOctStringW
#define	MA_UInt32ToOctString				MA_UInt32ToOctStringW
#define	MA_Int64ToOctString					MA_Int64ToOctStringW
#define	MA_UInt64ToOctString				MA_UInt64ToOctStringW
								
#define	MA_BinStringToInt32					MA_BinStringToInt32W
#define	MA_BinStringToUInt32				MA_BinStringToUInt32W
#define	MA_BinStringToInt64					MA_BinStringToInt64W
#define	MA_BinStringToUInt64				MA_BinStringToUInt64W
								
#define	MA_Int32ToBinString					MA_Int32ToBinStringW
#define	MA_UInt32ToBinString				MA_UInt32ToBinStringW
#define	MA_Int64ToBinString					MA_Int64ToBinStringW
#define	MA_UInt64ToBinString				MA_UInt64ToBinStringW
#elif	defined( _NTR_E )
#define	MA_Int32ToRadixString				MA_Int32ToRadixStringE
#define	MA_UInt32ToRadixString				MA_UInt32ToRadixStringE
#define	MA_Int64ToRadixString				MA_Int64ToRadixStringE
#define	MA_UInt64ToRadixString				MA_UInt64ToRadixStringE
#define	MA_RadixStringToInt32				MA_RadixStringToInt32E
#define	MA_RadixStringToUInt32				MA_RadixStringToUInt32E
#define	MA_RadixStringToInt64				MA_RadixStringToInt64E
#define	MA_RadixStringToUInt64				MA_RadixStringToUInt64E
#define	MA_FloatToString					MA_FloatToStringE
#define	MA_DoubleToString					MA_DoubleToStringE
#define	MA_StringToFloat					MA_StringToFloatE
#define	MA_StringToDouble					MA_StringToDoubleE
#define	MA_StringToDouble					MA_StringToDoubleE

#define	MA_Int32ToString					MA_Int32ToStringE
#define	MA_UInt32ToString					MA_UInt32ToStringE
#define	MA_Int64ToString					MA_Int64ToStringE
#define	MA_UInt64ToString					MA_UInt64ToStringE

#define	MA_StringToInt32					MA_StringToInt32E
#define	MA_StringToUInt32					MA_StringToUInt32E
#define	MA_StringToInt64					MA_StringToInt64E
#define	MA_StringToUInt64					MA_StringToUInt64E

#define	MA_IntToBinString					MA_IntToBinStringE
#define	MA_IntToOctString					MA_IntToOctStringE
#define	MA_IntToDecString					MA_IntToDecStringE
#define	MA_IntToHexString					MA_IntToHexStringE

#define	MA_BinStringToInt					MA_BinStringToIntE
#define	MA_OctStringToInt					MA_OctStringToIntE
#define	MA_DecStringToInt					MA_DecStringToIntE
#define	MA_HexStringToInt					MA_HexStringToIntE

#define	MA_IntToString						MA_IntToStringE
#define	MA_StringToInt						MA_StringToIntE

#define	MA_HexStringToInt32					MA_HexStringToInt32E
#define	MA_HexStringToUInt32				MA_HexStringToUInt32E
#define	MA_HexStringToInt64					MA_HexStringToInt64E
#define	MA_HexStringToUInt64				MA_HexStringToUInt64E
								
#define	MA_Int32ToHexString					MA_Int32ToHexStringE
#define	MA_UInt32ToHexString				MA_UInt32ToHexStringE
#define	MA_Int64ToHexString					MA_Int64ToHexStringE
#define	MA_UInt64ToHexString				MA_UInt64ToHexStringE
								
#define	MA_DecStringToInt32					MA_DecStringToInt32E
#define	MA_DecStringToUInt32				MA_DecStringToUInt32E
#define	MA_DecStringToInt64					MA_DecStringToInt64E
#define	MA_DecStringToUInt64				MA_DecStringToUInt64E
								
#define	MA_Int32ToDecString					MA_Int32ToDecStringE
#define	MA_UInt32ToDecString				MA_UInt32ToDecStringE
#define	MA_Int64ToDecString					MA_Int64ToDecStringE
#define	MA_UInt64ToDecString				MA_UInt64ToDecStringE
								
#define	MA_OctStringToInt32					MA_OctStringToInt32E
#define	MA_OctStringToUInt32				MA_OctStringToUInt32E
#define	MA_OctStringToInt64					MA_OctStringToInt64E
#define	MA_OctStringToUInt64				MA_OctStringToUInt64E
								
#define	MA_Int32ToOctString					MA_Int32ToOctStringE
#define	MA_UInt32ToOctString				MA_UInt32ToOctStringE
#define	MA_Int64ToOctString					MA_Int64ToOctStringE
#define	MA_UInt64ToOctString				MA_UInt64ToOctStringE
								
#define	MA_BinStringToInt32					MA_BinStringToInt32E
#define	MA_BinStringToUInt32				MA_BinStringToUInt32E
#define	MA_BinStringToInt64					MA_BinStringToInt64E
#define	MA_BinStringToUInt64				MA_BinStringToUInt64E
								
#define	MA_Int32ToBinString					MA_Int32ToBinStringE
#define	MA_UInt32ToBinString				MA_UInt32ToBinStringE
#define	MA_Int64ToBinString					MA_Int64ToBinStringE
#define	MA_UInt64ToBinString				MA_UInt64ToBinStringE
#else
#define	MA_Int32ToRadixString				MA_Int32ToRadixStringA
#define	MA_UInt32ToRadixString				MA_UInt32ToRadixStringA
#define	MA_Int64ToRadixString				MA_Int64ToRadixStringA
#define	MA_UInt64ToRadixString				MA_UInt64ToRadixStringA
#define	MA_RadixStringToInt32				MA_RadixStringToInt32A
#define	MA_RadixStringToUInt32				MA_RadixStringToUInt32A
#define	MA_RadixStringToInt64				MA_RadixStringToInt64A
#define	MA_RadixStringToUInt64				MA_RadixStringToUInt64A
#define	MA_FloatToString					MA_FloatToStringA
#define	MA_DoubleToString					MA_DoubleToStringA
#define	MA_StringToFloat					MA_StringToFloatA
#define	MA_StringToDouble					MA_StringToDoubleA
#define	MA_StringToDouble					MA_StringToDoubleA

#define	MA_Int32ToString					MA_Int32ToStringA
#define	MA_UInt32ToString					MA_UInt32ToStringA
#define	MA_Int64ToString					MA_Int64ToStringA
#define	MA_UInt64ToString					MA_UInt64ToStringA

#define	MA_StringToInt32					MA_StringToInt32A
#define	MA_StringToUInt32					MA_StringToUInt32A
#define	MA_StringToInt64					MA_StringToInt64A
#define	MA_StringToUInt64					MA_StringToUInt64A

#define	MA_IntToBinString					MA_IntToBinStringA
#define	MA_IntToOctString					MA_IntToOctStringA
#define	MA_IntToDecString					MA_IntToDecStringA
#define	MA_IntToHexString					MA_IntToHexStringA

#define	MA_BinStringToInt					MA_BinStringToIntA
#define	MA_OctStringToInt					MA_OctStringToIntA
#define	MA_DecStringToInt					MA_DecStringToIntA
#define	MA_HexStringToInt					MA_HexStringToIntA

#define	MA_IntToString						MA_IntToStringA
#define	MA_StringToInt						MA_StringToIntA

#define	MA_HexStringToInt32					MA_HexStringToInt32A
#define	MA_HexStringToUInt32				MA_HexStringToUInt32A
#define	MA_HexStringToInt64					MA_HexStringToInt64A
#define	MA_HexStringToUInt64				MA_HexStringToUInt64A
								
#define	MA_Int32ToHexString					MA_Int32ToHexStringA
#define	MA_UInt32ToHexString				MA_UInt32ToHexStringA
#define	MA_Int64ToHexString					MA_Int64ToHexStringA
#define	MA_UInt64ToHexString				MA_UInt64ToHexStringA
								
#define	MA_DecStringToInt32					MA_DecStringToInt32A
#define	MA_DecStringToUInt32				MA_DecStringToUInt32A
#define	MA_DecStringToInt64					MA_DecStringToInt64A
#define	MA_DecStringToUInt64				MA_DecStringToUInt64A
								
#define	MA_Int32ToDecString					MA_Int32ToDecStringA
#define	MA_UInt32ToDecString				MA_UInt32ToDecStringA
#define	MA_Int64ToDecString					MA_Int64ToDecStringA
#define	MA_UInt64ToDecString				MA_UInt64ToDecStringA
								
#define	MA_OctStringToInt32					MA_OctStringToInt32A
#define	MA_OctStringToUInt32				MA_OctStringToUInt32A
#define	MA_OctStringToInt64					MA_OctStringToInt64A
#define	MA_OctStringToUInt64				MA_OctStringToUInt64A
								
#define	MA_Int32ToOctString					MA_Int32ToOctStringA
#define	MA_UInt32ToOctString				MA_UInt32ToOctStringA
#define	MA_Int64ToOctString					MA_Int64ToOctStringA
#define	MA_UInt64ToOctString				MA_UInt64ToOctStringA
								
#define	MA_BinStringToInt32					MA_BinStringToInt32A
#define	MA_BinStringToUInt32				MA_BinStringToUInt32A
#define	MA_BinStringToInt64					MA_BinStringToInt64A
#define	MA_BinStringToUInt64				MA_BinStringToUInt64A
								
#define	MA_Int32ToBinString					MA_Int32ToBinStringA
#define	MA_UInt32ToBinString				MA_UInt32ToBinStringA
#define	MA_Int64ToBinString					MA_Int64ToBinStringA
#define	MA_UInt64ToBinString				MA_UInt64ToBinStringA
#endif

// [Default : Decimal] Number -> String
#define	MA_Int32ToStringA					MA_Int32ToDecStringA
#define	MA_UInt32ToStringA					MA_UInt32ToDecStringA
#define	MA_Int64ToStringA					MA_Int64ToDecStringA
#define	MA_UInt64ToStringA					MA_UInt64ToDecStringA

#define	MA_Int32ToStringW					MA_Int32ToDecStringW
#define	MA_UInt32ToStringW					MA_UInt32ToDecStringW
#define	MA_Int64ToStringW					MA_Int64ToDecStringW
#define	MA_UInt64ToStringW					MA_UInt64ToDecStringW

#define	MA_Int32ToStringE					MA_Int32ToDecStringE
#define	MA_UInt32ToStringE					MA_UInt32ToDecStringE
#define	MA_Int64ToStringE					MA_Int64ToDecStringE
#define	MA_UInt64ToStringE					MA_UInt64ToDecStringE

#define	MA_IntToBinStringA					MA_Int32ToBinStringA
#define	MA_IntToOctStringA					MA_Int32ToOctStringA
#define	MA_IntToDecStringA					MA_Int32ToDecStringA
#define	MA_IntToHexStringA					MA_Int32ToHexStringA

#define	MA_IntToBinStringW					MA_Int32ToBinStringW
#define	MA_IntToOctStringW					MA_Int32ToOctStringW
#define	MA_IntToDecStringW					MA_Int32ToDecStringW
#define	MA_IntToHexStringW					MA_Int32ToHexStringW

#define	MA_IntToBinStringE					MA_Int32ToBinStringE
#define	MA_IntToOctStringE					MA_Int32ToOctStringE
#define	MA_IntToDecStringE					MA_Int32ToDecStringE
#define	MA_IntToHexStringE					MA_Int32ToHexStringE

// [Default : 32Bit] String -> Number
#define	MA_BinStringToIntA					MA_BinStringToInt32A
#define	MA_OctStringToIntA					MA_OctStringToInt32A
#define	MA_DecStringToIntA					MA_DecStringToInt32A
#define	MA_HexStringToIntA					MA_HexStringToInt32A

#define	MA_BinStringToIntW					MA_BinStringToInt32W
#define	MA_OctStringToIntW					MA_OctStringToInt32W
#define	MA_DecStringToIntW					MA_DecStringToInt32W
#define	MA_HexStringToIntW					MA_HexStringToInt32W

// [ Default : 32Bit, Decimal]
#define	MA_BinStringToIntE					MA_BinStringToInt32E
#define	MA_OctStringToIntE					MA_OctStringToInt32E
#define	MA_DecStringToIntE					MA_DecStringToInt32E
#define	MA_HexStringToIntE					MA_HexStringToInt32E

#define	MA_IntToStringA						MA_Int32ToDecStringA
#define	MA_IntToStringW						MA_Int32ToDecStringW
#define	MA_IntToStringE						MA_Int32ToDecStringE

enum {
	eNUMBER_BINARY		= 2,
	eNUMBER_OCTAL		= 8,
	eNUMBER_DECIMAL		= 10,
	eNUMBER_HEXADECIMAL	= 16,
};

/*
 * Method: MA_Int32ToRadixString
 * 32비트 부호있는 숫자를 문자열로 변환한다.
 *
 * Parameters:
 *	s32Value [in]		- 변환할 숫자
 *	tszString [out]		- 변환된 숫자를 저장할 버퍼
 *	sizeString [in]		- 문자열 버퍼의 크기
 *	nRadix [in]		- 진수 2부터 36까지 가능
 *
 * Returns:
 *	성공했으면 tszString의 시작포인터를 리턴. 그렇지 않으면 MA_NULL을 리턴.
 */
MA_PSTR		MA_Int32ToRadixStringA( MA_XINT IN s32Value, MA_PSTR OUT tszString, MA_SIZE IN sizeString, int IN nRadix );
MA_PWSTR	MA_Int32ToRadixStringW( MA_XINT IN s32Value, MA_PWSTR OUT tszString, MA_SIZE IN sizeString, int IN nRadix );
MA_PESTR	MA_Int32ToRadixStringE( MA_XINT IN s32Value, MA_PESTR OUT tszString, MA_SIZE IN sizeString, int IN nRadix );

/*
 * Method: MA_UInt32ToRadixString
 * 32비트 부호없는 숫자를 문자열로 변환한다.
 *
 * Parameters:
 *	s32Value [in]		- 변환할 숫자
 *	tszString [out]		- 변환된 숫자를 저장할 버퍼
 *	sizeString [in]		- 문자열 버퍼의 크기
 *	nRadix [in]		- 진수 2부터 36까지 가능
 *
 * Returns:
 *	성공했으면 tszString의 시작포인터를 리턴. 그렇지 않으면 MA_NULL을 리턴.
 */
MA_PSTR		MA_UInt32ToRadixStringA( MA_XUINT IN u32Value, MA_PSTR OUT tszString, MA_SIZE IN sizeString, int IN nRadix );
MA_PWSTR	MA_UInt32ToRadixStringW( MA_XUINT IN u32Value, MA_PWSTR OUT tszString, MA_SIZE IN sizeString, int IN nRadix );
MA_PESTR	MA_UInt32ToRadixStringE( MA_XUINT IN u32Value, MA_PESTR OUT tszString, MA_SIZE IN sizeString, int IN nRadix );

/*
 * Method: MA_Int64ToRadixString
 * 64비트 부호있는 숫자를 문자열로 변환한다.
 *
 * Parameters:
 *	s32Value [in]		- 변환할 숫자
 *	tszString [out]		- 변환된 숫자를 저장할 버퍼
 *	sizeString [in]		- 문자열 버퍼의 크기
 *	nRadix [in]		- 진수 2부터 36까지 가능
 *
 * Returns:
 *	성공했으면 tszString의 시작포인터를 리턴. 그렇지 않으면 MA_NULL을 리턴.
 */
MA_PSTR		MA_Int64ToRadixStringA( MA_XLONG IN s64Value, MA_PSTR OUT tszString, MA_SIZE IN sizeString, int IN nRadix );
MA_PWSTR	MA_Int64ToRadixStringW( MA_XLONG IN s64Value, MA_PWSTR OUT tszString, MA_SIZE IN sizeString, int IN nRadix );
MA_PESTR	MA_Int64ToRadixStringE( MA_XLONG IN s64Value, MA_PESTR OUT tszString, MA_SIZE IN sizeString, int IN nRadix );

/*
 * Method: MA_UInt64ToRadixString
 * 64비트 부호없는 숫자를 문자열로 변환한다.
 *
 * Parameters:
 *	s32Value [in]		- 변환할 숫자
 *	tszString [out]		- 변환된 숫자를 저장할 버퍼
 *	sizeString [in]		- 문자열 버퍼의 크기
 *	nRadix [in]		- 진수 2부터 36까지 가능
 *
 * Returns:
 *	성공했으면 tszString의 시작포인터를 리턴. 그렇지 않으면 MA_NULL을 리턴.
 */
MA_PSTR		MA_UInt64ToRadixStringA( MA_XULONG IN u64Value, MA_PSTR OUT tszString, MA_SIZE IN sizeString, int IN nRadix );
MA_PWSTR	MA_UInt64ToRadixStringW( MA_XULONG IN u64Value, MA_PWSTR OUT tszString, MA_SIZE IN sizeString, int IN nRadix );
MA_PESTR	MA_UInt64ToRadixStringE( MA_XULONG IN u64Value, MA_PESTR OUT tszString, MA_SIZE IN sizeString, int IN nRadix );



/*
 * Method: MA_RadixStringToInt32
 * 문자열을 32비트 부호있는 숫자로 변환한다.
 *
 * Parameters:
 *	tszString [in]		- 변환할 숫자를 가진 문자열
 *	sizeString [in]		- 문자열 버퍼의 크기
 *	nRadix [in]		- 진수 2부터 36까지 가능
 *
 * Returns:
 *	변환된 숫자를 리턴.
 */
MA_XINT		MA_RadixStringToInt32A( MA_PCSTR IN tszString, MA_SIZE IN sizeString, int IN nRadix );
MA_XINT		MA_RadixStringToInt32W( MA_PCWSTR IN tszString, MA_SIZE IN sizeString, int IN nRadix );
MA_XINT		MA_RadixStringToInt32E( MA_PCESTR IN tszString, MA_SIZE IN sizeString, int IN nRadix );

/*
 * Method: MA_RadixStringToUInt32
 * 문자열을 32비트 부호없는 숫자로 변환한다.
 *
 * Parameters:
 *	tszString [in]		- 변환할 숫자를 가진 문자열
 *	sizeString [in]		- 문자열 버퍼의 크기
 *	nRadix [in]		- 진수 2부터 36까지 가능
 *
 * Returns:
 *	변환된 숫자를 리턴.
 */
MA_XUINT		MA_RadixStringToUInt32A( MA_PCSTR IN tszString, MA_SIZE IN sizeString, int IN nRadix );
MA_XUINT		MA_RadixStringToUInt32W( MA_PCWSTR IN tszString, MA_SIZE IN sizeString, int IN nRadix );
MA_XUINT		MA_RadixStringToUInt32E( MA_PCESTR IN tszString, MA_SIZE IN sizeString, int IN nRadix );

/*
 * Method: MA_RadixStringToInt64
 * 문자열을 64비트 부호있는 숫자로 변환한다.
 *
 * Parameters:
 *	tszString [in]		- 변환할 숫자를 가진 문자열
 *	sizeString [in]		- 문자열 버퍼의 크기
 *	nRadix [in]		- 진수 2부터 36까지 가능
 *
 * Returns:
 *	변환된 숫자를 리턴.
 */
MA_XLONG		MA_RadixStringToInt64A( MA_PCSTR IN tszString, MA_SIZE IN sizeString, int IN nRadix );
MA_XLONG		MA_RadixStringToInt64W( MA_PCWSTR IN tszString, MA_SIZE IN sizeString, int IN nRadix );
MA_XLONG		MA_RadixStringToInt64E( MA_PCESTR IN tszString, MA_SIZE IN sizeString, int IN nRadix );

/*
 * Method: MA_RadixStringToUInt64
 * 문자열을 64비트 부호없는 숫자로 변환한다.
 *
 * Parameters:
 *	tszString [in]		- 변환할 숫자를 가진 문자열
 *	sizeString [in]		- 문자열 버퍼의 크기
 *	nRadix [in]		- 진수 2부터 36까지 가능
 *
 * Returns:
 *	변환된 숫자를 리턴.
 */
MA_XULONG		MA_RadixStringToUInt64A( MA_PCSTR IN tszString, MA_SIZE IN sizeString, int IN nRadix );
MA_XULONG		MA_RadixStringToUInt64W( MA_PCWSTR IN tszString, MA_SIZE IN sizeString, int IN nRadix );
MA_XULONG		MA_RadixStringToUInt64E( MA_PCESTR IN tszString, MA_SIZE IN sizeString, int IN nRadix );



/*
 * Method: MA_FloatToString
 * 32바이트 소수를 문자열로 변환한다.
 *
 * Parameters:
 *	fValue [in]		- 변환할 소수
 *	tszString [out]		- 변환된 소수를 저장할 버퍼
 *	sizeString [in]		- 문자열 버퍼의 크기
 *	nDigit [in]		- 소수의 길이
 *
 * Returns:
 *	성공했으면 tszString의 시작포인터를 리턴. 그렇지 않으면 MA_NULL을 리턴.
 */
MA_PSTR		MA_FloatToStringA( float IN fValue, MA_PSTR OUT tszString, MA_SIZE IN sizeString, int IN nDigit );
MA_PWSTR	MA_FloatToStringW( float IN fValue, MA_PWSTR OUT tszString, MA_SIZE IN sizeString, int IN nDigit );
MA_PESTR	MA_FloatToStringE( float IN fValue, MA_PESTR OUT tszString, MA_SIZE IN sizeString, int IN nDigit );

/*
 * Method: MA_DoubleToString
 * 64바이트 소수를 문자열로 변환한다.
 *
 * Parameters:
 *	dValue [in]		- 변환할 소수
 *	tszString [out]		- 변환된 소수를 저장할 버퍼
 *	sizeString [in]		- 문자열 버퍼의 크기
*	nDigit [in]		- 소수의 길이
 *
 * Returns:
 *	성공했으면 tszString의 시작포인터를 리턴. 그렇지 않으면 MA_NULL을 리턴.
 */
MA_PSTR		MA_DoubleToStringA( double IN dValue, MA_PSTR OUT tszString, MA_SIZE IN sizeString, int IN nDigit );
MA_PWSTR	MA_DoubleToStringW( double IN dValue, MA_PWSTR OUT tszString, MA_SIZE IN sizeString, int IN nDigit );
MA_PESTR	MA_DoubleToStringE( double IN dValue, MA_PESTR OUT tszString, MA_SIZE IN sizeString, int IN nDigit );

/*
 * Method: MA_StringToFloat
 * 문자열을 32비트 소수로 변환한다.
 *
 * Parameters:
 *	tszString [in]		- 변환할 소수를 가진 문자열
 *	sizeString [in]		- 문자열 버퍼의 크기
 *
 * Returns:
 *	변환된 소수를 리턴.
 */
float		MA_StringToFloatA( MA_PCSTR IN tszString, MA_SIZE IN sizeString );
float		MA_StringToFloatW( MA_PCWSTR IN tszString, MA_SIZE IN sizeString );
float		MA_StringToFloatE( MA_PCESTR IN tszString, MA_SIZE IN sizeString );

/*
 * Method: MA_StringToDouble
 * 문자열을 64비트 소수로 변환한다.
 *
 * Parameters:
 *	tszString [in]		- 변환할 소수를 가진 문자열
 *	sizeString [in]		- 문자열 버퍼의 크기
 *
 * Returns:
 *	변환된 소수를 리턴.
 */
double		MA_StringToDoubleA( MA_PCSTR IN tszString, MA_SIZE IN sizeString );
double		MA_StringToDoubleW( MA_PCWSTR IN tszString, MA_SIZE IN sizeString );
double		MA_StringToDoubleE( MA_PCESTR IN tszString, MA_SIZE IN sizeString );



/*
 * Method: MA_GetInt32RadixLength
 * 32비트 부호있는 숫자를 문자열로 변환했을떄 길이를 얻는다.
 *
 * Parameters:
 *	s32Value [in]		- 32비트 숫자
 *	nRadix [in]		- 진수 2부터 36까지 가능
 *
 * Returns:
 *	문자열의 길이
 */
MA_SIZE	MA_GetInt32RadixLength( MA_XINT IN s32Value, int IN nRadix );

/*
 * Method: MA_GetUInt32RadixLength
 * 32비트 부호없는 숫자를 문자열로 변환했을떄 길이를 얻는다.
 *
 * Parameters:
 *	s32Value [in]		- 32비트 숫자
 *	nRadix [in]		- 진수 2부터 36까지 가능
 *
 * Returns:
 *	문자열의 길이
 */
MA_SIZE	MA_GetUInt32RadixLength( MA_XUINT IN u32Value, int IN nRadix );

/*
 * Method: MA_GetInt32RadixLength
 * 64비트 부호있는 숫자를 문자열로 변환했을떄 길이를 얻는다.
 *
 * Parameters:
 *	s32Value [in]		- 32비트 숫자
 *	nRadix [in]		- 진수 2부터 36까지 가능
 *
 * Returns:
 *	문자열의 길이
 */
MA_SIZE	MA_GetInt64RadixLength( MA_XLONG IN s64Value, int IN nRadix );

/*
 * Method: MA_GetUInt64RadixLength
 * 64비트 부호없는 숫자를 문자열로 변환했을떄 길이를 얻는다.
 *
 * Parameters:
 *	s32Value [in]		- 32비트 숫자
 *	nRadix [in]		- 진수 2부터 36까지 가능
 *
 * Returns:
 *	문자열의 길이
 */
MA_SIZE	MA_GetUInt64RadixLength( MA_XULONG IN u64Value, int IN nRadix );



/*
 * Method: MA_GetFloatLength
 * 32비트 소수를 문자열로 변환했을떄 길이를 얻는다.
 *
 * Parameters:
 *	fValue [in]		- 32비트 소수
 *	nDigit [in]		- 소수의 길이
 *	sizeNumber [optinal]	- 정수 부분의 길이
 *	sizeDecimal [optinal]	- 소수 부분의 길이
 *
 * Returns:
 *	문자열의 길이
 */
MA_SIZE	MA_GetFloatLength( float IN fValue, int IN nDigit, MA_SIZE* OPTIONAL sizeNumber, MA_SIZE* OPTIONAL sizeDecimal );

/*
 * Method: MA_GetDoubleLength
 * 64비트 소수를 문자열로 변환했을떄 길이를 얻는다.
 *
 * Parameters:
 *	fValue [in]		- 64비트 소수
 *	nDigit [in]		- 소수의 길이
 *	sizeNumber [optinal]	- 정수 부분의 길이
 *	sizeDecimal [optinal]	- 소수 부분의 길이
 *
 * Returns:
 *	문자열의 길이
 */
MA_SIZE			MA_GetDoubleLength( double IN dValue, int IN nDigit, MA_SIZE* OPTIONAL sizeNumber, MA_SIZE* OPTIONAL sizeDecimal );

// [BINARY] Number -> String
MA_PSTR			MA_Int32ToBinStringA( MA_XINT IN s32Value, MA_PSTR OUT tszString, MA_SIZE IN sizeString );
MA_PWSTR		MA_Int32ToBinStringW( MA_XINT IN s32Value, MA_PWSTR OUT tszString, MA_SIZE IN sizeString );
MA_PESTR		MA_Int32ToBinStringE( MA_XINT IN s32Value, MA_PESTR OUT tszString, MA_SIZE IN sizeString );

MA_PSTR			MA_UInt32ToBinStringA( MA_XUINT IN u32Value, MA_PSTR OUT tszString, MA_SIZE IN sizeString );
MA_PWSTR		MA_UInt32ToBinStringW( MA_XUINT IN u32Value, MA_PWSTR OUT tszString, MA_SIZE IN sizeString );
MA_PESTR		MA_UInt32ToBinStringE( MA_XUINT IN u32Value, MA_PESTR OUT tszString, MA_SIZE IN sizeString );

MA_PSTR			MA_Int64ToBinStringA( MA_XLONG IN s64Value, MA_PSTR OUT tszString, MA_SIZE IN sizeString );
MA_PWSTR		MA_Int64ToBinStringW( MA_XLONG IN s64Value, MA_PWSTR OUT tszString, MA_SIZE IN sizeString );
MA_PESTR		MA_Int64ToBinStringE( MA_XLONG IN s64Value, MA_PESTR OUT tszString, MA_SIZE IN sizeString );

MA_PSTR			MA_UInt64ToBinStringA( MA_XULONG IN u64Value, MA_PSTR OUT tszString, MA_SIZE IN sizeString );
MA_PWSTR		MA_UInt64ToBinStringW( MA_XULONG IN u64Value, MA_PWSTR OUT tszString, MA_SIZE IN sizeString );
MA_PESTR		MA_UInt64ToBinStringE( MA_XULONG IN u64Value, MA_PESTR OUT tszString, MA_SIZE IN sizeString );

// [BINARY] String -> Number
MA_XINT			MA_BinStringToInt32A( MA_PCSTR IN tszString, MA_SIZE IN sizeString );
MA_XINT			MA_BinStringToInt32W( MA_PCWSTR IN tszString, MA_SIZE IN sizeString );
MA_XINT			MA_BinStringToInt32E( MA_PCESTR IN tszString, MA_SIZE IN sizeString );

MA_XUINT		MA_BinStringToUInt32A( MA_PCSTR IN tszString, MA_SIZE IN sizeString );
MA_XUINT		MA_BinStringToUInt32W( MA_PCWSTR IN tszString, MA_SIZE IN sizeString );
MA_XUINT		MA_BinStringToUInt32E( MA_PCESTR IN tszString, MA_SIZE IN sizeString );

MA_XLONG		MA_BinStringToInt64A( MA_PCSTR IN tszString, MA_SIZE IN sizeString );
MA_XLONG		MA_BinStringToInt64W( MA_PCWSTR IN tszString, MA_SIZE IN sizeString );
MA_XLONG		MA_BinStringToInt64E( MA_PCESTR IN tszString, MA_SIZE IN sizeString );

MA_XULONG		MA_BinStringToUInt64A( MA_PCSTR IN tszString, MA_SIZE IN sizeString );
MA_XULONG		MA_BinStringToUInt64W( MA_PCWSTR IN tszString, MA_SIZE IN sizeString );
MA_XULONG		MA_BinStringToUInt64E( MA_PCESTR IN tszString, MA_SIZE IN sizeString );

// [OCTAL] Number -> String
MA_PSTR			MA_Int32ToOctStringA( MA_XINT IN s32Value, MA_PSTR OUT tszString, MA_SIZE IN sizeString );
MA_PWSTR		MA_Int32ToOctStringW( MA_XINT IN s32Value, MA_PWSTR OUT tszString, MA_SIZE IN sizeString );
MA_PESTR		MA_Int32ToOctStringE( MA_XINT IN s32Value, MA_PESTR OUT tszString, MA_SIZE IN sizeString );

MA_PSTR			MA_UInt32ToOctStringA( MA_XUINT IN u32Value, MA_PSTR OUT tszString, MA_SIZE IN sizeString );
MA_PWSTR		MA_UInt32ToOctStringW( MA_XUINT IN u32Value, MA_PWSTR OUT tszString, MA_SIZE IN sizeString );
MA_PESTR		MA_UInt32ToOctStringE( MA_XUINT IN u32Value, MA_PESTR OUT tszString, MA_SIZE IN sizeString );

MA_PSTR			MA_Int64ToOctStringA( MA_XLONG IN s64Value, MA_PSTR OUT tszString, MA_SIZE IN sizeString );
MA_PWSTR		MA_Int64ToOctStringW( MA_XLONG IN s64Value, MA_PWSTR OUT tszString, MA_SIZE IN sizeString );
MA_PESTR		MA_Int64ToOctStringE( MA_XLONG IN s64Value, MA_PESTR OUT tszString, MA_SIZE IN sizeString );

MA_PSTR			MA_UInt64ToOctStringA( MA_XULONG IN u64Value, MA_PSTR OUT tszString, MA_SIZE IN sizeString );
MA_PWSTR		MA_UInt64ToOctStringW( MA_XULONG IN u64Value, MA_PWSTR OUT tszString, MA_SIZE IN sizeString );
MA_PESTR		MA_UInt64ToOctStringE( MA_XULONG IN u64Value, MA_PESTR OUT tszString, MA_SIZE IN sizeString );

// [OCTAL] String -> Number
MA_XINT			MA_OctStringToInt32A( MA_PCSTR IN tszString, MA_SIZE IN sizeString );
MA_XINT			MA_OctStringToInt32W( MA_PCWSTR IN tszString, MA_SIZE IN sizeString );
MA_XINT			MA_OctStringToInt32E( MA_PCESTR IN tszString, MA_SIZE IN sizeString );

MA_XUINT		MA_OctStringToUInt32A( MA_PCSTR IN tszString, MA_SIZE IN sizeString );
MA_XUINT		MA_OctStringToUInt32W( MA_PCWSTR IN tszString, MA_SIZE IN sizeString );
MA_XUINT		MA_OctStringToUInt32E( MA_PCESTR IN tszString, MA_SIZE IN sizeString );

MA_XLONG		MA_OctStringToInt64A( MA_PCSTR IN tszString, MA_SIZE IN sizeString );
MA_XLONG		MA_OctStringToInt64W( MA_PCWSTR IN tszString, MA_SIZE IN sizeString );
MA_XLONG		MA_OctStringToInt64E( MA_PCESTR IN tszString, MA_SIZE IN sizeString );

MA_XULONG		MA_OctStringToUInt64A( MA_PCSTR IN tszString, MA_SIZE IN sizeString );
MA_XULONG		MA_OctStringToUInt64W( MA_PCWSTR IN tszString, MA_SIZE IN sizeString );
MA_XULONG		MA_OctStringToUInt64E( MA_PCESTR IN tszString, MA_SIZE IN sizeString );

// [DECIMAL] Number -> String
MA_PSTR			MA_Int32ToDecStringA( MA_XINT IN s32Value, MA_PSTR OUT tszString, MA_SIZE IN sizeString );
MA_PWSTR		MA_Int32ToDecStringW( MA_XINT IN s32Value, MA_PWSTR OUT tszString, MA_SIZE IN sizeString );
MA_PESTR		MA_Int32ToDecStringE( MA_XINT IN s32Value, MA_PESTR OUT tszString, MA_SIZE IN sizeString );

MA_PSTR			MA_UInt32ToDecStringA( MA_XUINT IN u32Value, MA_PSTR OUT tszString, MA_SIZE IN sizeString );
MA_PWSTR		MA_UInt32ToDecStringW( MA_XUINT IN u32Value, MA_PWSTR OUT tszString, MA_SIZE IN sizeString );
MA_PESTR		MA_UInt32ToDecStringE( MA_XUINT IN u32Value, MA_PESTR OUT tszString, MA_SIZE IN sizeString );

MA_PSTR			MA_Int64ToDecStringA( MA_XLONG IN s64Value, MA_PSTR OUT tszString, MA_SIZE IN sizeString );
MA_PWSTR		MA_Int64ToDecStringW( MA_XLONG IN s64Value, MA_PWSTR OUT tszString, MA_SIZE IN sizeString );
MA_PESTR		MA_Int64ToDecStringE( MA_XLONG IN s64Value, MA_PESTR OUT tszString, MA_SIZE IN sizeString );

MA_PSTR			MA_UInt64ToDecStringA( MA_XULONG IN u64Value, MA_PSTR OUT tszString, MA_SIZE IN sizeString );
MA_PWSTR		MA_UInt64ToDecStringW( MA_XULONG IN u64Value, MA_PWSTR OUT tszString, MA_SIZE IN sizeString );
MA_PESTR		MA_UInt64ToDecStringE( MA_XULONG IN u64Value, MA_PESTR OUT tszString, MA_SIZE IN sizeString );

// [DECIMAL] String -> Number
MA_XINT			MA_DecStringToInt32A( MA_PCSTR IN tszString, MA_SIZE IN sizeString );
MA_XINT			MA_DecStringToInt32W( MA_PCWSTR IN tszString, MA_SIZE IN sizeString );
MA_XINT			MA_DecStringToInt32E( MA_PCESTR IN tszString, MA_SIZE IN sizeString );

MA_XUINT		MA_DecStringToUInt32A( MA_PCSTR IN tszString, MA_SIZE IN sizeString );
MA_XUINT		MA_DecStringToUInt32W( MA_PCWSTR IN tszString, MA_SIZE IN sizeString );
MA_XUINT		MA_DecStringToUInt32E( MA_PCESTR IN tszString, MA_SIZE IN sizeString );

MA_XLONG		MA_DecStringToInt64A( MA_PCSTR IN tszString, MA_SIZE IN sizeString );
MA_XLONG		MA_DecStringToInt64W( MA_PCWSTR IN tszString, MA_SIZE IN sizeString );
MA_XLONG		MA_DecStringToInt64E( MA_PCESTR IN tszString, MA_SIZE IN sizeString );

MA_XULONG		MA_DecStringToUInt64A( MA_PCSTR IN tszString, MA_SIZE IN sizeString );
MA_XULONG		MA_DecStringToUInt64W( MA_PCWSTR IN tszString, MA_SIZE IN sizeString );
MA_XULONG		MA_DecStringToUInt64E( MA_PCESTR IN tszString, MA_SIZE IN sizeString );

// [HEXADECIMAL] Number -> String
MA_PSTR			MA_Int32ToHexStringA( MA_XINT IN s32Value, MA_PSTR OUT tszString, MA_SIZE IN sizeString );
MA_PWSTR		MA_Int32ToHexStringW( MA_XINT IN s32Value, MA_PWSTR OUT tszString, MA_SIZE IN sizeString );
MA_PESTR		MA_Int32ToHexStringE( MA_XINT IN s32Value, MA_PESTR OUT tszString, MA_SIZE IN sizeString );

MA_PSTR			MA_UInt32ToHexStringA( MA_XUINT IN u32Value, MA_PSTR OUT tszString, MA_SIZE IN sizeString );
MA_PWSTR		MA_UInt32ToHexStringW( MA_XUINT IN u32Value, MA_PWSTR OUT tszString, MA_SIZE IN sizeString );
MA_PESTR		MA_UInt32ToHexStringE( MA_XUINT IN u32Value, MA_PESTR OUT tszString, MA_SIZE IN sizeString );

MA_PSTR			MA_Int64ToHexStringA( MA_XLONG IN s64Value, MA_PSTR OUT tszString, MA_SIZE IN sizeString );
MA_PWSTR		MA_Int64ToHexStringW( MA_XLONG IN s64Value, MA_PWSTR OUT tszString, MA_SIZE IN sizeString );
MA_PESTR		MA_Int64ToHexStringE( MA_XLONG IN s64Value, MA_PESTR OUT tszString, MA_SIZE IN sizeString );

MA_PSTR			MA_UInt64ToHexStringA( MA_XULONG IN u64Value, MA_PSTR OUT tszString, MA_SIZE IN sizeString );
MA_PWSTR		MA_UInt64ToHexStringW( MA_XULONG IN u64Value, MA_PWSTR OUT tszString, MA_SIZE IN sizeString );
MA_PESTR		MA_UInt64ToHexStringE( MA_XULONG IN u64Value, MA_PESTR OUT tszString, MA_SIZE IN sizeString );

// [HEXADECIMAL] String -> Number
MA_XINT			MA_HexStringToInt32A( MA_PCSTR IN tszString, MA_SIZE IN sizeString );
MA_XINT			MA_HexStringToInt32W( MA_PCWSTR IN tszString, MA_SIZE IN sizeString );
MA_XINT			MA_HexStringToInt32E( MA_PCESTR IN tszString, MA_SIZE IN sizeString );

MA_XUINT		MA_HexStringToUInt32A( MA_PCSTR IN tszString, MA_SIZE IN sizeString );
MA_XUINT		MA_HexStringToUInt32W( MA_PCWSTR IN tszString, MA_SIZE IN sizeString );
MA_XUINT		MA_HexStringToUInt32E( MA_PCESTR IN tszString, MA_SIZE IN sizeString );

MA_XLONG		MA_HexStringToInt64A( MA_PCSTR IN tszString, MA_SIZE IN sizeString );
MA_XLONG		MA_HexStringToInt64W( MA_PCWSTR IN tszString, MA_SIZE IN sizeString );
MA_XLONG		MA_HexStringToInt64E( MA_PCESTR IN tszString, MA_SIZE IN sizeString );

MA_XULONG		MA_HexStringToUInt64A( MA_PCSTR IN tszString, MA_SIZE IN sizeString );
MA_XULONG		MA_HexStringToUInt64W( MA_PCWSTR IN tszString, MA_SIZE IN sizeString );
MA_XULONG		MA_HexStringToUInt64E( MA_PCESTR IN tszString, MA_SIZE IN sizeString );

// String -> Number
MA_XINT			MA_StringToInt32A( MA_PCSTR IN tszString, MA_SIZE IN sizeString );
MA_XINT			MA_StringToInt32W( MA_PCWSTR IN tszString, MA_SIZE IN sizeString );
MA_XINT			MA_StringToInt32E( MA_PCESTR IN tszString, MA_SIZE IN sizeString );

MA_XUINT		MA_StringToUInt32A( MA_PCSTR IN tszString, MA_SIZE IN sizeString );
MA_XUINT		MA_StringToUInt32W( MA_PCWSTR IN tszString, MA_SIZE IN sizeString );
MA_XUINT		MA_StringToUInt32E( MA_PCESTR IN tszString, MA_SIZE IN sizeString );

MA_XLONG		MA_StringToInt64A( MA_PCSTR IN tszString, MA_SIZE IN sizeString );
MA_XLONG		MA_StringToInt64W( MA_PCWSTR IN tszString, MA_SIZE IN sizeString );
MA_XLONG		MA_StringToInt64E( MA_PCESTR IN tszString, MA_SIZE IN sizeString );

MA_XULONG		MA_StringToUInt64A( MA_PCSTR IN tszString, MA_SIZE IN sizeString );
MA_XULONG		MA_StringToUInt64W( MA_PCWSTR IN tszString, MA_SIZE IN sizeString );
MA_XULONG		MA_StringToUInt64E( MA_PCESTR IN tszString, MA_SIZE IN sizeString );

// [Binary] Calculate Length
NTR_INLINE MA_SIZE	MA_GetInt32ToBinStringLength( MA_XINT s32Value )				{ return MA_GetInt32RadixLength( s32Value, eNUMBER_BINARY );		}
NTR_INLINE MA_SIZE	MA_GetUInt32ToBinStringLength( MA_XUINT u32Value )				{ return MA_GetUInt32RadixLength( u32Value, eNUMBER_BINARY );		}
NTR_INLINE MA_SIZE	MA_GetInt64ToBinStringLength( MA_XLONG s64Value )				{ return MA_GetInt64RadixLength( s64Value, eNUMBER_BINARY );		}
NTR_INLINE MA_SIZE	MA_GetUInt64ToBinStringLength( MA_XULONG u64Value )				{ return MA_GetUInt64RadixLength( u64Value, eNUMBER_BINARY );		}

// [Octal] Calculate Length
NTR_INLINE MA_SIZE	MA_GetInt32ToOctStringLength( MA_XINT s32Value )				{ return MA_GetInt32RadixLength( s32Value, eNUMBER_OCTAL );		}
NTR_INLINE MA_SIZE	MA_GetUInt32ToOctStringLength( MA_XUINT u32Value )				{ return MA_GetUInt32RadixLength( u32Value, eNUMBER_OCTAL );		}
NTR_INLINE MA_SIZE	MA_GetInt64ToOctStringLength( MA_XLONG s64Value )				{ return MA_GetInt64RadixLength( s64Value, eNUMBER_OCTAL );		}
NTR_INLINE MA_SIZE	MA_GetUInt64ToOctStringLength( MA_XULONG u64Value )				{ return MA_GetUInt64RadixLength( u64Value, eNUMBER_OCTAL );		}	

// [Decimal] Calculate Length
NTR_INLINE MA_SIZE	MA_GetInt32ToDecStringLength( MA_XINT s32Value )				{ return MA_GetInt32RadixLength( s32Value, eNUMBER_DECIMAL );		}
NTR_INLINE MA_SIZE	MA_GetUInt32ToDecStringLength( MA_XUINT u32Value )				{ return MA_GetUInt32RadixLength( u32Value, eNUMBER_DECIMAL );		}
NTR_INLINE MA_SIZE	MA_GetInt64ToDecStringLength( MA_XLONG s64Value )				{ return MA_GetInt64RadixLength( s64Value, eNUMBER_DECIMAL );		}
NTR_INLINE MA_SIZE	MA_GetUInt64ToDecStringLength( MA_XULONG u64Value )				{ return MA_GetUInt64RadixLength( u64Value, eNUMBER_DECIMAL );		}

// [Hexadecimal] Calculate Length
NTR_INLINE MA_SIZE	MA_GetInt32ToHexStringLength( MA_XINT s32Value )				{ return MA_GetInt32RadixLength( s32Value, eNUMBER_HEXADECIMAL );	}
NTR_INLINE MA_SIZE	MA_GetUInt32ToHexStringLength( MA_XUINT u32Value )				{ return MA_GetUInt32RadixLength( u32Value, eNUMBER_HEXADECIMAL );	}
NTR_INLINE MA_SIZE	MA_GetInt64ToHexStringLength( MA_XLONG s64Value )				{ return MA_GetInt64RadixLength( s64Value, eNUMBER_HEXADECIMAL );	}
NTR_INLINE MA_SIZE	MA_GetUInt64ToHexStringLength( MA_XULONG u64Value )				{ return MA_GetUInt64RadixLength( u64Value, eNUMBER_HEXADECIMAL );	}

// [Default : 64Bit] Calculate Length
#if	defined( _NTR_64BIT ) // Default 64Bit
NTR_INLINE MA_SIZE	MA_GetIntToBinStringLength( MA_XLONG s64Value )				{ return MA_GetInt64RadixLength( s64Value, eNUMBER_BINARY );		}
NTR_INLINE MA_SIZE	MA_GetIntToOctStringLength( MA_XLONG s64Value )				{ return MA_GetInt64RadixLength( s64Value, eNUMBER_OCTAL );		}
NTR_INLINE MA_SIZE	MA_GetIntToDecStringLength( MA_XLONG s64Value )				{ return MA_GetInt64RadixLength( s64Value, eNUMBER_DECIMAL );		}
NTR_INLINE MA_SIZE	MA_GetIntToHexStringLength( MA_XLONG s64Value )				{ return MA_GetInt64RadixLength( s64Value, eNUMBER_HEXADECIMAL );	}

NTR_INLINE MA_SIZE	MA_GetIntToStrignLength( MA_XLONG s64Value )					{ return MA_GetInt64RadixLength( s64Value, eNUMBER_DECIMAL );		}
#else
// [Default : 32Bit] Calculate Length
NTR_INLINE MA_SIZE	MA_GetIntToBinStringLength( MA_XINT s32Value )				{ return MA_GetInt32RadixLength( s32Value, eNUMBER_BINARY );		}
NTR_INLINE MA_SIZE	MA_GetIntToOctStringLength( MA_XINT s32Value )				{ return MA_GetInt32RadixLength( s32Value, eNUMBER_OCTAL );		}
NTR_INLINE MA_SIZE	MA_GetIntToDecStringLength( MA_XINT s32Value )				{ return MA_GetInt32RadixLength( s32Value, eNUMBER_DECIMAL );		}
NTR_INLINE MA_SIZE	MA_GetIntToHexStringLength( MA_XINT s32Value )				{ return MA_GetInt32RadixLength( s32Value, eNUMBER_HEXADECIMAL );	}

NTR_INLINE MA_SIZE	MA_GetIntToStrignLength( MA_XINT s32Value )					{ return MA_GetInt32RadixLength( s32Value, eNUMBER_DECIMAL );		}
#endif

// [Default : Decimal] Calculate Length
NTR_INLINE MA_SIZE	MA_GetInt32ToStringLength( MA_XINT s32Value )				{ return MA_GetInt32RadixLength( s32Value, eNUMBER_DECIMAL );		}
NTR_INLINE MA_SIZE	MA_GetUInt32ToStringLength( MA_XUINT u32Value )				{ return MA_GetUInt32RadixLength( u32Value, eNUMBER_DECIMAL );		}
NTR_INLINE MA_SIZE	MA_GetInt64ToStringLength( MA_XLONG s64Value )				{ return MA_GetInt64RadixLength( s64Value, eNUMBER_DECIMAL );		}
NTR_INLINE MA_SIZE	MA_GetUInt64ToStringLength( MA_XULONG u64Value )				{ return MA_GetUInt64RadixLength( u64Value, eNUMBER_DECIMAL );		}

_NTR_EXTERN_C_END

#endif /* !_MA_STRINGNUMERIC_H_ */
