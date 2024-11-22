/**
 * @file	EA_CBufferFormatter.h
 * @brief	Earth Buffer formatter header
 * @author	cpascal (cpascal@@buddygames.co.kr)
 * @author	cppeins (cppeins@@buddygames.co.kr)
 *
 * @version	2005/08/04 cppis - First release

 * @code
#include <Earth/Earth.h>
#include <Earth/Log.h>
#include <Earth/EA_CBufferFormatter.h>
#include <Earth/TBufferFormatter.h>

#include <string>
#include <conio.h>

using namespace Earth;
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	EA_InitLog( ELOGOUTTYPE_SYSDEFAULT );

	char		TempBuffer1[MA_MAX_PATH + 1];
	char		TempBuffer2[MA_MAX_PATH + 1];

	EA_CBufferFormatter	cFormatter(TempBuffer1);
	TBufferFormatter	tFormatter(TempBuffer2);

	cFormatter.PutU32( 0 );
	tFormatter.Put<u16>( 100 );
	EA_INF( ( _T("EA_CBufferFormatter size is %d"), cFormatter.Size() ) );
	EA_INF( ( _T("TBufferFormatter size is %d"), tFormatter.Size() ) );
	cFormatter.Reset();
	tFormatter.Reset();

	string	strTemp1( "Hello MKnight!" );
	string	strTemp2( "Merong~" );
	cFormatter.PutString( strTemp1 );
	tFormatter.Put<string&>( strTemp2 );
	EA_NTC( ( _T("EA_CBufferFormatter size is %d"), cFormatter.Size() ) );
	EA_NTC( ( _T("TBufferFormatter size is %d"), tFormatter.Size() ) );

	string	strReturn1;
	string	strReturn2;
	EA_CBufferFormatter	cNewFormatter(TempBuffer1);
	TBufferFormatter	tNewFormatter(TempBuffer2);
	cNewFormatter.GetString( strReturn1, cFormatter.Size() );
	tNewFormatter.Get<string&>( strReturn2, tFormatter.Size() );

	EA_INF( ( _T("EA_CBufferFormatter contents is %s"), strReturn1.c_str() ) );
	EA_INF( ( _T("TBufferFormatter contents is %s"), strReturn2.c_str() ) );

	getch();

	EA_ExitLog();
	return 0;
}
 * @endcode
 */

#ifndef _EA_CBUFFERFORMATTER_H_
#define _EA_CBUFFERFORMATTER_H_

#include "EA_IBufferFormatter.h"

namespace Earth
{

/**
	## 버퍼포멧터의 문자열 저장 룰 

	// ...
	PutString, GetString 의 리턴값은 NULL을 뺸 문자열의 길이이다 

	// ...
	strPut	- 뮨자열
	sizePut	- Put할 최대 크기 

	strlen( strPut ) < sizePut 이면 버퍼에 널종료문자열이 들어가게 된다 
	strlen( strPut ) >= sizePut 이면 sizePut만큼 넣고 버퍼의 문자열은 널종료문자열이 아니게 된다!! 


	## 문자열 읽을때 주의사항
	@ strlen( strPut ) >= sizePut 경우로 Put됬을때, 
		GetString(..) 함수로 sizePut이상의 크기를 주게 되면 잘못된 작동을 하게 된다 

	그러므로 왠만하면 PutString() 할때의 사이즈와 GetString() 할떄의 사이즈는 같게하는게 좋다 

	by spooky000
*/

/**
 * @brief	Buffer에 원하는 type의 데이타를 추가하거나 얻어올 때 사용한다.
 */
typedef class EA_CBufferFormatter*		EA_PCBufferFormatter;
class EA_CBufferFormatter : public EA_IBufferFormatter
{
public:
	// constructor and destructor
	EA_CBufferFormatter( void ) {}
	EA_CBufferFormatter( const LPVOID IN pStart ) : EA_IBufferFormatter( pStart )	{}
	~EA_CBufferFormatter( void ) {}

	// interface copy from previous buffer formatter
	/**
	 * Put default type data to attached buffer. and update(add) current pointer to type size.
	 */
	inline void	PutS8( const s8 IN chValue );
	inline void	PutU8( const u8 IN byValue );
	inline void	PutS16( const s16 IN sValue );
	inline void	PutU16( const u16 IN wValue );
	inline void	PutS32( const s32 IN nValue );
	inline void	PutU32( const u32 IN dwValue );
	inline void	PutF32( const f32 IN fValue );
	inline void	PutS64( const s64 IN i64Value );
	inline void	PutU64( const u64 IN dw64Value );
	inline void	PutF64( const f64 IN dValue );
	/**
	 * Get default type data from attached buffer. and update(add) current pointer to type size.
	 */
	inline s8	GetS8( void );
	inline u8	GetU8( void );
	inline s16	GetS16( void );
	inline u16	GetU16( void );
	inline s32	GetS32( void );
	inline u32	GetU32( void );
	inline f32	GetF32( void );
	inline s64	GetS64( void );
	inline u64	GetU64( void );
	inline f64	GetF64( void );

	inline void	PutStringA( char* IN szPut );
	inline void	PutStringA( const char* IN szPut );
	inline void	PutStringA( const std::string& IN strPut );
	inline size_t	PutStringA( char* IN szPut, const size_t IN sizePut );
	inline size_t	PutStringA( const char* IN szPut, const size_t IN sizePut );
	inline size_t	PutStringA( const std::string& IN strPut, const size_t IN sizePut );
	inline size_t	PutStringW( wchar_t* IN wszPut )					{ return PutStringW( (const wchar_t*)wszPut );		}
	inline size_t	PutStringW( const wchar_t* IN wszPut );
	inline size_t	PutStringW( const std::wstring& IN wstrPut )				{ return PutStringW( wstrPut.c_str() );			}
	inline size_t	PutStringW( wchar_t* IN wszPut, const size_t IN sizePut )		{ return PutStringW( (const wchar_t*)wszPut, sizePut );	}
	inline size_t	PutStringW( const wchar_t* IN wszPut, const size_t IN sizePut );
	inline size_t	PutStringW( const std::wstring& IN wstrPut, const size_t IN sizePut )	{ return PutStringW( wstrPut.c_str(), sizePut );	}

	inline size_t	GetStringA( char* OUT szGet, const size_t IN sizeGet );
	inline size_t	GetStringA( std::string& OUT strGet, const size_t IN sizeGet );
	inline size_t	GetStringW( wchar_t* OUT wszGet, const size_t IN sizeGet );
	inline size_t	GetStringW( std::wstring& OUT wstrGet, const size_t IN sizeGet );
	inline size_t	GetStringLengthA( void );
	inline size_t	GetStringLengthW( void );

#ifdef _EA_UNITTEST
	static inline BOOL Test( void );
#endif	// _EA_UNITTEST
};

// Put into Buffer formatter
void EA_CBufferFormatter::PutS8( const s8 IN chValue )
{
	*((s8 *)m_pCurrent) = chValue;
	m_pCurrent++;
}

void EA_CBufferFormatter::PutU8( const u8 IN byValue )
{
	*((u8 *) m_pCurrent) = byValue;
	m_pCurrent++;
}

void EA_CBufferFormatter::PutS16( const s16 IN sValue )
{
	*((s16 *) m_pCurrent) = sValue;
	m_pCurrent += sizeof( s16 );
}

void EA_CBufferFormatter::PutU16( const u16 IN wValue )
{
	*((u16 *) m_pCurrent) = wValue;
	m_pCurrent += sizeof( u16 );
}

void EA_CBufferFormatter::PutS32( const s32 IN nValue )
{
	*((s32 *) m_pCurrent) = nValue;
	m_pCurrent += sizeof( s32 );
}

void EA_CBufferFormatter::PutU32( const u32 IN dwValue )
{
	*((u32 *) m_pCurrent) = dwValue;
	m_pCurrent += sizeof( u32 );
}

void EA_CBufferFormatter::PutF32( const f32 IN fValue )
{
	*((f32 *) m_pCurrent) = fValue;
	m_pCurrent += sizeof( f32 );
}

void EA_CBufferFormatter::PutS64( const s64 IN i64Value )
{
	*((s64 *) m_pCurrent) = i64Value;
	m_pCurrent += sizeof( s64 );
}

void EA_CBufferFormatter::PutU64( const u64 IN dw64Value )
{
	*((u64 *) m_pCurrent) = dw64Value;
	m_pCurrent += sizeof( u64 );
}

void EA_CBufferFormatter::PutF64( const f64 IN f64Value )
{
	*((f64 *) m_pCurrent) = f64Value;
	m_pCurrent += sizeof( f64 );
}

// Get from Buffer formatter
s8 EA_CBufferFormatter::GetS8( void )
{
	register s8 chValue;

	chValue = *((s8 *)m_pCurrent);
	m_pCurrent++;
	return chValue;
}

u8 EA_CBufferFormatter::GetU8( void )
{
	register u8 byValue;

	byValue = *((u8 *) m_pCurrent);
	m_pCurrent++;
	return byValue;
}

s16 EA_CBufferFormatter::GetS16( void )
{
	register s16 sValue;

	sValue = *((s16 *) m_pCurrent);
	m_pCurrent += sizeof( s16 );
	return sValue;
}

u16 EA_CBufferFormatter::GetU16( void )
{
	u16 wValue;

	wValue = *((u16 *) m_pCurrent);
	m_pCurrent += sizeof( u16 );
	return wValue;
}

s32 EA_CBufferFormatter::GetS32( void )
{
	s32 nValue;

	nValue = *((s32 *) m_pCurrent);
	m_pCurrent += sizeof( s32 );
	return nValue;
}

u32 EA_CBufferFormatter::GetU32( void )
{
	u32 dwValue;

	dwValue = *((u32 *) m_pCurrent);
	m_pCurrent += sizeof( u32 );
	return dwValue;
}

f32 EA_CBufferFormatter::GetF32( void )
{
	f32 fValue;

	fValue = *((f32 *) m_pCurrent);
	m_pCurrent += sizeof( f32 );
	return fValue;
}

s64 EA_CBufferFormatter::GetS64( void )
{
	s64 i64Value;

	i64Value = *((s64 *) m_pCurrent);
	m_pCurrent += sizeof( s64 );
	return i64Value;
}

u64 EA_CBufferFormatter::GetU64( void )
{
	u64 dw64Value;

	dw64Value = *((u64 *) m_pCurrent);
	m_pCurrent += sizeof( u64 );
	return dw64Value;
}

f64 EA_CBufferFormatter::GetF64( void )
{
	f64 d64Value;

	d64Value = *((f64 *) m_pCurrent);
	m_pCurrent += sizeof( f64 );
	return d64Value;
}

// Put string into Buffer formatter
void EA_CBufferFormatter::PutStringA( char* IN szPut )
{
	while ( *szPut ) 
		*((char*)m_pCurrent++) = *(szPut++);
	*((char*)m_pCurrent++) = '\0';
}

void EA_CBufferFormatter::PutStringA( const char* IN szPut )
{
	while ( *szPut ) 
		*((char*)m_pCurrent++) = *((char*)szPut++);
	*((char*)m_pCurrent++) = '\0';
}

void EA_CBufferFormatter::PutStringA( const std::string& IN strPut )
{
	memcpy( (LPVOID) m_pCurrent, (LPVOID) strPut.c_str(), strPut.size() + 1 );
	m_pCurrent += (strPut.size() + 1);
}

size_t EA_CBufferFormatter::PutStringA( char* IN szPut, const size_t IN sizePut )
{
	int   nMaxLen	= static_cast<int>( sizePut );
	BYTE *pPtr	= m_pCurrent;
	while ( (nMaxLen-- > 0) && *szPut )
		*((char*)m_pCurrent++) = *(szPut++);
	if ( nMaxLen >= 0 ) {
		*((char*)m_pCurrent++) = '\0';
		return (size_t)(m_pCurrent - pPtr - 1);	// remove 1 byte of pending '\0' from return value
	} else
		return (size_t)(m_pCurrent - pPtr);
}

size_t EA_CBufferFormatter::PutStringA( const char* IN szPut, const size_t IN sizePut )
{
	int   nMaxLen	= static_cast<int>( sizePut );
	BYTE *pPtr	= m_pCurrent;
	while ( (nMaxLen-- > 0) && *szPut )
		*((char*)m_pCurrent++) = *(szPut++);
	if ( nMaxLen >= 0 ) {
		*((char*)m_pCurrent++) = '\0';
		return (size_t)(m_pCurrent - pPtr - 1);	// remove 1 byte of pending '\0' from return value
	} else
		return (size_t)(m_pCurrent - pPtr);
}

size_t EA_CBufferFormatter::PutStringA( const std::string& IN strPut, const size_t IN sizePut )
{
	if( strPut.size() < sizePut ) {
		memcpy( (LPVOID) m_pCurrent, (LPVOID) strPut.c_str(), strPut.size() + 1 );
		m_pCurrent += (strPut.size() + 1);
		return (strPut.size() + 1);
	}
	memcpy( (LPVOID) m_pCurrent, (LPVOID) strPut.c_str(), sizePut );
	m_pCurrent += sizePut;
	return sizePut;
}

size_t EA_CBufferFormatter::PutStringW( const wchar_t* IN wszPut )
{
	const wchar_t*	pCurrent = wszPut;
	size_t		sizeStringLength = 0;
	while( ++sizeStringLength && *(pCurrent++) );
	sizeStringLength *= sizeof( wchar_t );

	PutBINARY( (const LPVOID)wszPut, sizeStringLength );

	return sizeStringLength;
}

size_t EA_CBufferFormatter::PutStringW( const wchar_t* IN wszPut, const size_t IN sizePut )
{
	const wchar_t*	pCurrent = wszPut;
	size_t		sizeStringLength = 0;
	while( ++sizeStringLength < sizePut && *(pCurrent++) );
	sizeStringLength *= sizeof( wchar_t );

	PutBINARY( (const LPVOID)wszPut, sizeStringLength );

	return sizeStringLength;
}

// Get string from Buffer formatter
size_t EA_CBufferFormatter::GetStringA( char* OUT szGet, const size_t IN sizeGet )
{
	char* pPtr	= szGet;
	int   nMaxLen	= static_cast<int>( sizeGet );

	while ( (nMaxLen-- > 0) && *m_pCurrent )
		*(pPtr++) = *((char*)m_pCurrent++);
	*(pPtr) = '\0';
	if ( nMaxLen >= 0 )
		m_pCurrent++;
	return (size_t)(pPtr - szGet);
}

size_t EA_CBufferFormatter::GetStringA( std::string& OUT strGet, const size_t IN sizeGet )
{
	strGet.assign( (char*) m_pCurrent, 0, sizeGet );
	if ( strGet.size() < sizeGet )
		m_pCurrent += strGet.size() + 1;
	else
		m_pCurrent += sizeGet;
	return (size_t)strGet.size();
}

size_t EA_CBufferFormatter::GetStringW( wchar_t* OUT wszGet, const size_t IN sizeGet )
{
	wchar_t* pCurrent = (wchar_t*)m_pCurrent;
	size_t	sizeStringLength = 0;
	while( ++sizeStringLength < sizeGet && *(pCurrent++) );
	size_t	sizeStringBytes = sizeStringLength * sizeof( wchar_t );

	size_t	sizeRead = GetBINARY( wszGet, sizeStringBytes );
	if( L'\0' != wszGet[ sizeStringLength - 1 ] ) {
		wszGet[ sizeStringLength ] = L'\0';
		sizeRead += sizeof( wchar_t );
	}
	return sizeRead;
}

size_t EA_CBufferFormatter::GetStringW( std::wstring& OUT wstrGet, const size_t IN sizeGet )
{
	wstrGet.assign( (wchar_t*) m_pCurrent, 0, sizeGet );
	if( wstrGet.size() < sizeGet )
		m_pCurrent += ( wstrGet.size() + 1 ) * sizeof( wchar_t );
	else
		m_pCurrent += sizeGet * sizeof( wchar_t );
	return (size_t)wstrGet.size() * sizeof( wchar_t );
}

size_t EA_CBufferFormatter::GetStringLengthA( void )
{
	return strlen( (const char *) m_pCurrent );
}

size_t EA_CBufferFormatter::GetStringLengthW( void )
{
	return wcslen( (const wchar_t *) m_pCurrent );
}

#ifdef _EA_UNITTEST
BOOL EA_CBufferFormatter::Test( void )
{
	char			TempBuffer[MA_MAX_PATH + 1];
	EA_CBufferFormatter	cFormatter(TempBuffer);

	cFormatter.PutS8( 1 );
	cFormatter.PutU8( 2 );
	cFormatter.PutS16( 3 );
	cFormatter.PutU16( 4 );
	cFormatter.PutS32( 5 );
	cFormatter.PutU32( 6 );
	cFormatter.PutF32( 7.0 );
	cFormatter.PutS64( 8 );
	cFormatter.PutU64( 9 );
	cFormatter.PutF64( 10 );

	cFormatter.PutString( "11" );
	std::string	strTest1( "12" );
	cFormatter.PutString( strTest1 );
	std::string	strTest2( "1357" );
	cFormatter.PutString( strTest2, 2 );

	cFormatter.Dump();	// dump contents in the buffer formatter

	/*s8	s8Value		=*/ cFormatter.GetS8();
	/*u8	u8Value		=*/ cFormatter.GetU8();
	/*s16	s16Value	=*/ cFormatter.GetS16();
	/*u16	u16Value	=*/ cFormatter.GetU16();
	/*s32	s32Value	=*/ cFormatter.GetS32();
	/*u32	u32Value	=*/ cFormatter.GetU32();
	/*f32	f32Value	=*/ cFormatter.GetF32();
	/*s64	s64Value	=*/ cFormatter.GetS64();
	/*u64	u64Value	=*/ cFormatter.GetU64();
	/*f64	f64Value	=*/ cFormatter.GetF64();

	char		StringBuffer[MA_MAX_PATH + 1];
	cFormatter.GetString( StringBuffer, MA_MAX_PATH );
	std::string	strGet;
	cFormatter.GetString( strGet, MA_MAX_PATH );

	cFormatter.Dump();	// dump contents in the buffer formatter

	return TRUE;
}
#endif	// _EA_UNITTEST

};

#endif // _EA_CBUFFERFORMATTER_H_
