/**
 * @file	EA_CURLEncode.h
 * @brief	URL encoding/decoding class
 * @author	Standil (cpascal@cpascal.net)
 *
 * @version	2006/03/24 cpascal - First release
 */

#ifndef	_EA_CURLENCODE_H_
#define	_EA_CURLENCODE_H_

_EA_NAMESPACE_BEGIN

/**
 * @brief	TCHAR형 문자열을 3글자씩 잘라 4의 크기로 변형시키는 클래스
 * @remark	설명을 용이하게 하기 위하여 멤버함수 설명은 ANSI를 기준으로 설명하겠음.
 */
class EA_CURLEncode
{
protected:
	enum	{
		ENCODE_LEN	= 3,
		DECODE_LEN	= 4
	};

public:
	/**
	 * @brief	생성자
	 */
	EA_CURLEncode();
	/**
	 * @brief	소멸자
	 */
	~EA_CURLEncode();

	/**
	 * @brief	pbySource를 3바이트씩 잘라 4바이트로 Encoding 하는 함수
	 * @param[out]	tszTarget	Encoding된 값이 저장될 버퍼의 포인터
	 * @param[in]	sizeTarget	tszTarget의 유효길이
	 * @param[in]	pbySource	Encoding될 문자열
	 * @param[in[	sizeSource	pbySource의 유효길이
	 * @return	Encode된 사이즈
	 */
	size_t	Encode( LPTSTR OUT tszTarget, size_t IN sizeTarget, LPCTSTR IN tszSource, size_t IN sizeSource );

	/**
	 * @brief	tszSource를 4바이트씩 잘라 3바이트로 Decoding하는 함수
	 * @param[out]	tszTarget	Decoding된 값이 저장될 버퍼의 포인터
	 * @param[in]	sizeTarget	tszTarget의 유효길이
	 * @param[in]	tszSource	Decoding될 문자열
	 * @param[in]	sizeSource	tszSource의 유효길이
	 * @return	Decode된 사이즈
	 */
	size_t	Decode( LPTSTR OUT tszTarget, size_t IN sizeTarget, LPCTSTR IN tszSource, size_t IN sizeSource );

	/**
	 * @brief	Encoding에 필요한 버퍼의 길이를 미리 계산해준다.
	 * @param[in]	sizeDecoded	Decode되어있는 문자열의 길이
	 * @return	Encoding시 필요한 버퍼의 길이를 반환
	 */
	size_t	CalculateEncodeLength( size_t IN sizeDecoded );

	/**
	 * @brief	Decoding에 필요한 버퍼의 길이를 미리 계산해준다.
	 * @param[in]	sizeEncoded	Encode되어있는 문자열의 길이
	 * @return	Decoding시 필요한 버퍼의 길이를 반환
	 */
	size_t	CalculateDecodeLength( size_t IN sizeEncoded );

#ifdef	_EA_UNITTEST
	BOOL	Test();
#endif
protected:
	static	BYTE	m_au8MapSafe[];
	static	TCHAR	m_tszHex[];
};

_EA_NAMESPACE_END

#endif /* !_EA_CURLENCODE_H_ */
