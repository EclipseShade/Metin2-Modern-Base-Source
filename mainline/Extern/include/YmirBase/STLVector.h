/**
 * @file	STLVector.h
 * @author	Standil (cpascal@cpascal.net)
 * @brief	Header file to use STL vector
 *
 * @version	2004/09/07 cpascal - First release
 */

#ifndef _EL_STLVECTOR_H_
#define _EL_STLVECTOR_H_

#ifdef _WIN32
#pragma warning( push )
#pragma warning( disable : 4702 )
#endif

#include <vector>

#ifdef _WIN32
#pragma warning( pop )
#endif


#define EL_DEFINE_STL_VECTOR( VectorName, VectorType )\
	typedef std::vector< VectorType >					Vec##VectorName;	\
	typedef Vec##VectorName::iterator					Vec##VectorName##Itr;	\
	typedef Vec##VectorName::const_iterator				Vec##VectorName##CItr;

#define EL_DEFINE_STL_VECTOR_T( VectorName, VectorType )\
	typedef std::vector< VectorType >					Vec##VectorName;	\
	typedef typename Vec##VectorName::iterator			Vec##VectorName##Itr;	\
	typedef typename Vec##VectorName::const_iterator	Vec##VectorName##CItr;


#endif /* _EL_STLVECTOR_H_ */
