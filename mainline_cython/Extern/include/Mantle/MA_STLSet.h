/**
 * @file	STLSet.h
 * @author	Standil (cpascal@cpascal.net)
 * @brief	Header file to use STL set/multiset (remove compiler warning)
 *
 * @version	2004/09/07 cpascal - First release
 */

#ifndef _MA_STLSET_H_
#define _MA_STLSET_H_

#ifdef _NTR_WINDOWS
#pragma warning( push )
#pragma warning( disable : 4702 )
#endif

#include <set>

#ifdef _NTR_WINDOWS
#pragma warning( pop )
#endif

#define MA_DEFINE_STL_SET( SetName, SetValue ) \
	typedef std::set<SetValue>						Set##SetName; \
	typedef Set##SetName::iterator					Set##SetName##Itr; \
	typedef Set##SetName::const_iterator			Set##SetName##CItr; \
	typedef std::pair<Set##SetName##Itr, bool>		Set##SetName##Pr;

#endif // _MA_STLSET_H_
