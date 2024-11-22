/*-------------------------------------------------------------------------*\
|                                                                           |
|  FILE: PBINDWIN.H                                                         |
|                                                                           |
|                                                                           |
|  Runtime linkage header for PBindWin subsystem			    |
|  ver. 7.00                                                                |
|                                                                           |
|                                                                           |
|  (C) Copyright Pocket Soft, Inc. 1997-2002.  All Rights Reserved.         |
|                                                                           |
\*-------------------------------------------------------------------------*/

# include	<windows.h>

# ifdef __cplusplus
extern "C" {
# endif


typedef LPVOID (CALLBACK* PATCHCALLBACK)(UINT, LPVOID);


UINT CALLBACK RTPatchBoundApply( LPSTR CmdLine,
			PATCHCALLBACK CallBackFn,
			BOOL WaitFlag );


/*

CmdLine is a pointer to a command line as documented in Winapi.doc
	except without a patchfile name

CallBackFn is a pointer to a callback handling function as documented
	in Winapi.doc

WaitFlag is an integer flag as documented in Winapi.doc

*/


# ifdef __cplusplus
};
# endif
