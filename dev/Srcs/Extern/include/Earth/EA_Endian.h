/**
 * @file	EA_Endian.h
 * @author	bugmail (bugmail@buddygames.co.kr)
 * @brief	Endian 변환 관련 함수들
 *
 * @version	2005/10/19 bugmail - First release
 */

#ifndef _EA_ENDIAN_H_
#define _EA_ENDIAN_H_

_EA_NAMESPACE_BEGIN

/*===============ENDIAN SWAP MACROS===============*/
/**
 * @brief	16bit 변수의 Endian방식을 뒤집는다.
 * @author	bugmail (bugmail@buddygames.co.kr)
 */
#define		EA_SWAP_ENDIAN_16BIT( Variable )	( ( ( Variable >>  8 ) & 0x00FF )		\
							| ( ( Variable <<  8 ) & 0xFF00 ) )

/**
 * @brief	32bit 변수의 Endian방식을 뒤집는다.
 * @author	bugmail (bugmail@buddygames.co.kr)
 */
#define		EA_SWAP_ENDIAN_32BIT( Variable )	( ( ( Variable >> 24 ) & 0x000000FF )		\
							| ( ( Variable >>  8 ) & 0x0000FF00 )		\
							| ( ( Variable <<  8 ) & 0x00FF0000 )		\
							| ( ( Variable << 24 ) & 0xFF000000 ) )


/**
 * @brief	64bit 변수의 Endian방식을 뒤집는다.
 * @author	bugmail (bugmail@buddygames.co.kr)
 */
#define		EA_SWAP_ENDIAN_64BIT( Variable )	( ( ( Variable >> 56 ) & 0x00000000000000FF )	\
							| ( ( Variable >> 40 ) & 0x000000000000FF00 )	\
							| ( ( Variable >> 24 ) & 0x0000000000FF0000 )	\
							| ( ( Variable >>  8 ) & 0x00000000FF000000 )	\
							| ( ( Variable <<  8 ) & 0x000000FF00000000 )	\
							| ( ( Variable << 24 ) & 0x0000FF0000000000 )	\
							| ( ( Variable << 40 ) & 0x00FF000000000000 )	\
							| ( ( Variable << 56 ) & 0xFF00000000000000 ) )

#define	EA_TO_LITTLEENDIAN_16BIT( nValue )	nValue
#define	EA_TO_LITTLEENDIAN_32BIT( nValue )	nValue
#define	EA_TO_LITTLEENDIAN_64BIT( nValue )	nValue
#define	EA_TO_BIGENDIAN_16BIT( nValue )		EA_SWAP_ENDIAN_16BIT( nValue )
#define	EA_TO_BIGENDIAN_32BIT( nValue )		EA_SWAP_ENDIAN_32BIT( nValue )
#define	EA_TO_BIGENDIAN_64BIT( nValue )		EA_SWAP_ENDIAN_64BIT( nValue )

#define	EA_FROM_LITTLEENDIAN_16BIT( nValue )	nValue
#define	EA_FROM_LITTLEENDIAN_32BIT( nValue )	nValue
#define	EA_FROM_LITTLEENDIAN_64BIT( nValue )	nValue
#define	EA_FROM_BIGENDIAN_16BIT( nValue )	EA_SWAP_ENDIAN_16BIT( nValue )
#define	EA_FROM_BIGENDIAN_32BIT( nValue )	EA_SWAP_ENDIAN_32BIT( nValue )
#define	EA_FROM_BIGENDIAN_64BIT( nValue )	EA_SWAP_ENDIAN_64BIT( nValue )

void EA_SwapEndians_16BIT( u16* pu16Output, u16* pu16Input, size_t sizeCount );
void EA_SwapEndians_32BIT( u32* pu32Output, u32* pu32Input, size_t sizeCount );
void EA_SwapEndians_64BIT( u64* pu64Output, u64* pu64Input, size_t sizeCount );

void EA_SwapEndians_16BIT( u16* pu16Endians, size_t sizeCount );
void EA_SwapEndians_32BIT( u32* pu32Endians, size_t sizeCount );
void EA_SwapEndians_64BIT( u64* pu64Endians, size_t sizeCount );

#define	EA_TO_LITTLEENDIANS_16BIT( pOut, pIn, sizeCount )	memcpy( pOut, pIn, sizeCount * sizeof( u16 ) )
#define	EA_TO_LITTLEENDIANS_32BIT( pOut, pIn, sizeCount )	memcpy( pOut, pIn, sizeCount * sizeof( u32 ) )
#define	EA_TO_LITTLEENDIANS_64BIT( pOut, pIn, sizeCount )	memcpy( pOut, pIn, sizeCount * sizeof( u64 ) )
#define	EA_TO_BIGENDIANS_16BIT( pOut, pIn, sizeCount )		EA_SwapEndians_16BIT( pOut, pIn, sizeCount )
#define	EA_TO_BIGENDIANS_32BIT( pOut, pIn, sizeCount )		EA_SwapEndians_32BIT( pOut, pIn, sizeCount )
#define	EA_TO_BIGENDIANS_64BIT( pOut, pIn, sizeCount )		EA_SwapEndians_64BIT( pOut, pIn, sizeCount )

_EA_NAMESPACE_END

#endif // !_EA_ENDIAN_H_