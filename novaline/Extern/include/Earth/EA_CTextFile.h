/**
 * @file	EA_CTextFile.h
 * @brief	Earth low-level file class
 * @author	Standil (cpascal@cpascal.net)
 *
 * @version	2005/07/19 cpascal - First release
 */

#ifndef _EA_CTEXTFILE_H_
#define _EA_CTEXTFILE_H_

#include "EA_IO.h"
#include <Mantle/MA_STLVector.h>

_EA_NAMESPACE_BEGIN

/**
 * @brief	텍스트 파일 입출력 클래스.
 */
class EA_CTextFile
{
public:
	enum EEncodingType
	{
		eET_AUTOTYPE,
		eET_BINARY,
		eET_ANSI,
		eET_UNICODE,		// CodePage 1200
		eET_UNICODE_BE,		// CodePage 1201
		eET_UTF32_LE,
		eET_UTF32_BE,
		eET_UTF8
	};

	/// TextFile 생성자
	EA_CTextFile();

	/// TextFile 파괴자
	~EA_CTextFile();

	/// 파일 열기
	/**
	 * @param[in] szFilename Open할 파일명
	 * @param[in] enOpenFlags Open 모드
	 *
	 * @return 파일 열기에 성공하면 TRUE
	 */
	EA_BOOL Open( LPCTSTR szFilename, EA_EOpenFlags eOpenFlags = modeRead, EEncodingType eEncoding = eET_AUTOTYPE );

	EA_BOOL OpenFromMemory( );

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

	// Flush
	EA_BOOL Flush( void );

	/// 파일 저장
//	EA_BOOL Save( void );

	/// 파일 닫기
	void Close( void );

	/// 파일이 열려있는지 확인
	/**
	 * @return 열려있으면 TRUE, 열려있지 않으면 FALSE
	 */
	BOOL IsOpened( void )			{ return (m_hFile != INVALID_HANDLE_VALUE) && (m_hFile != NULL); }

	/// 열린 파일이름 얻기
	LPCTSTR	GetFileName( void ) const	{ return m_szFilename; }

	/// 컨텐츠 길이 얻기
	/**
	 * @return 컨텐츠 길이를 반환한다.
	 */
	EA_SIZE GetContentsLength( void ) const	{ return m_sizeContents; }

	/// 현재 위치 얻기
	/**
	 * @return 현재의 파일 위치를 반환한다.
	 */
	MA_LPCTSTR GetContents( void ) const	{ return m_ptszContents; }

	/// 컨텐츠 설정
	EA_BOOL SetContents( MA_LPCTSTR tszContents, EA_SIZE sizeContents );

	/// 라인 읽기
	EA_SSIZE ReadLine( MA_LPTSTR tszLine, EA_SIZE sizeLine, EA_BOOL bSkipFullLine = EA_FALSE );

	/// 라인 읽기
	EA_SIZE ReadLineRaw( MA_LPTSTR tszLine, EA_SIZE sizeLine, EA_BOOL bSkipFullLine = EA_FALSE );

	/// 라인 쓰기
	EA_SIZE Write( MA_LPCTSTR tszLine, EA_SIZE sizeLine = -1 );
	EA_SIZE WriteLine( MA_LPCTSTR tszLine, EA_SIZE sizeLine = -1 );

	/// 라인 이동
	EA_SIZE Seek( LONG dwCharactersToMove , EA_ESeekFlags eMoveMethod );

	/// 끝인지 검사
	BOOL IsEOF( void ) const;

private:
	EEncodingType			CheckEncodingType( MA_LPCBYTE szBuffer, EA_SIZE sizeBuffer );
	EEncodingType			CheckBOM( MA_LPCBYTE szBuffer, EA_SIZE sizeBuffer );
	EA_BOOL					WriteBOM( EEncodingType eType );
	EA_BOOL					Load();
	EA_BOOL					Load( MA_PCVOID pvBuffer, EA_SIZE sizeBuffer );
	EA_BOOL					CalculateLines( void );
	EA_INT					GetLineFromPosition( EA_SIZE sizePosition );

	/// 열린 파일 핸들
	HANDLE					m_hFile;

	/// 파일이름
	MA_TCHAR				m_szFilename[MA_MAX_PATH];

	MA_TCHAR*				m_ptszContents;
	EA_SIZE					m_sizeContentsBegin;
	EA_SIZE					m_sizeContents;
	EA_SIZE					m_sizeCurrentPosition;
	EA_BOOL					m_bModified;
	EEncodingType			m_eEncodingType;
	std::vector<EA_SIZE>	m_vecLinePositions;
};

typedef EA_CTextFile*	EA_PCTextFile;

_EA_NAMESPACE_END

#endif /* _EA_CTEXTFILE_H_ */