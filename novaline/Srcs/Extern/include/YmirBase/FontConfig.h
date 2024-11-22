#pragma once

enum EL_FontFlag
{
	FF_DEFAULT = 0,
	FF_NORMAL  = 0 << 0,
	FF_BOLD    = 1 << 0,
};

struct EL_FontConfig
{	
	EL_FontConfig(EL_UINT codePage = 0);

	void SetFaceName(const wchar_t* str, int len);
	void SetHeight(EL_INT height);
	void SetFlags(EL_UINT flags);	

	std::wstring faceName;

	EL_UINT codePage;	
	EL_UINT flags;
	EL_INT  height;	
};