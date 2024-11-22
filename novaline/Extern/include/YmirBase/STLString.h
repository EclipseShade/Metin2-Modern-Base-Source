/**
 * @file	STLString.h
 * @author	Standil (cpascal@cpascal.net)
 * @brief	Header file to use STL string
 *
 * @version	2004/09/07 cpascal - First release
 */

#ifndef _EL_STLSTRING_H_
#define _EL_STLSTRING_H_

#ifdef _WIN32
#pragma warning( push )
#pragma warning( disable : 4702 )
#endif

#include <string>

struct EL_CICompareA
{
	bool operator() (const std::string & s1, const std::string & s2) const
	{
		return _stricmp( s1.c_str(), s2.c_str() ) < 0;
	}
};

struct EL_CICompareW
{
	bool operator() (const std::wstring & s1, const std::wstring & s2) const
	{
		return _wcsicmp( s1.c_str(), s2.c_str() ) < 0;
	}
};

#ifdef _UNICODE
typedef std::wstring		EL_STLString;
typedef EL_CICompareW		EL_CICompareT;
#else
typedef std::string			EL_STLString;
typedef EL_CICompareA		EL_CICompareT;
#endif

typedef std::string			EL_STLStringA;
typedef std::wstring		EL_STLStringW;

#ifdef _WIN32
#pragma warning( pop )
#endif

#endif /* _EL_STLSTRING_H_ */
