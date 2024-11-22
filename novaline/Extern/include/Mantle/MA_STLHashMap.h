/**
 * @file	MA_STLHMap.h
 * @author	Standil (cpascal@cpascal.net)
 * @brief	Header file to use STL hash map (remove compiler warning)
 *
 * @version	2004/09/07 cpascal - First release
 */

#ifndef _MA_STLHASHMAP_H_
#define _MA_STLHASHMAP_H_

#include "MA_STLString.h"

#ifdef _NTR_WINDOWS
#pragma warning( push )
#pragma warning( disable : 4702 )
#endif

#include <hash_map>

#ifdef _NTR_WINDOWS
#pragma warning( pop )
#endif

#define MA_DEFINE_STL_HASHSTRINGCIMAP( MapName, MapValue ) \
	typedef stdext::hash_map<Earth::MA_STLTString, MapValue, stdext::hash_compare<Earth::MA_STLTString, Earth::MA_CICompareT> >	\
															HMap##MapName; \
	typedef HMap##MapName::value_type						HMap##MapName##VT; \
	typedef HMap##MapName::iterator							HMap##MapName##Itr; \
	typedef HMap##MapName::const_iterator					HMap##MapName##CItr; \
	typedef std::pair<HMap##MapName##Itr, bool>				HMap##MapName##Pr;

#define MA_DEFINE_STL_HASHSTRINGCIMAP_T( MapName, MapValue ) \
	typedef stdext::hash_map<Earth::MA_STLTString, stdext::hash_compare<Earth::MA_STLTString, Earth::MA_CICompareT> >	\
															HMap##MapName; \
	typedef typename HMap##MapName::value_type				HMap##MapName##VT; \
	typedef typename HMap##MapName::iterator				HMap##MapName##Itr; \
	typedef typename HMap##MapName::const_iterator			HMap##MapName##CItr; \
	typedef typename std::pair<HMap##MapName##Itr, bool>	HMap##MapName##Pr;

#endif /* !_MA_STLHASHMAP_H_ */

