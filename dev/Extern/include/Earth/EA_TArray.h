/**
 * @file	EA_TArray.h
 * @brief	Header file for Auto grow array template class in Solar System
 * @author	bravefirebat ( bravefirebat@gmail.com )
 *
 * @version	2008/04/28 bravefirebat - First release
 */

#ifndef	_EA_TARRAY_H_
#define	_EA_TARRAY_H_

#include "EA_Memory.h"

_EA_NAMESPACE_BEGIN

/**
 * @brief	Smart array.
 * @param[in]	fnMalloc - Function pointer for allocates memory blocks.
		fnFree - Function pointer for deallocates pr frees a memory blocks.
		fnRealloc - Function pointer for rellocate memory blocks.
 */
template<class T, EA_MALLOC fnMalloc = malloc, EA_FREE fnFree = free, EA_REALLOC fnRealloc = realloc>
class EA_TArray
{
public:
	typedef	typename EA_INT	(*ARRAY_COMPAREFUNC)( const T&, const T& );
	typedef	typename void	(*ARRAY_SWAPFUNC)( T&, T& );
public:
	/**
	 * @constructor	EA_TArray
	 * @brief	Basic constructor
	 */
	EA_TArray( void );

	/**
	 * @constructor	EA_TArray
	 * @brief	Constructor
	 * @param[in]	sizeChunk	- Size of memory chunk when array grow if necessary
	 */
	EA_TArray( EA_SIZE sizeChunk );

	/**
	 @destructor	~EA_TArray
	 @brief		Virtual destructor
	 */
	virtual	~EA_TArray( void );

	void		Exchange( EA_TArray* pcArray );

	T*		Attach( T* ptValue, EA_SIZE sizeCount );
	T*		Attach( T* ptValue, EA_SIZE sizeCount, EA_SIZE sizeAllocated );
	T*		Detach( void );
	void		Detach( T** pptValue, EA_SIZE* psizeCount, EA_SIZE* psizeAllocated );

	EA_SIZE	GetMemoryUsage( void ) const;
	EA_SIZE	GetMaxIndex( void ) const;
	EA_SIZE	GetAllocatedMemoryUsage( void ) const;

	/**
	 @brief		Get the number of elements in this array
	 */
	EA_SIZE	GetCount( void ) const;

	/**
	 * @brief	Set the number of elements to be contained in this array.
	 * @param[in]	sizeCount	- The new array size.
	 */
	virtual	void	SetCount( EA_SIZE sizeCount );

	/**
	 * @brief	Get the number of element slot to allocate.
	 */
	EA_SIZE	GetChunkSize( void ) const;

	/**
	 * @brief	Set the number of element slot to alloate.
	 * @param[in]	sizeChunk	- The number of elements slots to allocate if a size increase is necessary.
	 */
	void		SetChunkSize( EA_SIZE sizeChunk );

	/**
	 * @brief	Returns the number of elements that the this array could contain without allocating more storage.
	 */
	EA_SIZE	GetCapacitySize( void ) const;

	/**
	 * @brief	Returns the value at a given index.
	 * @returns	The pointer of array element currently at this index.
	 */
	T&		GetAt( EA_SIZE sizeIndex );

	/**
	 * @brief	Sets the value for a given index; array not allowed to grow.
	 * @param[in]	sizeIndex	- Index of array element.
	 *		pValue		- The new element.
	 */
	EA_BOOL		SetAt( EA_SIZE sizeIndex, T& rValue );

	/**
	 * @brief	Removes an element at a specific index.
	 * @param[in]	sizeIndex	- Index of array element.
	 */
	EA_BOOL		EraseAt( EA_SIZE sizeIndex );

	/**
	 * @brief	Find an element.
	 * @param[in]	pSource		- pointer an element that find.
	 *		pCompareFunc	- Pointer of find function.
	 * @returns	Index of found item. 0xFFFFFFFF if not found pSource in this class.
	 */
	EA_SIZE	Find( const T& rSource, ARRAY_COMPAREFUNC pCompareFunc = EA_NULL );

	/**
	 * @brief	Find an element in this class.
	 * @param[in]	pSource		- pointer an element that find.
	 *		pCompareFunc	- Pointer of find function.
	 * @returns	EA_TRUE if pValue is contained in this class. other wise EA_FALSE.
	 */
	EA_BOOL		IsContains( const T& rValue, ARRAY_COMPAREFUNC pCompareFunc = EA_NULL );

	/**
	 * @brief	Tests if the array is empty.
	 */
	EA_BOOL		IsEmpty( void );

	/**
	 * @brief	Get pointer of elements that allocated.
	 */
	const T*	GetRawBuffer( void ) const;

	T*		Get( void );
	const T*	Get( void ) const;
	void		Set( T* pSource, EA_SIZE sizeCount );

	/**
	 * @brief	Sort array elements in this class.
	 * @param[in]	pCompareFunc	- Pointer of compare function.
	 *		pSwapFunc	- Pointer of swap function.
	 */
	void		Sort( ARRAY_COMPAREFUNC pCompareFunc = EA_NULL, ARRAY_SWAPFUNC pSwapFunc = EA_NULL );

	/**
	 * @brief	Do a binary search, array must be sorted.
	 * @param[in]	pElement	- 찾을 element
	 */
	EA_INDEX_T	BinarySearchIndex( const T& rElement ) const;

	/**
	 * @brief	sizeFromInde이 위치에서 sizeToIndex까지 sizeCount만큼의 갯수를 이동시킨다.
	 * @param[in]	sizeFromIndex	- 이동 될 원본 index
	 *		sizeToIndex	- 이동 할 목적지의 index
	 *		sizeCount	- 이동할 element의 개수
	 * @returns	EA_TRUE		- 이동 성공
	 *		EA_FALSE	- 이동 실패. index + count의 개수가 전체 목록을 넘어가면 실패할 수 있다.
	 */
	EA_BOOL		Move( EA_SIZE sizeFromIndex, EA_SIZE sizeToIndex, EA_SIZE sizeCount );

	/**
	 * @brief	pcSource의 내용을 복사한다.
	 * @param[in]	pcSource	- 원본 클래스
	 */
	EA_SIZE	Copy( const EA_TArray& rcSource );

	/**
	 * @brief	현재 클래스의 뒤에 pcSource클래스의 element를 복사한다.
	 * @param[in]	pcSource	- 원본 클래스
	 */
	EA_SIZE	Append( const EA_TArray& rcSource );

	/**
	 * @brief	현재 클래스에 T를 sizeCount만큼 추가 한다.
	 * @returns	추가 완료된 현재 클래스의 총 count.
	 */
	EA_SIZE	Add( const T& rSource );
	EA_SIZE	Add( const T* pSource, EA_SIZE sizeCount );

	/**
	 * @brief	미리 sizeReverse만큼의 element를 예약한다.(count는 증가되지 않는다)
	 */
	void		Reserve( EA_SIZE sizeReserve );

	/**
	 * @brief	sizeNew만큼 array를 증가 시킨다. 만약 sizeNew가 2라면 전체 크기를 2로 만드는게 아니라, 2만큼 버퍼를 늘리게 된다.
	 */
	void		Grow( EA_SIZE sizeNew );

	/**
	 * @brief	chunk단위로 메모리를 늘리지 않고 입력된 sizeNew만큼 즉시 버퍼를 늘린다.
	 */
	void		GrowExact( EA_SIZE sizeNew );

	/**
	 * @brief	sizeCount만큼 element를 할당한다.
	 */
	void		Allocate( EA_SIZE sizeCount );

	/**
	 * @brief	sizeCount만큼 element를 재할당한다.
	 */
	void		Reallocate( EA_SIZE sizeNew );

	/**
	 * @brief	내부적으로 할당된 메모리를 해제한다.
	 */
	void		Free( void );

	/**
	 * @brief	클래스를 초기화 한다.
	 */
	void		Clear( void );


	/**
	 * @brief	sizeIndex위치에 있는 element의 생성자를 호출한다.
	 */
	void		Initialize( EA_SIZE sizeIndex );

	/**
	 * @brief	sizeIndex위치에 있는 element의 복사생성자를 호출한다.
	 */
	void		Initialize( EA_SIZE sizeIndex, const T& rValue );

	/**
	 * @brief	sizeIndex위치에 있는 element의 소멸자를 호출한다.
	 */
	void		Destroy( EA_SIZE sizeIndex );

	/**
	 * @brief	GetAt와 같은기능. 해당위치의 데이터를 얻어온다.
	 */
	T&		operator[]( EA_SIZE sizeIndex );

	/**
	 * @brief	GetAt와 같은기능. 해당위치의 데이터를 얻어온다.
	 */
	const T&	operator[]( EA_SIZE sizeIndex ) const;
protected:
	void		QuickSort( EA_SIZE sizeFirstIndex, EA_SIZE sizeLastIndex, ARRAY_COMPAREFUNC pCompareFunc, ARRAY_SWAPFUNC pSwapFunc );
	//static	EA_INT	DefaultCompareFunc( T& pLHS, T& pRHS );
	//static	EA_INT	DefaultSwapFunc( T& pLHS, T& pRHS );

	EA_SIZE	m_sizeAllocatedCount;
	EA_SIZE	m_sizeCount;
	EA_SIZE	m_sizeChunk;
	T*		m_pData;
};

#include "EA_TArray.inl"

_EA_NAMESPACE_END

#endif /* !_EA_TARRAY_H_ */

