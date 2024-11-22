#ifndef	_EA_CREGISTRY_H_
#define	_EA_CREGISTRY_H_

#include "EA_IConfiguration.h"

_EA_NAMESPACE_BEGIN

class EA_CRegistry : public EA_IConfiguration
{
public:
	EA_CRegistry();
	EA_CRegistry( HKEY hKeyRoot, EA_EOpenFlags eOpenFlags = modeRead );
	~EA_CRegistry();

	EA_BOOL		Open( MA_LPCTSTR tszFilename, EA_EOpenFlags eOpenFlags = modeRead );
	EA_BOOL		Open( HKEY hKeyRoot, EA_EOpenFlags eOpenFlags = modeRead );
	void		Close( void );

	void		SetRootHKEY( HKEY hKey );

	// Groups
	EA_BOOL		OpenGroup( MA_LPCTSTR IN tszGroup = EA_NULL, EA_BOOL bCreateIfEmpty = EA_FALSE );
	EA_BOOL		OpenSubGroup( MA_LPCTSTR IN tszSubGroup = EA_NULL, EA_BOOL bCreateIfEmpty = EA_FALSE );
	EA_RESULT	EnumGroup( EA_DWORD IN dwIndex, MA_LPTSTR OUT tszParameter, size_t IN sizeParameter );
	EA_BOOL		DeleteSubGroup( MA_LPCTSTR IN tszSubGroup = EA_NULL );
	void		CloseGroup( void );

	// Parameter & Values
	EA_RESULT	EnumParameter( EA_DWORD IN dwIndex, MA_LPTSTR OUT tszParameter, size_t IN sizeParameter );

	EA_SIZE	GetValueSize( MA_LPCTSTR IN tszParameter, MA_LPCTSTR IN tszSubGroup = EA_NULL );
	EA_BOOL		GetValueAsDWORD( EA_DWORD* OUT pdwValue, MA_LPCTSTR IN tszParameter, MA_LPCTSTR IN tszSubGroup = EA_NULL );
	EA_BOOL		GetValueAsQWORD( EA_QWORD* OUT pqwValue, MA_LPCTSTR IN tszParameter, MA_LPCTSTR IN tszSubGroup = EA_NULL );
	EA_BOOL		GetValueAsString( MA_LPTSTR OUT tszValue, size_t IN sizeValue, MA_LPCTSTR IN tszParameter, MA_LPCTSTR IN tszSubGroup = EA_NULL );
	EA_BOOL		GetValueAsBinary( EA_LPBYTE OUT pbyValue, size_t IN sizeValue, MA_LPCTSTR IN tszParameter, MA_LPCTSTR IN tszSubGroup = EA_NULL );

	EA_BOOL		SetValueAsDWORD( EA_DWORD IN dwValue, MA_LPCTSTR IN tszParameter, MA_LPCTSTR IN tszSubGroup = EA_NULL );
	EA_BOOL		SetValueAsQWORD( EA_QWORD IN qwValue, MA_LPCTSTR IN tszParameter, MA_LPCTSTR IN tszSubGroup = EA_NULL );
	EA_BOOL		SetValueAsString( MA_LPCTSTR OUT tszValue, size_t IN sizeValue, MA_LPCTSTR IN tszParameter, MA_LPCTSTR IN tszSubGroup = EA_NULL );
	EA_BOOL		SetValueAsBinary( EA_LPBYTE OUT pbyValue, size_t IN sizeValue, MA_LPCTSTR IN tszParameter, MA_LPCTSTR IN tszSubGroup = EA_NULL );

protected:
	EA_BOOL		CheckRootHKEY( MA_LPCTSTR IN tszString, HKEY* OUT phKey, EA_SIZE* OUT psizeGroupName = EA_NULL );
	REGSAM		GetREGSAM( void );

protected:
	HKEY			m_hKeyRoot;
	HKEY			m_hKeyCurrent;
	EA_EOpenFlags	m_eOpenMode;
};

_EA_NAMESPACE_END

#endif /* !_EA_CREGISTRY_H_ */
