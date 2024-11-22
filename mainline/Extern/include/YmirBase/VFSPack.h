#pragma once

#include <atlcoll.h>
#include <list>

#include "CRC32.h"
#include "MappedFile.h"
#include "TBasicString.h"

#ifndef MAKEFOURCC
#define MAKEFOURCC(ch0, ch1, ch2, ch3)                                           \
	((UINT32)(BYTE) (ch0       ) | ((UINT32)(BYTE) (ch1) <<  8) | \
	((UINT32)(BYTE) (ch2) << 16) | ((UINT32)(BYTE) (ch3) << 24))
#endif

namespace EL_VFS
{
	const UINT32 c_PackCC = MAKEFOURCC('Y', 'P', 'K', 'D');
	const UINT32 c_IndexCC = MAKEFOURCC('Y', 'P', 'K', 'D');
	const UINT32 c_Version = 4;
	const UINT32 c_FilenameLen = 160;

#define LOWER(c) (((c) >= 'A' && (c) <= 'Z') ? ((c) + ('a' - 'A')) : (c))

	__forceinline EL_UINT64 StringHash(EL_C_ACHAR_P s, EL_SIZE len)
	{
		EL_UINT32 crc = EL_CRC32_Makei(s, len);
		EL_UINT32 stringhash = 0;

		// this algorithm was created for sdbm (a public-domain reimplementation of ndbm) database library.
		// refer: http://www.cse.yorku.ca/~oz/hash.html
		for ( ; len; --len, ++s)
			stringhash = LOWER(*s) + (stringhash << 6) + (stringhash << 16) - stringhash;

		return (EL_UINT64) crc << 32 | stringhash;
	}
};

#pragma pack(push, 4)
struct EL_VFS_IndexHeader
{
	EL_UINT32 fourcc;
	EL_UINT32 version;
	EL_VFS_SIZE_T entrySize;
};

struct EL_VFS_IndexEntry
{
	EL_UINT32		id;
	EL_UINT64		hashkey;
	EL_ACHAR		filename[EL_VFS::c_FilenameLen + 1];
	EL_UINT32		data_crc;		// 원본 파일 CRC
	EL_UINT32		data_rawsize;	// 원본 파일 사이즈
	EL_UINT32		data_size;		// 프로세스 후 사이즈
	EL_UINT32		real_data_size;	// 실제 파일 사이즈
	EL_UINT32		data_position;	// 파일 시작 위치
	EL_UINT8		flags;
};
#pragma pack(pop)

class EL_VFS_Pack;

typedef std::pair<EL_VFS_Pack *, EL_VFS_IndexEntry *> EL_VFS_PackIndexEntry;
typedef CAtlMap<EL_UINT64, EL_VFS_PackIndexEntry> EL_VFS_IndexEntryMap;

EL_BOOST_PTR(EL_VFS_Pack);

class EL_VFS_Pack
{
public:
	enum
	{
		DBNAME_MAX_LEN = 255,
		FREE_INDEX_BLOCK_SIZE = 65536,
		FREE_INDEX_MAX_SIZE = 512,
		DATA_BLOCK_SIZE = 256,

		FLAG_ENCRYPTED = 1,			// (1 << 0)
		FLAG_LZO_COMPRESSED = 2,	// (1 << 1)
	};		
	typedef BOOL (WINAPI *PENUMFILES)( EL_VFS_Pack* pcPack, EL_VFS_IndexEntry* pcIndex, LPVOID pvUserContext );

	EL_VFS_Pack();
	virtual ~EL_VFS_Pack();

	EL_VOID				Destroy();
	EL_BOOL				Create(EL_VFS_IndexEntryMap & map, EL_C_TCHAR_P dbName, EL_BOOL bReadOnly = true);

	EL_C_TCHAR_P		GetDBName();

	EL_BOOL				Get(EL_MappedFile& outFile, const EL_VFS_IndexEntry* index);
	EL_BOOL				Get(EL_MappedFile& outFile, EL_C_ACHAR_P filename);

	EL_BOOL				Put(EL_C_ACHAR_P filename, EL_C_ACHAR_P sourceFilename = NULL, EL_BOOL bCompress = false, EL_BOOL bSecurity = false);

	EL_BOOL				Delete(EL_C_ACHAR_P filename);

	EL_BOOL				EnumerateFiles( PENUMFILES pfnEnumFiles, LPVOID pvUserContext );

	EL_BOOL				Extract();

	EL_VFS_SIZE_T		GetFragmentSize();

	EL_BOOL				Access(EL_C_ACHAR_P filename);

	EL_BOOL				EncryptIndexFile();
	EL_BOOL				DecryptIndexFile();

	UINT32				DeleteUnreferencedData();	// 몇개가 삭제 되었는지 리턴 한다.

	EL_VFS_IndexEntry *	FindIndex(EL_C_ACHAR_P filename);

private:
	EL_BOOL				__BuildIndex();

	EL_BOOL				Put(EL_C_ACHAR_P filename, LPCVOID data, EL_VFS_SIZE_T len, EL_BOOL bCompress, EL_BOOL bSecurity);

	EL_BOOL				CreateIndexFile();
	EL_VFS_SIZE_T		GetNewIndexPosition(EL_File& file);
	EL_VFS_IndexEntry *	NewIndex(EL_File& file, EL_C_ACHAR_P filename, EL_VFS_SIZE_T size);
	EL_VOID				WriteIndex(EL_File& file, EL_VFS_IndexEntry * index);
	EL_VFS_SIZE_T		GetFreeBlockIndex(EL_VFS_SIZE_T size);
	EL_VOID				PushFreeIndex(EL_VFS_IndexEntry * index);

	EL_BOOL				CreateDataFile();
	EL_VFS_SIZE_T		GetNewDataPosition(EL_File& file);
	EL_BOOL				WriteData(EL_File& file, EL_VFS_IndexEntry * index, LPCVOID data);
	EL_BOOL				Delete(EL_VFS_IndexEntry * pIndex);

protected:			
	EL_VFS_SIZE_T		m_fragmentSize;
	EL_VFS_SIZE_T		m_indexCount;

	EL_BOOL				m_bReadOnly;
	EL_BOOL				m_bEncrypted;

protected:
	EL_VFS_IndexEntry *		m_indexData;
	EL_VFS_IndexEntryMap *	m_indexMapPtr;		

protected:
	EL_BasicString		m_dbName;
	EL_BasicString		m_dataFileName;		
	EL_BasicString		m_indexFileName;

protected:
	typedef std::list<EL_VFS_IndexEntry *>			TFreeIndexList;
	typedef std::map<EL_VFS_SIZE_T, EL_VFS_SIZE_T>	TIndexRefCountDict;

	TFreeIndexList		m_freeIndics[FREE_INDEX_MAX_SIZE + 1];	// MAX 도 억세스 하므로 + 1 크기만큼 만든다.
	TIndexRefCountDict	m_indexRefCountd;

protected:
	EL_DiskFile m_readingFile;

};

class EL_VFS_PackLog
{
public:
	static EL_VFS_PackLog& GetSingleton();

public:
	EL_VFS_PackLog();
	~EL_VFS_PackLog();

	EL_VOID SetFileName(const char* c_szFileName);
	EL_VOID Writef(const char* c_szFormat, ...);
	EL_VOID Writenf(const char* c_szFormat, ...);
	EL_VOID Write(const char* c_szBuf);

private:
	EL_VOID __Write(const char* c_szBuf, size_t nBufLen);
	EL_BOOL __IsLogMode();

private:
	FILE* m_fp;

	std::string m_stFileName;
};

class EL_VFS_Browser
{
public:
	static EL_VFS_Browser& GetSingleton();

public:
	enum OpenMode
	{
		OPEN_MODE_READ_ONLY,
		OPEN_MODE_WRITABLE,
	};
	enum AccessMode
	{	
		ACCESS_MODE_DISK_ONLY,		
		ACCESS_MODE_DISK_FIRST,
		ACCESS_MODE_PACK_ONLY,
		ACCESS_MODE_PACK_FIRST,
	};


public:
	EL_VFS_Browser();

	EL_VOID	Destroy();

	EL_VOID SetAccessMode(EL_C_TCHAR_P modeNamez);
	EL_VOID SetPackDir(EL_C_TCHAR_P packDirz);
	EL_VOID SetPackDir2(EL_C_TCHAR_P packDirz);
	EL_VOID SetDiskDir(EL_C_TCHAR_P diskDirz);
	EL_VOID SetDiskDir2(EL_C_TCHAR_P diskDirz);

	EL_VFS_PackPtr AddPackage(EL_C_TCHAR_P dbName, OpenMode openMode);

	EL_BOOL	Get(EL_MappedFile& outFile, EL_C_ACHAR_P filePathz);
	EL_BOOL	Get(EL_MappedFile& outFile, EL_C_WCHAR_P filePathz);

	EL_BOOL Exists(EL_C_ACHAR_P filePathz);
	EL_BOOL Exists(EL_C_WCHAR_P filePathz);

private:
	EL_BOOL __LoadPackage(EL_VFS_Pack& pack, EL_C_TCHAR_P dbNamez, EL_BOOL isReadOnly);

	EL_BOOL __GetFromDiskA(EL_MappedFile& outFile, EL_C_ACHAR_P filePathz);
	EL_BOOL __GetFromDiskW(EL_MappedFile& outFile, EL_C_WCHAR_P filePathz);
	EL_BOOL __GetFromPackA(EL_MappedFile& outFile, EL_C_ACHAR_P filePathz);
	EL_BOOL __GetFromPackW(EL_MappedFile& outFile, EL_C_WCHAR_P filePathz);

	EL_BOOL __ExistsOnDiskA(EL_C_ACHAR_P filePathz);
	EL_BOOL __ExistsOnDiskW(EL_C_WCHAR_P filePathz);	
	EL_BOOL __ExistsOnPackA(EL_C_ACHAR_P filePathz);
	EL_BOOL __ExistsOnPackW(EL_C_WCHAR_P filePathz);

private:
	AccessMode m_accessMode;

	EL_BasicString m_packDir;
	EL_BasicString m_packDir2;

	EL_BasicStringW m_diskDir;
	EL_BasicStringW m_diskDir2;

private:
	typedef std::vector<EL_VFS_PackPtr> EL_VFS_PackageVector;

private:
	EL_VFS_PackageVector m_packageVector;
	EL_VFS_IndexEntryMap m_indexMapPtr;
};
