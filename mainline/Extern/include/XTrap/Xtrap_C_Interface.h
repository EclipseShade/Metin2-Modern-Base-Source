
/***********************************************************************************************************/
/* [TAG] Xtrap_C_Interface.h | 2013.05.10 | X-TRAP Interface Library For CLIENT                            */
/*                                                                                                         */
/*  Copyright (C)WiseLogic 2005 - 2013 All Rights Reserved                                                 */
/***********************************************************************************************************/

#ifndef __Xtrap_C_Interface_H
#define __Xtrap_C_Interface_H

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#define _USE_XTRAP_MODULE

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Return Values
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define XTRAP_API_RETURN_OK							0x00000000
#define XTRAP_API_RETURN_ERROR						0x00000001

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Library Export Declaration (for CLIENT) Function
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef _USE_XTRAP_MODULE

	void XTrap_C_Start( 
			IN	LPCSTR	lpArgv, 
			IN	LPCSTR	lpXTrapPath 
	);

	extern "C" 
	void XTrap_C_StartW( /*UNICODE*/
			IN	LPCSTR	lpArgv, 
			IN	LPCWSTR lpXTrapPath
	);

	void XTrap_C_KeepAlive(void);

#else

	#define XTrap_C_Start			
    #define XTrap_C_StartW
	#define XTrap_C_KeepAlive

#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Library Export Declaration Extended (for CLIENT) Function
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef _USE_XTRAP_MODULE

	void XTrap_C_SetUserInfoEx(
			IN	LPCSTR	lpUserID, 
			IN	LPCSTR	lpServerName, 
			IN	LPCSTR	lpCharacterName, 
			IN	LPCSTR	lpCharacterClass, 
			IN	DWORD	dwReserve,
			IN	SOCKET	pSocket
	);

	void XTrap_C_CallbackAlive(
			IN	DWORD	dwPeriod/*milliseconds*/
	);

#else

	#define XTrap_C_SetUserInfoEx
	#define XTrap_C_CallbackAlive

#endif

#ifdef _USE_XTRAP_MODULE

	DWORD XTrap_C_Detour(void);
	
	DWORD XTrap_C_SecureEngineDetour(
			IN	DWORD dwMode /*must be 0*/
	);

#else

	#define XTrap_C_Detour
	#define XTrap_C_SecureEngineDetour

#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Library Export Declaration (for SERVER) Function
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

// XTrap_CS_Step2 . dwMethod ////////////////////////////////////////////////////////////////////////////////
// XTrap_CS_Step2_M . dwMethod //////////////////////////////////////////////////////////////////////////////

#define	XTRAP_PROTECT_PE							0x00000001
#define	XTRAP_PROTECT_TEXT							0x00000010
#define XTRAP_PROTECT_CODE							XTRAP_PROTECT_TEXT
#define	XTRAP_PROTECT_RDATA							0x00000100
#define	XTRAP_PROTECT_EDATA							0x00001000
#define	XTRAP_PROTECT_RSRC							0x00010000
#define	XTRAP_PROTECT_RELOC							0x00100000
#define XTRAP_PROTECT_EXCEPT_VIRUS					0x00000002

#ifdef _USE_XTRAP_MODULE

	DWORD __cdecl XTrap_CS_Step2(
			IN  LPCVOID	lpBufPackData_IN, 
			OUT LPVOID	lpBufPackData_OUT,
			IN	DWORD	dwMethod
	);

	DWORD __cdecl XTrap_CS_Step2_M/*MultiSession*/(
			IN  LPCVOID	lpBufPackData_IN, 
			OUT LPVOID	lpBufPackData_OUT, 
			IN  DWORD	dwMethod,
			IN  SOCKET	pClientSocket
	);

	DWORD __cdecl XTrap_CS_Stop_M/*MultiSession*/(
			IN  SOCKET	pClientSocket
	);

#else

	#define XTrap_CS_Step2			

	#define XTrap_CS_Step2_M
	#define XTrap_CS_Stop_M

#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Library Export Declaration Undocument (for CLIENT) Function
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void WINAPI XTRAP_CALLBACK__XtrapCallbackProcedure (
	IN unsigned int		uReserve1,
	IN unsigned int		uReserve2,
	IN unsigned int		uReserve3,
	IN unsigned int		uReserve4,
	IN unsigned char *	pXtrapCode	// [in, out] Pointer to a XTRAP_CODE data structure
);

#ifdef _USE_XTRAP_MODULE

	void __cdecl XTrap_C_SetSecondaryProcess(
			IN	unsigned int uProcessId
	);

	void __cdecl XTrap_C_Start_HGW( 
			IN	LPCSTR	lpArgv, 
			IN	LPCSTR	lpXTrapPath
	);

	void __cdecl XTrap_C_Start_Callback( 
			IN	LPCSTR	lpArgv, 
			IN	LPCSTR	lpXTrapPath,
			IN	void *	pXtrapCallbackProcedure		// Pointer to the Xtrap-defined function. see XTRAP_CALLBACK__XtrapCallbackProcedure
	);

	void __cdecl XTrap_C_Terminate(void);

#else

	#define XTrap_C_SetSecondaryProcess
	#define XTrap_C_Start_HGW
	#define XTrap_C_Start_Callback
	#define XTrap_C_Terminate

#endif

#endif
