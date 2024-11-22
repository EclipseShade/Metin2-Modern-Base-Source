/**
* @file		MA_TCharacterTraits.h
* @brief	TCharacterTraits class
* @author	cppis (cppeins@gmail.com)
* 
* @version	2007/03/20 cppis - First release
*/

#ifndef _MA_TCHARACTERTRAITS_H_
#define _MA_TCHARACTERTRAITS_H_

#include "MA_String.h"

_MA_NAMESPACE_BEGIN

template<typename T>
struct MA_TCharacterTraits
{
	typedef typename T				MY_CHAR;
	typedef	typename MY_CHAR*		MY_PSTR;
	typedef	typename const MY_CHAR*	MY_PCSTR;
	typedef typename long			MY_LONG;
	typedef typename MA_SIZE		MY_SIZE;
	typedef typename MA_XUINT		MY_UINT;


	/*
	 * Method: sAssign
	 * Assign for Character.
	 *
	 * Parameters:
	 *	rLHS [in, out]	- reference of Left-Hand Side Operand
	 *	rRHS [in]	- reference of Right-Hand Side Operand
	 */
	static VOID	sAssign( MY_CHAR& INOUT rLHS, const MY_CHAR& IN rRHS )
	{
		rLHS = rRHS;
	}

	/*
	 * Method: sAssign
	 * Assign sizeCount * Character to [szString, ...).
	 *
	 * Parameters:
	 *	szString [in]	- String to assign
	 *	sizeCount [in]	- Count to assign
	 *	Char [in]	- Character to assign
	 *
	 * Returns:
	 *	returns Assigned String
	 */
	static MY_PSTR	sAssign( MY_PSTR IN szString, MY_SIZE IN sizeCount, MY_CHAR IN Char )
	{
		MY_PSTR	szNext	= szString;
		for( ; 0 < sizeCount; --sizeCount, ++szNext )
			sAssign( *szNext, Char );
		return szString;
	}

	/*
	 * Method: sEqual
	 * Test for Character Equality.
	 *
	 * Parameters:
	 *	rLHS [in]	- reference of Left-Hand Side Operand
	 *	rRHS [in]	- reference of Right-Hand Side Operand
	 *
	 * Returns:
	 *	If two operand is equal returns true, else returns false
	 */
	static bool	sEqual( const MY_CHAR& IN rLHS, const MY_CHAR& IN rRHS )
	{
		return (rLHS == rRHS);
	}

	/*
	 * Method: sCompare
	 * Compare if rLHS precedes rRHS.
	 *
	 * Parameters:
	 *	rLHS [in]	- reference of Left-Hand Side Operand
	 *	rRHS [in]	- reference of Right-Hand Side Operand
	 *
	 * Returns:
	 *	If rLHS is less than rRHS returns true, else returns false
	 */
	static bool	sCompare( const MY_CHAR& IN rLHS, const MY_CHAR& IN rRHS )
	{
		return (rLHS < rRHS);
	}

	/*
	 * Method: sCompare
	 * Compare if szDestination precedes szSource.
	 * Compare [szDestination, szDestination + sizeCount) with [szSource, ...).
	 *
	 * Parameters:
	 *	szDestination [in]	- Destination string to compare
	 *	szSource [in]		- Source string to compare
	 *	sizeCount [in]		- Count to compare
	 *
	 * Returns:
	 *	The return value indicates the relation of the substrings of szDestination and szSource as follows.
	 *
	 *	return < 0 - szDestination substring less than szSource substring
	 *	return = 0 - szDestination substring identical to szSource substring 
	 *	return > 0 - szDestination substring greater than szSource substring 
	 */
	static int	sCompare( MY_PCSTR IN szDestination, MY_PCSTR IN szSource, MY_UINT IN sizeCount )
	{
		for( ; 0 < sizeCount; --sizeCount, ++szDestination, ++szSource )
			if( !sEqual( *szDestination, *szSource ) )
				return (sCompare( *szDestination, *szSource )? -1 : +1);
		return 0;
	}

	/*
	 * Method: sCompareNoCase
	 * Compare if szDestination precedes szSource with no case.
	 * Compare [szDestination, szDestination + sizeCount) with [szSource, ...).
	 *
	 * Parameters:
	 *	szDestination [in]	- Destination string to compare
	 *	szSource [in]		- Source string to compare
	 *	sizeCount [in]		- Count to compare
	 *
	 * Returns:
	 *	The return value indicates the relation of the substrings of szDestination and szSource as follows.
	 *
	 *	return < 0 - szDestination substring less than szSource substring
	 *	return = 0 - szDestination substring identical to szSource substring 
	 *	return > 0 - szDestination substring greater than szSource substring 
	 */
	static MA_XINT	sCompareNoCase( MY_PCSTR IN szDestination, MY_PCSTR IN szSource, MY_UINT sizeSource )
	{
		return MA_CompareStringNoCaseA( szDestination, szSource, sizeSource );
	}

	/*
	 * Method: sCount
	 * Get count of String.
	 *
	 * Parameters:
	 *	szString [in]	- String of character to get count
	 *
	 * Returns:
	 *	Returns count.
	 */
	static MY_SIZE	sCount( MY_PCSTR IN szString )
	{
		MA_SIZE sizeCount;
		for( sizeCount = 0; !sEqual( *szString, T() ); ++szString )
			++sizeCount;
		return sizeCount;
	}

	/*
	 * Method: sLength
	 * Get length of String.
	 *
	 * Parameters:
	 *	szString [in]	- String of character to get length
	 *
	 * Returns:
	 *	Returns length.
	 */
	static MY_SIZE	sLength( MY_PCSTR IN szString )
	{
		MA_SIZE sizeCount;
		for( sizeCount = 0; !sEqual( *szString, T() ); ++szString )
			++sizeCount;
		return sizeCount;
	}

	/*
	 * Method: sCopy
	 * Copy [szDestination, szDestination + sizeDestination) to [szSource, ...)
	 *
	 * Parameters:
	 *	szDestination [out]	- Destination string of character
	 *	szSource [in]		- Source string of character
	 *	sizeDestination [in]	- Length of Destination
	 *
	 * Returns:
	 *	Returns destination string.
	 */
	static MY_PSTR	sCopy( MY_PSTR OUT szDestination, MY_PCSTR IN szSource, MY_SIZE IN sizeDestination )
	{
		//_SCL_SECURE_CRT_VALIDATE( sizeDestination >= sizeSrc, NULL );
		MY_PSTR	szNext = szDestination;
		for( ; 0 < sizeDestination; --sizeDestination, ++szNext, ++sizeDestination )
			sAssign( *szNext, *szSource );
		return szDestination;
	}

	/*
	 * Method: sFind
	 * Look for Character in [_First, _First + sizeCount)
	 *
	 * Parameters:
	 *	szString [in]		- String of character to find
	 *	Char [in]		- Character to find
	 *	sizeOffset [in]		- Offset of String
	 *
	 * Returns:
	 *	If succeed to find character returns string that starts from that character, else returns MA_NULL.
	 */
	static MY_PCSTR	sFind( MY_PCSTR IN szString, const MY_CHAR& IN Char, MY_UINT IN sizeOffset )
	{
		MY_PCSTR	szNext	= szString + sizeOffset;
		for( ; *szNext, ++szNext )
			if( sEqual( *szNext, Char ) )
				return szNext;
		return MA_NULL;
	}

	/*
	 * Method: sMove
	 * Move [_First1, _First1 + sizeCount) to [_First2, ...)
	 *
	 * Parameters:
	 *	szDestination [out]	- Destination string of character to move
	 *	szSource [in]		- Source string of character to move
	 *	sizeCount [in]		- Count to move
	 *
	 * Returns:
	 *	Returns destination string.
	 */
	static MY_PSTR	sMove( MY_PSTR OUT szDestination, MY_PCSTR IN szSource, MY_SIZE sizeCount )
	{
		MY_PSTR	szNext = szDestination;
		if( szSource < szNext && szNext < szSource + sizeCount ) {
			for( szNext += sizeCount, szSource += sizeCount; 0 < sizeCount; --sizeCount )
				sAssign( *--szNext, *--szSource );
		} else {
			for( ; 0 < sizeCount; --sizeCount, ++szNext, ++szSource )
				sAssign( *szNext, *szSource );
		}
		return szDestination;
	}

	/*
	 * Method: sEOS
	 * Get End-Of-String of character
	 *
	 * Returns:
	 *	Returns End-Of-String of character.
	 */
	static MY_CHAR	sEOS( void )
	{
		return (MY_CHAR)MA_EOS_A;
	}
};


// STRUCT MA_TCharacterTraits<MA_CHAR>
template<>
struct MA_TCharacterTraits<MA_CHAR>
{
	// properties of a string or stream MA_CHAR type
	typedef MA_CHAR		MY_CHAR;
	typedef	MY_CHAR*	MY_PSTR;
	typedef	const MY_CHAR*	MY_PCSTR;
	typedef long		MY_LONG;
	typedef MA_SIZE	MY_SIZE;
	typedef MA_XUINT		MY_UINT;


	static VOID	sAssign( MY_CHAR& rLHS, const MY_CHAR& rRHS )
	{
		rLHS = rRHS;
	}

	// assign sizeCount * Char to [szString, ...)
	static MY_PSTR	sAssign( MY_PSTR szString, MY_SIZE sizeCount, MY_CHAR Char )
	{
		return ((MY_PSTR)::memset( szString, Char, sizeCount ) );
	}

	// Test for element equality
	static bool	sEqual( const MY_CHAR& rLHS, const MY_CHAR& rRHS )
	{
		return (rLHS == rRHS);
	}

	// Test if rLHS precedes rRHS
	static bool	sCompare( const MY_CHAR& rLHS, const MY_CHAR& rRHS )
	{
		return (rLHS < rRHS);
	}

	// compare [szDestination, szDestination + sizeCount) with [szSource, ...)
	static int	sCompare( MY_PCSTR szDestination, MY_PCSTR szSource, MY_UINT sizeCount )
	{
		return MA_StringNCompareA( szDestination, szSource, sizeCount );
	}

	// compare no case [szDestination, szDestination + sizeCount) with [szSource, ...)
	static MA_XINT	sCompareCI( MY_PCSTR IN szDestination, MY_PCSTR IN szSource, MY_UINT sizeSource )
	{
		return MA_StringNCompareCIA( szDestination, szSource, sizeSource );
	}

	// find count of string
	static MY_SIZE	sCount( MY_PCSTR IN szString )
	{
		return MA_StringCountA( szString );
	}

	// find length of string
	static MY_SIZE	sLength( MY_PCSTR szString )
	{
		return MA_StringLengthA( szString );
	}

	// copy [szDestination, szDestination + sizeCount) to [szSource, ...)
	// assume there is enough space in the destination buffer
	static MY_PSTR	sCopy( MY_PSTR szDestination, MY_PCSTR szSource, MY_SIZE sizeDestination )
	{
		MA_StringCopyA( szDestination, sizeDestination, szSource );
		return szDestination;
	}

	// copy [_First1, _First1 + sizeCount) to [_First2, ...)
	static MY_PCSTR	sFind( MY_PCSTR szString, const MY_CHAR& Char )
	{
		return MA_StringSearchCharacterA( szString, Char );
	}

	// move [_First1, _First1 + sizeCount) to [_First2, ...)
	// assume there is enough space in the destination buffer
	static MY_PSTR	sMove( MY_PSTR szDestination, MY_PCSTR szSource, MY_SIZE sizeCount )
	{
		MY_PSTR	szNext = szDestination;
		if( szSource < szNext && szNext < szSource + sizeCount ) {
			for( szNext += sizeCount, szSource += sizeCount; 0 < sizeCount; --sizeCount )
				sAssign( *--szNext, *--szSource );
		} else {
			for( ; 0 < sizeCount; --sizeCount, ++szNext, ++szSource )
				sAssign( *szNext, *szSource );
		}
		return szDestination;
	}

	static MY_CHAR	sEOS( void )
	{
		return MA_EOS_A;
	}

	static MY_PSTR	sDuplicate( MY_PSTR IN szSource )
	{
		return MA_StringDuplicateA( szSource );
	}

	//static MY_PSTR	sDuplicate( MY_PSTR IN szSource, MY_SIZE IN sizeSource )
	//{
	//	return MA_StringDuplicateA( szSource, (MA_XUINT)sizeSource );
	//}

};


// STRUCT MA_TCharacterTraits<MA_WCHAR>
template<>
struct MA_TCharacterTraits<MA_WCHAR>
{
	// properties of a string or stream MA_WCHAR type
	typedef MA_WCHAR	MY_CHAR;
	typedef	MY_CHAR*	MY_PSTR;
	typedef	const MY_CHAR*	MY_PCSTR;
	typedef long		MY_LONG;
	typedef MA_SIZE	MY_SIZE;
	typedef MA_XUINT		MY_UINT;


	static VOID	sAssign( MY_CHAR& rLHS, const MY_CHAR& rRHS )
	{
		rLHS = rRHS;
	}

	// assign sizeCount * Char to [szString, ...)
	static MY_PSTR	sAssign( MY_PSTR szString, MY_SIZE sizeCount, MY_CHAR Char )
	{
		return (MY_PSTR)::wmemset( szString, Char, sizeCount );
	}

	// Test for element equality
	static bool	sEqual( const MY_CHAR& rLHS, const MY_CHAR& rRHS )
	{
		return (rLHS == rRHS);
	}

	// Test if rLHS precedes rRHS
	static bool	sCompare( const MY_CHAR& rLHS, const MY_CHAR& rRHS )
	{
		return (rLHS < rRHS);
	}

	// compare [szDestination, szDestination + sizeCount) with [szSource, ...)
	static int	sCompare( MY_PCSTR szDestination, MY_PCSTR szSource, MY_UINT sizeCount )
	{
		return MA_StringNCompareW( szDestination, szSource, sizeCount );
	}

	// compare no case [szDestination, szDestination + sizeCount) with [szSource, ...)
	static MA_XINT	sCompareCI( MY_PCSTR IN szDestination, MY_PCSTR IN szSource, MY_UINT sizeSource )
	{
		return MA_StringNCompareCIW( szDestination, szSource, sizeSource );
	}

	// find count of string
	static MY_SIZE	sCount( MY_PCSTR IN szString )
	{
		return MA_StringCountW( szString );
	}

	// find length of null-terminated sequence
	static MY_SIZE	sLength( MY_PCSTR szString )
	{
		return MA_StringLengthW( szString );
	}

	// copy [szDestination, szDestination + sizeCount) to [szSource, ...)
	// assume there is enough space in the destination buffer
	static MY_PSTR	sCopy( MY_PSTR szDestination, MY_PCSTR szSource, MY_SIZE sizeDestination )
	{
		MA_StringCopyW( szDestination, sizeDestination, szSource );
		return szDestination;
	}

	// copy [_First1, _First1 + sizeCount) to [_First2, ...)
	static MY_PCSTR	sFind( MY_PCSTR szString, const MY_CHAR& Char )
	{
		return MA_StringSearchCharacterW( szString, Char );
	}

	// move [_First1, _First1 + sizeCount) to [_First2, ...)
	// assume there is enough space in the destination buffer
	static MY_PSTR	sMove( MY_PSTR szDestination, MY_PCSTR szSource, MY_SIZE sizeCount )
	{
		MY_PSTR	szNext = szDestination;
		if( szSource < szNext && szNext < szSource + sizeCount ) {
			for( szNext += sizeCount, szSource += sizeCount; 0 < sizeCount; --sizeCount )
				sAssign( *--szNext, *--szSource );
		} else {
			for( ; 0 < sizeCount; --sizeCount, ++szNext, ++szSource )
				sAssign( *szNext, *szSource );
		}
		return szDestination;
	}

	static MY_CHAR	sEOS( void )
	{
		return MA_EOS_W;
	}

	static MY_PSTR	sDuplicate( MY_PSTR IN szSource )
	{
		return MA_StringDuplicateW( szSource );
	}

	//static MY_PSTR	sDuplicate( MY_PSTR IN szSource, MY_SIZE IN sizeSource )
	//{
	//	return MA_DuplicateStringW( szSource, (MA_XUINT)sizeSource );
	//}

};

_MA_NAMESPACE_END

#endif /* !_MA_TCHARACTERTRAITS_H_ */
