#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "SmartPointer.h"
#include "TSize.h"

EL_BOOST_PTR(EL_DC);
EL_BOOST_PTR(EL_Font);
EL_BOOST_PTR(EL_DCColor);

typedef EL_TSize2<int>	EL_DCSIZE;

class EL_DC
{
public:	
	virtual ~EL_DC();

public:
	EL_DC(HDC hDC);	

	void SetTextFont(EL_FontPtr fontPtr);

	void SetTextColor(const EL_DCColor& color);
	void SetTextColor(COLORREF crColor);
	void SetTextBackColor(const EL_DCColor& color);
	void SetTextBackColor(COLORREF crColor);

	void DrawTextw(int x, int y, const wchar_t* str, int len);
	void DrawTextwz(int x, int y, const wchar_t* str);

	void DrawText(int x, int y, const char* str, int len);
	void DrawTextz(int x, int y, const char* str);

	EL_DCSIZE GetTextExtentw(const wchar_t* str, int len);

	COLORREF GetTextColor(); 
	COLORREF GetTextBackColor(); 

	HDC GetHandle() const;
	
private:
	HDC m_hDC;
};

