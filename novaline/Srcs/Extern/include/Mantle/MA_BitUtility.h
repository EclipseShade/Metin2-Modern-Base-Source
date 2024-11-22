/**
 * @file	MA_BitUtiltiy.h
 * @brief	Bit utility functions header file
 * @author	Standil (cpascal@cpascal.net)
 *
 * @version	2008/04/24 cpascal - First release
 */

#ifndef _MA_BITUTILITY_H_
#define _MA_BITUTILITY_H_

_NTR_EXTERN_C_BEGIN

/*
 * Macro: BitFields
 * Bit field Macros
 *
 * (start code)
 * 
 * MA_BITFARRAY_DECLARE( bfFlags, 1000 );	// MA_BitField 선언 (1000개)
 * 
 * MA_BITFARRAY_ZERO( bfFlags );		// MA_BitField 초기화
 * MA_BITFARRAY_CHECK( bfFlags, 103 );		// 103번째 비트 확인 (TRUE/FALSE 반환)
 * MA_BITFARRAY_REMOVE( bfFlags, 103 );		// 103번째 비트 제거
 * MA_BITFARRAY_SET( bfFlags, 103 );		// 103번째 비트 셋팅
 *
 * (end)
 */
#define MA_BIT_CHECK( LHSBit, RHSBit )			( (LHSBit) & (RHSBit) )		// 비트 검사
#define MA_BIT_SET( LHSBit, RHSBit )			( (LHSBit) |= (RHSBit) )	// 비트 설정
#define MA_BIT_REMOVE( LHSBit, RHSBit )			( (LHSBit) &= ~(RHSBit) )	// 비트 해제
#define MA_BIT_ZERO( LHSBit )				( (LHSBit) = 0 )		// 전체비트 해제
#define	MA_BIT_MODIFY( Flags, Add, Remove )		{ MA_BIT_SET( Flags, Add ); MA_BIT_REMOVE( Flags, Remove );	}

// Bit fields
typedef MA_DWORD					MA_BitField;

// Number of Bits per BYtes
#define MA_BITF_FULL					0xFFFFFFFF
#define MA_NBBY						8				// 한 바이트당 비트수(Number of Bits per Byte - Glib 에 정의)
#define MA_NFDBITS					( sizeof( MA_BitField ) * MA_NBBY )
// 원하는 bit field 수를 만족하는 최소 바이트
#define MA_MINBYTES( MaxBits )				( ((MaxBits) + ((MA_NFDBITS)-1)) / ( MA_NFDBITS ) )

#define MA_BITF_SET( BitField, Position )		( BitField |=  (1 << ( Position ) ) )
#define MA_BITF_REMOVE( BitField, Position )		( BitField &= ~(1 << ( Position ) ) )
#define MA_BITF_CHECK( BitField, Position )		( BitField &   (1 << ( Position ) ) )
#define MA_BITF_ZERO( BitField )			memset( BitField, 0, sizeof( u32 ) );

#define MA_BITFARRAY_DECLARE( BitFieldArray, MaxBits )	MA_BitField	BitFieldArray[ MA_MINBYTES( MaxBits ) ]	= { 0, }
#define MA_BITFARRAY_SET( BitFieldArray, Position )	( (BitFieldArray)[ (Position)/MA_NFDBITS ] |=  (1 << ( (Position) & (MA_NFDBITS-1)) ) )
#define MA_BITFARRAY_REMOVE( BitFieldArray, Position )	( (BitFieldArray)[ (Position)/MA_NFDBITS ] &= ~(1 << ( (Position) & (MA_NFDBITS-1)) ) )
#define MA_BITFARRAY_CHECK( BitFieldArray, Position )	( (BitFieldArray)[ (Position)/MA_NFDBITS ] &   (1 << ( (Position) & (MA_NFDBITS-1)) ) )
#define MA_BITFARRAY_ZERO( BitFieldArray )		memset( BitFieldArray, 0, sizeof( *BitFieldArray ) );

extern MA_INT MA_FindHighestSetBitU32( MA_U32 dwValue );
extern MA_INT MA_FindHighestSetBitU64( MA_U64 qwValue );

_NTR_EXTERN_C_END

#endif // !_MA_BITUTILITY_H_
