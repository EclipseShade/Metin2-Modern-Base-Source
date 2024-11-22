#pragma once

#include "DC.h"
#include "TPooledObject.h"

EL_BOOST_PTR(EL_WindowDC);

class EL_WindowDC
: public EL_DC
, public EL_TPooledObject<EL_WindowDC>
{
public:
	virtual ~EL_WindowDC();

public:
	EL_BOOST_NEW_SHARED_PTR1(EL_WindowDC, HWND);

	EL_WindowDC(HWND hWnd);	

private:
	HWND m_hWnd;
};