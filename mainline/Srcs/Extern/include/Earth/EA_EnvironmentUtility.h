/**
 * @file	EA_EnvironmentUtility.h
 * @brief	EA_EnvironmentUtility class
 * @author	Standil (cpascal@cpascal.net)
 * 
 * @version	2009/06/04 cpascal - First Release
 */

#ifndef _EA_ENVIRONMENTUTILITY_H_
#define _EA_ENVIRONMENTUTILITY_H_

#if defined(_NTR_WINDOWS_INTEL)

_EA_NAMESPACE_BEGIN

void EA_SendSettingChangedNotification( void );

BOOL EA_SetSystemEnvironment( MA_LPCTSTR tszKey, MA_LPCTSTR tszValue );
BOOL EA_DeleteSystemEnvironment( MA_LPCTSTR tszKey );
BOOL EA_GetSystemEnvironment( MA_LPCTSTR tszKey, MA_LPTSTR tszValue, size_t sizeValue );

BOOL EA_SetUserEnvironment( MA_LPCTSTR tszKey, MA_LPCTSTR tszValue );
BOOL EA_DeleteUserEnvironment( MA_LPCTSTR tszKey );
BOOL EA_GetUserEnvironment( MA_LPCTSTR tszKey, MA_LPTSTR tszValue, size_t sizeValue );

_EA_NAMESPACE_END

#endif /* _NTR_WINDOWS_INTEL */

#endif /* !_EA_ENVIRONMENTUTILITY_H_ */
