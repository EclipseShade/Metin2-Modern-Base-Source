#pragma once

class EL_FileData
{
public:
	virtual ~EL_FileData()
	{}

	virtual EL_VOID* GetDataPtr() const = 0;
	
	virtual EL_SIZE GetDataSize() const = 0;
	
};