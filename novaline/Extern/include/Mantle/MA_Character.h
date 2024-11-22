#ifndef _MA_CHARACTER_H_
#define _MA_CHARACTER_H_

_NTR_EXTERN_C_BEGIN

#if defined( _NTR_UNICODE )
	#define MA_CharIsSpace						MA_CharIsSpaceW
	#define MA_CharIsTab						MA_CharIsTabW
	#define MA_CharIsTabs						MA_CharIsTabsW
	#define MA_CharIsBlank						MA_CharIsBlankW
	#define MA_CharIsDot						MA_CharIsDotW
	#define MA_CharIsAsterisk					MA_CharIsAsteriskW
	#define MA_CharIsLineFeed					MA_CharIsLineFeedW		// Line Feed
	#define MA_CharIsFormFeed					MA_CharIsFormFeedW		// Form Feed
	#define MA_CharIsCarrageReturn				MA_CharIsCarrageReturnW	// Carriage Return
	#define MA_CharIsNewLine					MA_CharIsNewLineW				// New Line
	#define MA_CharIsWhiteSpace					MA_CharIsWhiteSpaceW			// White Space
	#define MA_CharIsLower						MA_CharIsLowerW
	#define MA_CharIsUpper						MA_CharIsUpperW
	#define MA_CharLIsLower						MA_CharLIsLowerW
	#define MA_CharLIsUpper						MA_CharLIsUpperW
	#define MA_CharToLower						MA_CharToLowerW
	#define MA_CharToUpper						MA_CharToUpperW
	#define MA_CharLToLower						MA_CharLToLowerW
	#define MA_CharLToUpper						MA_CharLToUpperW
	#define MA_CharIsSymbolable					MA_CharIsSymbolableW
	#define MA_CharIsBin						MA_CharIsBinW
	#define MA_CharIsOct						MA_CharIsOctW
	#define MA_CharIsDec						MA_CharIsDecW
	#define MA_CharIsDigit						MA_CharIsDecW
	#define MA_CharIsHexAlphabet				MA_CharIsHexAlphabetW
	#define MA_CharIsHex						MA_CharIsHexW
	#define MA_CharIsPathDelimiter				MA_CharIsPathDelimiterW
	#define MA_CharIsEOS						MA_CharIsEOSW
	#define MA_CharIsQuote						MA_CharIsQuoteW
	#define MA_CharIsDoubleQuote				MA_CharIsDoubleQuoteW
	#define MA_CharIsPrint						MA_CharIsPrintW
	#define MA_HexToInt							MA_HexToIntW
#elif defined( _NTR_ASCII )
	#define MA_CharIsSpace						MA_CharIsSpaceA
	#define MA_CharIsTab						MA_CharIsTabA
	#define MA_CharIsTabs						MA_CharIsTabsA
	#define MA_CharIsBlank						MA_CharIsBlankA
	#define MA_CharIsDot						MA_CharIsDotA
	#define MA_CharIsAsterisk					MA_CharIsAsteriskA
	#define MA_CharIsLineFeed					MA_CharIsLineFeedA
	#define MA_CharIsFormFeed					MA_CharIsFormFeedA
	#define MA_CharIsCarrageReturn				MA_CharIsCarrageReturnA
	#define MA_CharIsNewLine					MA_CharIsNewLineA
	#define MA_CharIsWhiteSpace					MA_CharIsWhiteSpaceA
	#define MA_CharIsLower						MA_CharIsLowerA
	#define MA_CharIsUpper						MA_CharIsUpperA
	#define MA_CharLIsLLower					MA_CharLIsLowerA
	#define MA_CharLIsLUpper					MA_CharLIsUpperA
	#define MA_CharToLower						MA_CharToLowerA
	#define MA_CharToUpper						MA_CharToUpperA
	#define MA_CharLToLower						MA_CharLToLowerA
	#define MA_CharLToUpper						MA_CharLToUpperA
	#define MA_CharIsSymbolable					MA_CharIsSymbolableA
	#define MA_CharIsBin						MA_CharIsBinA
	#define MA_CharIsOct						MA_CharIsOctA
	#define MA_CharIsDec						MA_CharIsDecA
	#define MA_CharIsDigit						MA_CharIsDecA
	#define MA_CharIsHexAlphabet				MA_CharIsHexAlphabetA
	#define MA_CharIsHex						MA_CharIsHexA
	#define MA_CharIsPathDelimiter				MA_CharIsPathDelimiterA
	#define MA_CharIsEOS						MA_CharIsEOSA
	#define MA_CharIsQuote						MA_CharIsQuoteA
	#define MA_CharIsDoubleQuote				MA_CharIsDoubleQuoteA
	#define MA_CharIsPrint						MA_CharIsPrintA
	#define MA_HexToInt							MA_HexToIntA
#else
	#define MA_CharIsSpace						MA_CharIsSpaceE
	#define MA_CharIsTab						MA_CharIsTabE
	#define MA_CharIsTabs						MA_CharIsTabsE
	#define MA_CharIsBlank						MA_CharIsBlankE
	#define MA_CharIsDot						MA_CharIsDotE
	#define MA_CharIsAsterisk					MA_CharIsAsteriskE
	#define MA_CharIsLineFeed					MA_CharIsLineFeedE
	#define MA_CharIsFormFeed					MA_CharIsFormFeedE
	#define MA_CharIsCarrageReturn				MA_CharIsCarrageReturnE
	#define MA_CharIsNewLine					MA_CharIsNewLineE
	#define MA_CharIsWhiteSpace					MA_CharIsWhiteSpaceE
	#define MA_CharIsLower						MA_CharIsLowerE
	#define MA_CharIsUpper						MA_CharIsUpperE
	#define MA_CharLIsLower						MA_CharLIsLowerE
	#define MA_CharLIsUpper						MA_CharLIsUpperE
	#define MA_CharToLower						MA_CharToLowerE
	#define MA_CharToUpper						MA_CharToUpperE
	#define MA_CharLToLower						MA_CharLToLowerE
	#define MA_CharLToUpper						MA_CharLToUpperE
	#define MA_CharIsSymbolable					MA_CharIsSymbolableE
	#define MA_CharIsBin						MA_CharIsBinE
	#define MA_CharIsOct						MA_CharIsOctE
	#define MA_CharIsDec						MA_CharIsDecE
	#define MA_CharIsDigit						MA_CharIsDecE
	#define MA_CharIsHexAlphabet				MA_CharIsHexAlphabetE
	#define MA_CharIsHex						MA_CharIsHexE
	#define MA_CharIsPathDelimiter				MA_CharIsPathDelimiterE
	#define MA_CharIsEOS						MA_CharIsEOSE
	#define MA_CharIsQuote						MA_CharIsQuoteE
	#define MA_CharIsDoubleQuote				MA_CharIsDoubleQuoteE
	#define MA_CharIsPrint						MA_CharIsPrintE
	#define MA_HexToInt							MA_HexToIntE
#endif

#define MA_CharIsSpaceE							MA_CharIsSpaceA
#define MA_CharIsTabE							MA_CharIsTabA
#define MA_CharIsTabE							MA_CharIsTabA
#define MA_CharIsBlankE							MA_CharIsBlankA
#define MA_CharIsDotE							MA_CharIsDotA
#define MA_CharIsAsteriskE						MA_CharIsAsteriskA
#define MA_CharIsLineFeedE						MA_CharIsLineFeedA
#define MA_CharIsFormFeedE						MA_CharIsFormFeedA
#define MA_CharIsCarrageReturnE					MA_CharIsCarrageReturnA
#define MA_CharIsNewLineE						MA_CharIsNewLineA
#define MA_CharIsWhiteSpaceE					MA_CharIsWhiteSpaceA
#define MA_CharIsLowerE							MA_CharIsLowerA
#define MA_CharIsUpperE							MA_CharIsUpperA
#define MA_CharLIsLowerE						MA_CharLIsLowerA
#define MA_CharLIsUpperE						MA_CharLIsUpperA
#define MA_CharToLowerE							MA_CharToLowerA
#define MA_CharToUpperE							MA_CharToUpperA
#define MA_CharLToLowerE						MA_CharLToLowerA
#define MA_CharLToUpperE						MA_CharLToUpperA
#define MA_CharIsSymbolableE					MA_CharIsSymbolableA
#define MA_CharIsBinE							MA_CharIsBinA
#define MA_CharIsOctE							MA_CharIsOctA
#define MA_CharIsDecE							MA_CharIsDecA
#define MA_CharIsDecE							MA_CharIsDecA
#define MA_CharIsHexAlphabetE					MA_CharIsHexAlphabetA
#define MA_CharIsHexE							MA_CharIsHexA
#define MA_CharIsPathDelimiterE					MA_CharIsPathDelimiterA
#define MA_CharIsEOSE							MA_CharIsEOSA
#define MA_CharIsQuoteE							MA_CharIsQuoteA
#define MA_CharIsDoubleQuoteE					MA_CharIsDoubleQuoteA
#define MA_CharIsPrintE							MA_CharIsPrintA
#define MA_HexToIntE							MA_HexToIntA

/*
 * Function: MA_CharIsSpace
 * 문자가 Space인지 검사한다.
 * 이 함수가 확인하는 공백 문자는 0x09 ~ 0x0D, 0x20 이다.
 *
 * Parameters:
 *	ch [in]		- Space인지 검사할 문자
 *
 * Returns:
 *	ch가 Space이면 MA_TRUE, 그렇지 않으면 MA_FALSE를 return 한다.
 */
NTR_INLINE MA_BOOL 	MA_CharIsSpaceA( MA_CHAR IN ch )	{ return (ch  == ' ')?  MA_TRUE: MA_FALSE; }
NTR_INLINE MA_BOOL 	MA_CharIsSpaceW( MA_WCHAR IN wch )	{ return (wch == L' ')? MA_TRUE: MA_FALSE; }

/*
 * Function: MA_CharIsTab
 * 문자가 Tab(Horizontal Tab)인지 검사한다.
 *
 * Parameters:
 *	ch [in]		- Tab인지 검사할 문자
 *
 * Returns:
 *	ch가 Tab이면 MA_TRUE, 그렇지 않으면 MA_FALSE를 return 한다.
 */
NTR_INLINE MA_BOOL 	MA_CharIsTabA( MA_CHAR IN ch )			{ return (ch  == '\t')?  MA_TRUE: MA_FALSE; }
NTR_INLINE MA_BOOL 	MA_CharIsTabW( MA_WCHAR IN wch )		{ return (wch == L'\t')? MA_TRUE: MA_FALSE; }

/*
 * Function: MA_CharIsTab
 * 문자가 Tab인지 검사한다.
 *
 * Parameters:
 *	ch [in]		- Tab인지 검사할 문자
 *
 * Returns:
 *	ch가 Tab이면 MA_TRUE, 그렇지 않으면 MA_FALSE를 return 한다.
 */
NTR_INLINE MA_BOOL 	MA_CharIsTabsA( MA_CHAR IN ch )			{ return ((ch  == '\t')  || (ch  == L'v'))?  MA_TRUE: MA_FALSE; }
NTR_INLINE MA_BOOL 	MA_CharIsTabsW( MA_WCHAR IN wch )		{ return ((wch == L'\t') || (wch == L'\v'))? MA_TRUE: MA_FALSE; }

/*
 * Function: MA_CharIsBlank
 * 문자가 Blank인지 검사한다.
 *
 * Parameters:
 *	ch [in]		- Blank인지 검사할 문자
 *
 * Returns:
 *	ch가 Blank이면 MA_TRUE, 그렇지 않으면 MA_FALSE를 return 한다.
 */
NTR_INLINE MA_BOOL 	MA_CharIsBlankA( MA_CHAR IN ch )		{ return (MA_CharIsSpaceA( ch )  || MA_CharIsTabA( ch ))?  MA_TRUE: MA_FALSE; }
NTR_INLINE MA_BOOL 	MA_CharIsBlankW( MA_WCHAR IN wch )		{ return (MA_CharIsSpaceW( wch ) || MA_CharIsTabW( wch ))? MA_TRUE: MA_FALSE; }

/*
 * Function: MA_CharIsDot
 * 문자가 Dot인지 검사한다.
 *
 * Parameters:
 *	ch [in]		- Dot인지 검사할 문자
 *
 * Returns:
 *	ch가 Dot이면 MA_TRUE, 그렇지 않으면 MA_FALSE를 return 한다.
 */
NTR_INLINE MA_BOOL 	MA_CharIsDotA( MA_CHAR IN ch )	{ return (ch  == '.')?  MA_TRUE: MA_FALSE; }
NTR_INLINE MA_BOOL 	MA_CharIsDotW( MA_WCHAR IN wch )	{ return (wch == L'.')? MA_TRUE: MA_FALSE; }

/*
 * Function: MA_CharIsAsterisk
 * 문자가 Asterisk인지 검사한다.
 *
 * Parameters:
 *	ch [in]		- Asterisk인지 검사할 문자
 *
 * Returns:
 *	ch가 Asterisk이면 MA_TRUE, 그렇지 않으면 MA_FALSE를 return 한다.
 */
NTR_INLINE MA_BOOL 	MA_CharIsAsteriskA( MA_CHAR IN ch )	{ return (ch  == MA_ASTERISK_A)? MA_TRUE: MA_FALSE; }
NTR_INLINE MA_BOOL 	MA_CharIsAsteriskW( MA_WCHAR IN wch )	{ return (wch == MA_ASTERISK_W)? MA_TRUE: MA_FALSE; }

/*
 * Function: MA_CharIsLineFeed
 * 문자가 Line Feed인지 검사한다.
 *
 * Parameters:
 *	ch [in]		- Line Feed인지 검사할 문자
 *
 * Returns:
 *	ch가 Line Feed이면 MA_TRUE, 그렇지 않으면 MA_FALSE를 return 한다.
 */
NTR_INLINE MA_BOOL 	MA_CharIsLineFeedA( MA_CHAR IN ch )	{ return (ch  == MA_LF_A)?  MA_TRUE: MA_FALSE; }
NTR_INLINE MA_BOOL 	MA_CharIsLineFeedW( MA_WCHAR IN wch )	{ return (wch == MA_LF_W)? MA_TRUE: MA_FALSE; }

/*
 * Function: MA_CharIsFormFeed
 * 문자가 Form Feed인지 검사한다.
 *
 * Parameters:
 *	ch [in]		- Form Feed인지 검사할 문자
 *
 * Returns:
 *	ch가 Form Feed이면 MA_TRUE, 그렇지 않으면 MA_FALSE를 return 한다.
 */
NTR_INLINE MA_BOOL 	MA_CharIsFormFeedA( MA_CHAR IN ch )	{ return (ch  == '\f')?  MA_TRUE: MA_FALSE; }
NTR_INLINE MA_BOOL 	MA_CharIsFormFeedW( MA_WCHAR IN wch )	{ return (wch == L'\f')? MA_TRUE: MA_FALSE; }

/*
 * Function: MA_CharIsCarrageReturn
 * 문자가 Carriage Return인지 검사한다.
 *
 * Parameters:
 *	ch [in]		- Carriage Return인지 검사할 문자
 *
 * Returns:
 *	ch가 Carriage Return이면 MA_TRUE, 그렇지 않으면 MA_FALSE를 return 한다.
 */
NTR_INLINE MA_BOOL 	MA_CharIsCarrageReturnA( MA_CHAR IN ch )	{ return (ch  == MA_CR_A)?  MA_TRUE: MA_FALSE; }
NTR_INLINE MA_BOOL 	MA_CharIsCarrageReturnW( MA_WCHAR IN wch )	{ return (wch == MA_CR_W)? MA_TRUE: MA_FALSE; }

/*
 * Function: MA_CharIsNewLine
 * 문자가 NewLine인지 검사한다.
 *
 * Parameters:
 *	ch [in]		- NewLine인지 검사할 문자
 *
 * Returns:
 *	ch가 NewLine이면 MA_TRUE, 그렇지 않으면 MA_FALSE를 return 한다.
 */
NTR_INLINE MA_BOOL 	MA_CharIsNewLineA( MA_CHAR IN ch )		{ return (MA_CharIsCarrageReturnA( ch )  || MA_CharIsLineFeedA( ch ))?  MA_TRUE: MA_FALSE; }
NTR_INLINE MA_BOOL 	MA_CharIsNewLineW( MA_WCHAR IN wch )	{ return (MA_CharIsCarrageReturnW( wch ) || MA_CharIsLineFeedW( wch ))? MA_TRUE: MA_FALSE; }

/*
 * Function: MA_CharIsWhiteSpace
 * 문자가 Whiespace인지 검사한다.
 * white space 문자는 다음과 같다.
 * HT(0x09, Horizontal Tab), LF(0x0A, Line Feed), VT(0x0B, Vertical Tab), FF(0x0C, FormFeed), CR(0x0D, Carrage Return), Space(0x20)
 *
 * Parameters:
 *	ch [in]		- Whitespace인지 검사할 문자
 *
 * Returns:
 *	ch가 Whitespace이면 MA_TRUE, 그렇지 않으면 MA_FALSE를 return 한다.
 */
NTR_INLINE MA_BOOL 	MA_CharIsWhiteSpaceA( MA_CHAR IN ch )	{ return (MA_CharIsBlankA( ch )  || MA_CharIsNewLineA( ch )  || MA_CharIsLineFeedA( ch ))?  MA_TRUE: MA_FALSE; }
NTR_INLINE MA_BOOL 	MA_CharIsWhiteSpaceW( MA_WCHAR IN wch )	{ return (MA_CharIsBlankW( wch ) || MA_CharIsNewLineW( wch ) || MA_CharIsLineFeedW( wch ))? MA_TRUE: MA_FALSE; }

/*
 * Function: MA_CharIsLower
 * 문자가 소문자인지 검사한다.
 *
 * Parameters:
 *	ch [in]		- 소문자인지 검사할 문자
 *
 * Returns:
 *	ch가 소문자이면 MA_TRUE, 그렇지 않으면 MA_FALSE를 return 한다.
 */
NTR_INLINE MA_BOOL 	MA_CharIsLowerA( MA_CHAR IN ch )		{ return (('a'  <= ch)  && (ch  <= 'z'))?  MA_TRUE: MA_FALSE; }
NTR_INLINE MA_BOOL 	MA_CharIsLowerW( MA_WCHAR IN wch )		{ return ((L'a' <= wch) && (wch <= L'z'))? MA_TRUE: MA_FALSE; }

#if defined(_NTR_WINDOWS)
NTR_INLINE MA_BOOL 	MA_CharLIsLowerA( MA_CHAR IN ch )		{ return IsCharLowerA( ch ); }
NTR_INLINE MA_BOOL 	MA_CharLIsLowerW( MA_WCHAR IN wch )		{ return IsCharLowerW( wch ); }
#endif

/*
 * Function: MA_CharIsUpper
 * 문자가 대문자인지 검사한다.
 *
 * Parameters:
 *	ch [in]		- 대문자인지 검사할 문자
 *
 * Returns:
 *	ch가 대문자이면 MA_TRUE, 그렇지 않으면 MA_FALSE를 return 한다.
 */
NTR_INLINE MA_BOOL 	MA_CharIsUpperA( MA_CHAR IN ch )		{ return (('A'  <= ch)  && (ch  <= 'Z')) ?  MA_TRUE: MA_FALSE; }
NTR_INLINE MA_BOOL 	MA_CharIsUpperW( MA_WCHAR IN wch )		{ return ((L'A' <= wch) && (wch <= L'Z')) ? MA_TRUE: MA_FALSE; }

#if defined(_NTR_WINDOWS)
NTR_INLINE MA_BOOL 	MA_CharLIsUpperA( MA_CHAR IN ch )		{ return IsCharUpperA( ch ); }
NTR_INLINE MA_BOOL 	MA_CharLIsUpperW( MA_WCHAR IN wch )		{ return IsCharUpperW( wch ); }
#endif

/*
 * Function: MA_CharToLower
 * 문자를 소문자로 바꾼다.
 *
 * Parameters:
 *	ch [in]		- 소문자로 바꿀 문자
 *
 * Returns:
 *	소문자로 바꾼 문자
 */
// return IS_UPPER( tch ) ? tch + _T_CV('a') - _T_CV('A') : tch;
NTR_INLINE MA_CHAR	MA_CharToLowerA( MA_CHAR IN ch )		{ return MA_CharIsUpperA( ch ) ? (ch  | 0x20): ch;  }
NTR_INLINE MA_WCHAR	MA_CharToLowerW( MA_WCHAR IN wch )		{ return MA_CharIsUpperW( wch )? (wch | 0x20): wch; }

#if defined(_NTR_WINDOWS)
//NTR_INLINE MA_CHAR	MA_CharLToLowerA( MA_CHAR IN ch )		{ return CharLowerA( (LPSTR) (ch) );  }
//NTR_INLINE MA_WCHAR	MA_CharLToLowerW( MA_WCHAR IN wch )		{ return CharLowerW( (LPWSTR) wch ); }
#endif

/*
 * Function: MA_CharToUpper
 * 문자를 대문자로 바꾼다.
 *
 * Parameters:
 *	ch [in]		- 대문자로 바꿀 문자
 *
 * Returns:
 *	대문자로 바꾼 문자
 */
// return IS_LOWER( tch ) ? tch - _T_CV('a') + _T_CV('A') : tch;
NTR_INLINE MA_CHAR	MA_CharToUpperA( MA_CHAR IN ch )		{ return MA_CharIsLowerA( ch )  ? (ch  & 0xDF): ch;  }
NTR_INLINE MA_WCHAR	MA_CharToUpperW( MA_WCHAR IN wch )		{ return MA_CharIsLowerW( wch ) ? (wch & 0xDF): wch; }

#if defined(_NTR_WINDOWS)
//NTR_INLINE MA_CHAR	MA_CharLToUpperA( MA_CHAR IN ch )		{ return (MA_CHAR) CharUpperA( (LPSTR) (ch) );  }
//NTR_INLINE MA_WCHAR	MA_CharLToUpperW( MA_WCHAR IN wch )		{ return (MA_WCHAR) CharUpperW( (LPWSTR) wch ); }
#endif

/*
 * Function: MA_CharIsBin
 * 문자가 2진수 숫자(0 ~ 1)인지 검사한다.
 *
 * Parameters:
 *	ch [in]		- 2진수 숫자인지 검사할 문자
 *
 * Returns:
 *	2진수 숫자이면 MA_TRUE, 그렇지 않으면 MA_FALSE를 return 한다.
 */
NTR_INLINE MA_BOOL 	MA_CharIsBinA( MA_CHAR IN ch )		{ return ((ch  == '0')  || (ch  == '1'))?  MA_TRUE: MA_FALSE; }
NTR_INLINE MA_BOOL 	MA_CharIsBinW( MA_WCHAR IN wch )		{ return ((wch == L'0') || (wch == L'1'))? MA_TRUE: MA_FALSE; }

/*
 * Function: MA_CharIsOct
 * 문자가 8진수 숫자(0 ~ 7)인지 검사한다.
 *
 * Parameters:
 *	ch [in]		- 8진수 숫자인지 검사할 문자
 *
 * Returns:
 *	8진수 숫자이면 MA_TRUE, 그렇지 않으면 MA_FALSE를 return 한다.
 */
NTR_INLINE MA_BOOL 	MA_CharIsOctA( MA_CHAR IN ch )		{ return (('0'  <= ch)  && (ch  <= '7'))?  MA_TRUE: MA_FALSE; }
NTR_INLINE MA_BOOL 	MA_CharIsOctW( MA_WCHAR IN wch )		{ return ((L'0' <= wch) && (wch <= L'7'))? MA_TRUE: MA_FALSE; }

/*
 * Function: MA_CharIsDec
 * 문자가 10진수 숫자(0 ~ 9)인지 검사한다.
 *
 * Parameters:
 *	ch [in]		- 10진수 숫자인지 검사할 문자
 *
 * Returns:
 *	ch가 10진수 숫자이면 MA_TRUE, 그렇지 않으면 MA_FALSE를 return 한다.
 */
NTR_INLINE MA_BOOL 	MA_CharIsDecA( MA_CHAR IN ch )			{ return (('0'  <= ch)  && (ch  <= '9'))?  MA_TRUE: MA_FALSE; }
NTR_INLINE MA_BOOL 	MA_CharIsDecW( MA_WCHAR IN wch )		{ return ((L'0' <= wch) && (wch <= L'9'))? MA_TRUE: MA_FALSE; }

/*
 * Function: MA_CharIsSymbolable
 * 심볼이 될 수 있는 문자인지 검사한다. (알파벳, 숫자, _)
 *
 * Parameters:
 *	ch [in]		- 대문자인지 검사할 문자
 *
 * Returns:
 *	ch가 대문자이면 MA_TRUE, 그렇지 않으면 MA_FALSE를 return 한다.
 */
NTR_INLINE MA_BOOL 	MA_CharIsSymbolableA( MA_CHAR IN ch )		{ return MA_CharIsUpperA(ch) || MA_CharIsLowerA(ch) || MA_CharIsDecA(ch); }
NTR_INLINE MA_BOOL 	MA_CharIsSymbolableW( MA_WCHAR IN wch )		{ return MA_CharIsUpperW(wch) || MA_CharIsLowerW(wch) || MA_CharIsDecW(wch); }

/*
 * Function: MA_CharIsHexAlphabet
 * 문자가 16진수 Alphabet(A ~ F)인지 검사한다.
 *
 * Parameters:
 *	ch [in]		- 16진수 alphabet인지 검사할 문자
 *
 * Returns:
 *	ch가 16진수 alphabet이면 MA_TRUE, 그렇지 않으면 MA_FALSE를 return 한다.
 */
NTR_INLINE MA_BOOL 	MA_CharIsHexAlphabetA( MA_CHAR IN ch )	{ MA_CHAR  chUpper  = MA_CharToUpperA( ch );  return (('A'  <= chUpper)  && (chUpper  <= 'F'))?  MA_TRUE: MA_FALSE; }
NTR_INLINE MA_BOOL 	MA_CharIsHexAlphabetW( MA_WCHAR IN wch )	{ MA_WCHAR wchUpper = MA_CharToUpperW( wch ); return ((L'A' <= wchUpper) && (wchUpper <= L'F'))? MA_TRUE: MA_FALSE; }

/*
 * Function: MA_CharIsHex
 * 문자가 2진수 숫자(0 ~ 1)인지 검사한다.
 *
 * Parameters:
 *	ch [in]		- 2진수 숫자인지 검사할 문자
 *
 * Returns:
 *	ch가 2진수 숫자이면 MA_TRUE, 그렇지 않으면 MA_FALSE를 return 한다.
 */
NTR_INLINE MA_BOOL 	MA_CharIsHexA( MA_CHAR IN ch )		{ return (MA_CharIsDecA( ch )  || MA_CharIsHexAlphabetA( ch ))?  MA_TRUE: MA_FALSE; }
NTR_INLINE MA_BOOL 	MA_CharIsHexW( MA_WCHAR IN wch )		{ return (MA_CharIsDecW( wch ) || MA_CharIsHexAlphabetW( wch ))? MA_TRUE: MA_FALSE; }

/*
 * Function: MA_CharIsPathDelimiter
 * 문자가 Path의 Delimiter인지 검사한다.
 *
 * Parameters:
 *	ch [in]		- Path의 Delimiter인지 검사할 문자
 *
 * Returns:
 *	ch가 Path의 Delimiter이면 MA_TRUE, 그렇지 않으면 MA_FALSE를 return 한다.
 */
NTR_INLINE MA_BOOL 	MA_CharIsPathDelimiterA( MA_CHAR IN ch )	{ return ((ch  == '\\')  || (ch  == '/'))?  MA_TRUE: MA_FALSE; }
NTR_INLINE MA_BOOL 	MA_CharIsPathDelimiterW( MA_WCHAR IN wch )	{ return ((wch == L'\\') || (wch == L'/'))? MA_TRUE: MA_FALSE; }

/*
 * Function: MA_CharIsEOS
 * 문자가 End-Of-String(\0)인지 검사한다.
 *
 * Parameters:
 *	ch [in]		- Null인지 검사할 문자
 *
 * Returns:
 *	ch가 Null이면 MA_TRUE, 그렇지 않으면 MA_FALSE를 return 한다.
 */
NTR_INLINE MA_BOOL 	MA_CharIsEOSA( MA_CHAR IN ch )		{ return (ch  == '\0')?  MA_TRUE: MA_FALSE; }
NTR_INLINE MA_BOOL 	MA_CharIsEOSW( MA_WCHAR IN wch )		{ return (wch == L'\0')? MA_TRUE: MA_FALSE; }

/*
 * Function: MA_CharIsQuote
 * 문자가 Single Quotation인지 검사한다.
 *
 * Parameters:
 *	ch [in]		- Single Quotation인지 검사할 문자
 *
 * Returns:
 *	Single Quotation이면 MA_TRUE, 그렇지 않으면 MA_FALSE를 return 한다.
 */
NTR_INLINE MA_BOOL 	MA_CharIsQuoteA( MA_CHAR IN ch )		{ return (ch  == '\'')?  MA_TRUE: MA_FALSE; }
NTR_INLINE MA_BOOL 	MA_CharIsQuoteW( MA_WCHAR IN wch )		{ return (wch == L'\'')? MA_TRUE: MA_FALSE; }

/*
 * Function: MA_CharIsDoubleQuote
 * 문자가 Double Quotation인지 검사한다.
 *
 * Parameters:
 *	ch [in]		- Double Quotation인지 검사할 문자
 *
 * Returns:
 *	Double Quotation이면 MA_TRUE, 그렇지 않으면 MA_FALSE를 return 한다.
 */
NTR_INLINE MA_BOOL 	MA_CharIsDoubleQuoteA( MA_CHAR IN ch )	{ return (ch  == '"') ?  MA_TRUE: MA_FALSE;	}
NTR_INLINE MA_BOOL 	MA_CharIsDoubleQuoteW( MA_WCHAR IN wch )	{ return (wch == L'"') ? MA_TRUE: MA_FALSE;	}

/*
 * Function: MA_CharIsPrint
 * Print 가능한 문자인지 검사한다.
 *
 * Parameters:
 *	ch [in]		- Print 가능한 지 검사할 문자
 *
 * Returns:
 *	Print 가능한 문자인 경우에는 0이 아닌 값을, 그렇지 않으면 0을 리턴.
 */
NTR_INLINE MA_BOOL 	MA_CharIsPrintA( MA_CHAR IN ch )		{ return isprint( (unsigned char) ch );		}
NTR_INLINE MA_BOOL 	MA_CharIsPrintW( MA_WCHAR IN wch )		{ return iswprint( wch );			}


/*
 * Function: MA_HexToInt
 * Hex 문자를 숫자로 바꾼다.
 *
 * Parameters:
 *	ch [in]		- Hex characterr
 *
 * Returns:
 *	ch를 숫자로 바꾼 값.
 */
NTR_INLINE MA_CHAR	MA_HexToIntA( MA_CHAR IN ch )		{ if( MA_CharIsDecA( ch ) )  return (MA_CHAR)(ch  - '0');  else return (MA_CHAR)(ch  - 'A' + 10);	}
NTR_INLINE MA_WCHAR	MA_HexToIntW( MA_WCHAR IN wch )		{ if( MA_CharIsDecW( wch ) ) return (MA_WCHAR)(wch - L'0'); else return (MA_WCHAR)(wch - L'A' + 10);	}

_NTR_EXTERN_C_END

#endif /* !_MA_CHARACTER_H_ */
