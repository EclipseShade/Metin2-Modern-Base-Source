
/***********************************************************************************************************/
/* [TAG] Xtrap_L_Interface.h | 2010.03.03 | X-TRAP Interface Library For Launcher                          */
/*                                                                                                         */
/*  Copyright (C)WiseLogic 2005 - 2010 All Rights Reserved                                                 */
/***********************************************************************************************************/

#ifndef __Xtrap_L_Interface_H
#define __Xtrap_L_Interface_H

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Library Export Definition (for Launcher)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define XTEK_ARGV_SIZE_WITH_NULL		49

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Library Export Declaration (for Launcher) Function
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void __cdecl XTrap_L_Patch(
	IN LPCSTR	lpArgv,
	IN LPCSTR	lpGamePath, 
	IN DWORD	dwTimeout
);

void __cdecl XTrap_L_Patch(
	IN  LPCSTR	lpArgv, 
	IN  LPCSTR	lpGamePath, 
	IN  DWORD	dwTimeout, 
	OUT LPCSTR	pMsg, 
	OUT LPCSTR	pErrCode,
	OUT BOOL   *pErrFlag
);

BOOL __cdecl XTrap_L_ExecKey(
	OUT	void *pXTEKArgvBuff, 
	IN	DWORD dwBuffLength
);

#endif
