/**
 * @file	STLDeque.h
 * @author	Standil (cpascal@cpascal.net)
 * @brief	Header file to use STL deque
 *
 * @version	2004/09/07 cpascal - First release
 */

#ifndef _MA_STLDEQUE_H_
#define _MA_STLDEQUE_H_

#ifdef _NTR_WINDOWS
#pragma warning( push )
#pragma warning( disable : 4702 )
#endif

#include <deque>

#ifdef _NTR_WINDOWS
#pragma warning( pop )
#endif

#define MA_DEFINE_STL_DEQUE( DequeName, DequeType ) \
	typedef std::deque<DequeType>				Deque##Deque;\
	typedef Deque##DequeName::iterator			Deque##DequeName##Itr;\
	typedef Deque##DequeName::const_iterator		Deque##DequeName##CItr;

#endif /* _MA_STLDEQUE_H_ */
