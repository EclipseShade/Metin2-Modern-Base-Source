#pragma once

#include "FileData.h"
#include "TSimpleString.h"

class EL_DiskFileData : public EL_FileData
{
public:
	virtual ~EL_DiskFileData();

	virtual EL_VOID* GetDataPtr() const;
	virtual EL_SIZE GetDataSize() const;

public:
	EL_DiskFileData();

	EL_BOOL Load(const EL_SimpleStringA& filePath);
	EL_BOOL Load(const EL_SimpleStringE& filePath);
	EL_BOOL Load(const EL_SimpleStringW& filePath);	
		
private:
	EL_SIZE  m_dataSize;
	EL_VOID* m_dataPtr;
};