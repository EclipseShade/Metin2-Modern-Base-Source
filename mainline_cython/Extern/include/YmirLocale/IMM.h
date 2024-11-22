// CImm.h - part if Input Context management class
//
// Copyright (C) 2000-2005, Kwon-il Lee
//
// Kwon-il Lee
// zupet@hitel.net


#ifndef _YMIRLOCALE_IMM_H_
#define _YMIRLOCALE_IMM_H_

#include <imm.h>
#include <objbase.h>
#include <dimm.h>

class EL_CIMM
{
public:
	EL_CIMM();
	virtual ~EL_CIMM();

	void	Init();

	INPUTCONTEXT*	LockIMC(HIMC hImc);
	BOOL			UnlockIMC(HIMC hImc);
	LPVOID			LockIMCC( HIMCC );
	BOOL			UnlockIMCC( HIMCC );

protected:

	HINSTANCE		m_hDllImm32;

	INPUTCONTEXT*	(WINAPI * _ImmLockIMC)( HIMC );
	BOOL			(WINAPI * _ImmUnlockIMC)( HIMC );
	LPVOID			(WINAPI * _ImmLockIMCC)( HIMCC );
	BOOL			(WINAPI * _ImmUnlockIMCC)( HIMCC );
};

#endif /* !_YMIRLOCALE_IMM_H_ */
