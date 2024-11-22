#pragma once

class EL_CFlatMemory
{
public:
	//-----------------------------------------------------------
	//	Constructor / Destructor
	//-----------------------------------------------------------

	/// Constructor
	EL_CFlatMemory( void );
	EL_CFlatMemory( const EL_CFlatMemory& );

	/// Destructor
	virtual ~EL_CFlatMemory();


	/**
	* @brief	내용을 모두 지운다.
	*/
	void Clear( void );

	/**
	* @brief	내용을 모두 지운다.
	*/
	void Close( void ) { Clear(); }

	/**
	* @brief	각 row들 중 가장 긴 column의 cell 수를 return 한다.
	* @return	가장 긴 column의 cell 수
	*/
	EL_SIZE GetMaxColumns( void ) const { return m_sizeMaxColumns; }

	/**
	* @brief	Row의 수를 return 한다.
	* @return	Row의 수
	*/
	EL_SIZE GetRows( void ) const;

	/**
	* @brief	각 row의 column의 수롤 return 한다.
	* @param[in]	iRow	Columns의 수를 return 
	* @return	마지막 column의 zero-based index + 1
	*/
	EL_SIZE GetColumns( int iRow ) const;

	/**
	* @brief	Header를 가지고 있는지 return 한다.
	* @return	Header를 가지고 있으면 TRUE, 그렇지 않으면 FALSE를 return 한다.
	*/
	BOOL HasHeader( void ) const { return 0 < m_mapHeaders.size(); }

	/**
	* @brief			주어진 헤더이름을 가진 column의 index를 return한다.
	* @param[in]		tszHeader	Header의 이름
	* @return			해당 헤더의 column 번호를 반환한다. 해당 헤더를 찾지못할 경우 -1을 반환한다.
	*/
	int FindHeader( LPCTSTR tszColumnName ) const;

	/**
	* @brief	주어진 column의 header를 return 한다.
	* @param[in]		iCol		Zero-based index
	* @param[out]		tszHeader	Header를 저장할 buffer
	* @param[in,out]	psizeHeader	[in] tszHeader에 저장할 수 있는 크기
	[out] tszHeader에 저장한 크기
	TCHAR 단위
	* @return	주어진 column의 index에 header가 설정 되어있으면 TRUE, 그렇지 않으면 FALSE를 return 한다.
	*/
	BOOL GetHeader( int iCol, LPTSTR tszHeader, EL_SIZE *psizeHeader ) const;

	/**
	* @brief	주어진 column의 header를 return 한다.
	* @param[in]	iCol		Zero-based index
	* @param[out]	tszHeader	Header를 저장할 buffer
	* @param[in]	sizeHeader	tszHeader에 저장할 수 있는 크기. TCHAR 단위
	* @return	주어진 column의 index에 header가 설정 되어있으면 TRUE, 그렇지 않으면 FALSE를 return 한다.
	*/
	BOOL GetHeader( int iCol, LPTSTR tszHeader, EL_SIZE sizeHeader ) const;

	/**
	* @brief	주어진 column의 header를 return 한다.
	* @param[in]	iCol		Zero-based index
	* @param[out]	rstrHeader	Header를 저장할 buffer
	* @return	주어진 column의 index에 header가 설정 되어있으면 TRUE, 그렇지 않으면 FALSE를 return 한다.
	*/
	BOOL GetHeader( int iCol, EL_STLString &rstrHeader ) const;

	/**
	* @brief	주어진 column의 header를 return 한다.
	* @param[in]	iCol		Zero-based index
	* @return	주어진 column의 index에 header가 설정 되어있으면 string의 pointer를, 그렇지 않으면 NULL을 return 한다.
	*/
	LPCTSTR GetHeader( int iCol ) const;

	/**
	* @brief	Cell의 data 값을 return 한다.
	* @param[in]		iRow		Row의 zero-based index
	* @param[in]		iCol		Column의 zero-based index
	* @param[out]		tszData		Data를 저장할 buffer. NULL일 수 있다.
	* @param[in,out]	psizeData	[in] tszData에 저장할 수 있는 크기
	[out] tszData에 저장한 크기
	TCHAR 단위. tszData가 NULL인 경우에는 data의 길이를 return 한다.
	NULL 일 수 있다. tszValue가 NULL이 아니면 이 값도 NULL이 아니어야 한다.
	* @return	Cell에 data가 있으면 TRUE, 그렇지 않으면 FALSE를 return 한다.
	*
	* tszValue와 psizeValue 둘다 NULL로 사용하면 cell에 값이 있는지만 알 수 있다
	*/
	BOOL Get( int iRow, int iCol, LPTSTR tszData, EL_SIZE IN*psizeData ) const;

	/**
	* @brief	Cell의 data 값을 return 한다.
	* @param[in]	iRow		Row의 zero-based index
	* @param[in]	iCol		Column의 zero-based index
	* @param[out]	tszData		Data를 저장할 buffer
	* @param[in]	sizeData	tszData에 저장할 수 있는 크기. TCHAR 단위
	* @return	Cell에 data가 있으면 TRUE, 그렇지 않으면 FALSE를 return 한다.
	*/
	BOOL Get( int iRow, int iCol, LPTSTR tszData, EL_SIZE sizeData ) const;

	/**
	* @brief	Cell의 data 값을 return 한다.
	* @param[in]	iRow		Row의 zero-based index
	* @param[in]	iCol		Column의 zero-based index
	* @param[out]	rstrData	Data를 저장할 buffer
	* @return	Cell에 data가 있으면 TRUE, 그렇지 않으면 FALSE를 return 한다.
	*/
	BOOL Get( int iRow, int iCol, EL_STLString &rstrData ) const;

	/**
	* @brief	Cell의 data 값을 return 한다.
	* @param[in]	iRow		Row의 zero-based index
	* @param[in]	iCol		Column의 zero-based index
	* @return	Cell에 data가 있으면 string의 pointer를, 그렇지 않으면 NULL을 return 한다.
	*/
	LPCTSTR Get( int iRow, int iCol ) const;

	/**
	* @brief	Cell의 data 값을 return 한다.
	* @param[in]	iRow		Row의 zero-based index
	* @param[in]	iCol		Column의 zero-based index
	* @param[out]	rnData		Data를 저장할 buffer
	* @return	Cell에 data가 있고 integer로 변환할 수 있으면 TRUE, 그렇지 않으면 FALSE를 return 한다.
	*/
	BOOL Get( int iRow, int iCol, int &rnData ) const;

	/**
	* @brief	Cell의 data 값을 return 한다.
	* @param[in]	iRow		Row의 zero-based index
	* @param[in]	iCol		Column의 zero-based index
	* @param[out]	rnData		Data를 저장할 buffer
	* @return	Cell에 data가 있고 integer로 변환할 수 있으면 TRUE, 그렇지 않으면 FALSE를 return 한다.
	*/
	template<typename IntType>
	BOOL Get( int iRow, int iCol, IntType &rnData ) const
	{
		int nData;
		if( !Get( iRow, iCol, nData ) )
			return FALSE;
		rnData = static_cast<IntType>( nData );

		return TRUE;
	}

	/**
	* @brief	Cell의 data 값을 return 한다.
	* @param[in]	iRow		Row의 zero-based index
	* @param[in]	iCol		Column의 zero-based index
	* @param[out]	rfData		Data를 저장할 buffer
	* @return	Cell에 data가 있고 integer로 변환할 수 있으면 TRUE, 그렇지 않으면 FALSE를 return 한다.
	*/
	BOOL Get( int iRow, int iCol, float &rfData ) const;

	/**
	* @brief	Cell의 data 값을 return 한다.
	* @param[in]	iRow		Row의 zero-based index
	* @param[in]	iCol		Column의 zero-based index
	* @param[out]	rdData		Data를 저장할 buffer
	* @return	Cell에 data가 있고 integer로 변환할 수 있으면 TRUE, 그렇지 않으면 FALSE를 return 한다.
	*/
	BOOL Get( int iRow, int iCol, double &rdData ) const
	{
		float fData;
		if( !Get( iRow, iCol, fData ) )
			return FALSE;
		rdData = static_cast<double>( fData );

		return TRUE;
	}

	/**
	* @brief	Header를 setting 한다.
	* @param[in]	iCol		Column의 zero-based index
	* @param[in]	tszHeader	Setting 할 header
	*/
	void SetHeader( int iCol, LPCTSTR tszHeader );

	/**
	* @brief	Cell에 값을 setting 한다.
	* @param[in]	iRow	Row의 zero-based index
	* @param[in]	iCol	Column의 zero-based index
	* @param[in]	tszData	Cell에 setting 할 값
	*/
	void Set( int iRow, int iCol, LPCTSTR tszData );

	/**
	* @brief	Cell에 값을 setting 한다.
	* @param[in]	iRow	Row의 zero-based index
	* @param[in]	iCol	Column의 zero-based index
	* @param[in]	tszData	Cell에 setting 할 값
	*/
	void Set( int iRow, int iCol, LPTSTR tszData )
	{
		Set( iRow, iCol, reinterpret_cast<LPCTSTR>( tszData ) );
	}

	/**
	* @brief	Cell에 값을 setting 한다.
	* @param[in]	iRow	Row의 zero-based index
	* @param[in]	iCol	Column의 zero-based index
	* @param[in]	nData	Cell에 setting 할 값
	*/
	void Set( int iRow, int iCol, int nData );

	/**
	* @brief	Cell에 값을 setting 한다.
	* @param[in]	iRow	Row의 zero-based index
	* @param[in]	iCol	Column의 zero-based index
	* @param[in]	uData	Cell에 setting 할 값
	*/
	template<typename IntType>
	void Set( int iRow, int iCol, IntType nData )
	{
		Set( iRow, iCol, static_cast<int>( nData ) );
	}

	/**
	* @brief	Cell에 값을 setting 한다.
	* @param[in]	iRow	Row의 zero-based index
	* @param[in]	iCol	Column의 zero-based index
	* @param[in]	fData	Cell에 setting 할 값
	*/
	void Set( int iRow, int iCol, float fData );

	/**
	* @brief	Cell에 값을 setting 한다.
	* @param[in]	iRow	Row의 zero-based index
	* @param[in]	iCol	Column의 zero-based index
	* @param[in]	dData	Cell에 setting 할 값
	*/
	void Set( int iRow, int iCol, double dData );

protected:
	//-----------------------------------------------------------
	//	Private Types
	//-----------------------------------------------------------

	EL_DEFINE_STL_MAP( Values, int, EL_STLString );

	EL_DEFINE_STL_MAP( Rows, int, MapValues );

	/**
	* @brief	주어진 map에서 값을 찾아 return 한다.
	* @param[in]		pmapValues	값을 찾을 map
	* @parma[in]		iCol		Column의 zero-based index
	* @param[out]		tszValue	값을 저장할 buffer. NULL 일 수 있다.
	* @param[in,out]	psizeValue	[in] tszValues에 저장할 수 있는 크기
	[out] tszValues에 저장한 크기
	TCHAR 단위. tszValue가 NULL이면 값의 크기만 return 한다.
	NULL 일 수 있다. tszValue가 NULL이 아니면 이 값도 NULL이 아니어야 한다.
	* @return	Cell에 값이 있으면 TRUE, 그렇지 않으면 FALSE를 return 한다.
	*
	* tszValue와 psizeValue 둘다 NULL로 사용하면 cell에 값이 있는지만 알 수 있다
	*/
	static BOOL FindValue( const MapValues *pmapValues, int iCol, LPTSTR tszValue, EL_SIZE IN*psizeValue );

	/**
	* @brief	주어진 map에서 값을 찾아 return 한다.
	* @param[in]	pmapValues	값을 찾을 map
	* @parma[in]	iCol		Column의 zero-based index
	* @return	Cell에 값이 있으면 EL_STLString*, 그렇지 않으면 NULL을 return 한다.
	*/
	static const EL_STLString* FindValue( const MapValues *pmapValues, int iCol );

	/**
	* @brief	주어진 row와 column의 index로 값을 찾아 return 한다.
	* @param[in]	iRow	값을 찾을 map
	* @parma[in]	iCol		Column의 zero-based index
	* @return	Cell에 값이 있으면 EL_STLString*, 그렇지 않으면 NULL을 return 한다.
	*/
	const EL_STLString* FindValue( int iRow, int iCol ) const;

	/**
	* @brief	주어진 row의 index로 row를 찾는다.
	* @param[in]	iRow	Row의 zero-based index
	* @return	찾은 row의 pointer를 return 한다.
	*/
	const MapValues* FindRow( int iRow ) const;

	/**
	* @brief	Column의 index로 max columns를 update 한다.
	* @param[in]	iCol	Update할 column의 index
	*/
	void UpdateMaxColumns( unsigned int iCol );

protected:
	/// Parsing result
	typedef enum
	{ 
		PARSE_ERROR,
		PARSE_NEXT_RIGHT,
		PARSE_NEXT_BELOW,
		PARSE_END,
	} EParseCell;

	MapValues	m_mapHeaders;				///< Header를 저장
	MapRows		m_mapRows;					///< 각 row를 저장
	EL_SIZE		m_sizeMaxColumns;			///< 최대 column
};
