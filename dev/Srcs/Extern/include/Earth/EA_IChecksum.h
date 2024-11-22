#ifndef	_EA_ICHECKSUM_H_
#define	_EA_ICHECKSUM_H_

_EA_NAMESPACE_BEGIN

/**
 * @brief	CRC32와 Adler32의 Interface class
 */
class EA_IChecksum
{
public:
	/**
	 * @brief	Checksum작업을 시행하기 전에 초기화하는 함수.
	 */
	virtual	void	InitChecksum()					= 0;

	/**
	 * @brief	값이 삽입된 pvData를 이용하여 u32DataLen만큼 Checksum을 얻어내는 작업을 진행한다.
	 * @param[in]	pvData		Checksum을 얻어낼 데이터
	 * @param[in]	DataLen		데이터의 길이
	 */
	virtual	void	UpdateChecksum( LPVOID pvData, MA_SIZE DataLen )	= 0;

	/**
	 * @brief	Checksum class를 재초기화 시키는 함수
	 */
	virtual	void	ResetChecksum()					= 0;

	/**
	 * @brief	Checksum을 획득한다.
	 * @return	얻어낸 Checksum.
	 */
	virtual	DWORD	GetChecksum()					= 0;
};

_EA_NAMESPACE_END

#endif /* !_EA_ICHECKSUM_H_ */
