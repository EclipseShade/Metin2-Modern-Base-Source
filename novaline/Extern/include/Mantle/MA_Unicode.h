/**
* @file		MA_Unicode.h
* @brief	Mantle Unicode Conversion functions
* @author	Standil (cpascal@cpascal.net)
 *
 * @version	2009/08/19 cpascal - First release
 * @version 2010/02/27 cpascal - Involved from Unicode, Inc's code.
*/

#ifndef	_MA_UNICODE_H_
#define	_MA_UNICODE_H_

#include "MA_String.h"

_MA_NAMESPACE_BEGIN

//MA_SIZE MA_UTF8toUTF32( const MA_UTF8* IN szFrom, MA_SIZE IN sizeFrom, MA_UTF32* OUT szTo, MA_SIZE IN sizeTo, MA_BOOL bStrict );
//MA_SIZE MA_UTF16toUTF32( const MA_UTF16* IN szFrom, MA_SIZE IN sizeFrom, MA_UTF32* OUT szTo, MA_SIZE IN sizeTo, MA_BOOL bStrict );
//MA_SIZE MA_UTF32toUTF8( const MA_UTF32* IN szFrom, MA_SIZE IN sizeFrom, MA_UTF8* OUT szTo, MA_SIZE IN sizeTo, MA_BOOL bStrict );
//MA_SIZE MA_UTF32toUTF16( const MA_UTF32* IN szFrom, MA_SIZE IN sizeFrom, MA_UTF16* OUT szTo, MA_SIZE IN sizeTo, MA_BOOL bStrict );
MA_SIZE	MA_UTF8toUTF16( const MA_UTF8* IN szFrom, MA_SIZE IN sizeFrom, MA_UTF16* OUT szTo, MA_SIZE IN sizeTo, MA_BOOL bStrict );
MA_SIZE	MA_UTF16toUTF8( const MA_UTF16* IN szFrom, MA_SIZE IN sizeFrom, MA_UTF8* OUT szTo, MA_SIZE IN sizeTo, MA_BOOL bStrict );

_MA_NAMESPACE_END

#endif //!_MA_UNICODE_H_
