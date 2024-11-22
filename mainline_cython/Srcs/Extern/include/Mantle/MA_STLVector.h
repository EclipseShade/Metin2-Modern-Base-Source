/**
 * @file	STLVector.h
 * @author	Standil (cpascal@cpascal.net)
 * @brief	Header file to use STL vector (remove compiler warning)
 *
 * @version	2004/09/07 cpascal - First release
 */

#ifndef _MA_STLVECTOR_H_
#define _MA_STLVECTOR_H_

#ifdef _NTR_WINDOWS
#pragma warning( push )
#pragma warning( disable : 4702 )
#endif

#include <vector>

#ifdef _NTR_WINDOWS
#pragma warning( pop )
#endif


#define MA_DEFINE_STL_VECTOR( VectorName, VectorType )\
	typedef std::vector< VectorType >			Vec##VectorName;	\
	typedef Vec##VectorName::iterator			Vec##VectorName##Itr;	\
	typedef Vec##VectorName::const_iterator			Vec##VectorName##CItr;

#define MA_DEFINE_STL_VECTOR_T( VectorName, VectorType )\
	typedef std::vector< VectorType >			Vec##VectorName;	\
	typedef typename Vec##VectorName::iterator		Vec##VectorName##Itr;	\
	typedef typename Vec##VectorName::const_iterator	Vec##VectorName##CItr;


#endif /* _MA_STLVECTOR_H_ */
