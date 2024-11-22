/**
 * @file	EA_IBufferFormatter.h
 * @brief	Earth Buffer formatter header
 * @author	cpascal (cpascal@@buddygames.co.kr)
 * @author	cppis (cppeins@buddygames.co.kr)

 * @version	2005/08/04 cppis - First release
 */

#ifndef _EA_IBUFFERFORMATTER_H_
#define _EA_IBUFFERFORMATTER_H_

#include "EA_Log.h"

namespace Earth
{

/**
 * @brief	Buffer에 원하는 type의 데이타를 추가하거나 얻어올 때 사용한다.
 */
class EA_IBufferFormatter
{
public:
	// constructor and destructor
	EA_IBufferFormatter( void )			{ Reset();	    }
	EA_IBufferFormatter( const LPVOID IN pStart )	{ Attach( pStart ); }
	~EA_IBufferFormatter( void )			{}

	inline LPBYTE	Start( void ) const;
	inline LPBYTE	Current( void ) const;
	/**
	 * Attaches start position and current position to pStart
	 * @param[in]	pStart is the buffer pointer to attach
	 */
	inline void	Attach( const LPVOID IN pStart );
	/**
	 * Detaches start position and current position
	 */
	inline void	Detach( void );
	/**
	 * Set current position to start position
	 */
	inline void	Reset( void );

	/**
	 * Get size of contents( pCurrent - pStart )
	 * @return	size of contents
	 */
	inline size_t	Size( void ) const;
	/**
	 * Skip current position to size
	 * @return	the position before skip
	 */
	inline LPVOID	Skip( const size_t IN sizeSkip );

	/**
	 * Dump contents
	 */
	inline void	Dump( void );


	/**
	 * Put binary into Buffer formatter
	 * @param	pBuffer is buffer pointer contains binary data, sizeBuffer is binary size
	 * @return	the position before skip
	 */
	inline void	PutBINARY( const LPVOID IN pBuffer, const size_t IN sizeBuffer );
	/**
	 * Get binary from Buffer formatter
	 * @param	pBuffer is buffer pointer for output, sizeBuffer is buffer size
	 * @return	size of binary, we got
	 */
	inline size_t	GetBINARY( LPVOID OUT pBuffer, const size_t IN sizeBuffer );

protected:
	BYTE*		m_pStart;
	BYTE*		m_pCurrent;
};
typedef class EA_IBufferFormatter*		EA_PIBufferFormatter;

LPBYTE EA_IBufferFormatter::Start( void ) const
{
	return m_pStart;
}

LPBYTE EA_IBufferFormatter::Current( void ) const
{
	return m_pCurrent;
}

void EA_IBufferFormatter::Attach( const LPVOID IN pStart )
{
	m_pStart = (BYTE*)pStart; m_pCurrent = (BYTE*)pStart;
}

void EA_IBufferFormatter::Detach( void )
{
	m_pStart = m_pCurrent = NULL;
}

void EA_IBufferFormatter::Reset( void )
{
	m_pCurrent = m_pStart;
}

size_t EA_IBufferFormatter::Size( void ) const
{
	return static_cast<size_t>( m_pCurrent - m_pStart );
}

LPVOID EA_IBufferFormatter::Skip( const size_t IN sizeSkip )
{
	BYTE*	pReturn = m_pCurrent;
	m_pCurrent += sizeSkip;
	return pReturn;
}

void EA_IBufferFormatter::PutBINARY( const LPVOID IN pBuffer, const size_t IN sizeBuffer )
{
	memcpy( (LPVOID)m_pCurrent, pBuffer, sizeBuffer );
	m_pCurrent += sizeBuffer;
}

size_t EA_IBufferFormatter::GetBINARY( LPVOID OUT pBuffer, const size_t IN sizeBuffer )
{
	memcpy( pBuffer, (LPVOID) m_pCurrent, sizeBuffer );
	m_pCurrent += sizeBuffer;
	return sizeBuffer;
}

void EA_IBufferFormatter::Dump( void )
{
//	EA_DMP( (DWORD64)Start(), Size(), TRUE );
}

};

#endif // _EA_IBUFFERFORMATTER_H_
