/**
 * @file	MA_CStringHashFilter.h
 * @brief	Effective string filter class using tree
 * @author	Standil (cpascal@cpascal.net)
 *
 * @version	2003/09/01 cpascal - First release
 *
 * Special thanks to chan@esoftnet.com
 */

#ifndef _MA_CSTRINGFILTER_H_
#define _MA_CSTRINGFILTER_H_

#include "MA_STLSet.h"

_MA_NAMESPACE_BEGIN

#define MA_STRINGFILTER_BIT_COUNT		4
#define MA_STRINGFILTER_RESTBIT_COUNT	(8 - MA_STRINGFILTER_BIT_COUNT)
#define MA_STRINGFILTER_MASK			(((MA_U8) ~0) >> MA_STRINGFILTER_RESTBIT_COUNT)
#define MA_STRINGFILTER_NODE_COUNT		(MA_STRINGFILTER_MASK + 1)

// Case-insensitive string filter

class MA_CStringHashFilter
{
public:
	MA_CStringHashFilter();
	~MA_CStringHashFilter();

	/// 검색할 word를 추가
	/**
	 * @param[in]	szWord		추가할 검색어
	 */
	MA_BOOL		AddWord( MA_LPCTSTR IN szWord );

	/// 주어진 문자열을 검색해서 등록한 단어를 '*'로 바꾼다.
	/**
	 * @param[in]	szString	검색할 문자열
	 * @return	szString	단어를 바꾼 문자열
	 */
	MA_LPTSTR	ReplaceString( MA_LPTSTR INOUT szString );

	/// 주어진 문자열을 검색해서 등록한 단어가 있는지 찾는다.
	/**
	 * @param[in]	szString	검색할 문자열
	 * @return	등록한 단어가 존재하면 TRUE, 그렇지 않으면 FALSE
	 */
	MA_BOOL		SearchString( MA_LPCTSTR IN szString );

#ifdef _NTR_TEST
	static MA_BOOL	Test( void );
#endif

protected:
	MA_SIZE		SearchWord( MA_LPCTSTR IN tszString, MA_BOOL bLongest );

	MA_DEFINE_STL_SET( StringHash, DWORD )

	class XWORDNODE
	{
	public:
		XWORDNODE()
			: m_bHasWords( MA_TRUE )
		{
			for( int i=0; i < MA_STRINGFILTER_BIT_COUNT; i++ )
				m_pChilds[i] = NULL;
		}

		XWORDNODE*	GetChild( int nNode, MA_BOOL bCreateIfEmpty = MA_FALSE )
		{
			if( bCreateIfEmpty && (m_pChilds[nNode] == NULL) )
				m_pChilds[nNode] = new XWORDNODE;
			return m_pChilds[nNode];
		}

		MA_BOOL		AddHash( DWORD dwHashValue )
		{
			if( m_setStringHash.find( dwHashValue ) != m_setStringHash.end() )		// 중복
				return MA_FALSE;
			m_setStringHash.insert( dwHashValue );
			return MA_TRUE;
		}

		MA_BOOL		FindHash( DWORD dwHashValue )
		{
			if( m_bHasWords == MA_FALSE )
				return MA_FALSE;
			if( m_setStringHash.find( dwHashValue ) == m_setStringHash.end() )
				return MA_FALSE;
			return MA_TRUE;
		}

	protected:
		XWORDNODE*		m_pChilds[MA_STRINGFILTER_BIT_COUNT];		// 자식 노드들
		SetStringHash	m_setStringHash;							// 해당 노드에 등록된 단어들
		MA_BOOL			m_bHasWords;								// 해당 노드에 등록된 단어가 있는지 여부
	};

	XWORDNODE*		m_pRootNode;
	MA_BOOL			m_bCaseSensitive;
};

_MA_NAMESPACE_END

#endif /* _MA_CSTRINGFILTER_H_ */
