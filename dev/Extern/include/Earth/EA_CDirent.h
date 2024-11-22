/**
 * @file	EA_CDirent.h
 * @brief	Solar 라이브러리의 Directory Entry 클래스 헤더 파일.
 * @author	cppis (cppeins@gmail.com)
 *
 * @version	2007/03/15 cppis - First release
 *
 * @see		EA_CDirentEx
 */

#ifndef _EA_CDIRENT_H_
#define _EA_CDIRENT_H_

_EA_NAMESPACE_BEGIN

/*
 * Class:	EA_CDirent
 * Directory Entry 처리 클래스
 */
class EA_CDirent
{
public:
	/*
	 * Constructor:	EA_CDirent
	 * EA_CDirent의 기본 생성자.
	 */
	EA_CDirent( void );

	/*
	 * Destructor:	~EA_CDirent
	 * EA_CDirent의 소멸자.
	 */
	~EA_CDirent( void );

	/*
	 * Methods: Open
	 * 파일 Open
	 *
	 * Parameters:
	 *	tszFileName [in] - Open할 파일명
	 *	enOpenFlags [in] - Open 모드
	 *
	 * Returns:
	 *	파일 열기에 성공하면 EA_TRUE, 그렇지 않으면 EA_FALSE를 리턴
	 */
	EA_BOOL		Open( MA_PCTSTR IN tszFileName );

	/*
	 * Methods: FindFiles
	 * 파일 Open
	 *
	 * Parameters:
	 *	tszFileName [in] - Open할 파일명
	 *	enOpenFlags [in] - Open 모드
	 *
	 * Returns:
	 *	파일 열기에 성공하면 EA_TRUE, 그렇지 않으면 EA_FALSE를 리턴
	 */
	EA_BOOL		FindFiles( MA_PCTSTR IN tszFileName );

	/*
	 * Methods: Open
	 * 파일 열기(Formatted FileName 지원)
	 *
	 * Parameters:
	 *	tszFileName [in] - Open할 Formatted FileName
	 *
	 * Returns:
	 *	파일 열기에 성공하면 EA_TRUE, 그렇지 않으면 EA_FALSE를 리턴
	 */
	EA_BOOL		Openf( MA_PCTSTR IN tszFileName, ... );

	/*
	 * Methods: Read
	 * 첫번째 엔트리(파일 또는 디렉토리)를 읽어온다.
	 * EA_CDirent는 Directory DOT( _T("."), _T("..") )도 구분하여 처리한다.
	 *
	 * Parameters:
	 *	tszFileName [out]	- Read한 FileName
	 *	sizeFileName [in]	- Read할 FileName 최대 길이
	 *	psizeFile [out]		- Read한 File 사이즈
	 *	u32Attributes [out]	- Read한 File Attributes
	 *
	 * Returns:
	 *	파일 열기에 성공하면 EA_TRUE, 그렇지 않으면 EA_FALSE를 리턴
	 */
	EA_BOOL		Read( MA_PTSTR OUT tszFileName, EA_SIZE IN sizeFileName, EA_SIZE* OUT psizeFile, EA_DWORD* OUT pdwAttributes );


#if defined( _NTR_WINDOWS )
	EA_HANDLE	GetDirent( void )			{ return m_hDirent;		}
#else
	DIR*		GetDirent( void )			{ return m_pDirent;		}
#endif
	MA_PCTSTR	GetDirentName( void )		{ return m_tszDirentName;	}

	MA_PCTSTR	GetBaseDirectory( void )	{ return m_tszBaseDirectory;	}

	// 현재 디렉토리 스트림의 위치를 설정함.
	void	SetPosition( LONG IN lLocation );

	// 현재 디렉토리 스트림의 위치를 반환함.
	LONG	GetPosition( void );

	// 디렉토리 스트림을 디렉토리의 가장 앞으로 초기화함.
	void	Rewind( void );

	// 파일 닫기
	void	Close( void );

protected:
	EA_DIRENT_HANDLE	m_hDirent;
	MA_TCHAR			m_tszDirentName[ MA_MAX_PATH ];
	MA_TCHAR			m_tszBaseDirectory[ MA_MAX_PATH ];
};

_EA_NAMESPACE_END

#endif /* !_EA_CDIRENT_H_ */
