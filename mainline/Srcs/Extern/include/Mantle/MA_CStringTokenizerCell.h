/**
 * @file	MA_CStringTokenizerCell.h
 * @brief	MA_CStringTokenizerCell class
 * @author	Standil (cpascal@cpascal.net)
 *
 * @version	2004/10/04 cpascal - First release
 */

#ifndef _MA_CQUICKTOKENIZERCELL_H_
#define _MA_CQUICKTOKENIZERCELL_H_

#include <vector>

_MA_NAMESPACE_BEGIN

class MA_CStringTokenizerCell
{
public:
	MA_CStringTokenizerCell();
	MA_CStringTokenizerCell( MA_LPCTSTR tszString, MA_TCHAR tchPurpose, MA_TCHAR tchQuote );
	~MA_CStringTokenizerCell();

	BOOL		Tokenize( MA_LPCTSTR tszString, MA_TCHAR tchPurpose, MA_TCHAR tchQuote );

	void		Reset( void );

	MA_SIZE		GetSize( void ) const					{ return m_vecToken.size(); }
	MA_LPCTSTR	operator[]( MA_SIZE sizeIndex ) const 	{ return (MA_LPCTSTR) ( sizeIndex >= m_vecToken.size() ) ? NULL : m_vecToken[ sizeIndex ]; }

#ifdef _NTR_TEST
	static MA_BOOL	Test( void );
#endif

protected:
	std::vector<MA_TCHAR*>	m_vecToken;
	MA_TCHAR*				m_tszChunk;
};

_MA_NAMESPACE_END

#endif /* _MA_CQUICKTOKENIZER_H_ */
