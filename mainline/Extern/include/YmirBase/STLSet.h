/**
 * @file	STLSet.h
 * @author	Standil (cpascal@cpascal.net)
 * @brief	Header file to use STL set/multiset
 *
 * @version	2004/09/07 cpascal - First release
 */

#ifndef _EA_STLSET_H_
#define _EA_STLSET_H_

#ifdef _WIN32
#pragma warning( push )
#pragma warning( disable : 4702 )
#endif

#include <set>

#ifdef _WIN32
#pragma warning( pop )
#endif

#define EA_DEFINE_STL_SET( SetName, SetValue ) \
	typedef std::set<SetValue>				SetName##Set; \
	typedef SetName##Set::iterator				SetName##SetItr; \
	typedef SetName##Set::const_iterator			SetName##SetCItr; \
	typedef std::pair<SetName##SetItr, bool>		SetName##SetPr;

#endif // _EA_STLSET_H_
