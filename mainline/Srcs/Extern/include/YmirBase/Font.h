#pragma once

#include "SmartPointer.h"

struct EL_FontConfig;

EL_BOOST_PTR(EL_Font);

class EL_Font
{
public:
	EL_BOOST_NEW_SHARED_PTR1(EL_Font, const EL_FontConfig&);
	
	EL_Font(const EL_FontConfig& config);
	virtual ~EL_Font();
	
	HFONT	Win32_GetHandle();

private:
	HFONT	m_hFont;
};

