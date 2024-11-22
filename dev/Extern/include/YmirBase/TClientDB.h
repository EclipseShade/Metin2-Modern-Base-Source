#ifndef _TCLIENTDB_H_
#define _TCLIENTDB_H_

#include "Environment.h"
#include "TStringBuffer.h"
#include "TStatus.h"
#include "VFSPack.h"

#pragma pack( push, 1 )
#define MAX_COLUMN_COUNT		64
#define MAX_POINTER_COUNT		64

struct EL_CDB_HEADER {
	DWORD	dwCDBSignature;
	DWORD	dwCDBVersion;
	DWORD	dwStructureSignature;
	DWORD	dwRowSize;
	DWORD	dwNumberOfRows;
	WORD	wNumberOfColumns;
	WORD	awElementOffsets[MAX_COLUMN_COUNT];
	BYTE	abyElementTypes[MAX_COLUMN_COUNT];
	WORD	wPointerCounts;
	WORD	awPointerOffsets[MAX_POINTER_COUNT];
	DWORD	dwExtraSize;
};
#pragma pack( pop )

#define EL_SIGNATURE_CDB					0x43424457		// WDBC
#define EL_VERSION_CDB						100

#define EL_DEFINE_CLIENTDB_STRUCTURE()		\
	static LPCTSTR	GetFileName();			\
	static EL_UINT	GetNumColumns();		\
	static EL_UINT	GetRowSize();			\
	static EL_UINT	GetIDMode();		\
	EL_UINT			GetID() const;			\
	EL_VOID			SetID( EL_UINT );
//	EL_SIZE			Read( FILE*, LPCBYTE );	\

#define EL_IMPLEMENT_CLIENTDB_STRUCTURE_INTERNAL( xType, xDefaultFileName, xNumColumns, xRowSize )			\
	LPCTSTR	xType::GetFileName()		{ return xDefaultFileName; }										\
	EL_UINT	xType::GetNumColumns()		{ return xNumColumns; }												\
	EL_UINT	xType::GetRowSize()			{ return xRowSize; }


#define EL_IMPLEMENT_CLIENTDB_STRUCTURE( xType, xDefaultFileName, xNumColumns, xRowSize )					\
	EL_IMPLEMENT_CLIENTDB_STRUCTURE_INTERNAL( xType, xDefaultFileName, xNumColumns, xRowSize )				\
	EL_UINT	xType::GetIDMode()			{ return 0; }														\
	EL_UINT	xType::GetID() const		{ return (EL_UINT)-1; }														\
	EL_VOID	xType::SetID( EL_UINT /*iID*/ )	{}

#define EL_IMPLEMENT_CLIENTDB_STRUCTURE_ID( xType, xDefaultFileName, xNumColumns, xRowSize, xID )			\
	EL_IMPLEMENT_CLIENTDB_STRUCTURE_INTERNAL( xType, xDefaultFileName, xNumColumns, xRowSize )				\
	EL_UINT	xType::GetIDMode()			{ return 1; }														\
	EL_UINT	xType::GetID() const		{ return xID; }														\
	EL_VOID	xType::SetID( EL_UINT iID )	{ xID = iID; }

#define EL_IMPLEMENT_CLIENTDB_STRUCTURE_BSEARCHID( xType, xDefaultFileName, xNumColumns, xRowSize, xID )	\
	EL_IMPLEMENT_CLIENTDB_STRUCTURE_INTERNAL( xType, xDefaultFileName, xNumColumns, xRowSize )				\
	EL_UINT	xType::GetIDMode()			{ return 2; }														\
	EL_UINT	xType::GetID() const		{ return xID; }														\
	EL_VOID	xType::SetID( EL_UINT iID )	{ xID = iID; }

template <typename T>
class EL_TClientDB
{
public:
	EL_TClientDB();
	~EL_TClientDB();

	EL_BOOL	Load( LPCTSTR tszFileName = NULL, EL_Status* statusPtr = NULL );
	EL_BOOL	LoadEx( LPCTSTR tszFileName, EL_Status* statusPtr = NULL );

	EL_VOID	Reload( );
	EL_VOID	Unload( );

	T*		GetRecord( int nIndex ) const;
	EL_UINT	GetMaxID() const;
	int		GetNumRecords() const;
	T*		GetRecordByID( EL_UINT nID ) const;

protected:
	EL_VOID	Init( );
	EL_VOID	Free( );
	EL_VOID	ModifyOffset( T* pstRecord, const EL_UINT8* pbyMemory, EL_CDB_HEADER* pstHeader );

	static int SortClientDB_ID( const EL_VOID *arg1, const EL_VOID *arg2 );
protected:
	T**		m_ppRecordsByID;
	T*		m_pRecords;
	EL_INT	m_nRecords;	
	EL_UINT	m_nMaxID;
	EL_BOOL	m_bLoaded;
	EL_TCHAR m_tszFileName[ EL_MAX_PATH ];
};

template <typename T>
EL_TClientDB<T>::EL_TClientDB()
: m_pRecords( NULL ), m_nRecords(0), m_ppRecordsByID( NULL ), m_nMaxID(0), m_bLoaded(FALSE)
{
}

template <typename T>
EL_TClientDB<T>::~EL_TClientDB()
{
	Free();
}

template <typename T>
EL_VOID EL_TClientDB<T>::Reload( )
{
	Load( m_tszFileName );
}

template <typename T>
EL_VOID EL_TClientDB<T>::Unload( )
{
	Free();
}

template <typename T>
T* EL_TClientDB<T>::GetRecord( int iIndex ) const
{
	return &(m_pRecords[ iIndex ]);
}

template <typename T>
EL_UINT EL_TClientDB<T>::GetMaxID() const
{
	return m_nMaxID;
}

template <typename T>
int EL_TClientDB<T>::GetNumRecords() const
{
	return m_nRecords;
}

template <typename T>
T* EL_TClientDB<T>::GetRecordByID( EL_UINT nID ) const
{
	if( nID > m_nMaxID )
		return NULL;
	if( T::GetIDMode() == 0 )
		return NULL;
	if( T::GetIDMode() == 1 )
		return m_ppRecordsByID[ nID ];

	int iTop	= m_nRecords - 1;
	int iBottom = 0;
	int iMiddle	= (iBottom + iTop) / 2;

	for( ; iBottom <= iTop; iMiddle = (iBottom + iTop) / 2 ) {
		if( m_ppRecordsByID[iMiddle]->GetID() == nID )
			return m_ppRecordsByID[ iMiddle ];
		if( m_ppRecordsByID[iMiddle]->GetID() < nID )
			iBottom	= iMiddle + 1;
		else
			iTop	= iMiddle - 1;
	}
	return NULL;
}

template <typename T>
EL_VOID EL_TClientDB<T>::Init( )
{
	m_pRecords		= NULL;
	m_nRecords		= 0;
	m_ppRecordsByID	= NULL;
	m_nMaxID		= 0;
	m_bLoaded		= FALSE;
}

template <typename T>
EL_VOID EL_TClientDB<T>::Free( )
{
	EL_SAFE_FREE( m_ppRecordsByID );
	EL_SAFE_FREE( m_pRecords );
	m_nRecords		= 0;
	m_ppRecordsByID	= NULL;
	m_nMaxID		= 0;
	m_bLoaded		= FALSE;
}

template <typename T>
EL_VOID EL_TClientDB<T>::ModifyOffset( T* pstRecord, const EL_UINT8* pbyMemory, EL_CDB_HEADER* pstHeader )
{
	for( int i=0; i < (int) pstHeader->wPointerCounts; i++ ) {
		LPDWORD pdwOffset = ((LPDWORD) (((LPBYTE) pstRecord) + pstHeader->awPointerOffsets[i]));

		if( *pdwOffset == 0xFFFFFFFF )
			*pdwOffset = 0;
		else
			*pdwOffset = (DWORD) (DWORD_PTR) (pbyMemory + *pdwOffset);
	}
}

template <typename T>
int EL_TClientDB<T>::SortClientDB_ID( const EL_VOID *arg1, const EL_VOID *arg2 )
{
	EL_UINT nLeft	= (*(T**) arg1)->GetID();
	EL_UINT nRight	= (*(T**) arg2)->GetID();

	if( nLeft == nRight )
		return 0;
	else if( nLeft < nRight )
		return -1;
	else
		return 1;
}

template <typename T>
EL_BOOL	EL_TClientDB<T>::LoadEx( LPCTSTR tszFileName, EL_Status* statusPtr )
{
	EL_Environment& environ = EL_Environment::GetEnvironment();

	EL_StringBuffer_M fileNameBuf;
	environ.ReplaceMacros( tszFileName, &fileNameBuf );
	return Load( fileNameBuf, statusPtr );
}

template <typename T>
EL_BOOL EL_TClientDB<T>::Load( LPCTSTR tszFileName, EL_Status* statusPtr )
{
	//FILE*	fp;
	EL_BOOL	bRet = EL_FALSE;

	if( tszFileName && *tszFileName ) {
		if( m_tszFileName != tszFileName )
			_tcscpy_s( m_tszFileName, tszFileName );
	} else {
		_tcscpy_s( m_tszFileName, T::GetFileName() );
	}

	EL_STATUS_INFOF( statusPtr, EL_TEXT("CDB.LOAD(filePath=%s)"), m_tszFileName );

	EL_VFS_Browser& vfsBrowser = EL_VFS_Browser::GetSingleton();

	EL_MappedFile file;
	if (!vfsBrowser.Get(file, m_tszFileName)) //if( _tfopen_s( &fp, m_tszFileName, _T("rb") ) != 0 ) 
	{
		EL_STATUS_ERRORF( statusPtr, EL_TEXT("CDB.FILE_OPEN_ERROR") );
		return FALSE;
	}
	
	EL_CDB_HEADER	stHeader;
	LPCSTR			szExtra;

	if (!file.Read(&stHeader, sizeof( stHeader ))) //if( fread( &stHeader, sizeof( stHeader ), 1, fp ) != 1 ) 
	{
		EL_STATUS_ERRORF( statusPtr, EL_TEXT("CDB.HEADER_READ_ERROR") );
		goto Cleanup;
	}
	if( stHeader.dwCDBSignature != EL_SIGNATURE_CDB ) {
		EL_STATUS_ERRORF( statusPtr, EL_TEXT("CDB.HEADER_SIGNATURE_ERROR") );
		goto Cleanup;
	}

	m_nRecords	= stHeader.dwNumberOfRows;
	if( stHeader.wNumberOfColumns != T::GetNumColumns() ) {
		EL_STATUS_ERRORF( statusPtr, EL_TEXT("CDB.HEADER_NUMBER_OF_COLUMNS_MISMATCH_ERROR(file(%d) != table(%d))"),  stHeader.wNumberOfColumns, T::GetNumColumns() );
		goto Cleanup;
	}
	if( stHeader.dwRowSize != T::GetRowSize() ) {
		EL_STATUS_ERRORF( statusPtr, EL_TEXT("CDB.HEADER_ROW_SIZE_MISMATCH_ERROR(file(%d) != table(%d))"),  stHeader.dwRowSize, T::GetRowSize() );
		goto Cleanup;
	}
	EL_SIZE sizeRecords = T::GetRowSize() * m_nRecords + stHeader.dwExtraSize;
	m_pRecords	= (T*) EL_ALLOC( sizeRecords );
	szExtra		= stHeader.dwExtraSize ? (((LPCSTR) m_pRecords) + T::GetRowSize() * m_nRecords) : NULL;
	m_nMaxID	= 0;

	file.Read((LPVOID) m_pRecords, (EL_VFS_SIZE_T) sizeRecords); //fread( (LPVOID) m_pRecords, sizeRecords, 1, fp );
	for( int i=0; i < m_nRecords; i++ ) {
		T* pstRecord = &(m_pRecords[i]);
		ModifyOffset( pstRecord, (LPCBYTE) szExtra, &stHeader );
//		stRecord.Read( fp, (LPCBYTE) szExtra );
		if( pstRecord->GetID() > GetMaxID() )
		{
			if (pstRecord->GetID() != (EL_UINT)-1) // 아이디값을 못찾는 경우가 아닌 경우만 				
				m_nMaxID = pstRecord->GetID(); // 최대 ID 로 등록한다
		}
	}
	switch( T::GetIDMode() ) {
	case 0 :
		break;
	case 1 : {
		m_ppRecordsByID = (T**) EL_ALLOC( (m_nMaxID + 1)* sizeof( T* ) );
		memset( m_ppRecordsByID, 0, m_nMaxID * sizeof( T* ) );
		for( int i=0; i < m_nRecords; i++ ) {
			T* pstRecord = &(m_pRecords[i]);

			if (pstRecord->GetID() != (EL_UINT)-1) // 배열 맵핑 모드에서는 아이디 값이 유효한 경우만 등록한다
				m_ppRecordsByID[pstRecord->GetID()] = pstRecord;
		}
		break;
		}
	case 2 : {
		m_ppRecordsByID = (T**) EL_ALLOC( m_nRecords * sizeof( T* ) );
		EL_UINT iLastID = 0;
		EL_BOOL bNeedSort = EL_FALSE;
		for( int i=0; i < m_nRecords; i++ ) {
			T* pstRecord = &(m_pRecords[i]);
			m_ppRecordsByID[i] = pstRecord;

			if( iLastID > pstRecord->GetID() )
				bNeedSort = EL_TRUE;
			iLastID = pstRecord->GetID();
		}
		if( bNeedSort )
			qsort( (EL_VOID *) m_ppRecordsByID, (size_t) m_nRecords, sizeof( T* ), SortClientDB_ID );
		break;
		}
	}
	bRet = EL_TRUE;

Cleanup:
	//fclose( fp );
	return bRet;
}

#endif /* !_TCLIENTDB_H_ */
