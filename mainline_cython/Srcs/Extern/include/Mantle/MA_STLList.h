/**
 * @file	STLList.h
 * @author	Standil (cpascal@cpascal.net)
 * @brief	Header file to use STL list (remove compiler warning)
 *
 * @version	2004/09/07 cpascal - First release
 */

#ifndef _MA_STLLIST_H_
#define _MA_STLLIST_H_

#ifdef _NTR_WINDOWS
#pragma warning( push )
#pragma warning( disable : 4702 )
#endif

#include <list>

#ifdef _NTR_WINDOWS
#pragma warning( pop )
#endif

#define MA_DEFINE_STL_LIST( ListName, ListType ) \
	typedef std::list<ListType>					List##ListName;\
	typedef List##ListName::iterator			List##ListName##Itr;\
	typedef List##ListName::const_iterator		List##ListName##CItr;

#endif /* _MA_STLLIST_H_ */
