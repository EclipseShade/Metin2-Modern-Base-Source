#ifndef _EA_TSLIST_H_
#define _EA_TSLIST_H_

#include "EA_TSLink.h"

_EA_NAMESPACE_BEGIN

template <class T, class TLinker>
class EA_TSList
{
public:
	EA_TSList();
	EA_TSList( int );
	~EA_TSList();

	void		InitializeTerminator();
	TDLink<T>*	Link( T* pPointerToLink );
	void		ChangeLinkOffset( int );
	void		Clear();
	void		Combine( EA_TSList *, u32, T* );
	T*			DeleteNode( T* );
	T*			Head();
	int			IsEmpty() const;
	int			IsLinked( const T* ) const;
	void		LinkNode( T*, u32, T* );
	T*			NewNode( u32 );
	T*			Next( T* );
	T*			Prev( T* );
	T*			RawNext( T* );
	T*			Tail();
	void		UnlinkAll();
	void		UnlinkNode( T* );
protected:
	void		SetLinkOffset( int );

	int		m_iLinkOffset;
	TDLink<T>	m_Terminator;

private:
	EA_TSList( EA_TSList & );
	EA_TSList& operator=( const EA_TSList & );
};

template <class T, class TLinker>
EA_TSList<T, TLinker>::EA_TSList() : m_iLinkOffset( 0 )
{
	InitializeTerminator();
}

template <class T, class TLinker>
EA_TSList<T, TLinker>::EA_TSList( int nLinkOffset ) : m_iLinkOffset( nLinkOffset )
{
	InitializeTerminator();
}

template <class T, class TLinker>
EA_TSList<T, TLinker>::~EA_TSList()
{
	UnlinkAll();
}

//template <class T, class TLinker>
//EA_TSList<T, TLinker>::EA_TSList( EA_TSList & )
//{
//}

//template <class T, class TLinker>
//EA_TSList& EA_TSList<T, TLinker>::operator=( const EA_TSList & )
//{
//}

template <class T, class TLinker>
void EA_TSList<T, TLinker>::InitializeTerminator()
{
	m_Terminator.m_pPrevLink	= &m_Terminator;
	m_Terminator.m_pNext		= NULL;
}

template <class T, class TLinker>
TDLink<T>* EA_TSList<T, TLinker>::Link( T* pPointerToLink )
{
	if( pPointerToLink == NULL )
		return &m_Terminator;
	return TLinker::Link( pPointerToLink, m_iLinkOffset );
}

template <class T, class TLinker>
void EA_TSList<T, TLinker>::ChangeLinkOffset( int iLinkOffset )
{
	if( iLinkOffset == m_iLinkOffset )
		return;
	TDLink<T> *pLink = &m_Terminator, *pOriginalLink, *pNextLink;
	while( (T* pNextData = pLink->m_pNext) ) {
		pOriginalLink			= TLinker::Link( pNextData, m_iLinkOffset );
		pNewLink			= TLinker::Link( pNextData, iLinkOffset );

		pNewLink->m_pPrevLink		= pLink;
		pNewLink->m_pNext		= pOriginalLink->m_pNext;

		pOriginalLink->m_pPrevLink	= NULL;
		pOriginalLink->m_pNext		= NULL;

		pLink				= pNewLink;
	}
	m_Terminator.m_pPrevLink	= &m_Terminator;
	m_Terminator.m_pNext		= NULL;
	m_iLinkOffset			= iLinkOffset;
}

template <class T, class TLinker>
void EA_TSList<T, TLinker>::Clear()
{
	T*		pData;
	TDLink<T>*	pLink;

	while( (pData = Head()) != NULL ) {
		pLink = Link( pData );
		delete pData;
		pLink->Unlink();
	}
}

template <class T, class TLinker>
void EA_TSList<T, TLinker>::Combine( EA_TSList *pList, u32 iLinkType, T* pExistingPointer )
{
	if( pList == NULL )
		return;
	if( pList == this )
		return;
	if( pList->m_iLinkOffset != m_iLinkOffset )
		return;
	// TODO
}

template <class T, class TLinker>
T* EA_TSList<T, TLinker>::DeleteNode( T* pPointer )
{
	T* pNext = Next( pPointer );
	delete pPointer;
	return pNext;
}

template <class T, class TLinker>
T* EA_TSList<T, TLinker>::Head()
{
	return m_Terminator.Next();
}

template <class T, class TLinker>
int EA_TSList<T, TLinker>::IsEmpty() const
{
	return (m_Terminator.Next() == NULL);
}

template <class T, class TLinker>
int EA_TSList<T, TLinker>::IsLinked( const T* ) const
{
}

#define INSERT_RIGHT		1
#define INSERT_LEFT		2

template <class T, class TLinker>
void EA_TSList<T, TLinker>::LinkNode( T* pNew, u32 iLinkType, T* pBase )
{
	TDLink<T>*	pBaseLink;
	TDLink<T>*	pNewLink		= Link( pNew );

	if( pBase )
		pBaseLink = Link( pBase );
	else
		pBaseLink = &m_Terminator;
	pNewLink->Unlink();
	switch( iLinkType ) {
	case 1 :
		pNewLink->m_pPrevLink					= pBaseLink;
		pNewLink->m_pNext					= pBaseLink->m_pNext;
		pBaseLink->NextLink( m_iLinkOffset )->m_pPrevLink	= pNewLink;
		pBaseLink->m_pNext					= pNew;
		break;
	case 2 :
		pNewLink->m_pPrevLink					= pBaseLink->m_pPrevLink;
		pNewLink->m_pNext					= pBaseLink->m_pPrevLink->m_pNext;
		pNewLink->m_pPrevLink->m_pNext				= pNew;
		pBaseLink->m_pPrevLink					= pNewLink;
		break;
	}
};

template <class T, class TLinker>
T* EA_TSList<T, TLinker>::NewNode( u32 u32Location )
{
	T* pNewData = new T;

	if( u32Location )
		LinkNode( pNewData, u32Location, 0 );
	return pNewData;
}

template <class T, class TLinker>
T* EA_TSList<T, TLinker>::Next( T* pPointer )
{
	return Link( pPointer )->Next();
}

template <class T, class TLinker>
T* EA_TSList<T, TLinker>::Prev( T* pPointer )
{
	return Link( pPointer )->Prev();
}

template <class T, class TLinker>
T* EA_TSList<T, TLinker>::RawNext( T* )
{
	return Link( pPointer )->RawNext();
}

template <class T, class TLinker>
T* EA_TSList<T, TLinker>::Tail()
{
	return m_Terminator.Prev();
}

template <class T, class TLinker>
void EA_TSList<T, TLinker>::UnlinkAll()
{
	T* pData;

	while( (pData = Head()) != NULL ) {
		UnlinkNode( pData );
	}
}

template <class T, class TLinker>
void EA_TSList<T, TLinker>::UnlinkNode( T* pNode )
{
	Link( pNode )->Unlink();
}

template <class T, class TLinker>
void EA_TSList<T, TLinker>::SetLinkOffset( int iLinkOffset )
{
	m_iLinkOffset = iLinkOffset;
	InitializeTerminator();
}

template <class T, int LinkOffset>
class EA_TSExplicitList : public EA_TSList<T, TSGetExplicitLink<T> >
{
public:
	EA_TSExplicitList();
	~EA_TSExplicitList();
private:
	EA_TSExplicitList( const EA_TSExplicitList & );
	EA_TSExplicitList& operator=( const EA_TSExplicitList & );
};

template <class T, int LinkOffset>
EA_TSExplicitList<T, LinkOffset>::EA_TSExplicitList()
{
	m_iLinkOffset			= LinkOffset;
}

template <class T, int LinkOffset>
EA_TSExplicitList<T, LinkOffset>::~EA_TSExplicitList()
{
}

#define EA_LIST_ARG(DataType,MemberName)				offsetof(DataType,MemberName)
#define EA_LIST_LINK(DataType,MemberName,NewTypeName)	typedef EA_TSExplicitList<DataType,EA_LIST_ARG(DataType,MemberName)> NewTypeName;

//#define EA_LIST_MEMBER(Type,MemberName)		TDLink<Type>						MemberName;
//#define EA_LIST(Type,MemberName)			EA_TSExplicitList<Type,offsetof(Type,MemberName)>

_EA_NAMESPACE_END

#endif /* !_EA_TSLIST_H_ */


/*

#include <STNBase/STN.h>
#include <STNBase/STNTList.h>
#include <stddef.h>

// LinkedNode mode structure
class TestLinkedNode : public TDLinkedNode<TestLinkedNode>
{
public:
	TestLinkedNode() : m_nValue(-1) {};
	
public:
	int m_nValue;
};

void RunTestLinkedNode( void )
{
	printf( "== Testing LinkedNode ==\n\n" );

	TDList<TestLinkedNode>	g_LinkedNodeList;
	class TestLinkedNode *pNewData, *pNewData1, *pNewData2, *pNewData25, *pNewData3;
	
	pNewData1  = g_LinkedNodeList.NewNode( PUSH_BACK );
	pNewData1->m_nValue = 100;
	
	pNewData2  = g_LinkedNodeList.NewNode( PUSH_FRONT );
	pNewData2->m_nValue = 200;
	
	pNewData3  = g_LinkedNodeList.NewNode( INSERT_NONE );
	pNewData3->m_nValue = 300;
	g_LinkedNodeList.PushBack( pNewData3 );

	pNewData25  = g_LinkedNodeList.NewNode( 0 );
	pNewData25->m_nValue = 250;
	g_LinkedNodeList.LinkNode( pNewData25, INSERT_BEFORE, pNewData3 );

	g_LinkedNodeList.NewNode( INSERT_AFTER )->m_nValue = -1000;
	g_LinkedNodeList.NewNode( INSERT_BEFORE )->m_nValue = 1000;

	pNewData = g_LinkedNodeList.Head();
	while( pNewData ) {
		printf( "%d\n", pNewData->m_nValue );
		pNewData = pNewData->Next();
	}
	printf( "\n" );
}

class TestExplicitStructure
{
public:
	TestExplicitStructure() : m_nValue(-1) {};
	
public:
	CHAR szName[256];
	int m_nValue;
	TDLink<TestExplicitStructure>	m_LocalNextLink;
	TDLink<TestExplicitStructure>	m_GlobalNextLink;
};

void RunTestExplicitList( void )
{
	printf( "== Testing ExplicitList ==\n\n" );

	TDExplicitList<TestExplicitStructure, offsetof(TestExplicitStructure, m_GlobalNextLink)>	g_GlobalExplicitList;
	TDExplicitList<TestExplicitStructure, offsetof(TestExplicitStructure, m_LocalNextLink)>		g_LocalExplicitList;
	// Use STN_LIST_LINK(TestExplicitStructure, m_MyNextLink, TestExplicitList) instead of above.
	class TestExplicitStructure *pNewGlobalData, *pNewData1, *pNewData2, *pNewData25, *pNewData26, *pNewData3, *pNewLocalData;
	
	pNewData1  = g_GlobalExplicitList.NewNode( INSERT_BEFORE );
	pNewData1->m_nValue = 100;
	
	pNewData2  = g_GlobalExplicitList.NewNode( INSERT_BEFORE );
	pNewData2->m_nValue = 200;
	
	pNewData3  = g_GlobalExplicitList.NewNode( INSERT_NONE );
	pNewData3->m_nValue = 300;
	g_GlobalExplicitList.LinkNode( pNewData3, INSERT_BEFORE, NULL );

	pNewData25  = g_GlobalExplicitList.NewNode( 0 );
	pNewData25->m_nValue = 250;
	g_GlobalExplicitList.LinkNode( pNewData25, INSERT_BEFORE, pNewData3 );
	
	g_LocalExplicitList.LinkNode( pNewData2, INSERT_AFTER, NULL );
	g_LocalExplicitList.LinkNode( pNewData25, INSERT_AFTER, pNewData2 );

	pNewData26  = g_GlobalExplicitList.NewNode( INSERT_NONE );
	pNewData26->m_nValue = 260;
	g_GlobalExplicitList.LinkNode( pNewData26, INSERT_AFTER, pNewData25 );
	g_LocalExplicitList.LinkNode( pNewData26, INSERT_AFTER, pNewData25 );

	g_GlobalExplicitList.NewNode( INSERT_AFTER )->m_nValue = -1000;
	g_GlobalExplicitList.NewNode( INSERT_BEFORE )->m_nValue = 1000;

	pNewGlobalData = g_GlobalExplicitList.Head();
	while( pNewGlobalData ) {
		printf( "%d\n", pNewGlobalData->m_nValue );

		if( pNewGlobalData == g_LocalExplicitList.Head() ) {
			pNewLocalData = g_LocalExplicitList.Head();
			while( pNewLocalData ) {
				printf( "  + %d\n", pNewLocalData->m_nValue );
//				pNewLocalData = g_LocalExplicitList.Next( pNewLocalData );
				pNewLocalData = pNewLocalData->m_LocalNextLink.Next();
			}
		}
		pNewGlobalData = g_GlobalExplicitList.Next( pNewGlobalData );
	}
	printf( "\n" );
}

int main( int argc, char *argv[] )
{
	RunTestLinkedNode();
	RunTestExplicitList();

}

*/
