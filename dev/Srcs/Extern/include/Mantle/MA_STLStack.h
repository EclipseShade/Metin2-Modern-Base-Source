/**
 * @file	STLStack.h
 * @author	Standil (cpascal@cpascal.net)
 * @brief	Header file to use STL stack
 *
 * @version	2004/09/07 cpascal - First release
 */

#ifndef _MA_STLDEQUE_H_
#define _MA_STLDEQUE_H_

#ifdef _NTR_WINDOWS
#pragma warning( push )
#pragma warning( disable : 4702 )
#endif

#include <stack>

#ifdef _NTR_WINDOWS
#pragma warning( pop )
#endif

#define MA_DEFINE_STL_STACK( StackName, StackType ) \
	typedef std::stack<StackType>				Stack##StackName; \
	typedef Stack##StackName::reference			Stack##StackName##Ref; \
	typedef Stack##StackName::const_reference		Stack##StackName##CRef;

#endif /* _MA_STLDEQUE_H_ */
