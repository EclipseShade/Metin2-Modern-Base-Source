/**
 * @file	EA_CLowFile.h
 * @brief	Earth low-level file class
 * @author	Standil (cpascal@cpascal.net)
 *
 * @version	2005/07/19 cpascal - First release
 */

#ifndef _EA_CLOWFILE_H_
#define _EA_CLOWFILE_H_

#include "EA_IO.h"
//#include "EA_IFileSystem.h"
#include <time.h>

namespace Earth
{

class EA_CLowFile
{
public:
	/// LowFile 생성자
	EA_CLowFile();

	/// LowFile 파괴자
	~EA_CLowFile();

	/// 파일 열기
	/**
	 * @param[in] szFilename Open할 파일명
	 * @param[in] enOpenFlags Open 모드
	 *
	 * @return 파일 열기에 성공하면 TRUE
	 */
	BOOL Open( LPCTSTR szFilename, EA_EOpenFlags eOpenFlags = modeRead );

	/**
	 * @brief	Variable argument list를 이용해서 file을 open 한다.
	 * @param[in]	szFormat	Open할 filen name의 format
	 * @parma[in]	pArgs		va_list
	 * @param[in]	enOpenFlags	Open 모드
	 *
	 * @return 파일 열기에 성공하면 TRUE
	 */
	BOOL Openv( LPCTSTR IN tszFormat, va_list IN pArgs, EA_EOpenFlags IN eOpenFlags = modeRead );

	/// 읽기전용 모드로 파일 열기(Formatted Filename 지원)
	/**
	 * @param[in] szFilename Open할 Formatted Filename
	 *
	 * @return 파일 열기에 성공하면 TRUE
	 */
	BOOL OpenToReadf( LPCTSTR szFilename, ... );

	/// 쓰기전용 모드로 파일 열기(Formatted Filename 지원)
	/**
	 * @param[in] szFilename Open할 Formatted Filename
	 *
	 * @return 파일 열기에 성공하면 TRUE
	 */
	BOOL OpenToWritef( LPCTSTR szFilename, ... );

	/// 생성 모드로 파일 열기(Formatted Filename 지원)
	/**
	 * @param[in] szFilename Open할 Formatted Filename
	 *
	 * @return 파일 열기에 성공하면 TRUE
	 */
	BOOL OpenToCreatef( LPCTSTR szFilename, ... );

	/// 파일 닫기
	void Close( void );

	/// 파일이 열려있는지 확인
	/**
	 * @return 열려있으면 TRUE, 열려있지 않으면 FALSE
	 */
	BOOL IsOpened( void )			{ return (m_hFile != INVALID_HANDLE_VALUE) && (m_hFile != NULL); }

	/// 열린 파일이름 얻기
	LPCTSTR	GetFileName( void ) const	{ return m_szFilename; }

	/// 파일 길이 얻기
	/**
	 * @return 파일 길이를 반환한다.
	 */
	MA_FSIZE Size( void ) const;

	/// 현재 위치 얻기
	/**
	 * @return 현재의 파일 위치를 반환한다.
	 */
	MA_FSIZE GetFilePointer( void ) const;

	/// 파일 읽기
	size_t Read( LPVOID lpBuffer, size_t sizeToRead );

	/// 파일 쓰기
	size_t Write( LPCVOID lpBuffer, size_t sizeToWrite );

	/// 위치 이동
	MA_FSIZE Seek( MA_FSIZE sizeBytesToMove , EA_ESeekFlags eMoveMethod );

	/// Flush
	BOOL Flush( void );

	/// 끝인지 검사
	BOOL IsEOF( void ) const;

	/// FileTime(Write) 얻기
	time_t GetTime( void );

	/// FileTime(Write) 쓰기
	BOOL   SetTime( time_t timeSet );

	/// 파일 속성 얻어오기
	u32 GetAttribute();

	// NULL처리를 하고 HANDLE리턴
	HANDLE	GetSafeHandle() const;

	// HANDLE 바로 리턴
	HANDLE	GetHandle() const;

	/// 파일 존재여부 검사 (인자로 파일이름을 받음)
	static BOOL sAccess( LPCTSTR szFilename );

	/// 파일 길이 얻기 (인자로 파일이름을 받음)
	static MA_FSIZE sSize( LPCTSTR szFilename );

	/// 파일 읽기 (인자로 파일이름을 받음)
	static MA_SIZE sRead( LPCTSTR szFilename, LPVOID lpBuffer, size_t sizeBytesToRead );

	/// 파일 쓰기 (인자로 파일이름을 받음)
	static MA_SIZE sWrite( LPCTSTR szFilename, LPVOID lpBuffer, size_t sizeBytesToRead );

	/// 파일 속성 얻어오기
	static u32 sGetAttribute( LPCTSTR tszFileName );

private:
	/// 열린 파일 핸들
	HANDLE		m_hFile;

	/// 파일이름
	MA_TCHAR	m_szFilename[MA_MAX_PATH];
};

typedef EA_CLowFile*	EA_PCLowFile;

};

#endif /* _EA_CLOWFILE_H_ */

