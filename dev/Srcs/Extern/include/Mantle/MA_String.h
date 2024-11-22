/**
* @file	MA_String.h
* @brief	Mantle string function header
* @author	Standil (cpascal@cpascal.net)
*
* @version	2009/08/19 cpascal - First release
*/

#ifndef _MA_STRING_H_
#define _MA_STRING_H_

#include "MA_Character.h"

#if defined(_NTR_WINDOWS)
#include <malloc.h>
#endif

_NTR_EXTERN_C_BEGIN

#if defined( _NTR_UNICODE )
#define MA_StringAlloc								MA_StringAllocW
#define MA_StringFree								MA_StringFreeW
#define	MA_StringLength								MA_StringLengthW
#define	MA_StringCount								MA_StringCountW
#define	MA_StringSize								MA_StringSizeW
#define MA_StringCopy								MA_StringCopyW
#define MA_StringCopyUnsafe							MA_StringCopyUnsafeW
#define MA_StringNCopy								MA_StringNCopyW
#define MA_StringNCopyUnsafe						MA_StringNCopyUnsafeW
#define MA_StringCompare							MA_StringCompareW
#define MA_StringNCompare							MA_StringNCompareW
#define MA_StringCompareCI							MA_StringCompareCIW
#define MA_StringLCompareCI							MA_StringLCompareCIW
#define MA_StringNCompareCI							MA_StringNCompareCIW
#define MA_StringLNCompareCI						MA_StringLNCompareCIW
#define MA_StringComparePos							MA_StringComparePosW
#define MA_StringComparePosCI						MA_StringComparePosCIW
#define MA_StringNComparePos						MA_StringNComparePosW
#define MA_StringNComparePosCI						MA_StringNComparePosCIW
#define MA_StringFormatv							MA_StringFormatvW
#define MA_StringFormat								MA_StringFormatW
#define MA_StringAppend								MA_StringAppendW
#define MA_StringNAppend							MA_StringNAppendW
#define MA_StringAppendf							MA_StringAppendfW
#define MA_StringAppendv							MA_StringAppendvW
#define MA_StringDuplicate							MA_StringDuplicateW
#define MA_StringDuplicateByCount					MA_StringDuplicateByCountW
#define MA_StringUpper								MA_StringUpperW
#define MA_StringLUpper								MA_StringLUpperW
#define MA_StringUpperSelf							MA_StringUpperSelfW
#define MA_StringLUpperSelf							MA_StringLUpperSelfW
#define MA_StringLower								MA_StringLowerW
#define MA_StringLLower								MA_StringLLowerW
#define MA_StringLowerSelf							MA_StringLowerSelfW
#define MA_StringLLowerSelf							MA_StringLLowerSelfW
#define MA_StringTrim								MA_StringTrimW
#define MA_StringTrimByCharacter					MA_StringTrimByCharacterW
#define	MA_StringTrimByCharacters					MA_StringTrimByCharactersW
#define MA_StringTrimLeft							MA_StringTrimLeftW
#define MA_StringTrimLeftByCharacter				MA_StringTrimLeftByCharacterW
#define MA_StringTrimLeftByCharacters				MA_StringTrimLeftByCharactersW
#define MA_StringTrimRight							MA_StringTrimRightW
#define MA_StringTrimRightByCharacter				MA_StringTrimRightByCharacterW
#define MA_StringTrimRightByCharacters				MA_StringTrimRightByCharactersW
#define MA_StringTrimSelfUnsafe						MA_StringTrimSelfUnsafeW
#define MA_StringSearchCharacter					MA_StringSearchCharacterW
#define MA_StringSearchCharacterFromRear			MA_StringSearchCharacterFromRearW
#define MA_StringSearchCharacterCI					MA_StringSearchCharacterCIW
#define MA_StringSearchCharacterFromRearCI			MA_StringSearchCharacterFromRearCIW
#define MA_StringSearchCharacterFromRearPos			MA_StringSearchCharacterFromRearPosW
#define MA_StringSearchCharacterFromRearPosCI		MA_StringSearchCharacterFromRearPosCIW
#define MA_StringSearchCharacters					MA_StringSearchCharactersW
#define MA_StringSearchCharactersFromRear			MA_StringSearchCharactersFromRearW
#define MA_StringSearchCharactersFromRearPos		MA_StringSearchCharactersFromRearPosW
#define MA_StringSearchString						MA_StringSearchStringW
#define MA_StringSearchStringFromRear				MA_StringSearchStringFromRearW
#define MA_StringSearchStringCI						MA_StringSearchStringCIW
#define MA_StringSearchStringFromRearCI				MA_StringSearchStringFromRearCIW
#define MA_StringStripNewLine						MA_StringStripNewLineW
#define	MA_StringTokenCharacter						MA_StringTokenCharacterW
#define	MA_StringToken								MA_StringTokenW
#define	MA_StringTokenCharacterUntouch				MA_StringTokenCharacterUntouchW
#define	MA_StringTokenUntouch						MA_StringTokenUntouchW
#define	MA_StringTokenCell							MA_StringTokenCellW
#define	MA_StringTokenCellUntouch					MA_StringTokenCellUntouchW
#elif defined( _NTR_ASCII )
#define MA_StringAlloc								MA_StringAllocA
#define MA_StringFree								MA_StringFreeA
#define	MA_StringCount								MA_StringCountA
#define	MA_StringLength								MA_StringLengthA
#define	MA_StringSize								MA_StringSizeA
#define MA_StringCopy								MA_StringCopyA
#define MA_StringCopyUnsafe							MA_StringCopyUnsafeA
#define MA_StringNCopy								MA_StringNCopyA
#define MA_StringNCopyUnsafe						MA_StringNCopyUnsafeA
#define MA_StringCompare							MA_StringCompareA
#define MA_StringNCompare							MA_StringNCompareA
#define MA_StringCompareCI							MA_StringCompareCIA
#define MA_StringLCompareCI							MA_StringLCompareCIA
#define MA_StringNCompareCI							MA_StringNCompareCIA
#define MA_StringLNCompareCI						MA_StringLNCompareCIA
#define MA_StringComparePos							MA_StringComparePosA
#define MA_StringComparePosCI						MA_StringComparePosCIA
#define MA_StringNComparePos						MA_StringNComparePosA
#define MA_StringNComparePosCI						MA_StringNComparePosCIA
#define MA_StringFormatv							MA_StringFormatvA
#define MA_StringFormat								MA_StringFormatA
#define MA_StringAppend								MA_StringAppendA
#define MA_StringNAppend							MA_StringNAppendA
#define MA_StringAppendf							MA_StringAppendfA
#define MA_StringAppendv							MA_StringAppendvA
#define MA_StringDuplicate							MA_StringDuplicateA
#define MA_StringDuplicateByCount					MA_StringDuplicateByCountA
#define MA_StringUpper								MA_StringUpperA
#define MA_StringLUpper								MA_StringLUpperA
#define MA_StringUpperSelf							MA_StringUpperSelfA
#define MA_StringLUpperSelf							MA_StringLUpperSelfA
#define MA_StringLower								MA_StringLowerA
#define MA_StringLLower								MA_StringLLowerA
#define MA_StringLowerSelf							MA_StringLowerSelfA
#define MA_StringLLowerSelf							MA_StringLLowerSelfA
#define MA_StringTrim								MA_StringTrimA
#define MA_StringTrimByCharacter					MA_StringTrimByCharacterA
#define	MA_StringTrimByCharacters					MA_StringTrimByCharactersA
#define MA_StringTrimLeft							MA_StringTrimLeftA
#define MA_StringTrimLeftByCharacter				MA_StringTrimLeftByCharacterA
#define MA_StringTrimLeftByCharacters				MA_StringTrimLeftByCharactersA
#define MA_StringTrimRight							MA_StringTrimRightA
#define MA_StringTrimRightByCharacter				MA_StringTrimRightByCharacterA
#define MA_StringTrimRightByCharacters				MA_StringTrimRightByCharactersA
#define MA_StringTrimSelfUnsafe						MA_StringTrimSelfUnsafeA
#define MA_StringSearchCharacter					MA_StringSearchCharacterA
#define MA_StringSearchCharacterFromRear			MA_StringSearchCharacterFromRearA
#define MA_StringSearchCharacterCI					MA_StringSearchCharacterCIA
#define MA_StringSearchCharacterFromRearCI			MA_StringSearchCharacterFromRearCIA
#define MA_StringSearchCharacterFromRearPos			MA_StringSearchCharacterFromRearPosA
#define MA_StringSearchCharacterFromRearPosCI		MA_StringSearchCharacterFromRearPosCIA
#define MA_StringSearchCharacters					MA_StringSearchCharactersA
#define MA_StringSearchCharactersFromRear			MA_StringSearchCharactersFromRearA
#define MA_StringSearchCharactersFromRearPos		MA_StringSearchCharactersFromRearPosA
#define MA_StringSearchString						MA_StringSearchStringA
#define MA_StringSearchStringFromRear				MA_StringSearchStringFromRearA
#define MA_StringSearchStringCI						MA_StringSearchStringCIA
#define MA_StringSearchStringFromRearCI				MA_StringSearchStringFromRearCIA
#define MA_StringStripNewLine						MA_StringStripNewLineA
#define	MA_StringTokenCharacter						MA_StringTokenCharacterA
#define	MA_StringToken								MA_StringTokenA
#define	MA_StringTokenCharacterUntouch				MA_StringTokenCharacterUntouchA
#define	MA_StringTokenUntouch						MA_StringTokenUntouchA
#define	MA_StringTokenCell							MA_StringTokenCellA
#define	MA_StringTokenCellUntouch					MA_StringTokenCellUntouchA
#else
#define MA_StringAlloc								MA_StringAllocE
#define MA_StringFree								MA_StringFreeE
#define	MA_StringLength								MA_StringLengthE
#define	MA_StringCount								MA_StringCountE
#define	MA_StringSize								MA_StringSizeE
#define MA_StringCopy								MA_StringCopyE
#define MA_StringCopyUnsafe							MA_StringCopyUnsafeE
#define MA_StringNCopy								MA_StringNCopyE
#define MA_StringNCopyUnsafe						MA_StringNCopyUnsafeE
#define MA_StringCompare							MA_StringCompareE
#define MA_StringNCompare							MA_StringNCompareE
#define MA_StringCompareCI							MA_StringCompareCIE
#define MA_StringLCompareCI							MA_StringLCompareCIE
#define MA_StringNCompareCI							MA_StringNCompareCIE
#define MA_StringLNCompareCI						MA_StringLNCompareCIE
#define MA_StringComparePos							MA_StringComparePosE
#define MA_StringComparePosCI						MA_StringComparePosCIE
#define MA_StringNComparePos						MA_StringNComparePosE
#define MA_StringNComparePosCI						MA_StringNComparePosCIE
#define MA_StringFormatv							MA_StringFormatvE
#define MA_StringFormat								MA_StringFormatE
#define MA_StringAppend								MA_StringAppendE
#define MA_StringNAppend							MA_StringNAppendE
#define MA_StringAppendf							MA_StringAppendfE
#define MA_StringAppendv							MA_StringAppendvE
#define MA_StringDuplicate							MA_StringDuplicateE
#define MA_StringDuplicateByCount					MA_StringDuplicateByCountE
#define MA_StringUpper								MA_StringUpperE
#define MA_StringLUpper								MA_StringLUpperE
#define MA_StringUpperSelf							MA_StringUpperSelfE
#define MA_StringLUpperSelf							MA_StringLUpperSelfE
#define MA_StringLower								MA_StringLowerE
#define MA_StringLLower								MA_StringLLowerE
#define MA_StringLowerSelf							MA_StringLowerSelfE
#define MA_StringLLowerSelf							MA_StringLLowerSelfE
#define MA_StringTrim								MA_StringTrimE
#define MA_StringTrimByCharacter					MA_StringTrimByCharacterE
#define	MA_StringTrimByCharacters					MA_StringTrimByCharactersE
#define MA_StringTrimLeft							MA_StringTrimLeftE
#define MA_StringTrimLeftByCharacter				MA_StringTrimLeftByCharacterE
#define MA_StringTrimLeftByCharacters				MA_StringTrimLeftByCharactersE
#define MA_StringTrimRight							MA_StringTrimRightE
#define MA_StringTrimRightByCharacter				MA_StringTrimRightByCharacterE
#define MA_StringTrimRightByCharacters				MA_StringTrimRightByCharactersE
#define MA_StringTrimSelfUnsafe						MA_StringTrimSelfUnsafeE
#define MA_StringSearchCharacter					MA_StringSearchCharacterE
#define MA_StringSearchCharacterFromRear			MA_StringSearchCharacterFromRearE
#define MA_StringSearchCharacterCI					MA_StringSearchCharacterCIE
#define MA_StringSearchCharacterFromRearCI			MA_StringSearchCharacterFromRearCIE
#define MA_StringSearchCharacterFromRearPos			MA_StringSearchCharacterFromRearPosA
#define MA_StringSearchCharacterFromRearPosCI		MA_StringSearchCharacterFromRearPosCIA
#define MA_StringSearchCharacters					MA_StringSearchCharactersE
#define MA_StringSearchCharactersFromRear			MA_StringSearchCharactersFromRearE
#define MA_StringSearchCharactersFromRearPos		MA_StringSearchCharactersFromRearPosE
#define MA_StringSearchString						MA_StringSearchStringE
#define MA_StringSearchStringFromRear				MA_StringSearchStringFromRearE
#define MA_StringSearchStringCI						MA_StringSearchStringCIE
#define MA_StringSearchStringFromRearCI				MA_StringSearchStringFromRearCIE
#define MA_StringStripNewLine						MA_StringStripNewLineE
#define	MA_StringTokenCharacter						MA_StringTokenCharacterE
#define	MA_StringToken								MA_StringTokenE
#define	MA_StringTokenCharacterUntouch				MA_StringTokenCharacterUntouchE
#define	MA_StringTokenUntouch						MA_StringTokenUntouchE
#define	MA_StringTokenCell							MA_StringTokenCellE
#define	MA_StringTokenCellUntouch					MA_StringTokenCellUntouchE
#endif

typedef struct _MA_MACROMAP_ENTRYA
{
	MA_LPASTR	szKey;
	MA_LPASTR	szData;
} MA_MACROMAP_ENTRYA, *MA_PREPLACEMAP_ENTRYA;

typedef struct _MA_MACROMAP_ENTRYE
{
	MA_LPESTR	szKey;
	MA_LPESTR	szData;
} MA_MACROMAP_ENTRYE, *MA_PREPLACEMAP_ENTRYE;

typedef struct _MA_MACROMAP_ENTRYW
{
	MA_LPWSTR	szKey;
	MA_LPWSTR	szData;
} MA_MACROMAP_ENTRYW, *MA_PREPLACEMAP_ENTRYW;

#if defined( _NTR_UNICODE )
#define MA_MACROMAP_ENTRY							MA_MACROMAP_ENTRYW
#define	MA_StringReplaceMacro						MA_StringReplaceMacroW
#define	MA_StringReplace							MA_StringReplaceW
#elif	defined( _NTR_UTF8 )
#define MA_MACROMAP_ENTRY							MA_MACROMAP_ENTRYE
#define	MA_StringReplaceMacro						MA_StringReplaceMacroE
#define	MA_StringReplace							MA_StringReplaceE
#else
#define MA_MACROMAP_ENTRY							MA_MACROMAP_ENTRYA
#define	MA_StringReplaceMacro						MA_StringReplaceMacroA
#define	MA_StringReplace							MA_StringReplaceA
#endif

/*
* Function: MA_StringLength
* Get the length of a string.
*
* Parameters:
*	szString [in]			- Null-terminated string
*
* Returns:
*	Each of these functions returns the number of characters in szString, excluding the terminal MA_NULL.
*/
MA_SIZE	MA_StringLengthA( MA_PCSTR IN szString );
MA_SIZE	MA_StringLengthW( MA_PCWSTR IN szString );
MA_SIZE	MA_StringLengthE( MA_PCESTR IN szString );

/*
* Function: MA_StringCount
* Get the character counts of a string.
*
* Parameters:
*	szString [in]			- Null-terminated string
*
* Returns:
*	Each of these functions returns the count of characters in szString, excluding the terminal MA_NULL.
*/
MA_SIZE	MA_StringCountA( MA_PCSTR IN szString );
MA_SIZE	MA_StringCountW( MA_PCWSTR IN szString );
MA_SIZE	MA_StringCountE( MA_PCESTR IN szString );

/*
* Function: MA_StringSize
* Get the size of a string buffer.
*
* Parameters:
*	szString [in]			- Null-terminated string
*
* Returns:
*	Each of these functions returns the number of bytes in szString, excluding the terminal MA_NULL.
*/
MA_SIZE	MA_StringSizeA( MA_PCSTR IN szString );
MA_SIZE	MA_StringSizeW( MA_PCWSTR IN szString );
MA_SIZE	MA_StringSizeE( MA_PCESTR IN szString );

/*
* Function: MA_StringCopy
* Copy one string to another
*
* Parameters:
*	szDestination [out]		- Destination string
*	sizeDestination [in]		- Size of destination string
*	szSource [in]			- Null-terminated source string
*	sizeSource[in]			- Size of source string
*
* Returns:
*	Each of these functions returns the destination string.
*/
MA_SIZE NTR_FASTCALL MA_StringCopyA( MA_PASTR OUT szDestination, MA_SIZE IN sizeDestination, MA_PCASTR IN szSource );
MA_SIZE NTR_FASTCALL MA_StringCopyW( MA_PWSTR OUT szDestination, MA_SIZE IN sizeDestination, MA_PCWSTR IN szSource );
MA_SIZE NTR_FASTCALL MA_StringCopyE( MA_PESTR OUT szDestination, MA_SIZE IN sizeDestination, MA_PCESTR IN szSource );

MA_SIZE NTR_FASTCALL MA_StringCopyUnsafeA( MA_PASTR OUT szDestination, MA_PCASTR IN szSource );
MA_SIZE NTR_FASTCALL MA_StringCopyUnsafeW( MA_PWSTR OUT szDestination, MA_PCWSTR IN szSource );
MA_SIZE NTR_FASTCALL MA_StringCopyUnsafeE( MA_PESTR OUT szDestination, MA_PCESTR IN szSource );

/*
* Function: MA_StringNCopy
* Copy one string to another
*
* Parameters:
*	szDestination [out]		- Destination string
*	sizeDestination [in]		- Size of destination string
*	szSource [in]			- Null-terminated source string
*	sizeSource[in]			- Size of source string
*
* Returns:
*	Each of these functions returns the destination string.
*/
MA_SIZE NTR_FASTCALL MA_StringNCopyA( MA_PASTR OUT szDestination, MA_SIZE IN sizeDestination, MA_PCASTR IN szSource, MA_SIZE IN sizeSource );
MA_SIZE NTR_FASTCALL MA_StringNCopyW( MA_PWSTR OUT szDestination, MA_SIZE IN sizeDestination, MA_PCWSTR IN szSource, MA_SIZE IN sizeSource );
MA_SIZE NTR_FASTCALL MA_StringNCopyE( MA_PESTR OUT szDestination, MA_SIZE IN sizeDestination, MA_PCESTR IN szSource, MA_SIZE IN sizeSource );

MA_SIZE NTR_FASTCALL MA_StringNCopyUnsafeA( MA_PASTR OUT szDestination, MA_PCASTR IN szSource, MA_SIZE IN sizeSource );
MA_SIZE NTR_FASTCALL MA_StringNCopyUnsafeW( MA_PWSTR OUT szDestination, MA_PCWSTR IN szSource, MA_SIZE IN sizeSource );
MA_SIZE NTR_FASTCALL MA_StringNCopyUnsafeE( MA_PESTR OUT szDestination, MA_PCESTR IN szSource, MA_SIZE IN sizeSource );

/*
* Function: MA_CompareString
* Compares two strings (case sensitive).
*
* Parameters:
*	szDestination [out]		- Null-terminated strings to compare. 
*	szSource [in]			- Null-terminated strings to compare. 
*
* Returns:
*	The return value indicates the relation of the substrings of szDestination and szSource as follows.
*
*	return < 0 - szDestination substring less than szSource substring
*	return = 0 - szDestination substring identical to szSource substring 
*	return > 0 - szDestination substring greater than szSource substring 
*/
MA_XINT MA_StringCompareA( MA_PCSTR OUT szDestination, MA_PCSTR IN szSource );
MA_XINT MA_StringCompareW( MA_PCWSTR OUT szDestination, MA_PCWSTR IN szSource );
MA_XINT MA_StringCompareE( MA_PCESTR OUT szDestination, MA_PCESTR IN szSource );

/*
* Function: MA_CompareString
* Compares two strings (case sensitive).
*
* Parameters:
*	szDestination [out]		- Null-terminated strings to compare. 
*	szSource [in]			- Null-terminated strings to compare. 
*	nCompareLength [in]		- Number of characters to compare.
*
* Returns:
*	The return value indicates the relation of the substrings of szDestination and szSource as follows.
*
*	return < 0 - szDestination substring less than szSource substring
*	return = 0 - szDestination substring identical to szSource substring 
*	return > 0 - szDestination substring greater than szSource substring 
*/
MA_XINT MA_StringNCompareA( MA_PCSTR OUT szDestination, MA_PCSTR IN szSource, MA_SIZE nCompareLength );
MA_XINT MA_StringNCompareW( MA_PCWSTR OUT szDestination, MA_PCWSTR IN szSource, MA_SIZE nCompareLength );
MA_XINT MA_StringNCompareE( MA_PCESTR OUT szDestination, MA_PCESTR IN szSource, MA_SIZE nCompareLength );

/*
* Function: MA_CompareStringNoCase
* Compares two strings (case insensitive).
*
* Parameters:
*	szDestination [out]		- Null-terminated strings to compare. 
*	szSource [in]			- Null-terminated strings to compare. 
*
* Returns:
*	The return value indicates the relation of the substrings of szDestination and szSource as follows.
*
*	return < 0 - szDestination substring less than szSource substring
*	return = 0 - szDestination substring identical to szSource substring 
*	return > 0 - szDestination substring greater than szSource substring 
*/
MA_XINT MA_StringCompareCIA( MA_PCSTR OUT szDestination, MA_PCSTR IN szSource );
MA_XINT MA_StringCompareCIW( MA_PCWSTR OUT szDestination, MA_PCWSTR IN szSource );
MA_XINT MA_StringCompareCIE( MA_PCESTR OUT szDestination, MA_PCESTR IN szSource );

MA_XINT MA_StringLCompareCIA( MA_PCSTR OUT szDestination, MA_PCSTR IN szSource );
MA_XINT MA_StringLCompareCIW( MA_PCWSTR OUT szDestination, MA_PCWSTR IN szSource );
MA_XINT MA_StringLCompareCIE( MA_PCESTR OUT szDestination, MA_PCESTR IN szSource );

/*
* Function: MA_CompareStringNoCase
* Compares two strings (case insensitive).
*
* Parameters:
*	szDestination [out]		- Null-terminated strings to compare. 
*	szSource [in]			- Null-terminated strings to compare. 
*	nCompareLength [in]		- Number of characters to compare.
*
* Returns:
*	The return value indicates the relation of the substrings of szDestination and szSource as follows.
*
*	return < 0 - szDestination substring less than szSource substring
*	return = 0 - szDestination substring identical to szSource substring 
*	return > 0 - szDestination substring greater than szSource substring 
*/
MA_XINT MA_StringNCompareCIA( MA_PCSTR OUT szDestination, MA_PCSTR IN szSource, MA_SIZE nCompareLength );
MA_XINT MA_StringNCompareCIW( MA_PCWSTR OUT szDestination, MA_PCWSTR IN szSource, MA_SIZE nCompareLength );
MA_XINT MA_StringNCompareCIE( MA_PCESTR OUT szDestination, MA_PCESTR IN szSource, MA_SIZE nCompareLength );

MA_XINT MA_StringLNCompareCIA( MA_PCSTR OUT szDestination, MA_PCSTR IN szSource, MA_SIZE nCompareLength );
MA_XINT MA_StringLNCompareCIW( MA_PCWSTR OUT szDestination, MA_PCWSTR IN szSource, MA_SIZE nCompareLength );
MA_XINT MA_StringLNCompareCIE( MA_PCESTR OUT szDestination, MA_PCESTR IN szSource, MA_SIZE nCompareLength );


MA_XINT MA_StringComparePosA( MA_PCSTR OUT szDestination, MA_XINT nDestinationPosition, MA_PCSTR IN szSource );
MA_XINT MA_StringComparePosW( MA_PCWSTR OUT szDestination, MA_XINT nDestinationPosition, MA_PCWSTR IN szSource );
MA_XINT MA_StringComparePosE( MA_PCESTR OUT szDestination, MA_XINT nDestinationPosition, MA_PCESTR IN szSource );

MA_XINT MA_StringComparePosCIA( MA_PCSTR OUT szDestination, MA_XINT nDestinationPosition, MA_PCSTR IN szSource );
MA_XINT MA_StringComparePosCIW( MA_PCWSTR OUT szDestination, MA_XINT nDestinationPosition, MA_PCWSTR IN szSource );
MA_XINT MA_StringComparePosCIE( MA_PCESTR OUT szDestination, MA_XINT nDestinationPosition, MA_PCESTR IN szSource );

MA_XINT MA_StringNComparePosA( MA_PCSTR OUT szDestination, MA_XINT nDestinationPosition, MA_PCSTR IN szSource, MA_SIZE nCompareLength );
MA_XINT MA_StringNComparePosW( MA_PCWSTR OUT szDestination, MA_XINT nDestinationPosition, MA_PCWSTR IN szSource, MA_SIZE nCompareLength );
MA_XINT MA_StringNComparePosE( MA_PCESTR OUT szDestination, MA_XINT nDestinationPosition, MA_PCESTR IN szSource, MA_SIZE nCompareLength );

MA_XINT MA_StringNComparePosCIA( MA_PCSTR OUT szDestination, MA_XINT nDestinationPosition, MA_PCSTR IN szSource, MA_SIZE nCompareLength );
MA_XINT MA_StringNComparePosCIW( MA_PCWSTR OUT szDestination, MA_XINT nDestinationPosition, MA_PCWSTR IN szSource, MA_SIZE nCompareLength );
MA_XINT MA_StringNComparePosCIE( MA_PCESTR OUT szDestination, MA_XINT nDestinationPosition, MA_PCESTR IN szSource, MA_SIZE nCompareLength );

/*
* Function: MA_FormatStringv
* Writes formatted data to a string. (using va_list)
*
* Parameters:
*	szDestination [out]		- Destination string. 
*	sizeDestination [in]		- Size of destination string
*	szFormat [in]			- Null-terminated format-control string. 
*	vaList[in]			- variable-argument lists.
*
* Returns:
*	Each of these functions returns the destination string.
*/
MA_SIZE	MA_StringFormatvA( MA_PSTR szDestination, MA_SIZE sizeDestination, MA_PCSTR szFormat, va_list vaList );
MA_SIZE	MA_StringFormatvW( MA_PWSTR szDestination, MA_SIZE sizeDestination, MA_PCWSTR szFormat, va_list vaList );
MA_SIZE	MA_StringFormatvE( MA_PESTR szDestination, MA_SIZE sizeDestination, MA_PCESTR szFormat, va_list vaList );

/*
* Function: MA_FormatString
* Writes formatted data to a string.
*
* Parameters:
*	szDestination [out]		- Destination string. 
*	sizeDestination [in]		- Size of destination string
*	szFormat [in]			- Null-terminated format-control string. 
*	...(argument) [in]		- Optional arguments.
*
* Returns:
*	Each of these functions returns the destination string.
*/
MA_SIZE	MA_StringFormatA( MA_PSTR szDestination, MA_SIZE sizeDestination, MA_PCSTR szFormat, ... );
MA_SIZE	MA_StringFormatW( MA_PWSTR szDestination, MA_SIZE sizeDestination, MA_PCWSTR szFormat, ... );
MA_SIZE	MA_StringFormatE( MA_PESTR szDestination, MA_SIZE sizeDestination, MA_PCESTR szFormat, ... );

/*
* Function: MA_StringAppend
* Appends a string to an existing null-terminated string.
*
* Parameters:
*	szDestination [out]		- Null-terminated destination string. 
*	sizeDestination [in]		- Size of destination string buffer.
*	szAppend [in]			- Null-terminated source string.
*	nAppendLength [in]		- Number of characters to append.
*
* Returns:
*	Each of these functions returns the destination string.
*/
MA_PSTR		MA_StringAppendA( MA_PSTR szDestination, MA_SIZE sizeDestination, MA_PCSTR szAppend );
MA_PWSTR	MA_StringAppendW( MA_PWSTR szDestination, MA_SIZE sizeDestination, MA_PCWSTR szAppend );
MA_PESTR	MA_StringAppendE( MA_PESTR szDestination, MA_SIZE sizeDestination, MA_PCESTR szAppend );

MA_PSTR		MA_StringNAppendA( MA_PSTR szDestination, MA_SIZE sizeDestination, MA_PCSTR szAppend, MA_SIZE nCount );
MA_PWSTR	MA_StringNAppendW( MA_PWSTR szDestination, MA_SIZE sizeDestination, MA_PCWSTR szAppend, MA_SIZE nCount );
MA_PESTR	MA_StringNAppendE( MA_PESTR szDestination, MA_SIZE sizeDestination, MA_PCESTR szAppend, MA_SIZE nCount );

/*
* Function: MA_StringAppendf
* Appends a fomatted data to an existing null-terminated string.
*
* Parameters:
*	szDestination [out]		- Null-terminated destination string. 
*	sizeDestination [in]		- Size of destination string buffer.
*	szFormat [in]			- Null-terminated format-control string. 
*	...(argument) [in]		- Optional arguments.
*
* Returns:
*	Each of these functions returns the destination string.
*/
MA_PSTR		MA_StringAppendfA( MA_PSTR szDestination, MA_SIZE sizeDestination, MA_PCSTR szFormat, ... );
MA_PWSTR	MA_StringAppendfW( MA_PWSTR szDestination, MA_SIZE sizeDestination, MA_PCWSTR szFormat, ... );
MA_PESTR	MA_StringAppendfE( MA_PESTR szDestination, MA_SIZE sizeDestination, MA_PCESTR szFormat, ... );

/*
* Function: MA_StringAppendv
* Appends a fomatted data to an existing null-terminated string.
*
* Parameters:
*	szDestination [out]		- Null-terminated destination string. 
*	sizeDestination [in]		- Size of destination string buffer.
*	szFormat [in]			- Null-terminated format-control string. 
*	vaList [in]			- variable-argument lists.
*
* Returns:
*	Each of these functions returns the destination string.
*/
MA_PSTR		MA_StringAppendvA( MA_PSTR szDestination, MA_SIZE sizeDestination, MA_PCSTR szFormat, va_list vaList );
MA_PWSTR	MA_StringAppendvW( MA_PWSTR szDestination, MA_SIZE sizeDestination, MA_PCWSTR szFormat, va_list vaList );
MA_PESTR	MA_StringAppendvE( MA_PESTR szDestination, MA_SIZE sizeDestination, MA_PCESTR szFormat, va_list vaList );

// --------------------------------------------
// String Allocations
// --------------------------------------------

/*
* Function: MA_AllocString
* Allocate memory for string
*
* Parameters:
*	nLength [in]			- Character length
*
* Returns:
*	Allocated memory
*/
NTR_INLINE	MA_PSTR		MA_StringAllocA( MA_SIZE nLength )		{ return (MA_PSTR)malloc( (nLength + 1) * sizeof( MA_CHAR ) );	}
NTR_INLINE	MA_PWSTR	MA_StringAllocW( MA_SIZE nLength )		{ return (MA_PWSTR)malloc( (nLength + 1) * sizeof( MA_WCHAR ) );	}
NTR_INLINE	MA_PESTR	MA_StringAllocE( MA_SIZE nLength )		{ return (MA_PESTR)malloc( (nLength + 1) * sizeof( MA_ECHAR ) );	}

NTR_INLINE	void		MA_StringFreeA( MA_PSTR szString )		{ free( szString ); 						}
NTR_INLINE	void		MA_StringFreeW( MA_PWSTR szString )		{ free( szString ); 						}
NTR_INLINE	void		MA_StringFreeE( MA_PESTR szString )		{ free( szString ); 						}

/*
* Function: MA_DuplicateString
* Duplicates a string.
*
* Parameters:
*	szSource [in]			- Null-terminated source string. 
*	nWantBufferLength [in]		- Number of characters allocate string.
*
* Returns:
*	Returns the address of the string that was copied.
*/
MA_PSTR		MA_StringDuplicateA( MA_PCSTR szSource );
MA_PWSTR	MA_StringDuplicateW( MA_PCWSTR szSource );
MA_PESTR	MA_StringDuplicateE( MA_PCESTR szSource );

MA_PSTR		MA_StringDuplicateByCountA( MA_PCSTR szSource, MA_SIZE nCount );
MA_PWSTR	MA_StringDuplicateByCountW( MA_PCWSTR szSource, MA_SIZE nCount );
MA_PESTR	MA_StringDuplicateByCountE( MA_PCESTR szSource, MA_SIZE nCount );

/*
* Function: MA_StringUpper
* Convert a string to uppercase.
*
* Parameters:
*	szDestination [out]		- Destination string.
*	szSource				- Null-terminated string to convert.
*	sizeDestination [in]	- Size of szDestination.
*	uSize [in]				- Number of characters to be converted.
*
* Returns:
*	Returns the address of the string that was converted.
*
*/
MA_PASTR	MA_StringUpperA( MA_PASTR szDestination, MA_SIZE sizeDestination, MA_PCASTR szSource, MA_SIZE uCount );
MA_PWSTR	MA_StringUpperW( MA_PWSTR szDestination, MA_SIZE sizeDestination, MA_PCWSTR szSource, MA_SIZE uCount );
MA_PESTR	MA_StringUpperE( MA_PESTR szDestination, MA_SIZE sizeDestination, MA_PCESTR szSource, MA_SIZE uCount );

MA_PASTR	MA_StringLUpperA( MA_PASTR szDestination, MA_SIZE sizeDestination, MA_PCASTR szSource, MA_SIZE uCount );
MA_PWSTR	MA_StringLUpperW( MA_PWSTR szDestination, MA_SIZE sizeDestination, MA_PCWSTR szSource, MA_SIZE uCount );
MA_PESTR	MA_StringLUpperE( MA_PESTR szDestination, MA_SIZE sizeDestination, MA_PCESTR szSource, MA_SIZE uCount );

/*
* Function: MA_StringLower
* Convert a string to lowercase.
*
* Parameters:
*	szDestination [out]		- Destination string.
*	szSource				- Null-terminated string to convert.
*	sizeDestination [in]	- Size of szDestination.
*	uSize [in]				- Number of characters to be converted.
*
* Returns:
*	Returns the address of the string that was converted.
*
*/
MA_PASTR	MA_StringLowerA( MA_PASTR szDestination, MA_SIZE sizeDestination, MA_PCASTR szSource, MA_SIZE uCount );
MA_PWSTR	MA_StringLowerW( MA_PWSTR szDestination, MA_SIZE sizeDestination, MA_PCWSTR szSource, MA_SIZE uCount );
MA_PESTR	MA_StringLowerE( MA_PESTR szDestination, MA_SIZE sizeDestination, MA_PCESTR szSource, MA_SIZE uCount );

MA_PASTR	MA_StringLLowerA( MA_PASTR szDestination, MA_SIZE sizeDestination, MA_PCASTR szSource, MA_SIZE uCount );
MA_PWSTR	MA_StringLLowerW( MA_PWSTR szDestination, MA_SIZE sizeDestination, MA_PCWSTR szSource, MA_SIZE uCount );
MA_PESTR	MA_StringLLowerE( MA_PESTR szDestination, MA_SIZE sizeDestination, MA_PCESTR szSource, MA_SIZE uCount );

/* 
* Function: MA_StringToUpperCase
* Convert a string to uppercase.
*
* Parameters:
*	szDestination [inout]	- Null-terminated string to convert.
*	uSize [in]				- Number of characters to be converted.
*
* Returns:
*	Returns the address of the string that was converted.
*
*/
MA_PSTR		MA_StringUpperSelfA( MA_PSTR szDestination, MA_SIZE uCount );
MA_PWSTR	MA_StringUpperSelfW( MA_PWSTR szDestination, MA_SIZE uCount );
MA_PESTR	MA_StringUpperSelfE( MA_PESTR szDestination, MA_SIZE uCount );

MA_PSTR		MA_StringLUpperSelfA( MA_PSTR szDestination, MA_SIZE uCount );
MA_PWSTR	MA_StringLUpperSelfW( MA_PWSTR szDestination, MA_SIZE uCount );
MA_PESTR	MA_StringLUpperSelfE( MA_PESTR szDestination, MA_SIZE uCount );

/*
* Function: MA_StringToLowerCase
* Convert a string to lowercase.
*
* Parameters:
*	szDestination [inout]	- Null-terminated string to convert.
*	uSize [in]				- Number of characters to be converted.
*
* Returns:
*	Returns the address of the string that was converted.
*
*/
MA_PSTR		MA_StringLowerSelfA( MA_PSTR szDestination, MA_SIZE uCount );
MA_PWSTR	MA_StringLowerSelfW( MA_PWSTR szDestination, MA_SIZE uCount );
MA_PESTR	MA_StringLowerSelfE( MA_PESTR szDestination, MA_SIZE uCount );

// Trim
MA_PASTR	MA_StringTrimA( MA_PASTR OUT szDestination, MA_SIZE IN sizeDestination, MA_PCASTR IN szSource );
MA_PASTR	MA_StringTrimByCharacterA( MA_PASTR OUT szDestination, MA_SIZE IN sizeDestination, MA_PCASTR IN szSource, MA_ACHAR chTarget );
MA_PASTR	MA_StringTrimByCharactersA( MA_PASTR OUT szDestination, MA_SIZE INOUT sizeDestination, MA_PCASTR IN szSource, MA_PCASTR szTarget );
MA_PASTR	MA_StringTrimLeftA( MA_PASTR OUT szDestination, MA_SIZE IN sizeDestination, MA_PCASTR IN szSource );
MA_PASTR	MA_StringTrimLeftByCharacterA( MA_PASTR OUT szDestination, MA_SIZE IN sizeDestination, MA_PCASTR IN szSource, MA_ACHAR chTarget );
MA_PASTR	MA_StringTrimLeftByCharactersA( MA_PASTR OUT szDestination, MA_SIZE INOUT sizeDestination, MA_PCASTR IN szSource, MA_PCASTR szTarget );
MA_PASTR	MA_StringTrimRightA( MA_PASTR OUT szDestination, MA_SIZE IN sizeDestination, MA_PCASTR IN szSource );
MA_PASTR	MA_StringTrimRightByCharacterA( MA_PASTR OUT szDestination, MA_SIZE IN sizeDestination, MA_PCASTR IN szSource, MA_ACHAR chTarget );
MA_PASTR	MA_StringTrimRightByCharactersA( MA_PASTR OUT szDestination, MA_SIZE IN sizeDestination, MA_PCASTR IN szSource, MA_PCASTR szTarget );
MA_PASTR	MA_StringTrimSelfUnsafeA( MA_PASTR INOUT szString );

MA_PWSTR	MA_StringTrimW( MA_PWSTR OUT szDestination, MA_SIZE IN sizeDestination, MA_PCWSTR IN szSource );
MA_PWSTR	MA_StringTrimByCharacterW( MA_PWSTR OUT szDestination, MA_SIZE IN sizeDestination, MA_PCWSTR IN szSource, MA_WCHAR chTarget );
MA_PWSTR	MA_StringTrimByCharactersW( MA_PWSTR OUT szDestination, MA_SIZE INOUT sizeDestination, MA_PCWSTR IN szSource, MA_PCWSTR szTarget );
MA_PWSTR	MA_StringTrimLeftW( MA_PWSTR OUT szDestination, MA_SIZE IN sizeDestination, MA_PCWSTR IN szSource );
MA_PWSTR	MA_StringTrimLeftByCharacterW( MA_PWSTR OUT szDestination, MA_SIZE IN sizeDestination, MA_PCWSTR IN szSource, MA_WCHAR chTarget );
MA_PWSTR	MA_StringTrimLeftByCharactersW( MA_PWSTR OUT szDestination, MA_SIZE INOUT sizeDestination, MA_PCWSTR IN szSource, MA_PCWSTR szTarget );
MA_PWSTR	MA_StringTrimRightW( MA_PWSTR OUT szDestination, MA_SIZE IN sizeDestination, MA_PCWSTR IN szSource );
MA_PWSTR	MA_StringTrimRightByCharacterW( MA_PWSTR OUT szDestination, MA_SIZE IN sizeDestination, MA_PCWSTR IN szSource, MA_WCHAR chTarget );
MA_PWSTR	MA_StringTrimRightByCharactersW( MA_PWSTR OUT szDestination, MA_SIZE IN sizeDestination, MA_PCWSTR IN szSource, MA_PCWSTR szTarget );
MA_PWSTR	MA_StringTrimSelfUnsafeW( MA_PWSTR INOUT szString );

MA_PESTR	MA_StringTrimE( MA_PESTR OUT szDestination, MA_SIZE IN sizeDestination, MA_PCESTR IN szSource );
MA_PESTR	MA_StringTrimByCharacterE( MA_PESTR OUT szDestination, MA_SIZE IN sizeDestination, MA_PCESTR IN szSource, MA_ECHAR chTarget );
MA_PESTR	MA_StringTrimByCharactersE( MA_PESTR OUT szDestination, MA_SIZE INOUT sizeDestination, MA_PCESTR IN szSource, MA_PCESTR szTarget );
MA_PESTR	MA_StringTrimLeftE( MA_PESTR OUT szDestination, MA_SIZE IN sizeDestination, MA_PCESTR IN szSource );
MA_PESTR	MA_StringTrimLeftByCharacterE( MA_PESTR OUT szDestination, MA_SIZE IN sizeDestination, MA_PCESTR IN szSource, MA_ECHAR chTarget );
MA_PESTR	MA_StringTrimLeftByCharactersE( MA_PESTR OUT szDestination, MA_SIZE INOUT sizeDestination, MA_PCESTR IN szSource, MA_PCESTR szTarget );
MA_PESTR	MA_StringTrimRightE( MA_PESTR OUT szDestination, MA_SIZE IN sizeDestination, MA_PCESTR IN szSource );
MA_PESTR	MA_StringTrimRightByCharacterE( MA_PESTR OUT szDestination, MA_SIZE IN sizeDestination, MA_PCESTR IN szSource, MA_ECHAR chTarget );
MA_PESTR	MA_StringTrimRightByCharactersE( MA_PESTR OUT szDestination, MA_SIZE IN sizeDestination, MA_PCESTR IN szSource, MA_PCESTR szTarget );
MA_PESTR	MA_StringTrimSelfUnsafeE( MA_PESTR INOUT szString );

/*
* Function: MA_SearchCharacter
* Returns a pointer to the first occurrence of a search character in a string.
*
* Parameters:
*	szSource [in]			- Null-terminated string to search.
*	chPurpose [in]			- Character to serach for.
*
* Returns:
*	Returns the address of the string that was searched or MA_NULL if chPurpose does not appear in szSource..
*/
MA_PCASTR	MA_StringSearchCharacterA( MA_PCASTR szSource, MA_ACHAR chPurpose );
MA_PCWSTR	MA_StringSearchCharacterW( MA_PCWSTR szSource, MA_WCHAR chPurpose );
MA_PCESTR	MA_StringSearchCharacterE( MA_PCESTR szSource, MA_ECHAR chPurpose );

/*
* Function: MA_SearchCharacter
* Returns a pointer to the first occurrence of a character in spcified character set
*
* Parameters:
*	szSource [in]			- Null-terminated string to search.
*	szPurpose [in]			- Null-terminated character set to search for.
*
* Returns:
*	Returns the address of the string that was searched or MA_NULL if szPurpose does not appear in szSource.
*/
MA_PCASTR	MA_StringSearchCharactersA( MA_PCASTR szSource, MA_PCASTR szPurpose );
MA_PCWSTR	MA_StringSearchCharactersW( MA_PCWSTR szSource, MA_PCWSTR szPurpose );
MA_PCESTR	MA_StringSearchCharactersE( MA_PCESTR szSource, MA_PCESTR szPurpose );

/*
* Function: MA_SearchString
* Returns a pointer to the first occurrence of a search string in a string.
*
* Parameters:
*	szSource [in]			- Null-terminated string to search.
*	szPurpose [in]			- Null-terminated string to search for.
*
* Returns:
*	Returns the address of the string that was searched or MA_NULL if szPurpose does not appear in szSource.
*/
MA_PCASTR	MA_StringSearchStringA( MA_PCASTR szSource, MA_PCASTR szPurpose );
MA_PCWSTR	MA_StringSearchStringW( MA_PCWSTR szSource, MA_PCWSTR szPurpose );
MA_PCESTR	MA_StringSearchStringE( MA_PCESTR szSource, MA_PCESTR szPurpose );

/*
* Function: MA_SearchCharacter
* Returns a pointer to the last occurrence of a search character in a string.
*
* Parameters:
*	szSource [in]			- Null-terminated string to search.
*	chPurpose [in]			- Character to serach for.
*
* Returns:
*	Returns the address of the string that was searched or NULL if chPurpose does not appear in szSource.
*/
MA_PCASTR	MA_StringSearchCharacterFromRearA( MA_PCASTR szSource, MA_ACHAR chPurpose );
MA_PCWSTR	MA_StringSearchCharacterFromRearW( MA_PCWSTR szSource, MA_WCHAR chPurpose );
MA_PCESTR	MA_StringSearchCharacterFromRearE( MA_PCESTR szSource, MA_ECHAR chPurpose );

MA_PCASTR	MA_StringSearchCharacterFromRearPosA( MA_PCASTR szSource, MA_XINT nSourcePosition, MA_ACHAR chPurpose );
MA_PCWSTR	MA_StringSearchCharacterFromRearPosW( MA_PCWSTR szSource, MA_XINT nSourcePosition, MA_WCHAR chPurpose );
MA_PCESTR	MA_StringSearchCharacterFromRearPosE( MA_PCESTR szSource, MA_XINT nSourcePosition, MA_ECHAR chPurpose );

MA_PCASTR	MA_StringSearchCharacterFromRearPosCIA( MA_PCASTR szSource, MA_XINT nSourcePosition, MA_ACHAR chPurpose );
MA_PCWSTR	MA_StringSearchCharacterFromRearPosCIW( MA_PCWSTR szSource, MA_XINT nSourcePosition, MA_WCHAR chPurpose );
MA_PCESTR	MA_StringSearchCharacterFromRearPosCIE( MA_PCESTR szSource, MA_XINT nSourcePosition, MA_ECHAR chPurpose );

/*
* Function: MA_StringSearchCharacterFromRear
* Returns a pointer to the last occurrence of a character in spcified character set
*
* Parameters:
*	szSource [in]			- Null-terminated string to search.
*	szPurpose [in]			- Null-terminated character set to search for.
*
* Returns:
*	Returns the address of the string that was searched or MA_NULL if szPurpose does not appear in szSource.
*/
MA_PCASTR	MA_StringSearchCharactersFromRearA( MA_PCASTR szSource, MA_PCASTR szPurpose );
MA_PCWSTR	MA_StringSearchCharactersFromRearW( MA_PCWSTR szSource, MA_PCWSTR szPurpose );
MA_PCESTR	MA_StringSearchCharactersFromRearE( MA_PCESTR szSource, MA_PCESTR szPurpose );

MA_PCASTR	MA_StringSearchCharactersFromRearPosA( MA_PCASTR szSource, MA_XINT nSourcePosition, MA_PCASTR szPurpose );
MA_PCWSTR	MA_StringSearchCharactersFromRearPosW( MA_PCWSTR szSource, MA_XINT nSourcePosition, MA_PCWSTR szPurpose );
MA_PCESTR	MA_StringSearchCharactersFromRearPosE( MA_PCESTR szSource, MA_XINT nSourcePosition, MA_PCESTR szPurpose );

/*
* Function: MA_SearchStringFromRear
* Returns a pointer to the last occurrence of a search string in a string.
*
* Parameters:
*	szSource [in]			- Null-terminated string to search.
*	szPurpose [in]			- Null-terminated string to search for.
*	uOffset [in]			- Begin offset of szSource to search.
*
* Returns:
*	Returns the address of the string that was searched or MA_NULL if szPurpose does not appear in szSource.
*/
MA_PCASTR	MA_StringSearchStringFromRearA( MA_PCASTR szSource, MA_PCASTR szPurpose );
MA_PCWSTR	MA_StringSearchStringFromRearW( MA_PCWSTR szSource, MA_PCWSTR szPurpose );
MA_PCESTR	MA_StringSearchStringFromRearE( MA_PCESTR szSource, MA_PCESTR szPurpose );

/*
* Function: MA_SearchCharacterCI
* Returns a pointer to the first occurrence of a search character in a string (case insensitive)
*
* Parameters:
*	szSource [in]			- Null-terminated string to search.
*	chPurpose [in]			- Character to serach for.
*
* Returns:
*	Returns the address of the string that was searched or MA_NULL if chPurpose does not appear in szSource.
*/
MA_PCASTR	MA_StringSearchCharacterCIA( MA_PCASTR szSource, MA_ACHAR chPurpose );
MA_PCWSTR	MA_StringSearchCharacterCIW( MA_PCWSTR szSource, MA_WCHAR chPurpose );
MA_PCESTR	MA_StringSearchCharacterCIE( MA_PCESTR szSource, MA_ECHAR chPurpose );

/*
* Function: MA_SearchCharacterCIFromRear
* Returns a pointer to the last occurrence of a search character in a string (case insensitive)
*
* Parameters:
*	szSource [in]			- Null-terminated string to search.
*	chPurpose [in]			- Character to serach for.
*	uOffset [in]			- Begin offset of szSource to search.
*
* Returns:
*	Returns the address of the string that was searched or MA_NULL if chPurpose does not appear in szSource.
*/
MA_PCASTR	MA_StringSearchCharacterFromRearCIA( MA_PCASTR szSource, MA_ACHAR chPurpose );
MA_PCWSTR	MA_StringSearchCharacterFromRearCIW( MA_PCWSTR szSource, MA_WCHAR chPurpose );
MA_PCESTR	MA_StringSearchCharacterFromRearCIE( MA_PCESTR szSource, MA_ECHAR chPurpose );

/*
* Function: MA_SearchCharacterCIFromRear
* Returns a pointer to the first occurrence of a search string in a string (case insensitive)
*
* Parameters:
*	szSource [in]			- Null-terminated string to search.
*	chPurpose [in]			- Character to serach for.
*	uOffset [in]			- Begin offset of szSource to search.
*
* Returns:
*	Returns the address of the string that was searched or MA_NULL if chPurpose does not appear in szSource.
*/
MA_PCASTR	MA_StringSearchStringCIA( MA_PCASTR szSource, MA_PCASTR szPurpose );
MA_PCWSTR	MA_StringSearchStringCIW( MA_PCWSTR szSource, MA_PCWSTR szPurpose );
MA_PCESTR	MA_StringSearchStringCIE( MA_PCESTR szSource, MA_PCESTR szPurpose );

/*
* Function: MA_SearchStringCIFromRear
* Returns a pointer to the last occurrence of a search string in a string (case insensitive)
*
* Parameters:
*	szSource [in]			- Null-terminated string to search.
*	chPurpose [in]			- Character to serach for.
*	uOffset [in]			- Begin offset of szSource to search.
*
* Returns:
*	Returns the address of the string that was searched or MA_NULL if chPurpose does not appear in szSource.
*
*/
MA_PCASTR		MA_StringSearchStringFromRearCIA( MA_PCASTR szSource, MA_PCASTR szPurpose );
MA_PCWSTR		MA_StringSearchStringFromRearCIW( MA_PCWSTR szSource, MA_PCWSTR szPurpose );
MA_PCESTR		MA_StringSearchStringFromRearCIE( MA_PCESTR szSource, MA_PCESTR szPurpose );


MA_PASTR		MA_StringStripNewLineA( MA_PASTR szSource );
MA_PWSTR		MA_StringStripNewLineW( MA_PWSTR szSource );
MA_PESTR		MA_StringStripNewLineE( MA_PESTR szSource );



MA_PASTR		MA_StringTokenCharacterA( MA_PASTR szSource, MA_CHAR chPurpose, MA_PASTR *pszNext );
MA_PWSTR		MA_StringTokenCharacterW( MA_PWSTR szSource, MA_WCHAR chPurpose, MA_PWSTR *pszNext );
MA_PESTR		MA_StringTokenCharacterE( MA_PESTR szSource, MA_UTF8 chPurpose, MA_PESTR *pszNext );

MA_PASTR		MA_StringTokenA( MA_PASTR szSource, MA_PCASTR szPurpose, MA_PASTR *pszNext );
MA_PWSTR		MA_StringTokenW( MA_PWSTR szSource, MA_PCWSTR szPurpose, MA_PWSTR *pszNext );
MA_PESTR		MA_StringTokenE( MA_PESTR szSource, MA_PCESTR szPurpose, MA_PESTR *pszNext );

MA_PCASTR		MA_StringTokenCharacterUntouchA( MA_PCASTR szSource, MA_CHAR chPurpose, MA_PCASTR *pszNext, MA_SIZE *psizeToken );
MA_PCWSTR		MA_StringTokenCharacterUntouchW( MA_PCWSTR szSource, MA_WCHAR chPurpose, MA_PCWSTR *pszNext, MA_SIZE *psizeToken );
MA_PCESTR		MA_StringTokenCharacterUntouchE( MA_PCESTR szSource, MA_UTF8 chPurpose, MA_PCESTR *pszNext, MA_SIZE *psizeToken );

MA_PCASTR		MA_StringTokenUntouchA( MA_PCASTR szSource, MA_PCASTR szPurpose, MA_PCASTR *pszNext, MA_SIZE *psizeToken );
MA_PCWSTR		MA_StringTokenUntouchW( MA_PCWSTR szSource, MA_PCWSTR szPurpose, MA_PCWSTR *pszNext, MA_SIZE *psizeToken );
MA_PCESTR		MA_StringTokenUntouchE( MA_PCESTR szSource, MA_PCESTR szPurpose, MA_PCESTR *pszNext, MA_SIZE *psizeToken );

MA_PASTR		MA_StringTokenCellA( MA_PASTR szSource, MA_CHAR chPurpose, MA_CHAR chQuote, MA_PASTR *pszNext );
MA_PWSTR		MA_StringTokenCellW( MA_PWSTR szSource, MA_WCHAR chPurpose, MA_WCHAR chQuote, MA_PWSTR *pszNext );
MA_PESTR		MA_StringTokenCellE( MA_PESTR szSource, MA_UTF8 chPurpose, MA_UTF8 chQuote, MA_PESTR *pszNext );

MA_PCASTR		MA_StringTokenCellUntouchA( MA_PCASTR szSource, MA_CHAR chPurpose, MA_CHAR chQuote, MA_PCASTR *pszNext, MA_SIZE *psizeToken );
MA_PCWSTR		MA_StringTokenCellUntouchW( MA_PCWSTR szSource, MA_WCHAR chPurpose, MA_WCHAR chQuote, MA_PCWSTR *pszNext, MA_SIZE *psizeToken );
MA_PCESTR		MA_StringTokenCellUntouchE( MA_PCESTR szSource, MA_UTF8 chPurpose, MA_UTF8 chQuote, MA_PCESTR *pszNext, MA_SIZE *psizeToken );


MA_BOOL			MA_StringReplaceMacroA( MA_LPASTR tszDestination, MA_SIZE sizeDestination, MA_LPCASTR tszSource, MA_PREPLACEMAP_ENTRYA pstMacroMap );
MA_BOOL			MA_StringReplaceMacroE( MA_LPESTR tszDestination, MA_SIZE sizeDestination, MA_LPCESTR tszSource, MA_PREPLACEMAP_ENTRYE pstMacroMap );
MA_BOOL			MA_StringReplaceMacroW( MA_LPWSTR tszDestination, MA_SIZE sizeDestination, MA_LPCWSTR tszSource, MA_PREPLACEMAP_ENTRYW pstMacroMap );

MA_BOOL			MA_StringReplaceA( MA_LPASTR tszDestination, MA_SIZE sizeDestination, MA_LPCASTR tszSource, MA_PREPLACEMAP_ENTRYA pstMacroMap );
MA_BOOL			MA_StringReplaceE( MA_LPESTR tszDestination, MA_SIZE sizeDestination, MA_LPCESTR tszSource, MA_PREPLACEMAP_ENTRYE pstMacroMap );
MA_BOOL			MA_StringReplaceW( MA_LPWSTR tszDestination, MA_SIZE sizeDestination, MA_LPCWSTR tszSource, MA_PREPLACEMAP_ENTRYW pstMacroMap );

_NTR_EXTERN_C_END

#endif /* !_MA_STRING_H_ */
