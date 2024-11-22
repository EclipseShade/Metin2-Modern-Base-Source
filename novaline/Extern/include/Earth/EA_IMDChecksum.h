/**
 * @file	EA_IMDChecksum.h
 * @brief	Baekdu Checksum Library
 * @author	bugmail (bugmail@buddygames.co.kr)
 *
 * @version	2005/08/12 bugmail - first release
 */

#ifndef	_IMDCHECKSUM_H_
#define	_IMDCHECKSUM_H_

#include "EA_ChecksumUtility.h"

_EA_NAMESPACE_BEGIN

const	u32	SIZE_MD_RESULT	= 16;
/**
 * @brief	MD4와 MD5의 Interface및 데이터를 통일하기 위한 Interface Class
 * @author	bugmail (bugmail@buddygames.co.kr)
 * @remark	MD5는 MD4의 무결성을 조금 더 높인 알고리즘이기때문에 Interface나 데이터를 맞추기가 쉽다.
		몇가지 불필요한 중복 코딩을 없애기 위한 Class
 */
class	EA_IMDChecksum
{
public:
	/**
	 * @brief	MD계열의 Checksum을 사용할때 내부에서 사용하는 구조체.
	 * @author	bugmail (bugmail@buddygames.co.kr)
	 */
	typedef	struct	EA_tagMDContext
	{
		u32 		au32State[4];		// buf
		u32 		au32Count[2];		// number of bits
		BYTE		abyInput[64];
	} MDCONTEXT, *LPMDCONTEXT;

	/**
	 * @brief	기본생성자.
	 * @author	bugmail (bugmail@buddygames.co.kr)
	 */
	EA_IMDChecksum()					{}
	/**
	 * @brief	소멸자.
	 * @author	bugmail (bugmail@buddygames.co.kr)
	 */
	virtual	~EA_IMDChecksum()				{}

	/**
	 * @brief	Checksum작업을 시행하기 전에 초기화하는 함수.
	 * @author	bugmail (bugmail@buddygames.co.kr)
	 */
	virtual	void	InitChecksum()					= 0;

	/**
	 * @brief	값이 삽입된 pvData를 이용하여 u32DataLen만큼 Checksum을 얻어내는 작업을 진행한다.
	 * @author	bugmail (bugmail@buddygames.co.kr)
	 * @param[in]	pvData		Checksum을 얻어낼 데이터
	 * @param[in]	u32DataLen	데이터의 길이. 정확한 길이를 넣어야 정확한 데이터를 얻어낼 수 있다.
	 */
	virtual	void	UpdateChecksum( LPVOID pvData, u32 u32DataLen )	= 0;

	/**
	 * @brief	Checksum class를 재초기화 시키는 함수
	 * @author	bugmail (bugmail@buddygames.co.kr)
	 */
	virtual	void	ResetChecksum()					= 0;

	/**
	 * @brief	Checksum을 획득한다.
	 * @author	bugmail (bugmail@buddygames.co.kr)
	 * @param[out]	pu8Checksum	16개의 BYTE에 정보를 얻어온다.
	 */
	virtual	void	GetChecksum( u8 *pu8Checksum )			= 0;
};

_EA_NAMESPACE_END

#endif //_IMDCHECKSUM_H_