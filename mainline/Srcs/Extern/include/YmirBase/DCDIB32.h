#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

typedef EL_UINT32 EL_DCPIXEL32;

class EL_DCDIB32
{
public:
	EL_DCDIB32();
	~EL_DCDIB32();
	
	EL_BOOL Create(HDC hDC, EL_INT width, EL_INT height);	
	EL_VOID Destroy();

	EL_VOID Clear();
	EL_VOID ClearColor(EL_UINT color);

	EL_UINT GetWidth();	
	EL_UINT GetHeight();

	HBITMAP GetHandle();

	EL_DCPIXEL32* GetPixels();

	EL_VOID Draw(HDC hDCDst, EL_INT x, EL_INT y);
	EL_VOID DrawSub(HDC hDCDst, EL_INT x, EL_INT y, const RECT& rcSub);
	
private:
	EL_DCPIXEL32*		m_pixels;

private:
	HBITMAP		m_hBmp;
	BITMAPINFO	m_bmi;
};

