/**
* @file		MA_MemoryUtility.h
* @brief	MA_Memory utility functions
* @author	Standil (cpascal@cpascal.net)
* 
* @version	2008/12/17 cpascal - First Release
*/

#ifndef _MA_MEMORYUTILITY_H_
#define _MA_MEMORYUTILITY_H_

_NTR_EXTERN_C_BEGIN

typedef enum MA_tagEHeapType
{
	eHT_DEFAULT_HEAP	= 0,
	eHT_OBJECT_HEAP,
	eHT_OBJECT_ARRAY_HEAP,
	eHT_STRING_HEAP,
	eHT_QUANTITY
} MA_EHEAPTYPE;

extern MA_HANDLE volatile g_ahHeaps[ eHT_QUANTITY ];

extern void MA_MemoryHeapInitialize( void );
extern void MA_MemoryHeapUninitialize( void );

NTR_FORCEINLINE MA_LPVOID MA_MemoryHeapAlloc( MA_EHEAPTYPE eHeapType, MA_SIZE sizeAmount )
{
#if defined(_NTR_WINDOWS)
	MA_ASSERT( g_ahHeaps[eHeapType] != MA_NULL );
	return (MA_LPVOID) HeapAlloc( g_ahHeaps[eHeapType], HEAP_GENERATE_EXCEPTIONS, sizeAmount );
#else
	return (MA_LPVOID) malloc( sizeAmount );
#endif
}

NTR_FORCEINLINE MA_LPVOID MA_MemoryHeapRealloc( MA_EHEAPTYPE eHeapType, MA_LPVOID lpvPointer, MA_SIZE sizeAmount )
{
#if defined(_NTR_WINDOWS)
	MA_ASSERT( g_ahHeaps[eHeapType] != MA_NULL );
	return (MA_LPVOID) HeapReAlloc( g_ahHeaps[eHeapType], HEAP_GENERATE_EXCEPTIONS, lpvPointer, sizeAmount );
#else
	return (MA_LPVOID) realloc( lpvPointer, sizeAmount );
#endif
}

NTR_FORCEINLINE void MA_MemoryHeapFree( MA_EHEAPTYPE eHeapType, MA_LPVOID lpvPointer )
{
#if defined(_NTR_WINDOWS)
	MA_ASSERT( g_ahHeaps[eHeapType] != MA_NULL );
	HeapFree( g_ahHeaps[eHeapType], 0, lpvPointer );
#else
	free( lpvPointer );
#endif
}

NTR_FORCEINLINE void MA_MemoryCopy( MA_LPVOID lpvDestination, MA_LPVOID lpvSource, MA_SIZE sizeAmount )
{
#if defined(_NTR_WINDOWS)
	CopyMemory( lpvDestination, lpvSource, sizeAmount );
#else
	memcpy( lpvDestination, lpvSource, sizeAmount );
#endif
}

NTR_FORCEINLINE void MA_MemoryClear( MA_LPVOID lpvPointer, MA_SIZE sizeAmount )
{
#if defined(_NTR_WINDOWS)
	ZeroMemory( lpvPointer, sizeAmount );
#else
	memset( lpvPointer, 0, sizeAmount );
#endif
}

NTR_FORCEINLINE void MA_MemoryFill( MA_LPVOID lpvPointer, MA_SIZE sizeAmount, MA_BYTE byValue )
{
#if defined(_NTR_WINDOWS)
	FillMemory( lpvPointer, sizeAmount, byValue );
#else
	memset( lpvPointer, byValue, sizeAmount );
#endif
}

_NTR_EXTERN_C_END

#endif /* !_MA_MEMORYUTILITY_H_ */
