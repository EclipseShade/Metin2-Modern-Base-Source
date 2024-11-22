#pragma once

template<typename T>
struct EL_TStringConstants
{
	typedef T			IN_CHAR;
	typedef const T*	IN_C_CHAR_P;
	
	static IN_C_CHAR_P DIR_SEP();
	static IN_C_CHAR_P FLAG_SEP();
	static IN_C_CHAR_P NAME_SEP();
	static IN_C_CHAR_P LINE_SEP();	
	static IN_C_CHAR_P RANGE_SEP();
	static IN_C_CHAR_P COMMA_SEP();
	
	static IN_C_CHAR_P TEXT_TRUE();
	static IN_C_CHAR_P TEXT_FALSE();

	static IN_C_CHAR_P TEXT_ZERO();
};

// ACHAR
template<>
inline EL_TStringConstants<EL_ACHAR>::IN_C_CHAR_P EL_TStringConstants<EL_ACHAR>::NAME_SEP()
{return ":";}

template<>
inline EL_TStringConstants<EL_ACHAR>::IN_C_CHAR_P EL_TStringConstants<EL_ACHAR>::LINE_SEP()
{return "\n";}

template<>
inline EL_TStringConstants<EL_ACHAR>::IN_C_CHAR_P EL_TStringConstants<EL_ACHAR>::DIR_SEP()
{return "\\";}

template<>
inline EL_TStringConstants<EL_ACHAR>::IN_C_CHAR_P EL_TStringConstants<EL_ACHAR>::FLAG_SEP()
{return "|";}

template<>
inline EL_TStringConstants<EL_ACHAR>::IN_C_CHAR_P EL_TStringConstants<EL_ACHAR>::RANGE_SEP()
{return "~";}

template<>
inline EL_TStringConstants<EL_ACHAR>::IN_C_CHAR_P EL_TStringConstants<EL_ACHAR>::COMMA_SEP()
{return ",";}

template<>
inline EL_TStringConstants<EL_ACHAR>::IN_C_CHAR_P EL_TStringConstants<EL_ACHAR>::TEXT_ZERO()
{return "0";}

template<>
inline EL_TStringConstants<EL_ACHAR>::IN_C_CHAR_P EL_TStringConstants<EL_ACHAR>::TEXT_TRUE()
{return "TRUE";}

template<>
inline EL_TStringConstants<EL_ACHAR>::IN_C_CHAR_P EL_TStringConstants<EL_ACHAR>::TEXT_FALSE()
{return "FALSE";}

// ECHAR
template<>
inline EL_TStringConstants<EL_ECHAR>::IN_C_CHAR_P EL_TStringConstants<EL_ECHAR>::NAME_SEP()
{return EL_TEXTE(":");}

template<>
inline EL_TStringConstants<EL_ECHAR>::IN_C_CHAR_P EL_TStringConstants<EL_ECHAR>::LINE_SEP()
{return EL_TEXTE("\n");}

template<>
inline EL_TStringConstants<EL_ECHAR>::IN_C_CHAR_P EL_TStringConstants<EL_ECHAR>::DIR_SEP()
{return EL_TEXTE("\\");}

template<>
inline EL_TStringConstants<EL_ECHAR>::IN_C_CHAR_P EL_TStringConstants<EL_ECHAR>::FLAG_SEP()
{return EL_TEXTE("|");}

template<>
inline EL_TStringConstants<EL_ECHAR>::IN_C_CHAR_P EL_TStringConstants<EL_ECHAR>::RANGE_SEP()
{return EL_TEXTE("~");}

template<>
inline EL_TStringConstants<EL_ECHAR>::IN_C_CHAR_P EL_TStringConstants<EL_ECHAR>::COMMA_SEP()
{return EL_TEXTE(",");}

template<>
inline EL_TStringConstants<EL_ECHAR>::IN_C_CHAR_P EL_TStringConstants<EL_ECHAR>::TEXT_ZERO()
{return EL_TEXTE("0");}

template<>
inline EL_TStringConstants<EL_ECHAR>::IN_C_CHAR_P EL_TStringConstants<EL_ECHAR>::TEXT_TRUE()
{return EL_TEXTE("TRUE");}

template<>
inline EL_TStringConstants<EL_ECHAR>::IN_C_CHAR_P EL_TStringConstants<EL_ECHAR>::TEXT_FALSE()
{return EL_TEXTE("FALSE");}


// WCHAR
template<>
inline EL_TStringConstants<EL_WCHAR>::IN_C_CHAR_P EL_TStringConstants<EL_WCHAR>::NAME_SEP()
{return L":";}

template<>
inline EL_TStringConstants<EL_WCHAR>::IN_C_CHAR_P EL_TStringConstants<EL_WCHAR>::LINE_SEP()
{return L"\n";}

template<>
inline EL_TStringConstants<EL_WCHAR>::IN_C_CHAR_P EL_TStringConstants<EL_WCHAR>::DIR_SEP()
{return L"\\";}

template<>
inline EL_TStringConstants<EL_WCHAR>::IN_C_CHAR_P EL_TStringConstants<EL_WCHAR>::RANGE_SEP()
{return L"~";}

template<>
inline EL_TStringConstants<EL_WCHAR>::IN_C_CHAR_P EL_TStringConstants<EL_WCHAR>::FLAG_SEP()
{return L"|";}

template<>
inline EL_TStringConstants<EL_WCHAR>::IN_C_CHAR_P EL_TStringConstants<EL_WCHAR>::COMMA_SEP()
{return L",";}

template<>
inline EL_TStringConstants<EL_WCHAR>::IN_C_CHAR_P EL_TStringConstants<EL_WCHAR>::TEXT_ZERO()
{return L"0";}

template<>
inline EL_TStringConstants<EL_WCHAR>::IN_C_CHAR_P EL_TStringConstants<EL_WCHAR>::TEXT_TRUE()
{return L"TRUE";}

template<>
inline EL_TStringConstants<EL_WCHAR>::IN_C_CHAR_P EL_TStringConstants<EL_WCHAR>::TEXT_FALSE()
{return L"FALSE";}