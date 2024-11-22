/**
 * @file	MA_CStringBits.h
 * @brief	Mantle type class
 * @author	Standil (cpascal@cpascal.net)
 *
 * @version	2009/08/26 cpascal - First release
 */

#ifndef _MA_CSTRINGBITS_H_
#define _MA_CSTRINGBITS_H_

_MA_NAMESPACE_BEGIN

#define MA_INVALID_TYPE			0xFFFFFFFF

class MA_CStringBitsSerial
{
public:
	MA_CStringBitsSerial();
	MA_CStringBitsSerial( MA_LPCTSTR tszNames[], MA_XUINT nCount = MA_INVALID_TYPE, MA_BOOL bCopyMemory = MA_FALSE );
	~MA_CStringBitsSerial();

	MA_BOOL		Init( MA_LPCTSTR tszNames[], MA_XUINT nCount = MA_INVALID_TYPE, MA_BOOL bCopyMemory = MA_FALSE );
	void		Free( void );

	MA_XUINT	GetBit( MA_LPCTSTR tszText ) const;
	MA_XUINT	GetBits( MA_LPCTSTR tszText ) const;
	MA_LPTSTR	GetText( MA_XUINT uBits, MA_LPTSTR tszText, MA_SIZE sizeText ) const;

	MA_BOOL		Load( MA_LPCTSTR tszFileName );

protected:
	MA_XUINT	InternalGetBit( MA_LPCTSTR tszText, MA_SIZE sizeTextLength ) const;

protected:
	MA_BOOL		m_bMemoryOwner;
	MA_LPTSTR*	m_atszNames;
	MA_XUINT	m_nCount;
};

_MA_NAMESPACE_END

#endif /* !_MA_CSTRINGBITS_H_ */
