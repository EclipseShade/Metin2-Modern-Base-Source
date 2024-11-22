/**
 * @file	STLString.h
 * @author	Standil (cpascal@cpascal.net)
 * @brief	Header file to use STL string (remove compiler warning)
 *
 * @version	2004/09/07 cpascal - First release
 */

#ifndef _MA_STLSTRING_H_
#define _MA_STLSTRING_H_

#ifdef _NTR_WINDOWS
#pragma warning( push )
#pragma warning( disable : 4702 )
#endif

#include <string>

_MA_NAMESPACE_BEGIN

struct MA_CICompareA
{
	bool operator() (const std::string & s1, const std::string & s2) const
	{
		return _stricmp( s1.c_str(), s2.c_str() ) < 0;
	}
};

struct MA_CICompareW
{
	bool operator() (const std::wstring & s1, const std::wstring & s2) const
	{
		return _wcsicmp( s1.c_str(), s2.c_str() ) < 0;
	}
};

#ifdef _UNICODE
typedef std::wstring		MA_STLTString;
typedef MA_CICompareW		MA_CICompareT;
#else
typedef std::string			MA_STLTString;
typedef MA_CICompareA		MA_CICompareT;
#endif

_MA_NAMESPACE_END

#ifdef _NTR_WINDOWS
#pragma warning( pop )
#endif

#endif /* _MA_STLSTRING_H_ */
