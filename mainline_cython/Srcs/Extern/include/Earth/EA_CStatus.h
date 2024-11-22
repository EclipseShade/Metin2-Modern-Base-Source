#ifndef _EA_CSTATUS_H_
#define _EA_CSTATUS_H_

#include <Mantle/MA_STLList.h>
#include <Mantle/MA_STLVector.h>

_EA_NAMESPACE_BEGIN

enum EA_STATUS_TYPE {
	EA_STATUS_INFO	= 0,
	EA_STATUS_WARNING,
	EA_STATUS_ERROR,
	EA_STATUS_FATAL,
	EA_STATUS_QUANTITY
};

class EA_CStatus
{
public:

	EA_CStatus();
	~EA_CStatus();

	void			Clear( void );
	EA_BOOL			IsEmpty( void );
	EA_BOOL			Add( EA_STATUS_TYPE eSeverity, LPCTSTR tszMessage );
	EA_BOOL			Addf( EA_STATUS_TYPE eSeverity, LPCTSTR tszFormat, ... );
	EA_BOOL			AddNR( EA_STATUS_TYPE eSeverity, LPCTSTR tszMessage );
	EA_BOOL			AddNRf( EA_STATUS_TYPE eSeverity, LPCTSTR tszFormat, ... );
	EA_BOOL			Prepend( EA_STATUS_TYPE eSeverity, LPCTSTR tszMessage );
	EA_BOOL			Prependf(  EA_STATUS_TYPE eSeverity, LPCTSTR tszFormat, ... );
	EA_BOOL			PrependNR( EA_STATUS_TYPE eSeverity, LPCTSTR tszMessage );
	EA_BOOL			PrependNRf( EA_STATUS_TYPE eSeverity, LPCTSTR tszFormat, ... );
	EA_BOOL			GetString( MA_LPTSTR tszBuffer, EA_SIZE sizeBuffer, EA_STATUS_TYPE eMinSeverity = EA_STATUS_INFO );
	EA_SIZE			GetStringLength( EA_STATUS_TYPE eMinSeverity = EA_STATUS_INFO );
	MA_LPTSTR		GetStringAlloc( EA_STATUS_TYPE eMinSeverity = EA_STATUS_INFO );
	MA_LPTSTR		GetString( EA_STATUS_TYPE eMinSeverity = EA_STATUS_INFO );

	EA_STATUS_TYPE	GetHighestSeverity();
	EA_CStatus&	operator=( const EA_CStatus& cStatus );

protected:
	struct SSTATUSENTRY {
		MA_LPTSTR			tszText;
		EA_STATUS_TYPE		eSeverity;
		//TSExplicitList<STATUSENTRY,8> statusList;
	};

	MA_DEFINE_STL_LIST( Status, struct SSTATUSENTRY );
	ListStatus			m_listStatus;
	MA_LPTSTR			m_tszBuffer;
};

_EA_NAMESPACE_END

#endif /* !_EA_CSTATUS_H_ */
