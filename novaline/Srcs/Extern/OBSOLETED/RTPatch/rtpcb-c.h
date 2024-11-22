/*-------------------------------------------------------------------------*\
|                                                                           |
|  FILE: RTPCB-C.H	                                                    |
|                                                                           |
|                                                                           |
|  RTPatch Generic Interface DLL API Header File		            |
|                                                                           |
|                                                                           |
|  (C) Copyright Pocket Soft, Inc. 1997-2002.  All Rights Reserved.         |
|                                                                           |
\*-------------------------------------------------------------------------*/

# ifndef RTPCB_INCLUDED
# define RTPCB_INCLUDED	

# include <windows.h>

/*-----------------------------------------------------------------------*\
|  C++ name mangling prevention -- beginning of block                     |
\*-----------------------------------------------------------------------*/
# ifdef __cplusplus
  extern "C" {
# endif /*__cplusplus */		 

//----------------------------------------------------
// Manifest constants
//----------------------------------------------------
# define RTPATCH_FULL_PATHS           0x1
# define RTPATCH_SEARCH_ALL           0x2
# define RTPATCH_SUPPRESS_WARNINGS    0x4
# define RTPATCH_SUPPRESS_ERRORS      0x8
# define RTPATCH_SUPPRESS_STATUS      0x10 
# define RTPATCH_NO_USER_INTERACTION  0x40
# define RTPATCH_SUPPRESS_ALL         0x7c
# define RTPATCH_OEM_PATCHFILE        0x80
# define RTPATCH_SEARCH_NET           0x100
# define RTPATCH_LOG_FILE             0x200
# define RTPATCH_REBOOT_WARN          0x400
# define RTPATCH_REBOOT_RESTART       0x800


//----------------------------------------------------
// RTPatchxx - main entry point
//----------------------------------------------------

__declspec( dllexport )
unsigned int WINAPI
RTPatchApply32WithCall( 
	HANDLE hWindow,       // handle to main window
	LPSTR lpPatchFile,    // full path for Patch File
	LPSTR lpApplyDir,     // full path for Apply Directory
	LPSTR lpWindowTitle,  // Title for Status Window
	LPSTR lpOptionStr,    // RTPatch options string
	LONG dwOptions,       // other (interface) options
	LONG dwVertPos,       // vertical origin (-1 => center)
	LONG dwHorizPos );    // horizontal origin (-1 => center)

__declspec( dllexport )
unsigned int WINAPI
RTPatch32SetText(  
	LPSTR lpReserved1, // must be NULL
	LPSTR lpReserved2, // must be NULL
	LPSTR lpStatusStr, // set static status string
	LPSTR lpLogFile ); // set logfile name (default: rtpatch.log)
 
/*-----------------------------------------------------------------------*\
    C++ name mangling prevention -- end of block
\*-----------------------------------------------------------------------*/
# ifdef __cplusplus
  };
# endif

# endif /* RTPCB_INCLUDED */
