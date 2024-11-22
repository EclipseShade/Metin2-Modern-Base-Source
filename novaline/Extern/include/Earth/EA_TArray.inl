template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
EA_TArray<T, fnMalloc, fnFree, fnRealloc>::EA_TArray()
: m_pData( EA_NULL )
, m_sizeCount( 0 )
, m_sizeChunk( 0 )
, m_sizeAllocatedCount( 0 )
{
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
EA_TArray<T, fnMalloc, fnFree, fnRealloc>::EA_TArray( EA_SIZE sizeChunk )
: m_pData( EA_NULL )
, m_sizeCount( 0 )
, m_sizeChunk( sizeChunk )
, m_sizeAllocatedCount( 0 )
{
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
EA_TArray<T, fnMalloc, fnFree, fnRealloc>::~EA_TArray()
{
	Free();
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
void		EA_TArray<T, fnMalloc, fnFree, fnRealloc>::Exchange( EA_TArray* pcArray )
{
	T*		pDataTemp = EA_NULL;
	EA_SIZE	sizeTemp = 0;

	pDataTemp = m_pData;
	m_pData = pcArray->m_pData;
	pcArray->m_pData = pDataTemp;
	
	EA_SWAP( m_sizeAllocatedCount, pcArray->m_sizeAllocatedCount );
	EA_SWAP( m_sizeCount, pcArray->m_sizeCount );
	EA_SWAP( m_sizeChunk, pcArray->m_sizeChunk );
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
T*		EA_TArray<T, fnMalloc, fnFree, fnRealloc>::Attach( T* ptValue, EA_SIZE sizeCount )
{
	T*	pDataTemp = m_pData;

	m_pData = ptValue;
	m_sizeCount = sizeCount;
	m_sizeAllocatedCount = sizeCount;

	return pDataTemp;
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
T*		EA_TArray<T, fnMalloc, fnFree, fnRealloc>::Attach( T* ptValue, EA_SIZE sizeCount, EA_SIZE sizeAllocated )
{
	T*	pDataTemp = m_pData;

	m_pData	= ptValue;
	m_sizeCount = sizeCount;
	m_sizeAllocatedCount = sizeAllocated;

	return pDataTemp;
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
T*		EA_TArray<T, fnMalloc, fnFree, fnRealloc>::Detach( void )
{
	T*	pDataTemp = m_pData;

	m_pData = EA_NULL;
	m_sizeCount = 0;
	m_sizeAllocatedCount = 0;

	return pDataTemp;
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
void		EA_TArray<T, fnMalloc, fnFree, fnRealloc>::Detach( T** pptValue, EA_SIZE* psizeCount, EA_SIZE* psizeAllocated )
{
	*pptValue	= m_pData;
	*psizeCount	= m_sizeCount;
	*psizeAllocated	= m_sizeAllocatedCount;

	m_pData			= EA_NULL;
	m_sizeCount		= 0;
	m_sizeAllocatedCount	= 0;
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
EA_SIZE	EA_TArray<T, fnMalloc, fnFree, fnRealloc>::GetMemoryUsage() const
{
	return m_sizeCount * sizeof( T );
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
EA_SIZE	EA_TArray<T, fnMalloc, fnFree, fnRealloc>::GetMaxIndex() const
{
	return m_sizeCount - 1;
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
EA_SIZE	EA_TArray<T, fnMalloc, fnFree, fnRealloc>::GetAllocatedMemoryUsage() const
{
	return m_sizeAllocatedCount * sizeof( T );
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
NTR_INLINE EA_SIZE	EA_TArray<T, fnMalloc, fnFree, fnRealloc>::GetCount() const
{
	return m_sizeCount;
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
NTR_INLINE void		EA_TArray<T, fnMalloc, fnFree, fnRealloc>::SetCount( EA_SIZE sizeCount )
{
	if( sizeCount == 0 )
		return Free();

	EA_SIZE sizeOldCount = (EA_INT)m_sizeCount;
	if( m_sizeCount < sizeCount ) {
		Grow( sizeCount - m_sizeCount );

		for( ; sizeOldCount < m_sizeCount; ++sizeOldCount )
			Initialize( sizeOldCount );

		m_sizeCount = sizeCount;
	} else
		return;
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
NTR_INLINE EA_SIZE	EA_TArray<T, fnMalloc, fnFree, fnRealloc>::GetChunkSize() const
{
	return m_sizeChunk;
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
NTR_INLINE void		EA_TArray<T, fnMalloc, fnFree, fnRealloc>::SetChunkSize( EA_SIZE sizeChunk )
{
	m_sizeChunk = sizeChunk;
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
NTR_INLINE EA_SIZE	EA_TArray<T, fnMalloc, fnFree, fnRealloc>::GetCapacitySize() const
{
	return m_sizeAllocatedCount * sizeof( T );
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
NTR_INLINE T&		EA_TArray<T, fnMalloc, fnFree, fnRealloc>::GetAt( EA_SIZE sizeIndex )
{
	//if( sizeIndex >= m_sizeCount )
	//	return EA_NULL;

	return m_pData[ sizeIndex ];
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
NTR_INLINE EA_BOOL		EA_TArray<T, fnMalloc, fnFree, fnRealloc>::SetAt( EA_SIZE sizeIndex, T& rValue )
{
	if( sizeIndex >= m_sizeCount )
		return EA_FALSE;

	memcpy( &m_pData[ sizeIndex ], &rValue, sizeof( T ) );
	return EA_TRUE;
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
NTR_INLINE EA_BOOL		EA_TArray<T, fnMalloc, fnFree, fnRealloc>::EraseAt( EA_SIZE sizeIndex )
{
	if( sizeIndex >= m_sizeCount )
		return EA_FALSE;

	Destroy( sizeIndex );

	if( Move( sizeIndex + 1, sizeIndex, m_sizeCount - sizeIndex - 1 ) ) {
		--m_sizeCount;
		return EA_TRUE;
	} else {
		--m_sizeCount;
		return EA_FALSE;
	}
	
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
NTR_INLINE EA_SIZE	EA_TArray<T, fnMalloc, fnFree, fnRealloc>::Find( const T& rSource, typename EA_TArray<T, fnMalloc, fnFree, fnRealloc>::ARRAY_COMPAREFUNC pCompareFunc )
{
	if( EA_ISNULL( pCompareFunc ) ) {
		for( EA_SIZE sizeIndex = 0; sizeIndex < m_sizeCount; ++sizeIndex ) {
			if( 0 == memcmp( &rSource, &m_pData[sizeIndex], sizeof( T ) ) )
				return sizeIndex;
		}
	} else {
		for( EA_SIZE sizeIndex = 0; sizeIndex < m_sizeCount; ++sizeIndex ) {
			if( 0 == pCompareFunc( rSource, m_pData[sizeIndex] ) )
				return sizeIndex;
		}
	}

	return EA_NOT_FOUND;
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
NTR_INLINE EA_BOOL		EA_TArray<T, fnMalloc, fnFree, fnRealloc>::IsContains( const T& rValue, typename EA_TArray<T, fnMalloc, fnFree, fnRealloc>::ARRAY_COMPAREFUNC pCompareFunc )
{
	if( EA_NOT_FOUND == Find( rValue, pCompareFunc ) )
		return EA_FALSE;
	else
		return EA_TRUE;
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
NTR_INLINE EA_BOOL		EA_TArray<T, fnMalloc, fnFree, fnRealloc>::IsEmpty( void )
{
	return (m_sizeCount == 0) ? EA_TRUE : EA_FALSE;
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
NTR_INLINE const T*	EA_TArray<T, fnMalloc, fnFree, fnRealloc>::GetRawBuffer( void ) const
{
	return m_pData;
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
NTR_INLINE T*		EA_TArray<T, fnMalloc, fnFree, fnRealloc>::Get()
{
	return m_pData;
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
NTR_INLINE const T*	EA_TArray<T, fnMalloc, fnFree, fnRealloc>::Get() const
{
	return m_pData;
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
NTR_INLINE void		EA_TArray<T, fnMalloc, fnFree, fnRealloc>::Set( T* pSource, EA_SIZE sizeCount )
{
	sizeCount = EA_MIN( sizeCount, m_sizeAllocatedCount );

	for( EA_SIZE sizeIndex = 0; sizeIndex < sizeCount; ++sizeIndex )
		SetAt( sizeIndex, pSource[sizeIndex] );
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
NTR_INLINE void EA_TArray<T, fnMalloc, fnFree, fnRealloc>::Sort( typename EA_TArray<T, fnMalloc, fnFree, fnRealloc>::ARRAY_COMPAREFUNC pCompareFunc, typename EA_TArray<T, fnMalloc, fnFree, fnRealloc>::ARRAY_SWAPFUNC pSwapFunc )
{
	QuickSort( 0, m_sizeCount, pCompareFunc, pSwapFunc );
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
EA_INDEX_T EA_TArray<T, fnMalloc, fnFree, fnRealloc>::BinarySearchIndex( const T& rElement ) const
{
	EA_INDEX_T nCount = (EA_INDEX_T) GetCount();
	if( nCount > 0 ) {
		EA_INDEX_T iHalf;
		EA_INDEX_T iLow = 0;
		EA_INDEX_T iHigh = nCount - 1;
		EA_INDEX_T iMiddle;

		while( iLow <= iHigh ) {
			if( 0 != (iHalf = nCount/2) ) {
				iMiddle = iLow + ((nCount & 1) ? iHalf : (iHalf - 1));
				if( rElement < m_pData[iMiddle] ) {
					iHigh = iMiddle - 1;
					nCount = nCount & 1 ? iHalf : iHalf - 1;
				} else if (rElement > m_pData[iMiddle]) {
					iLow = iMiddle + 1;
					nCount = iHalf;
				} else {
					return iMiddle;
				}
			} else if( 0 != nCount ) {
				if( rElement != m_pData[iLow] ) {
					return EA_INVALID_INDEX_T;
				} else {
					return iLow;
				}
			} else {
				break;
			}
		}
	}
	return EA_INVALID_INDEX_T;
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
NTR_INLINE void		EA_TArray<T, fnMalloc, fnFree, fnRealloc>::QuickSort( EA_SIZE sizeFirstIndex, EA_SIZE sizeLastIndex, typename EA_TArray<T, fnMalloc, fnFree, fnRealloc>::ARRAY_COMPAREFUNC pCompareFunc, typename EA_TArray<T, fnMalloc, fnFree, fnRealloc>::ARRAY_SWAPFUNC pSwapFunc )
{
	if( sizeFirstIndex >= sizeLastIndex )
		return;

	EA_SIZE	sizePivot	= sizeFirstIndex;
	EA_SIZE	sizeLeft	= sizeFirstIndex;
	EA_SIZE	sizeRight	= sizeLastIndex;

	for( ; ; ) {
		while( &m_pData[sizePivot], pCompareFunc( &m_pData[sizeLeft] ) <= 0 ) ++sizeLeft;
		while( &m_pData[sizePivot], pCompareFunc( &m_pData[sizeRight] ) >= 0 ) --sizeRight;

		if( sizeLeft > sizeRight )
			break;
		else
			pSwapFunc( &m_pData[sizeLeft], &m_pData[sizeRight] );
	}

	pSwapFunc( &m_pData[sizePivot], &m_pData[sizeRight] );

	QuickSort( sizeFirstIndex, sizeRight - 1, pCompareFunc, pSwapFunc );
	QuickSort( sizeRight + 1, sizeLastIndex, pCompareFunc, pSwapFunc );
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
NTR_INLINE EA_BOOL		EA_TArray<T, fnMalloc, fnFree, fnRealloc>::Move( EA_SIZE sizeFromIndex, EA_SIZE sizeToIndex, EA_SIZE sizeCount )
{
	if( sizeFromIndex == sizeToIndex )
		return EA_TRUE;

	if( m_sizeCount < ( sizeFromIndex + sizeCount ) || m_sizeCount < ( sizeToIndex + sizeCount ) )
		return EA_FALSE;

	if( sizeFromIndex > sizeToIndex ) { // Front to rear
		for( EA_SIZE sizeIndex = 0; sizeIndex < sizeCount; ++sizeIndex )
			memcpy( &m_pData[sizeToIndex + sizeIndex], &m_pData[sizeFromIndex + sizeIndex], sizeof( T ) );
	} else { // Rear to front
		for( EA_INT nIndex = (EA_INT)sizeCount; nIndex > 0; --nIndex )
			memcpy( &m_pData[sizeToIndex + nIndex], &m_pData[sizeFromIndex + nIndex], sizeof( T ) );
	}

	return EA_TRUE;
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
NTR_INLINE EA_SIZE	EA_TArray<T, fnMalloc, fnFree, fnRealloc>::Copy( const EA_TArray& rcSource )
{
	if( rcSource.IsEmpty() )
		return 0;

	Free();

	m_sizeAllocatedCount = rcSource.m_sizeAllocatedCount;
	m_sizeCount = rcSource.GetCount();
	m_sizeChunkSize = rcSource.GetChunkSize();

	m_pData = (T*)fnMalloc( sizeof( T ) * m_sizeAllocatedCount );

	memcpy( m_pData, rcSource.GetRawBuffer(), m_sizeAllocatedCount );

	return m_sizeCount;
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
NTR_INLINE EA_SIZE	EA_TArray<T, fnMalloc, fnFree, fnRealloc>::Append( const EA_TArray& rcSource )
{
	if( rcSource.GetCount() == 0 )
		return GetCount();

	EA_SIZE sizeSource = rcSource.GetCount();
	Grow( sizeSource );

	memcpy( &m_pData[ m_sizeCount ], rcSource.GetRawBuffer(), sizeof( T ) * sizeSource );

	m_sizeCount += sizeSource;

	return m_sizeCount;
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
EA_SIZE		EA_TArray<T, fnMalloc, fnFree, fnRealloc>::Add( const T& rSource )
{
	Grow( 1 );
	Initialize( GetMaxIndex(), rSource );

	return m_sizeCount;
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
NTR_INLINE EA_SIZE	EA_TArray<T, fnMalloc, fnFree, fnRealloc>::Add( const T* pcSource, EA_SIZE sizeCount )
{
	if( sizeCount == 0 )
		return m_sizeCount;

	EA_SIZE sizeOldCount = GetCount();
	Grow( sizeCount );

	for( EA_SIZE sizeIndex = sizeOldCount; sizeIndex < m_sizeCount; ++sizeIndex ) {
		Initialize( sizeIndex );
		memcpy( &m_pData[ sizeIndex ], pcSource, sizeof( T ) );
		++pcSource;
	}

	return m_sizeCount;
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
NTR_INLINE void		EA_TArray<T, fnMalloc, fnFree, fnRealloc>::Reserve( EA_SIZE sizeReserveCount )
{
	if( m_sizeAllocatedCount < sizeReserveCount ) {
		if( EA_ISNULL( m_pData ) )
			Allocate( sizeReserveCount );
		else
			Reallocate( sizeReserveCount );
	}
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
NTR_INLINE void		EA_TArray<T, fnMalloc, fnFree, fnRealloc>::Grow( EA_SIZE sizeGrowCount )
{
	m_sizeCount += sizeGrowCount;
	if( m_sizeCount < m_sizeAllocatedCount )
		return;

	if( !EA_ISNULL( m_pData ) ) {
		if( m_sizeChunk != 0 ) {
			int nNewCountMultiple = (int)sizeGrowCount / (int)m_sizeChunk;
			if( sizeGrowCount % m_sizeChunk != 0 )
				nNewCountMultiple++;

			Reallocate( ( m_sizeCount - sizeGrowCount ) + ( m_sizeChunk * nNewCountMultiple ) );
		} else
			Reallocate( m_sizeCount );
	} else {
		if( m_sizeChunk != 0 ) {
			int nNewCountMultiple = ( (int)sizeGrowCount / (int)m_sizeChunk );
			if( sizeGrowCount % m_sizeChunk != 0 )
				nNewCountMultiple++;

			Allocate( ( m_sizeCount - sizeGrowCount ) + ( m_sizeChunk * nNewCountMultiple ) );
		} else
			Allocate( m_sizeCount );
	}
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
NTR_INLINE void		EA_TArray<T, fnMalloc, fnFree, fnRealloc>::GrowExact( EA_SIZE sizeGrowCount )
{
	m_sizeCount += sizeGrowCount;
	if( m_sizeAllocatedCount > m_sizeCount )
		return;

	if( !EA_ISNULL( m_pData ) )
		Reallocate( m_sizeCount );
	else
		Allocate( m_sizeCount );
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
NTR_INLINE void		EA_TArray<T, fnMalloc, fnFree, fnRealloc>::Allocate( EA_SIZE sizeCount )
{
	if( !EA_ISNULL( m_pData ) )
		Free();

	m_pData = (T*)fnMalloc( sizeof( T ) * sizeCount );
	m_sizeAllocatedCount = sizeCount;
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
NTR_INLINE void		EA_TArray<T, fnMalloc, fnFree, fnRealloc>::Reallocate( EA_SIZE sizeCount )
{
	if( EA_ISNULL( m_pData ) )
		return;

	EA_PVOID pReallocated = fnRealloc( m_pData, sizeof( T ) * sizeCount );
	if( pReallocated ) {
		m_pData = (T*)pReallocated;
		m_sizeAllocatedCount = sizeCount;
	}
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
NTR_INLINE void		EA_TArray<T, fnMalloc, fnFree, fnRealloc>::Free( void )
{
	for( EA_SIZE sizeIndex = 0; sizeIndex < m_sizeCount; ++sizeIndex )
		Destroy( sizeIndex );

	m_sizeAllocatedCount	= 0;
	m_sizeCount		= 0;
	m_sizeChunk		= 0;

	if( EA_ISNOTNULL( m_pData ) ) {
		fnFree( m_pData );
		m_pData = EA_NULL;
	}
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
NTR_INLINE void		EA_TArray<T, fnMalloc, fnFree, fnRealloc>::Clear( void )
{
	EA_SIZE sizeChunk = m_sizeChunk;
	Free();
	SetChunkSize( sizeChunk );
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
NTR_INLINE void		EA_TArray<T, fnMalloc, fnFree, fnRealloc>::Initialize( EA_SIZE sizeIndex )
{
	::new ( m_pData + sizeIndex ) T;
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
NTR_INLINE void		EA_TArray<T, fnMalloc, fnFree, fnRealloc>::Initialize( EA_SIZE sizeIndex, const T& rValue )
{
	::new ( m_pData + sizeIndex ) T( rValue );
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
NTR_INLINE void		EA_TArray<T, fnMalloc, fnFree, fnRealloc>::Destroy( EA_SIZE sizeIndex )
{
	( m_pData + sizeIndex )->~T();
	sizeIndex; // ;;;
}


template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
NTR_INLINE T&		EA_TArray<T, fnMalloc, fnFree, fnRealloc>::operator[]( EA_SIZE sizeIndex )
{
	return m_pData[ sizeIndex ];
}

template<class T, EA_MALLOC fnMalloc, EA_FREE fnFree, EA_REALLOC fnRealloc>
NTR_INLINE const T&	EA_TArray<T, fnMalloc, fnFree, fnRealloc>::operator[]( EA_SIZE sizeIndex ) const
{
	return m_pData[ sizeIndex ];
}

