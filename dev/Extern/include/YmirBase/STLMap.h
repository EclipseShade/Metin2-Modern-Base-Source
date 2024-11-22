/**
 * @file	STLMap.h
 * @author	Standil (cpascal@cpascal.net)
 * @brief	Header file to use STL map/multimap
 *
 * @version	2004/09/07 cpascal - First release
 */

#ifndef _EL_STLMAP_H_
#define _EL_STLMAP_H_

#ifdef _WIN32
#pragma warning( push )
#pragma warning( disable : 4702 )
#endif

#include <map>

#ifdef _WIN32
#pragma warning( pop )
#endif

#define EL_DEFINE_STL_MAP( MapName, MapKey, MapValue ) \
	typedef std::map<MapKey, MapValue>					Map##MapName; \
	typedef Map##MapName::value_type					Map##MapName##VT; \
	typedef Map##MapName::iterator						Map##MapName##Itr; \
	typedef Map##MapName::const_iterator				Map##MapName##CItr; \
	typedef std::pair<Map##MapName##Itr, bool>			Map##MapName##Pr;

#define EL_DEFINE_STL_MAP_T( MapName, MapKey, MapValue ) \
	typedef std::map<MapKey, MapValue>					Map##MapName; \
	typedef typename Map##MapName::value_type			Map##MapName##VT; \
	typedef typename Map##MapName::iterator				Map##MapName##Itr; \
	typedef typename Map##MapName::const_iterator		Map##MapName##CItr; \
	typedef typename std::pair<Map##MapName##Itr, bool>	Map##MapName##Pr;

#define EL_DEFINE_STL_MULTIMAP( MapName, MapKey, MapValue ) \
	typedef std::multimap<MapKey, MapValue>				Map##MapName; \
	typedef Map##MapName::value_type					Map##MapName##VT; \
	typedef Map##MapName::iterator						Map##MapName##Itr; \
	typedef Map##MapNameMap::const_iterator				Map##MapName##CItr; \
	typedef std::pair<Map##MapName##Itr, Map##MapName##Itr>		Map##MapName##Range;

#define EL_DEFINE_STL_MAP_ASC( MapName, MapKey, MapValue ) \
	typedef std::map<MapKey, MapValue, greater<MapKey>>		Map##MapName; \
	typedef Map##MapName::value_type						Map##MapName##VT; \
	typedef Map##MapName::iterator							Map##MapName##Itr; \
	typedef Map##MapName::const_iterator					Map##MapName##CItr; \
	typedef std::pair<MapName##MapItr, bool>				Map##MapName##Pr;

#define EL_DEFINE_STL_MULTIMAP_ASC( MapName, MapKey, MapValue ) \
	typedef std::multimap<MapKey, MapValue, greater<MapKey>>	Map##MapName; \
	typedef Map##MapName::value_type							Map##MapName##VT; \
	typedef Map##MapName::iterator								Map##MapName##Itr; \
	typedef Map##MapName::const_iterator						Map##MapName##CItr; \
	typedef std::pair<Map##MapName##Itr, Map##MapNameItr>		Map##MapName##Range;

#endif // _EL_STLMAP_H_
