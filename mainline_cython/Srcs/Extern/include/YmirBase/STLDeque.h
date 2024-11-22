/**
 * @file	STLDeque.h
 * @author	Standil (cpascal@cpascal.net)
 * @brief	Header file to use STL deque
 *
 * @version	2004/09/07 cpascal - First release
 */

#ifndef _EL_STLDEQUE_H_
#define _EL_STLDEQUE_H_

#ifdef _WIN32
#pragma warning( push )
#pragma warning( disable : 4702 )
#endif

#include <deque>

#ifdef _WIN32
#pragma warning( pop )
#endif

#define EL_DEFINE_STL_DEQUE( DequeName, DequeType ) \
	typedef std::deque<DequeType>				Deque##Deque;\
	typedef Deque##DequeName::iterator			Deque##DequeName##Itr;\
	typedef Deque##DequeName::const_iterator		Deque##DequeName##CItr;

#endif /* _EL_STLDEQUE_H_ */
