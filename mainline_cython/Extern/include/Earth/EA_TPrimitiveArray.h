/**
 * @file	EA_TPrimitiveArray.h
 * @brief	Primitive type¿ª ¿ß«— Array template class
 * @author	Standil (cpascal@cpascal.net)
 *
 * @version	2006/01/02 cpascal - First release
 */

#ifndef	_EA_TPRIMITIVEARRAY_H_
#define	_EA_TPRIMITIVEARRAY_H_

_EA_NAMESPACE_BEGIN

template <class T>
class EA_TPrimitiveArray
{
	enum {
		MIN_ARRAY_COUNT	= 16
	};

public:
	EA_TPrimitiveArray();
	explicit EA_TPrimitiveArray( u32 u32InitialSize );
	explicit EA_TPrimitiveArray( T* pData, u32 u32DataCount );
	~EA_TPrimitiveArray();

	T*		GetPointer( void )				{ return m_pData; }
	const T*	GetPointerConst( void )				{ return m_pData; }

	void		GrowToFit( u32 u32Index );
	void		SetSize( u32 u32MaxSize );
	void		SetAt( u32 u32Index, const T& Element )		{ m_pData[u32Index] = Element; if( u32Index >= m_u32Count ) m_u32Count = u32Index + 1; }
	void		SetAtGrow( u32 u32Index, const T& Element )	{ if( u32Index >= m_u32Allocated ) GrowToFit( u32Index ); SetAt( u32Index, Element ); }
	void		AddElement( T& Element )			{ m_pData[m_u32Count++] = Element; }
	void		AddElements( T* pData, u32 u32Count )		{ memcpy( m_pData + m_u32Count, pData, u32Count * sizeof( T ) ); m_u32Count += u32Count; }
	void		AddElementAtGrow( T& Element )			{ if( m_u32Count >= m_u32Allocated ) GrowToFit( m_u32Count + 1 ); m_pData[m_u32Count++] = Element; }
	void		AddElementsAtGrow( T* pData, u32 u32Count )	{ if( (m_u32Count + u32Count) >= m_u32Allocated ) memcpy( m_pData + m_u32Count, pData, u32Count * sizeof( T ) ); m_u32Count += u32Count; }
	T*		NewElement( void )				{ return &(m_pData[m_u32Count++]); }

	u32		GetSize( void )					{ return m_u32Count; }
	const T&	GetAt( u32 u32Index) const			{ return m_pData[u32Index]; }
	const T&	GetFirst( void )				{ return m_pData[0]; }
	const T&	GetLast( void )					{ return m_pData[m_u32Count - 1]; }

	u32		GetBytes( void )				{ return m_u32Count * sizeof( T ); }
	u32		GetCount( void )				{ return m_u32Count; }
	u32		GetLength( void )				{ return m_u32Count; }
	u32		GetUnusedCount( void )				{ return m_u32Allocated - m_u32Count; }

	BOOL		IsEmpty( void )					{ return (m_u32Count == 0); }

	void		Zero( void )					{ memset( m_pData, 0, sizeof( T ) * m_u32Size ); }
	void		Detach( T** ppData, u32* pu32Count, u32* pu32Allocated );

	// Operators
	T&		operator[]( int nPosition )			{ return m_pData[nPosition]; }
	const T&	operator[]( int nPosition ) const		{ return m_pData[nPosition]; }

protected:
	u32	m_u32Allocated;
	u32	m_u32Count;
	T*	m_pData;
};

template <class T>
EA_TPrimitiveArray<T>::EA_TPrimitiveArray() : m_u32Allocated(0), m_u32Count(0), m_pData(NULL)
{
}

template <class T>
EA_TPrimitiveArray<T>::EA_TPrimitiveArray( u32 u32InitialSize ) :  m_u32Allocated(u32InitialSize), m_u32Count(u32InitialSize), m_pData( new T[u32InitialSize] )
{
}

template <class T>
EA_TPrimitiveArray<T>::EA_TPrimitiveArray( T* pData, u32 u32DataCount ) : m_u32Allocated(u32DataCount), m_u32Count(u32DataCount), m_pData( new T[u32DataCount] )
{
	memcpy( m_pData, pData, u32DataCount * sizeof( u32DataCount ) );
}

template <class T>
EA_TPrimitiveArray<T>::~EA_TPrimitiveArray()
{
	EA_SAFE_FREE( m_pData );
}

template <class T>
void EA_TPrimitiveArray<T>::SetSize( u32 u32MaxSize )
{
	if( u32MaxSize < m_u32Count )
		m_u32Count = u32MaxSize;
	m_u32Allocated = u32MaxSize;
	T* pOldData = m_pData;
	if( u32MaxSize > 0 ) {
		m_pData = (T*) malloc( sizeof( T ) * m_u32Allocated );
		memcpy( m_pData, pOldData, sizeof( T ) * m_u32Count );
	}
	EA_SAFE_FREE( pOldData );
}

template <class T>
void EA_TPrimitiveArray<T>::GrowToFit( u32 u32Index )
{
	u32 u32NewSize = m_u32Allocated;

	if( u32NewSize == 0 )
		u32NewSize = MIN_ARRAY_COUNT;
	while( u32NewSize <= u32Index )
		u32NewSize <<= 1;
	SetSize( u32NewSize );
}

template <class T>
void EA_TPrimitiveArray<T>::Detach( T** ppData, u32* pu32Count, u32* pu32Allocated )
{
	if( ppData )
		*ppData = m_pData;
	if( pu32Size )
		*pu32Size = m_u32Cont;
	if( pu32Allocated )
		*pu32Allocated = m_u32Allocated;
	EA_SAFE_FREE( m_pData );
};

_EA_NAMESPACE_END

#endif // !_EA_TPRIMITIVEARRAY_H_
