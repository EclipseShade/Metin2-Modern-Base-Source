//#ifndef _EA_CWORDSEARCHBITBINARY_H_
//#define _EA_CWORDSEARCHBITBINARY_H_
//
//#define CS_BIT_COUNT		3
//#define CS_RESTBIT_COUNT	(8 - CS_BIT_COUNT)
//#define CS_MASK				(((u8) ~0) >> CS_RESTBIT_COUNT)
//#define CS_NODE_COUNT		(CS_MASK + 1)
//
//class EA_CWordSearchBitBinary
//{
//
//};
//
//#endif /* !_EA_CWORDSEARCHBITBINARY_H_ */
//
//#include "STLMap.h"
//
//
///**
// * @class	WordSearchBitBinary
// * @brief	Tree를 이용한 word 검색 class
// * @author	Standil (cpascal@cpascal.net)
// */
//class WordSearchBitBinary
//{
//public:
//	/// Tree의 node를 해당하는 data를 저장한 map
//	DEFINE_STL_MAP( BitBinary, DWORD, LPVOID );
//
//
//	/**
//	* @class	WordNode
//	* @brief	WordSearchBitBinary tree의 node
//	* @author	Standil (cpascal@cpascal@e-zen.net)
//	*/
//	class WordNode
//	{
//		friend class WordSearchBitBinary;
//	public:
//		/// 단어의 끝을 표시
//		BOOL			bTermination;
//
//		/// Parent node
//		WordNode		* pParent;
//
//		/// Parent node에서의 index
//		int			m_iIndex;
//
//		/// Child node들
//		WordNode		* pNext[CS_NODE_COUNT];
//
//		/// Node에 저장한 data
//		BitBinaryMap		IndexMap;
//
//
//	public:
//		/// Constructor
//		WordNode( WordNode IN * pParent, int IN iIndex )
//			: bTermination	( FALSE )
//			, pParent	( pParent )
//			, m_iIndex	( iIndex )
//		{
//			memset( pNext, 0, sizeof(pNext) );
//		}
//
//		// Destructor
//		~WordNode() {}
//
//
//		/// Parent node를 return 한다.
//		WordNode * GetParent() const	{ return pParent; }
//
//		/// 현재 node가 parent에서 가지는 index를 return 한다.
//		int GetIndex() const		{ return m_iIndex; }
//	};
//
//	typedef WordNode *	PWordNode;
//
//
//	/**
//	* @class	Iterator
//	* @brief	WordSearchBitBinary의 tree를 traverse 하기 위한 itearator
//	* @autho	MadKnight (mknight@e-zen.net)
//	*/
//	class Iterator
//	{
//		friend class WordSearchBitBinary;
//	private:
//		/// WordSearchBitBinary의 instance pointer
//		WordSearchBitBinary	* m_pWSBB;
//
//		/// Node
//		PWordNode		m_pNode;
//
//		/// Node에서의 interator
//		BitBinaryMapItr		m_Itr;
//
//
//	public:
//		/// Constructor
//		Iterator( WordSearchBitBinary IN * pWSBB = NULL, PWordNode IN pNode = NULL )
//			: m_pWSBB	( pWSBB )
//			, m_pNode	( pNode )
//		{
//		}
//
//		/// Destructor
//		~Iterator() {}
//
//		/// Data를 return 한다.
//		LPVOID GetData()	{ return m_Itr->second; }
//
//		/// Overloadded prefix ++ operator
//		Iterator & operator++()
//		{
//			Iterator	Next( m_pWSBB );
//
//
//			++ m_Itr;
//			if( m_Itr == m_pNode->IndexMap.end() ) {
//				Next = m_pWSBB->GetNext( *this );
//				m_pNode = Next.m_pNode;
//				m_Itr	= Next.m_Itr;
//			}
//
//			return *this;
//		}
//
//		/// Overridded posfix ++ operator
//		Iterator operator++( int )
//		{
//			Iterator	Temp = *this;
//
//			++ *this;
//
//			return Temp;
//		}
//
//		/// Overloadded == operator
//		BOOL operator==( const Iterator & Right )
//		{
//			return (m_pWSBB == Right.m_pWSBB)
//				&& (m_pNode == Right.m_pNode)
//				&& (m_Itr == Right.m_Itr);
//		}
//
//		/// Overloadded == operator
//		BOOL operator!=( const Iterator & Right )
//		{
//			return !(*this == Right);
//		}
//	};
//
//	/// Constructor
//	WordSearchBitBinary( BOOL bCaseSensitive = TRUE );
//
//	/// Destructor
//	~WordSearchBitBinary( void );
//
//	/// 검색할 word를 추가
//	/**
//	 * @param[in]	szWord		추가할 검색어
//	 * @param[in]	lpData		추가한 word와 연결된 data
//	 */
//	BOOL		AddWord( LPCTSTR IN szWord, LPVOID IN lpData = NULL );
//
//	/// 주어진 문자열을 검색해서 등록한 단어를 '*'로 바꾼다.
//	/**
//	 * @param[in]	szString	검색할 문자열
//	 * @return	szString	단어를 바꾼 문자열
//	 */
//	TCHAR *		ReplaceString( LPTSTR INOUT szString );
//
//	/// 주어진 문자열을 검색해서 등록한 단어가 있는지 찾는다.
//	/**
//	 * @param[in]	szString	검색할 문자열
//	 * @return	등록한 단어가 존재하면 TRUE, 그렇지 않으면 FALSE
//	 */
//	BOOL		SearchString( LPCTSTR IN szString );
//
//	/// 등록한 word를 검색한다.
//	/**
//	 * @param[in]	szString	검색할 word
//	 * @param[out]	lpData		검색할 word와 연결된 data
//	 */
//	BOOL		SearchWord( LPCTSTR IN szString, LPVOID OUT * lpData = NULL ) const;
//
//	/// 등록한 word를 검색한다.
//	/**
//	 * @param[in]	szString	검색할 word
//	 * @param[out]	lpData		검색할 word와 연결된 data
//	 */
//	size_t		MatchWord( LPCTSTR IN szString, BOOL bMustMatchTermination, LPVOID OUT * lpData = NULL ) const;
//	size_t		MatchWordCI( LPCTSTR IN szString, BOOL bMustMatchTermination, LPVOID OUT * lpData = NULL ) const;
//
//	/// 검색할 단어들을 모두 지우고 instance를 초기화 시킨다.
//	void		Clear();
//
//	/// 등록한 word의 수를 return 한다.
//	size_t		GetCount() const	{ return m_sizeWords; }
//
//	/// Tree의 맨 왼쪽 아래 node를 return 한다.
//	Iterator	GetFirst();
//
//	/// Tree의 맨 오른쪽 아래 node를 return 한다.
//	Iterator	GetLast();
//
//	/// Tree를 traverse 한다. (depth-first, preorder)
//	Iterator	GetNext( const Iterator IN & Itr );
//
//
//private:
//	/// 등록한 word의 수
//	size_t		m_sizeWords;
//
//	/// 검색 tree의 root node
//	PWordNode	m_pRoot;
//
//	/// 주어진 node와 child node들을 모두 삭제 한다.
//	void		ReleaseWordNode( PWordNode IN pWordNode );
//
//	BOOL		m_bCaseSensitive;
//};
//
//class WordSearchBitBinaryIterator : public WordSearchBitBinary::Iterator
//{
//};
//
//#endif
