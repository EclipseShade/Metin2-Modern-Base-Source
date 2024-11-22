/**
 * @file	MA_StringCharSet.h
 * @brief	MA_StringCharSet template classes
 * 
 * Adapted from atlconv.h (ATL 7.0)
 */

#ifndef _MA_STRINGCHARSET_H_
#define _MA_STRINGCHARSET_H_

#include "MA_String.h"
#include "MA_MemoryUtility.h"

_MA_NAMESPACE_BEGIN

#ifndef _SECURECRT_FILL_BUFFER_PATTERN
#define _SECURECRT_FILL_BUFFER_PATTERN 0xFE
#endif

#define MA_SECURE_PATTERN		_SECURECRT_FILL_BUFFER_PATTERN

MA_LPTSTR MA_SetLocale( MA_LPCTSTR tszLocale );

#ifndef CP_ACP
#define CP_ACP		0
#endif

inline MA_UINT MA_GetConversionACP()
{
	return( CP_ACP );
}

#if defined( _NTR_UNICODE )
	#define MA_LCtoMB	MA_WCtoMB
	#define MA_LCtoEC	MA_WCtoEC
	#define MA_LCtoWC	MA_WCtoWC
	#define MA_MBtoLC	MA_MBtoWC
	#define MA_ECtoLC	MA_ECtoWC
	#define MA_WCtoLC	MA_WCtoWC
#elif defined( _NTR_UTF8 )
	#define MA_LCtoMB	MA_ECtoMB
	#define MA_LCtoEC	MA_ECtoEC
	#define MA_LCtoWC	MA_ECtoWC
	#define MA_MBtoLC	MA_MBtoEC
	#define MA_ECtoLC	MA_ECtoEC
	#define MA_WCtoLC	MA_WCtoEC
#else
	#define MA_LCtoMB	MA_MBtoMB
	#define MA_LCtoEC	MA_MBtoEC
	#define MA_LCtoWC	MA_MBtoWC
	#define MA_MBtoLC	MA_MBtoMB
	#define MA_ECtoLC	MA_ECtoMB
	#define MA_WCtoLC	MA_WCtoMB
#endif

MA_SIZE	MA_MBtoEC( MA_LPCASTR IN szFrom, MA_SIZE IN sizeFrom, MA_LPESTR OUT szTo, MA_SIZE IN sizeTo );
MA_SIZE	MA_MBtoWC( MA_LPCASTR IN szFrom, MA_SIZE IN sizeFrom, MA_LPWSTR OUT szTo, MA_SIZE IN sizeTo );

MA_SIZE	MA_ECtoMB( MA_LPCESTR IN szFrom, MA_SIZE IN sizeFrom, MA_LPASTR OUT szTo, MA_SIZE IN sizeTo );
MA_SIZE	MA_ECtoWC( MA_LPCESTR IN szFrom, MA_SIZE IN sizeFrom, MA_LPWSTR OUT szTo, MA_SIZE IN sizeTo );

MA_SIZE	MA_WCtoMB( MA_LPCWSTR IN szFrom, MA_SIZE IN sizeFrom, MA_LPASTR OUT szTo, MA_SIZE IN sizeTo );
MA_SIZE	MA_WCtoEC( MA_LPCWSTR IN szFrom, MA_SIZE IN sizeFrom, MA_LPESTR OUT szTo, MA_SIZE IN sizeTo );

NTR_INLINE MA_SIZE MA_MBtoMB( MA_LPCASTR IN szFrom, MA_SIZE IN sizeFrom, MA_LPASTR OUT szTo, MA_SIZE IN sizeTo )
{
	return MA_StringNCopyA( szTo, sizeTo, szFrom, sizeFrom );
}

NTR_INLINE MA_SIZE MA_ECtoEC( MA_LPCESTR IN szFrom, MA_SIZE IN sizeFrom, MA_LPESTR OUT szTo, MA_SIZE IN sizeTo )
{
	return MA_StringNCopyE( szTo, sizeTo, szFrom, sizeFrom );
}

NTR_INLINE MA_SIZE MA_WCtoWC( MA_LPCWSTR IN szFrom, MA_SIZE IN sizeFrom, MA_LPWSTR OUT szTo, MA_SIZE IN sizeTo )
{
	return MA_StringNCopyW( szTo, sizeTo, szFrom, sizeFrom );
}

template <class _CharType>
inline BOOL MA_AllocConvMemory( _CharType** ppBuff, int nLength, _CharType* pszFixedBuffer, int nFixedBufferLength )
{
	//ATLENSURE_THROW(ppBuff != NULL, E_INVALIDARG);
	//ATLENSURE_THROW(nLength >= 0, E_INVALIDARG);
	//ATLENSURE_THROW(pszFixedBuffer != NULL, E_INVALIDARG);

	//if buffer malloced, try to realloc.
	if( *ppBuff != pszFixedBuffer ) {
		if( nLength > nFixedBufferLength ) {
#if defined( _NTR_WINDOWS )
			_CharType* ppReallocBuf = static_cast< _CharType* >( _recalloc(*ppBuff, nLength,sizeof( _CharType ) ) );
#else
			_CharType* ppReallocBuf = static_cast< _CharType* >( recalloc(*ppBuff, nLength,sizeof( _CharType ) ) );
#endif
			if( ppReallocBuf == NULL )
				return FALSE;
			*ppBuff = ppReallocBuf;
		} else {
			free(*ppBuff);
			*ppBuff=pszFixedBuffer;
		}
	} else { //Buffer is not currently malloced.
		if( nLength > nFixedBufferLength ) {
			*ppBuff = static_cast< _CharType* >( calloc(nLength,sizeof( _CharType ) ) );
		} else {			
			*ppBuff=pszFixedBuffer;
		}
	}
	if( *ppBuff == NULL )
		return FALSE;
	return TRUE;
}

template <class _CharType>
inline void MA_FreeConvMemory( _CharType* pBuff,_CharType* pszFixedBuffer,int nFixedBufferLength )
{
	(nFixedBufferLength);
	if( pBuff != pszFixedBuffer ) {
		free( pBuff );
	}
#ifdef _DEBUG
	else {		
		memset( pszFixedBuffer, MA_SECURE_PATTERN, nFixedBufferLength * sizeof(_CharType) );
	}
#endif
}

//
//	CA2AEX
//	CW2WEX
//	CE2EEX
//
template< int t_nBufferLength = 128 >
class MA_CA2AEX
{
public:
	MA_CA2AEX( MA_LPCSTR psz ) : m_psz( m_szBuffer )
	{
		Init( psz );
	}

	MA_CA2AEX( MA_LPCSTR psz, int nStringLength, MA_UINT nCodePage = CP_ACP ) : m_psz( m_szBuffer )
	{
		(void)nCodePage;  // Code page doesn't matter
		Init( psz, nStringLength );
	}

	~MA_CA2AEX()
	{
		MA_FreeConvMemory( m_psz,m_szBuffer,t_nBufferLength );
	}

	operator MA_LPSTR() const
	{
		return( m_psz );
	}

private:
	void Init( MA_LPCSTR psz )
	{
		if( psz == NULL ) {
			m_psz = NULL;
			return;
		}
		int nLength = (int) MA_StringLengthA( psz ) + 1;
		MA_AllocConvMemory( &m_psz, nLength, m_szBuffer, t_nBufferLength );
		MA_MemoryCopy( m_psz, (MA_LPVOID)psz, nLength );
	}

	void Init( MA_LPCSTR psz, int nStringLength )
	{
		if (psz == NULL) {
			m_psz = NULL;
			return;
		}
		int nLength = nStringLength + 1;
		MA_AllocConvMemory( &m_psz, nLength, m_szBuffer, t_nBufferLength );		
		MA_MemoryCopy( m_psz, (MA_LPVOID) psz, nStringLength );
		m_psz[nStringLength] = '\0';
	}

public:
	MA_LPSTR m_psz;
	char m_szBuffer[t_nBufferLength];

private:
	MA_CA2AEX( const MA_CA2AEX& );
	MA_CA2AEX& operator=( const MA_CA2AEX& );
};
typedef MA_CA2AEX<> MA_CA2A;

template< int t_nBufferLength = 128 >
class MA_CW2WEX
{
public:
	MA_CW2WEX( MA_LPCWSTR psz ) : m_psz( m_szBuffer )
	{
		Init( psz );
	}

	MA_CW2WEX( MA_LPCWSTR psz, int nStringLength, MA_UINT nCodePage = CP_ACP ) : m_psz( m_szBuffer )
	{
		(void)nCodePage;  // Code page doesn't matter
		Init( psz, nStringLength );
	}

	~MA_CW2WEX()
	{
		MA_FreeConvMemory( m_psz,m_szBuffer, t_nBufferLength );
	}

	operator MA_LPWSTR() const
	{
		return( m_psz );
	}

private:
	void Init( MA_LPCWSTR psz )
	{
		if( psz == NULL ) {
			m_psz = NULL;
			return;
		}
		int nLength = (int) MA_StringLengthW( psz ) + 1;
		MA_AllocConvMemory( &m_psz, nLength, m_szBuffer, t_nBufferLength );
		MA_MemoryCopy( m_psz, (MA_LPVOID) psz, nLength * sizeof( wchar_t ) );
	}

	void Init( MA_LPCWSTR psz, int nStringLength )
	{
		if( psz == NULL ) {
			m_psz = NULL;
			return;
		}
		int nLength = nStringLength+1;
		MA_AllocConvMemory( &m_psz,nLength, m_szBuffer, t_nBufferLength );
		MA_MemoryCopy( m_psz, (MA_LPVOID) psz, nStringLength*sizeof( wchar_t ) );
		m_psz[nStringLength] = L'\0';
	}

public:
	MA_LPWSTR m_psz;
	wchar_t m_szBuffer[t_nBufferLength];

private:
	MA_CW2WEX( const MA_CW2WEX& );
	MA_CW2WEX& operator=( const MA_CW2WEX& );
};
typedef MA_CW2WEX<> MA_CW2W;

template< int t_nBufferLength = 128 >
class MA_CE2EEX
{
public:
	MA_CE2EEX( MA_LPCESTR psz ) : m_psz( m_szBuffer )
	{
		Init( psz );
	}

	MA_CE2EEX( MA_LPCESTR psz, int nStringLength, MA_UINT nCodePage = CP_ACP ) : m_psz( m_szBuffer )
	{
		(void)nCodePage;  // Code page doesn't matter
		Init( psz, nStringLength );
	}

	~MA_CE2EEX()
	{
		MA_FreeConvMemory(m_psz,m_szBuffer,t_nBufferLength);
	}

	operator MA_LPESTR() const
	{
		return( m_psz );
	}

private:
	void Init( MA_LPCESTR psz )
	{
		if (psz == NULL) {
			m_psz = NULL;
			return;
		}
		int nLength = (int) MA_StringLengthE( psz ) + 1;
		MA_AllocConvMemory( &m_psz, nLength, m_szBuffer, t_nBufferLength );
		MA_MemoryCopy( m_psz, (MA_LPVOID) psz, nLength );
	}

	void Init( MA_LPCESTR psz, int nStringLength )
	{
		if (psz == NULL) {
			m_psz = NULL;
			return;
		}
		int nLength = nStringLength + 1;
		MA_AllocConvMemory( &m_psz, nLength, m_szBuffer, t_nBufferLength );		
		MA_MemoryCopy( m_psz, (MA_LPVOID) psz, nStringLength );
		m_psz[nStringLength] = '\0';
	}

public:
	MA_LPESTR m_psz;
	char m_szBuffer[t_nBufferLength];

private:
	MA_CE2EEX( const MA_CE2EEX& );
	MA_CE2EEX& operator=( const MA_CE2EEX& );
};
typedef MA_CE2EEX<> MA_CE2E;

//
//	CA2CAEX
//	CW2CWEX
//	CE2CEEX
//
template< int t_nBufferLength = 128 >
class MA_CA2CAEX
{
public:
	MA_CA2CAEX( MA_LPCSTR psz ) : m_psz( psz )
	{
	}

	MA_CA2CAEX( MA_LPCSTR psz, MA_UINT nCodePage ) : m_psz( psz )
	{
		(void)nCodePage;
	}

	~MA_CA2CAEX()
	{
	}

	operator MA_LPCSTR() const
	{
		return( m_psz );
	}

public:
	MA_LPCSTR m_psz;

private:
	MA_CA2CAEX( const MA_CA2CAEX& );
	MA_CA2CAEX& operator=( const MA_CA2CAEX& );
};
typedef MA_CA2CAEX<> MA_CA2CA;

template< int t_nBufferLength = 128 >
class MA_CW2CWEX
{
public:
	MA_CW2CWEX( MA_LPCWSTR psz ) : m_psz( psz )
	{
	}

	MA_CW2CWEX( MA_LPCWSTR psz, int nStringLength, MA_UINT nCodePage = CP_ACP ) :
		m_psz( psz )
	{
		(void)nCodePage;
	}

	~MA_CW2CWEX()
	{
	}

	operator MA_LPCWSTR() const
	{
		return( m_psz );
	}

public:
	MA_LPCWSTR m_psz;

private:
	MA_CW2CWEX( const MA_CW2CWEX& );
	MA_CW2CWEX& operator=( const MA_CW2CWEX& );
};
typedef MA_CW2CWEX<> MA_CW2CW;

template< int t_nBufferLength = 128 >
class MA_CE2CEEX
{
public:
	MA_CE2CEEX( MA_LPCESTR psz ) : m_psz( psz )
	{
	}

	MA_CE2CEEX( MA_LPCESTR psz, int nStringLength, MA_UINT nCodePage = CP_ACP ) :
		m_psz( psz )
	{
		(void)nCodePage;
	}

	~MA_CE2CEEX()
	{
	}

	operator MA_LPCESTR() const
	{
		return( m_psz );
	}

public:
	MA_LPCESTR m_psz;

private:
	MA_CE2CEEX( const MA_CE2CEEX& );
	MA_CE2CEEX& operator=( const MA_CE2CEEX& );
};
typedef MA_CE2CEEX<> MA_CE2CE;

//
//	MA_CA2WEX
//	MA_CA2EEX
//	MA_CW2AEX
//	MA_CW2EEX
//	MA_CE2AEX
//	MA_CE2WEX
//
template< int t_nBufferLength = 128 >
class MA_CA2WEX
{
public:
	MA_CA2WEX( MA_LPCSTR psz ) : m_psz( m_szBuffer )
	{
		Init( psz, MA_GetConversionACP() );
	}

	MA_CA2WEX( MA_LPCSTR psz, int nStringLength, MA_UINT nCodePage = CP_ACP ) : m_psz( m_szBuffer )
	{
		Init( psz, nStringLength, nCodePage );
	}

	~MA_CA2WEX()
	{
		MA_FreeConvMemory( m_psz,m_szBuffer,t_nBufferLength );
	}

	operator MA_LPWSTR() const
	{
		return( m_psz );
	}

private:
	void Init( MA_LPCSTR psz, MA_UINT nCodePage )
	{
		if( psz == NULL ) {
			m_psz = NULL;
			return;
		}
		int nLengthA = (int) MA_StringLengthA( psz );

		if( nLengthA == 0 ) {
			m_psz[0] = '\0';
			return;
		}
		int nLengthW = (int) MA_MBtoWC( psz, nLengthA, NULL, 0 );

		if( nLengthW == -1 ) {
			m_psz[0] = '\0';
			return;
		}

		MA_AllocConvMemory( &m_psz, nLengthW+1, m_szBuffer, t_nBufferLength );
		MA_MBtoWC( psz, nLengthA, m_psz, nLengthW+1 );
		return;
		(void)nCodePage;  // Code page doesn't matter
	}

	void Init( MA_LPCSTR psz, int nStringLength, MA_UINT nCodePage )
	{
		if( psz == NULL ) {
			m_psz = NULL;
			return;
		}
		if (nStringLength == 0) {
			m_psz[0] = '\0';
			return;
		}

		int nLengthA = nStringLength;
		int nLengthW = MA_MBtoWC( psz, nLengthA, NULL, 0 );

		if( nLengthW == -1 ) {
			m_psz[0] = '\0';
			return;
		}

		MA_AllocConvMemory( &m_psz, nLengthW+1, m_szBuffer, t_nBufferLength );
		MA_MBtoWC( psz, nLengthA, m_psz, nLengthW+1 );
		return;
		(void)nCodePage;  // Code page doesn't matter
	}

public:
	MA_LPWSTR m_psz;
	wchar_t m_szBuffer[t_nBufferLength];

private:
	MA_CA2WEX( const MA_CA2WEX& );
	MA_CA2WEX& operator=( const MA_CA2WEX& );
};
typedef MA_CA2WEX<> MA_CA2W;

template< int t_nBufferLength = 128 >
class MA_CW2AEX
{
public:
	MA_CW2AEX( MA_LPCWSTR psz ) :
		m_psz( m_szBuffer )
	{
		Init( psz, MA_GetConversionACP() );
	}

	MA_CW2AEX( MA_LPCWSTR psz, int nStringLength, MA_UINT nCodePage = CP_ACP ) : m_psz( m_szBuffer )
	{
		Init( psz, nStringLength, nCodePage );
	}

	~MA_CW2AEX()
	{		
		MA_FreeConvMemory(m_psz,m_szBuffer,t_nBufferLength);
	}

	operator MA_LPSTR() const
	{
		return( m_psz );
	}

private:
	void Init( MA_LPCWSTR psz, MA_UINT nCodePage )
	{
		if( psz == NULL ) {
			m_psz = NULL;
			return;
		}
		int nLengthW = (int) MA_StringLengthW( psz );
		if( nLengthW == 0 ) {
			m_psz[0] = '\0';
			return;
		}
		int nLengthA = (int) MA_WCtoMB( psz, nLengthW, NULL, 0 );
		if( nLengthA == -1 ) {
			m_psz[0] = '\0';
			return;
		}
		
		MA_AllocConvMemory( &m_psz, nLengthA+1, m_szBuffer, t_nBufferLength );
		MA_WCtoMB( psz, nLengthW, m_psz, nLengthA+1 );
		return;
		(void)nCodePage;  // Code page doesn't matter
	}

	void Init( MA_LPCWSTR psz, int nStringLength, MA_UINT nCodePage )
	{
		if( psz == NULL ) {
			m_psz = NULL;
			return;
		}

		if (nStringLength == 0) {
			m_psz[0] = '\0';
			return;
		}

		int nLengthW = nStringLength;
		int nLengthA = MA_WCtoMB( psz, nLengthW, NULL, 0 );
		if( nLengthA == -1 ) {
			m_psz[0] = '\0';
			return;
		}
		
		MA_AllocConvMemory( &m_psz, nLengthA+1, m_szBuffer, t_nBufferLength );
		MA_WCtoMB( psz, nLengthW, m_psz, nLengthA+1 );
		return;
		(void)nCodePage;  // Code page doesn't matter
	}

public:
	MA_LPSTR m_psz;
	char m_szBuffer[t_nBufferLength];

private:
	MA_CW2AEX( const MA_CW2AEX& );
	MA_CW2AEX& operator=( const MA_CW2AEX& );
};
typedef MA_CW2AEX<> MA_CW2A;

template< int t_nBufferLength = 128 >
class MA_CW2EEX
{
public:
	MA_CW2EEX( MA_LPCWSTR psz ) :
		m_psz( m_szBuffer )
	{
		Init( psz );
	}

	MA_CW2EEX( MA_LPCWSTR psz, int nStringLength, MA_UINT nCodePage = CP_ACP ) : m_psz( m_szBuffer )
	{
		Init( psz, nStringLength );
		return;
		nCodePage;
	}

	~MA_CW2EEX()
	{		
		MA_FreeConvMemory( m_psz, m_szBuffer, t_nBufferLength );
	}

	operator MA_LPESTR() const
	{
		return( m_psz );
	}

private:
	void Init( MA_LPCWSTR psz )
	{
                if( psz == NULL ) {
                        m_psz = NULL;
                        return;
                }
                int nLengthW = (int) MA_StringLengthW( psz );
                if( nLengthW == 0 ) {
                        m_psz[0] = '\0';
                        return;
                }
                int nLengthE = (int) MA_WCtoEC( psz, nLengthW, NULL, 0 );
                if( nLengthE == -1 ) {
                        m_psz[0] = '\0';
                        return;
                }

                MA_AllocConvMemory( &m_psz, nLengthE+1, m_szBuffer, t_nBufferLength );
                MA_WCtoEC( psz, nLengthW, m_psz, nLengthE+1 );
	}

	void Init( MA_LPCWSTR psz, int nStringLength )
	{
                if( psz == NULL ) {
                        m_psz = NULL;
                        return;
                }

                if (nStringLength == 0) {
                        m_psz[0] = '\0';
                        return;
                }

                int nLengthW = nStringLength;
                int nLengthE = MA_WCtoEC( psz, nLengthW, NULL, 0 );
                if( nLengthE == -1 ) {
                        m_psz[0] = '\0';
                        return;
                }

                MA_AllocConvMemory( &m_psz, nLengthE+1, m_szBuffer, t_nBufferLength );
                MA_WCtoEC( psz, nLengthW, m_psz, nLengthE+1 );
	}

public:
	MA_LPESTR	m_psz;
	MA_ECHAR	m_szBuffer[t_nBufferLength];

private:
	MA_CW2EEX( const MA_CW2EEX& );
	MA_CW2EEX& operator=( const MA_CW2EEX& );
};
typedef MA_CW2EEX<> MA_CW2E;

template< int t_nBufferLength = 128 >
class MA_CA2EEX
{
public:
	MA_CA2EEX( MA_LPCASTR psz ) :
		m_pesz( m_szBuffer )
	{
		Init( psz );
	}

	MA_CA2EEX( MA_LPCASTR psz, int nStringLength, MA_UINT nCodePage = CP_ACP ) : m_pesz( m_szBuffer )
	{
		Init( psz, nStringLength );
		return;
		nCodePage;
	}

	~MA_CA2EEX()
	{		
		MA_FreeConvMemory(m_pesz,m_szBuffer,t_nBufferLength);
	}

	operator MA_LPESTR() const
	{
		return( m_pesz );
	}

private:
	void Init( MA_LPCASTR psz )
	{
                if( psz == NULL ) {
                        m_pesz = NULL;
                        return;
                }
                int nLengthA = (int) MA_StringLengthA( psz );
                if( nLengthA == 0 ) {
                        m_pesz[0] = '\0';
                        return;
                }
                int nLengthE = (int) MA_MBtoEC( psz, nLengthA, NULL, 0 );
                if( nLengthE == -1 ) {
                        m_pesz[0] = '\0';
                        return;
                }

                MA_AllocConvMemory( &m_pesz, nLengthE+1, m_szBuffer, t_nBufferLength );
                MA_MBtoEC( psz, nLengthA, m_pesz, nLengthE+1 );
	}

	void Init( MA_LPCASTR psz, int nStringLength )
	{
                if( psz == NULL ) {
                        m_pesz = NULL;
                        return;
                }

                if (nStringLength == 0) {
                        m_pesz[0] = '\0';
                        return;
                }

                int nLengthA = nStringLength;
                int nLengthE = MA_MBtoEC( psz, nLengthA, NULL, 0 );
                if( nLengthE == -1 ) {
                        m_pesz[0] = '\0';
                        return;
                }

                MA_AllocConvMemory( &m_pesz, nLengthE+1, m_szBuffer, t_nBufferLength );
                MA_MBtoEC( psz, nLengthA, m_pesz, nLengthE+1 );
	}

public:
	MA_LPESTR	m_pesz;
	MA_ECHAR	m_szBuffer[t_nBufferLength];

private:
	MA_CA2EEX( const MA_CA2EEX& );
	MA_CA2EEX& operator=( const MA_CA2EEX& );
};
typedef MA_CA2EEX<> MA_CA2E;

template< int t_nBufferLength = 128 >
class MA_CE2AEX
{
public:
	MA_CE2AEX( MA_LPCESTR pesz ) :
		m_psz( m_szBuffer )
	{
		Init( pesz, MA_GetConversionACP() );
	}

	MA_CE2AEX( MA_LPCESTR pesz, int nStringLength, MA_UINT nCodePage = CP_ACP ) : m_psz( m_szBuffer )
	{
		Init( pesz, nStringLength, nCodePage );
	}

	~MA_CE2AEX()
	{		
		MA_FreeConvMemory(m_psz,m_szBuffer,t_nBufferLength);
	}

	operator MA_LPSTR() const
	{
		return( m_psz );
	}

private:
	void Init( MA_LPCESTR pesz, MA_UINT nCodePage )
	{
		if( pesz == NULL ) {
			m_psz = NULL;
			return;
		}
		int nLengthE = (int) MA_StringLengthE( pesz );
		if( nLengthE == 0 ) {
			m_psz[0] = '\0';
			return;
		}
		int nLengthA = (int) MA_ECtoMB( pesz, nLengthE, NULL, 0 );
		if( nLengthA == -1 ) {
			m_psz[0] = '\0';
			return;
		}

		MA_AllocConvMemory( &m_psz, nLengthA+1, m_szBuffer, t_nBufferLength );
		MA_ECtoMB( pesz, nLengthE, m_psz, nLengthA+1 );
		return;
		(void)nCodePage;  // Code page doesn't matter
	}

	void Init( MA_LPCESTR pesz, int nStringLength, MA_UINT nCodePage )
	{
		if( pesz == NULL ) {
			m_psz = NULL;
			return;
		}

		if (nStringLength == 0) {
			m_psz[0] = '\0';
			return;
		}

		int nLengthE = nStringLength;
		int nLengthA = MA_ECtoMB( pesz, nLengthE, NULL, 0 );
		if( nLengthA == -1 ) {
			m_psz[0] = '\0';
			return;
		}

		MA_AllocConvMemory( &m_psz, nLengthA+1, m_szBuffer, t_nBufferLength );
		MA_ECtoMB( pesz, nLengthE, m_psz, nLengthA+1 );
		return;
		(void)nCodePage;  // Code page doesn't matter
	}

public:
	MA_LPSTR	m_psz;
	char		m_szBuffer[t_nBufferLength];

private:
	MA_CE2AEX( const MA_CE2AEX& );
	MA_CE2AEX& operator=( const MA_CE2AEX& );
};
typedef MA_CE2AEX<> MA_CE2A;

template< int t_nBufferLength = 128 >
class MA_CE2WEX
{
public:
	MA_CE2WEX( MA_LPCESTR psz ) : m_psz( m_szBuffer )
	{
		Init( psz );
	}

	MA_CE2WEX( MA_LPCESTR psz, int nStringLength, MA_UINT nCodePage = CP_ACP ) : m_psz( m_szBuffer )
	{
		Init( psz, nStringLength );
		return;
		nCodePage;
	}

	~MA_CE2WEX()
	{
		MA_FreeConvMemory( m_psz,m_szBuffer,t_nBufferLength );
	}

	operator MA_LPWSTR() const
	{
		return( m_psz );
	}

private:
	void Init( MA_LPCESTR pesz )
	{
                if( pesz == NULL ) {
                        m_psz = NULL;
                        return;
                }
                int nLengthE = (int) MA_StringLengthE( pesz );
                if( nLengthE == 0 ) {
                        m_psz[0] = L'\0';
                        return;
                }
                int nLengthW = (int) MA_ECtoWC( pesz, nLengthE, NULL, 0 );
                if( nLengthW == -1 ) {
                        m_psz[0] = L'\0';
                        return;
                }

                MA_AllocConvMemory( &m_psz, nLengthW+1, m_szBuffer, t_nBufferLength );
                MA_ECtoWC( pesz, nLengthE, m_psz, nLengthW+1 );
	}

	void Init( MA_LPCESTR pesz, int nStringLength )
	{
                if( pesz == NULL ) {
                        m_psz = NULL;
                        return;
                }

                if (nStringLength == 0) {
                        m_psz[0] = L'\0';
                        return;
                }

                int nLengthE = nStringLength;
                int nLengthW = MA_ECtoWC( pesz, nLengthE, NULL, 0 );
                if( nLengthW == -1 ) {
                        m_psz[0] = L'\0';
                        return;
                }

		MA_AllocConvMemory( &m_psz, nLengthW+1, m_szBuffer, t_nBufferLength );
                MA_ECtoWC( pesz, nLengthE, m_psz, nLengthW+1 );
	}

public:
	MA_LPWSTR m_psz;
	wchar_t m_szBuffer[t_nBufferLength];

private:
	MA_CE2WEX( const MA_CE2WEX& );
	MA_CE2WEX& operator=( const MA_CE2WEX& );
};
typedef MA_CE2WEX<> MA_CE2W;

#ifdef _NTR_UNICODE
	#define MA_CW2T			MA_CW2W
	#define MA_CW2TEX		MA_CW2WEX
	#define MA_CW2CT		MA_CW2CW
	#define MA_CW2CTEX		MA_CW2CWEX
	#define MA_CT2W			MA_CW2W
	#define MA_CT2WEX		MA_CW2WEX
	#define MA_CT2CW		MA_CW2CW
	#define MA_CT2CWEX		MA_CW2CWEX

	#define MA_CA2T			MA_CA2W
	#define MA_CA2TEX		MA_CA2WEX
	#define MA_CA2CT		MA_CA2W
	#define MA_CA2CTEX		MA_CA2WEX
	#define MA_CT2A			MA_CW2A
	#define MA_CT2AEX		MA_CW2AEX
	#define MA_CT2CA		MA_CW2A
	#define MA_CT2CAEX		MA_CW2AEX

	#define MA_CE2T			MA_CE2W
	#define MA_CE2TEX		MA_CE2WEX
	#define MA_CE2CT		MA_CE2W
	#define MA_CE2CTEX		MA_CE2WEX
	#define MA_CT2E			MA_CW2E
	#define MA_CT2EEX		MA_CW2EEX
	#define MA_CT2CE		MA_CW2E
	#define MA_CT2CEEX		MA_CW2EEX
#else  // !_UNICODE
	#define MA_CW2T			MA_CW2A
	#define MA_CW2TEX		MA_CW2AEX
	#define MA_CW2CT		MA_CW2A
	#define MA_CW2CTEX		MA_CW2AEX
	#define MA_CT2W			MA_CA2W
	#define MA_CT2WEX		MA_CA2WEX
	#define MA_CT2CW		MA_CA2W
	#define MA_CT2CWEX		MA_CA2WEX

	#define MA_CA2T			MA_CA2A
	#define MA_CA2TEX		MA_CA2AEX
	#define MA_CA2CT		MA_CA2CA
	#define MA_CA2CTEX		MA_CA2CAEX
	#define MA_CT2A			MA_CA2A
	#define MA_CT2AEX		MA_CA2AEX
	#define MA_CT2CA		MA_CA2CA
	#define MA_CT2CAEX		MA_CA2CAEX

	#define MA_CE2T			MA_CE2A
	#define MA_CE2TEX		MA_CE2AEX
	#define MA_CE2CT		MA_CE2CA
	#define MA_CE2CTEX		MA_CE2CAEX
	#define MA_CT2E			MA_CA2E
	#define MA_CT2EEX		MA_CA2EEX
	#define MA_CT2CE		MA_CA2CE
	#define MA_CT2CEEX		MA_CA2CEEX
#endif

_MA_NAMESPACE_END

#endif /* !_MA_STRINGCHARSET_H_ */
