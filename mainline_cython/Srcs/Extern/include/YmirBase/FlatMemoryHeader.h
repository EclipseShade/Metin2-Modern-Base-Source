#pragma once

#include "VariantType.h"

#include "STLVector.h"

class EL_CFlatMemoryHeader
{
public:
	EL_CFlatMemoryHeader();
	~EL_CFlatMemoryHeader();

	void	Reset( void );

	void	SetBaseDirectory( MA_LPCTSTR tszDirectory );
	EL_BOOL AddColumn( MA_LPCTSTR tszName, EL_EVARIANTTYPE eType, EL_CVariantType* pcConvertor = NULL );
	EL_BOOL AddColumn( MA_LPCTSTR tszTypeInfo );
	EL_BOOL StringToType( int iColumn, MA_LPCTSTR tszText, LPVOID pvType, EL_SIZE sizeType );
	EL_EVARIANTTYPE GetColumnType( int iColumn ) const	{ return m_vecColumn[iColumn]->m_eType; }

protected:
	struct SCOLUMNINFO {
		EL_STLString		m_tstrName;
		int					m_iColumn;
		EL_EVARIANTTYPE		m_eType;
		EL_CVariantType*	m_pcConvertor;
	};

	EL_DEFINE_STL_VECTOR( Column, SCOLUMNINFO* );

	EL_CVariantType*		CreateTypeInfo( EL_EVARIANTTYPE eType, MA_LPCTSTR tszListType, MA_LPCTSTR tszFileName );

protected:
	VecColumn	m_vecColumn;
	MA_TCHAR	m_tszBaseDirectory[ MA_MAX_PATH ];
};
