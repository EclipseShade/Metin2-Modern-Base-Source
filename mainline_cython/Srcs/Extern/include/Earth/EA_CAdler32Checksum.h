#ifndef	_EA_ADLER32CHECKSUM_H_
#define	_EA_ADLER32CHECKSUM_H_

#include "EA_IChecksum.h"

_EA_NAMESPACE_BEGIN

/**
 * @brief	Adler32 Checksum을 얻어내는 클래스
 * @author	bugmail (bugmail@buddygames.co.kr)
 * @remark	CRC32와 Adler32는 Interface와 Checksum의 결과값이 완전이 똑같기 때문에 이와 같은 Interface class를 이용하여
		Interface를 맞추는 방법을 꾀한다.

		\b Example
 * @code
DWORD			dwResult
u8			pTest[ 8 ]	= { 0x46, 0x45, 0x41, 0x54, 0x55, 0x52, 0x45, 0x20 };

EA_CAdler32Checksum	adler32;
adler32.InitChecksum();
adler32.UpdateChecksum( pTest, sizeof( pTest ) );

dwResult = adler32.GetChecksum();
 * @endcode
 */
class	EA_CAdler32Checksum : public EA_IChecksum
{
public:
	EA_CAdler32Checksum()			{}
	virtual	~EA_CAdler32Checksum()		{}

	void	InitChecksum()			{ m_u32Checksum = 0;	}
	void	UpdateChecksum( LPVOID pvData, u32 u32DataLen );
	void	ResetChecksum()					{ InitChecksum();	}
	DWORD	GetChecksum()					{ return m_u32Checksum;	}

#ifdef	_EA_UNITTEST
	BOOL	Test();
#endif

protected:
	u32		m_u32Checksum;
};

_EA_NAMESPACE_END

#endif /* !_EA_ADLER32CHECKSUM_H_ */
