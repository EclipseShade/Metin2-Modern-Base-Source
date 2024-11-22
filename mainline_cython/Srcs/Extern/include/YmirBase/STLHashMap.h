/**
 * @file	EL_STLHMap.h
 * @author	Standil (cpascal@cpascal.net)
 * @brief	Header file to use STL hash map
 *
 * @version	2004/09/07 cpascal - First release
 */

#ifndef _EL_STLHASHMAP_H_
#define _EL_STLHASHMAP_H_

#include "STLString.h"

#ifdef _WIN32
#pragma warning( push )
#pragma warning( disable : 4702 )
#endif

#include <hash_map>

#ifdef _WIN32
#pragma warning( pop )
#endif

#define EL_DEFINE_STL_HASHSTRINGCIMAP( MapName, MapValue ) \
	typedef stdext::hash_map<EL_STLString, MapValue, stdext::hash_compare<EL_STLString, EL_CICompareT> >	\
															HMap##MapName; \
	typedef HMap##MapName::value_type						HMap##MapName##VT; \
	typedef HMap##MapName::iterator							HMap##MapName##Itr; \
	typedef HMap##MapName::const_iterator					HMap##MapName##CItr; \
	typedef std::pair<HMap##MapName##Itr, bool>				HMap##MapName##Pr;

#define EL_DEFINE_STL_HASHSTRINGCIMAP_T( MapName, MapValue ) \
	typedef stdext::hash_map<EL_STLString, stdext::hash_compare<EL_STLString, EL_CICompareT> >	\
															HMap##MapName; \
	typedef typename HMap##MapName::value_type				HMap##MapName##VT; \
	typedef typename HMap##MapName::iterator				HMap##MapName##Itr; \
	typedef typename HMap##MapName::const_iterator			HMap##MapName##CItr; \
	typedef typename std::pair<HMap##MapName##Itr, bool>	HMap##MapName##Pr;

#endif /* !_EL_STLHASHMAP_H_ */
