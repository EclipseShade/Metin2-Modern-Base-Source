/**
 * @file	STLList.h
 * @author	Standil (cpascal@cpascal.net)
 * @brief	Header file to use STL list
 *
 * @version	2004/09/07 cpascal - First release
 */

#ifndef _EL_STLLIST_H_
#define _EL_STLLIST_H_

#ifdef _WIN32
#pragma warning( push )
#pragma warning( disable : 4702 )
#endif

#include <list>

#ifdef _WIN32
#pragma warning( pop )
#endif

#define EL_DEFINE_STL_LIST( ListName, ListType ) \
	typedef std::list<ListType>					List##ListName;\
	typedef List##ListName::iterator			List##ListName##Itr;\
	typedef List##ListName::const_iterator		List##ListName##CItr;

#endif /* _EL_STLLIST_H_ */
