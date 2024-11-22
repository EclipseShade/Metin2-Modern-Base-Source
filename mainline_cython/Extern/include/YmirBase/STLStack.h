/**
 * @file	STLStack.h
 * @author	Standil (cpascal@cpascal.net)
 * @brief	Header file to use STL stack
 *
 * @version	2004/09/07 cpascal - First release
 */

#ifndef _EA_STLDEQUE_H_
#define _EA_STLDEQUE_H_

#ifdef _WIN32
#pragma warning( push )
#pragma warning( disable : 4702 )
#endif

#include <stack>

#ifdef _WIN32
#pragma warning( pop )
#endif

#define EA_DEFINE_STL_STACK( StackName, StackType ) \
	typedef std::stack<StackType>				Stack##StackName; \
	typedef Stack##StackName::reference			Stack##StackName##Ref; \
	typedef Stack##StackName::const_reference		Stack##StackName##CRef;

#endif /* _EA_STLDEQUE_H_ */
