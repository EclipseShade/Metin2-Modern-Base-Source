/**
 * @file	EA_CSHA1Checksum.h
 * @brief	Earth SHA1 class
 * @author	Standil (cpascal@cpascal.net)
 *
 * @version	2010/03/16 Standil - first release
 */

#ifndef	_EA_CSHA1CHECKSUM_H_
#define	_EA_CSHA1CHECKSUM_H_

#include "EA_IMDChecksum.h"

_EA_NAMESPACE_BEGIN

const	u32	SIZE_SHA1_RESULT	= 20;

class	EA_CSHA1Checksum : public EA_IMDChecksum
{
public:
	typedef	struct	EA_tagSHA1Context
	{
		u32 		au32State[5];	// buf
		u32 		au32Count[2];	// number of bits
		BYTE		abyInput[64];
	} SHA1CONTEXT, *LPSHA1CONTEXT;

	EA_CSHA1Checksum()							{}
	virtual	~EA_CSHA1Checksum()					{}

	void	InitChecksum();
	void	UpdateChecksum( LPVOID pvData, u32 u32DataLen);
	void	ResetChecksum()					{ InitChecksum();	}
	void	GetChecksum( u8 *pu8Checksum );
#ifdef	_EA_UNITTEST
	BOOL	Test();
#endif
protected:
	void	Transform( u32 *pu32Block );

	SHA1CONTEXT	m_stContext;
};

_EA_NAMESPACE_END

#endif /* _EA_CSHA1CHECKSUM_H_ */