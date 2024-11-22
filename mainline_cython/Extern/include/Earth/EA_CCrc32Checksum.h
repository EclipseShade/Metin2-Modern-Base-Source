#ifndef	_EA_CRC32_CHECKSUM_H_
#define	_EA_CRC32_CHECKSUM_H_

#include "EA_IChecksum.h"

_EA_NAMESPACE_BEGIN

/**
 * @brief	CRC32를 얻어내는 클래스
 * @remark	CRC32와 Adler32는 Interface와 Checksum의 결과값이 완전이 똑같기 때문에 이와 같은 Interface class를 이용하여
		Interface를 맞추는 방법을 꾀한다.

		\b Example
 * @code
DWORD		dwResult
u8		pTest[ 8 ]	= { 0x46, 0x45, 0x41, 0x54, 0x55, 0x52, 0x45, 0x20 };

EA_CCrc32Checksum	ccrc32;
ccrc32.InitChecksum();
ccrc32.UpdateChecksum( pTest, sizeof( pTest ) );

dwResult = ccrc32.GetChecksum();
 * @endcode
 */
class	EA_CCrc32Checksum : public EA_IChecksum
{
public:
	EA_CCrc32Checksum();
	virtual	~EA_CCrc32Checksum();
	
	void	InitChecksum();
	void	UpdateChecksum(LPVOID pvData, MA_SIZE DataLen);
	void	ResetChecksum()					{ InitChecksum();	}
	DWORD	GetChecksum()					{ return ~m_dwCrc32;	}

	static DWORD	sGetFileChecksum( MA_LPCTSTR tszFileName, MA_FSIZE* psizeFile = NULL );

#ifdef	_EA_UNITTEST
	BOOL	Test();
#endif
protected:
	DWORD		m_dwCrc32;
};

_EA_NAMESPACE_END

#endif /* !_EA_CRC32_CHECKSUM_H_ */
