#ifndef _EL_CLIENTDBGENERICI_H_
#define _EL_CLIENTDBGENERICI_H_

#include "TClientDB.h"
#include "FlatMemory.h"
#include "FlatMemoryHeader.h"

class EL_CClientDBGeneric : public EL_CFlatMemory
{
public:
	EL_CClientDBGeneric();
	EL_CClientDBGeneric( const EL_CFlatMemory& );
	virtual ~EL_CClientDBGeneric();

	EL_BOOL			Load( MA_LPCTSTR tszFileName );

	EL_BOOL			Save( MA_LPCTSTR tszFileName );

	EL_BOOL			PrepareCDBHeader( void );
	EL_BOOL			BuildCDB( void );

protected:
	LPVOID					m_pvRecords;
	LPVOID					m_pvExtra;
	EL_CDB_HEADER			m_stFileHeader;
	EL_CFlatMemoryHeader	m_cHeader;
};

#endif /* !_EL_CLIENTDBGENERICI_H_ */
