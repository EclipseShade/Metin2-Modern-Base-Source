#ifndef _EL_POLYGON2D_H_
#define _EL_POLYGON2D_H_

#include "TPos.h"

class EL_CPolygon2D
{
public:
	EL_CPolygon2D();
	~EL_CPolygon2D();

	EL_BOOL		Attach( LPVOID pvBuffer );
	LPVOID		Detatch( void );
	void		Free( void );
	EL_BOOL		Set( LPVOID pvBuffer );

	EL_BOOL		CheckPointInPolygon( EL_FPOS2& cPosition );

protected:
	DWORD		m_dwVerticles;			//< Vertex 갯수
	EL_FPOS2*	m_apcVertex;			//< Vertex 묶음 포인터
	LPVOID		m_pvBuffer;				//< 할당된 메모리 포인터
	DWORD		m_dwReserved;			//< 할당된 Vertex 갯수
	EL_BOOL		m_bBufferOwned;			//< 메모리 소유 여부
};

#endif /* !_EL_POLYGON2D_H_ */
