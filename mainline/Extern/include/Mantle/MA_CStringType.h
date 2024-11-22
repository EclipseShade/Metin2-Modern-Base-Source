/**
 * @file	MA_CStringType.h
 * @brief	Mantle type class
 * @author	Standil (cpascal@cpascal.net)
 *
 * @version	2009/08/26 cpascal - First release
 */

#ifndef _MA_CSTRINGTYPE_H_
#define _MA_CSTRINGTYPE_H_

_MA_NAMESPACE_BEGIN

#define MA_INVALID_TYPE			0xFFFFFFFF

class MA_CStringTypeSerial
{
public:
	MA_CStringTypeSerial();
	MA_CStringTypeSerial( MA_LPCTSTR tszNames[], MA_XUINT nCount = MA_INVALID_TYPE, MA_BOOL bCopyMemory = MA_FALSE );
	~MA_CStringTypeSerial();

	MA_BOOL		Init( MA_LPCTSTR tszNames[], MA_XUINT nCount = MA_INVALID_TYPE, MA_BOOL bCopyMemory = MA_FALSE );
	void		Free( void );

	MA_XUINT	GetType( MA_LPCTSTR tszName ) const;
	MA_LPTSTR	GetText( MA_XUINT uType ) const			{ if( uType >= m_nCount ) return MA_NULL; return m_atszNames[uType]; }

	MA_BOOL		Load( MA_LPCTSTR tszFileName );

protected:
	MA_BOOL		m_bMemoryOwner;
	MA_LPTSTR*	m_atszNames;
	MA_XUINT	m_nCount;
};

_MA_NAMESPACE_END

#endif /* !_MA_CSTRINGTYPE_H_ */
