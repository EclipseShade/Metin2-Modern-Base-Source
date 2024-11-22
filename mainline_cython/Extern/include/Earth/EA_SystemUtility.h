/**
 * @file	EA_SystemUtility.h
 * @brief	System Utilities for Earth
 * @author	Standil (cpascal@cpascal.net)
 * 
 * @version	2009/06/27 cpascal - First Release
 */

#ifndef _EA_SYSTEMUTILITY_H_
#define _EA_SYSTEMUTILITY_H_

_EA_NAMESPACE_BEGIN

#if defined(_NTR_WINDOWS_INTEL)
BOOL	EA_IsWindowsFamilyNT( void );
BOOL	EA_IsWindowsNT4( void );
BOOL	EA_IsWindows2000( void );
BOOL	EA_IsWindowsXP( void );
BOOL	EA_IsWindowsServer2003( void );
BOOL	EA_IsWindows2000orBetter( void );
BOOL	EA_IsWindowsXPorBetter( void );
BOOL	EA_IsWindowsVistaOrBetter( void );
BOOL	EA_IsWindowsServer2003orBetter( void );

BOOL	EA_IsInteractiveMode( void );
#endif /* _NTR_WINDOWS_INTEL */

_EA_NAMESPACE_END

#endif /* !_EA_SYSTEMUTILITY_H_ */
