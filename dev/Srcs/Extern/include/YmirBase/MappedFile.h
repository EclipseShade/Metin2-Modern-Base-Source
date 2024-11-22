#pragma once

#include "File.h"
#include "CryptoTea.h"

class EL_MappedFile : public EL_File
{
public:		
	virtual ~EL_MappedFile();

	virtual EL_BOOL Seek(EL_VFS_SIZE_T offset, ESeekType mode = SEEK_TYPE_BEGIN, EL_VFS_SIZE_T* retPosPtr=NULL);
	virtual EL_BOOL Write(const void* src, EL_VFS_SIZE_T bytes, EL_VFS_SIZE_T* writtenSizePtr=NULL);
	virtual EL_BOOL Read(void* dest, EL_VFS_SIZE_T bytes, EL_VFS_SIZE_T* readSizePtr=NULL);

	virtual EL_VFS_SIZE_T GetSize() const;

public:
	EL_MappedFile();		
	
	EL_BOOL Open(EL_C_ACHAR_P filePathz, EFileMode mode);
	EL_BOOL Open(EL_C_WCHAR_P filePathz, EFileMode mode);

	EL_BOOL Map(EL_DiskFile& file, EL_VFS_SIZE_T offset, EL_VFS_SIZE_T size);					
	EL_VOID Decrypt(const EL_TEA_SECRET_KEY* keys);
	EL_BOOL Decompress(EL_VFS_SIZE_T orgSize);
	EL_VOID Close();

	EL_VOID_P GetDataPtr();

protected:
	EL_VOID _Link(EL_VFS_SIZE_T bufSize, const void* c_pvBufData);	
	
private:
	BYTE*			m_basePtr;
	BYTE*			m_lpMapData;
	BYTE*			m_lpDecryptData;
	BYTE*			m_lpDecompressData;

private:
	EL_VFS_SIZE_T	m_seekPosition;
	EL_VFS_SIZE_T	m_size;

private:
	EL_DiskFilePtr	m_diskFilePtr;

private:
	HANDLE			m_hMap;		
};
