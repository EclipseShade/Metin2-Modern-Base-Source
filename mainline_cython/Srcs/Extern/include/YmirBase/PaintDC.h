#pragma once

#include "DC.h"
#include "TPooledObject.h"

EL_BOOST_PTR(EL_PaintDC);

class EL_PaintDC
: public EL_DC
, public EL_TPooledObject<EL_PaintDC>
{
public:
	virtual ~EL_PaintDC();

public:
	EL_BOOST_NEW_SHARED_PTR1(EL_PaintDC, HWND);

	EL_PaintDC(HWND hWnd);

private:
	HWND m_hWnd;
	PAINTSTRUCT m_ps;
};
