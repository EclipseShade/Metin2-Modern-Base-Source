/**
 * @file	STLMap.h
 * @author	Standil (cpascal@cpascal.net)
 * @brief	Header file to use STL map/multimap (remove compiler warning)
 *
 * @version	2004/09/07 cpascal - First release
 */

#ifndef _MA_STLMAP_H_
#define _MA_STLMAP_H_

#ifdef _NTR_WINDOWS
#pragma warning( push )
#pragma warning( disable : 4702 )
#endif

#include <map>

#ifdef _NTR_WINDOWS
#pragma warning( pop )
#endif

#define MA_DEFINE_STL_MAP( MapName, MapKey, MapValue ) \
	typedef std::map<MapKey, MapValue>				Map##MapName; \
	typedef Map##MapName::value_type				Map##MapName##VT; \
	typedef Map##MapName::iterator					Map##MapName##Itr; \
	typedef Map##MapName::const_iterator				Map##MapName##CItr; \
	typedef std::pair<Map##MapName##Itr, bool>			Map##MapName##Pr;

#define MA_DEFINE_STL_MAP_T( MapName, MapKey, MapValue ) \
	typedef std::map<MapKey, MapValue>				Map##MapName; \
	typedef typename Map##MapName::value_type			Map##MapName##VT; \
	typedef typename Map##MapName::iterator				Map##MapName##Itr; \
	typedef typename Map##MapName::const_iterator			Map##MapName##CItr; \
	typedef typename std::pair<Map##MapName##Itr, bool>		Map##MapName##Pr;

#define MA_DEFINE_STL_MULTIMAP( MapName, MapKey, MapValue ) \
	typedef std::multimap<MapKey, MapValue>				Map##MapName; \
	typedef Map##MapName::value_type				Map##MapName##VT; \
	typedef Map##MapName::iterator					Map##MapName##Itr; \
	typedef Map##MapNameMap::const_iterator				Map##MapName##CItr; \
	typedef std::pair<Map##MapName##Itr, Map##MapName##Itr>		Map##MapName##Range;

#define MA_DEFINE_STL_MAP_ASC( MapName, MapKey, MapValue ) \
	typedef std::map<MapKey, MapValue, greater<MapKey>>		Map##MapName; \
	typedef Map##MapName::value_type				Map##MapName##VT; \
	typedef Map##MapName::iterator					Map##MapName##Itr; \
	typedef Map##MapName::const_iterator				Map##MapName##CItr; \
	typedef std::pair<MapName##MapItr, bool>			Map##MapName##Pr;

#define MA_DEFINE_STL_MULTIMAP_ASC( MapName, MapKey, MapValue ) \
	typedef std::multimap<MapKey, MapValue, greater<MapKey>>	Map##MapName; \
	typedef Map##MapName::value_type				Map##MapName##VT; \
	typedef Map##MapName::iterator					Map##MapName##Itr; \
	typedef Map##MapName::const_iterator				Map##MapName##CItr; \
	typedef std::pair<Map##MapName##Itr, Map##MapNameItr>		Map##MapName##Range;

#endif // _MA_STLMAP_H_
