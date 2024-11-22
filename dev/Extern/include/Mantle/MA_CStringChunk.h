#ifndef _MA_CSTRINGCHUNK_H_
#define _MA_CSTRINGCHUNK_H_

class MA_CStringChunk
{
public:

protected:
	class xMemoryHolder
	{
		xMemoryHolder( LPVOID pvData, MA_SIZE sizeData );
		~xMemoryHolder();

		void	Set( LPVOID pvData, MA_SIZE sizeData )			{ m_pvData = (LPVOID) malloc( sizeData ); memcpy( m_pvData, pvData, sizeData ); m_sizeData = sizeData;		}
		int		Compare( LPVOID pvData, MA_SIZE sizeData )		{ if( sizeData != m_sizeData ) return (int) (m_sizeData - sizeData); return memcmp( m_pvData, pvData, sizeData );	}

	protected:
		LPVOID	m_pvData;
		MA_SIZE	m_sizeData;
	};
};

//#pragma pack( push, 1 )
//typedef	struct MA_tagTextChunkData
//{
//	LPTSTR	tszData;
//	DWORD	dwOffset;
//} MA_STEXTCHUNKDATA, *MA_PTEXTCHUNKDATA;
//
//typedef	struct	MA_tagTextChunkHeader
//{
//	DWORD	dwSignature;
//	DWORD	dwHeaderSize;
//	DWORD	dwTableSize;
//	DWORD	dwEntryCount;
//	DWORD	dwTotalDataSize;
//	DWORD	dwTextChunkBeginOffset;
//} MA_TEXTCHUNKHEADER, MA_PTEXTCHUNKHEADER;
//#pragma pack( pop )
//
//class	MA_CTextChunk : public MA_TCStringDoubleHashTable<MA_PTEXTCHUNKDATA>
//{
//public:
//	enum {
//		TEXTCHUNK_DEFAULT_SIZE	= 128,
//		TEXTCHUNK_SIGNATURE	= 0x0043544D
//	};
//
//	MA_CTextChunk( size_t sizeChunk = TEXTCHUNK_DEFAULT_SIZE );
//	virtual	~MA_CTextChunk();
//
//	void	Release();
//	BOOL	Insert( LPCTSTR tszText );
//	DWORD	GetOffset( LPCTSTR tszText );
//	LPTSTR	GetTextPointer( LPCTSTR tszText, BOOL bInsertWhenNoExist = FALSE );
//	LPTSTR	GetTextPointer( DWORD dwOffset );
//
//	size_t	SaveByFileSystem( LPCTSTR tszFileName );
//	size_t	SaveByFileSystem( MA_IFile *pcFile );
//	//size_t	SaveByMemory( DWORD dwBufferLength, LPVOID pvBuffer ); // 지원하지 않는다. offset이 필요한데 offset 정보를 알 수 없기 때문이다.
//
//	size_t	LoadFromFileSystem( LPCTSTR tszFileName );
//	size_t	LoadFromFileSystem( MA_IFile *pcFile, MA_EOpenFlags eOpenMode = modeRead );
//	size_t	LoadFromMemory( LPCVOID pcvBuffer );
//
//	void	DeleteExtra();
//
//protected:
//	size_t		m_sizeWholeData;
//	MA_EOpenFlags	m_eOpenMode;
//	LPBYTE		m_pbyText;
//	size_t		m_sizeBeginOffset;
//};

#endif /* !_MA_CSTRINGCHUNK_H_ */
