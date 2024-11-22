#ifndef _EA_TSLINK_H_
#define _EA_TSLINK_H_

_EA_NAMESPACE_BEGIN

template <class T>
struct EA_TSLink
{
	EA_TSLink<T>*	m_pPrevLink;
	T*				m_pNext;

public:
//	EA_TSLink*		NextLink( void )
	EA_TSLink*		NextLink( int iLinkOffset )

	BOOL			IsLinked();
	T*				Next();
	T*				Prev();
	T*				RawNext();
	void			Unlink();

private:
	EA_TSLink( EA_TSLink & );
	EA_TSLink& operator=( EA_TSLink& );
};

template <class T>
BOOL EA_TSLink<T>::IsLinked()
{
	return (m_pNext != NULL);
}

template <class T>
T* EA_TSLink<T>::Prev()
{
	return m_pPrevLink->Next();
}

template <class T>
EA_TSLink<T>* EA_TSLink<T>::NextLink( int iLinkOffset )
{
	if( m_pNext == NULL )
		return NULL;
	if( iLinkOffset < 0 ) {
		return (EA_TSLink*) ((u8 *) this - (u8 *) m_pPrevLink->m_pNext + (u8 *) m_pNext);
	}
	return (EA_TSLink*) ((u8 *) m_pNext + iLinkOffset);
}

template <class T>
T* EA_TSLink<T>::Next()
{
	return m_pNext;
}

template <class T>
T* EA_TSLink<T>::RawNext()
{
	return m_pNext;
}

template <class T>
void EA_TSLink<T>::Unlink()
{
	if( m_pPrevLink ) {
		if( m_pNext )
			NextLink( -1 )->m_pPrevLink = m_pPrevLink;
		m_pPrevLink->m_pNext	= m_pNext;
		m_pPrevLink		= NULL;
		m_pNext			= NULL;
	}
}


template <class T>
class EA_TSLinkedNode
{
	EA_TSLink<T>	m_Link;
public:
	EA_TSLinkedNode( EA_TSLinkedNode & );
	EA_TSLinkedNode();
	~EA_TSLinkedNode();
	EA_TSLinkedNode& operator=( const EA_TSLinkedNode& );
	T*	Next();
	T*	Prev();
	T*	RawNext();
	void	Unlink();
};

template <class T>
EA_TSLinkedNode<T>::EA_TSLinkedNode()
{
}

template <class T>
EA_TSLinkedNode<T>::~EA_TSLinkedNode()
{
	m_Link.Unlink();
}

template <class T>
EA_TSLinkedNode<T>& EA_TSLinkedNode<T>::operator=( const EA_TSLinkedNode<T>& )
{
}

template <class T>
T* EA_TSLinkedNode<T>::Next()
{
	return m_Link.Next();
}

template <class T>
T* EA_TSLinkedNode<T>::Prev()
{
	return m_Link.Prev();
}

template <class T>
T* EA_TSLinkedNode<T>::RawNext()
{
	return m_Link.RawNext();
}

template <class T>
void EA_TSLinkedNode<T>::Unlink()
{
	m_Link.Unlink();
}

template <class T>
class EA_TSGetExplicitLink
{
public:
	static EA_TSLink<T>* GetLink( const T* pNode, int iLinkOffset ) {
		return (EA_TSLink<T> *) ((u8 *) pNode + iLinkOffset);
	}
};

template <class T>
class EA_TSGetLink
{
public:
	static EA_TSLink<T>* GetLink( const EA_TSLinkedNode<T>* pNode, int iLinkOffset ) {
		return pNode->m_pLink;
	}
};

_EA_NAMESPACE_END

#endif /* !_EA_TSLINK_H_ */
