#pragma once

#include "TBasicString.h"
#include "SmartPointer.h"

EL_BOOST_PTR(EL_File);
EL_BOOST_PTR(EL_DiskFile);

class EL_File
{
public:
	enum EFileMode
	{
		FILEMODE_READ = (1 << 0),
		FILEMODE_WRITE = (1 << 1)
	};

public:
	enum ESeekType
	{
		SEEK_TYPE_BEGIN,
		SEEK_TYPE_CURRENT,
	};

public: // pure virtual
	virtual EL_BOOL Seek(EL_VFS_SIZE_T offset, ESeekType mode = SEEK_TYPE_BEGIN, EL_VFS_SIZE_T* retPos=NULL) = 0;
	virtual EL_BOOL Write(const void* src, EL_VFS_SIZE_T bytes, EL_VFS_SIZE_T* writtenSize=NULL) = 0;
	virtual EL_BOOL Read(void* dest, EL_VFS_SIZE_T bytes, EL_VFS_SIZE_T* readSize=NULL) = 0;

	virtual EL_VFS_SIZE_T GetSize() const = 0;

public:	// virtual
	virtual	~EL_File() {}
		
};

class EL_DiskFile : public EL_File
{
public:
	virtual EL_BOOL Seek(EL_VFS_SIZE_T offset, ESeekType mode = SEEK_TYPE_BEGIN, EL_VFS_SIZE_T* retPos=NULL);
	virtual EL_BOOL Write(const void* src, EL_VFS_SIZE_T bytes, EL_VFS_SIZE_T* writtenSize=NULL);
	virtual EL_BOOL Read(void* dest, EL_VFS_SIZE_T bytes, EL_VFS_SIZE_T* readSize=NULL);

	virtual EL_VFS_SIZE_T GetSize() const;
	
public:	// public
	EL_DiskFile();
	virtual ~EL_DiskFile();

	EL_BOOL Open(EL_C_ACHAR_P filePathz, EFileMode mode);
	EL_BOOL Open(EL_C_WCHAR_P filePathz, EFileMode mode);

	EL_VOID Close();

	EL_C_WCHAR_P	GetNamez() const;	
	HANDLE			GetHandle() const;

protected:	
	EL_INT			m_mode;
	EL_VFS_SIZE_T	m_size;

protected:
	EL_BasicStringW  m_filePath;	
	
protected:
	HANDLE m_hFile;	
};
