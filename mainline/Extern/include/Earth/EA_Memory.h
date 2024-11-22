/**
 * @file	EA_Memory.h
 * @brief	Memory management class / functions
 * @author	Standil (cpascal@gmail.com)
 *
 * @version	2008/04/23 cpascal - First release
 *
 * @reference	Quazal Eterna library
 */

#ifndef	_EA_MEMORY_H_
#define	_EA_MEMORY_H_

#include <new>

//#include "EA_TParasiteLink.h"

_EA_NAMESPACE_BEGIN

void EA_SafeCopy( PVOID pDestination, PVOID pSource, DWORD dwSize );

typedef	EA_PVOID			(*EA_MALLOC)(EA_SIZE sizeAlloc );
typedef	void				(*EA_FREE)(EA_PVOID pvAllocated );
typedef	EA_PVOID			(*EA_REALLOC)( EA_PVOID pvAllocated, EA_SIZE sizeAlloc );

typedef	class EA_CAllocator*		EA_PCALLOCATOR;

//typedef	struct EA_tagAllocateHeader	EA_SALLOCATEHEADER;
//typedef	EA_SALLOCATEHEADER*		EA_PALLOCATEHEADER;
//
//typedef	struct	EA_tagAllocateHeader : public EA_TParasiteLink<EA_tagAllocateHeader>
//{
//	EA_PCALLOCATOR		m_pMemoryManager;
//	EA_FREE			m_fnFreeHandler;
//	EA_SIZE		m_sizeReal;
//	EA_SIZE		m_sizeAlignment;
//#if defined (_UNV_DEBUG)
//	MA_PTSTR		m_tszFileName;
//	EA_INT			m_nLineNumber;
//#endif
//	EA_SIZE		m_sizePadding;
//
//	EA_tagAllocateHeader( void )
//		: m_pMemoryManager( EA_NULL ), m_fnFreeHandler( EA_NULL ), m_sizeReal( 0 ), m_sizeAlignment( 0 ), m_sizePadding( 0 )
//	{
//	}
//
//	static	void			sInitHeader( EA_PALLOCATEHEADER pHeader )
//	{
//		pHeader->m_pNext		= EA_NULL;
//		pHeader->m_pPrevLink		= EA_NULL;
//		pHeader->m_pMemoryManager	= EA_NULL;
//		pHeader->m_fnFreeHandler	= EA_NULL;
//		pHeader->m_sizeReal		= 0;
//		pHeader->m_sizeAlignment	= 0;
//#if defined( _UNV_DEBUG )
//		pHeader->m_tszFileName		= EA_NULL;
//		pHeader->m_nLineNumber		= 0;
//#endif
//		pHeader->m_sizePadding		= 0;
//	}
//
//	static EA_PALLOCATEHEADER	sGetHeader( EA_PVOID IN pvAllocatedMemory )
//	{
//		EA_SIZE sizePadding = *( (EA_SIZE*)((EA_PBYTE)pvAllocatedMemory - sizeof(EA_SIZE)) );
//		return (EA_PALLOCATEHEADER)((EA_PBYTE)pvAllocatedMemory - sizePadding);
//	}
//} EA_SALLOCATEHEADER, *EA_PALLOCATEHEADER;

// Memory Util function : Singleton 규칙이 정해진 후 작업
//template<typename T>
//EA_PVOID	EA_AllocateArray( EA_SIZE sizeCount, EA_SIZE sizeAlignment, MA_PCTSTR tszFileName, EA_INT nLineNumber );
//
//template<typename T>
//EA_PVOID	EA_ReallocateArray( T* pvPointer, EA_SIZE sizeCount, EA_SIZE sizeAlignment, MA_PCTSTR tszFileName, EA_INT nLineNumber );
//
//template<typename T>
//void		EA_DeallocateArray( T* pvPointer );

_EA_NAMESPACE_END

#endif /* !_EA_MEMORY_H_ */

