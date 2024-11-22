/**
 * @file	NTR_OSFamilyWindowsCE.h
 * @brief	Nature Windows CE platform header file
 * @author	Standil (cpascal@cpascal.net)
 *
 * @version	2009/08/19 cpascal - First release
 */

#ifndef _NTR_OSFAMILYWINDOWSWIN32_H_
#define _NTR_OSFAMILYWINDOWSWIN32_H_

#define WINVER				_WIN32_WCE

#define _NTR_WINDOWS_CE

#ifndef ULLONG_MAX
#define ULLONG_MAX			_UI64_MAX
#endif

#ifndef LLONG_MAX
#define LLONG_MAX			_I64_MAX
#endif

#pragma warning( push, 3 )
#pragma pack(push)
#include <ceconfig.h>
#include <windows.h>
#include <commctrl.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <ctype.h>

//#if defined(WIN32_PLATFORM_PSPC) || defined(WIN32_PLATFORM_WFSP)
//#ifndef _DEVICE_RESOLUTION_AWARE
//#define _DEVICE_RESOLUTION_AWARE
//#endif
//#endif

//#ifdef _DEVICE_RESOLUTION_AWARE
//#include <DeviceResolutionAware.h>
//#endif

#include <altcecrt.h>
#pragma warning( pop )

#endif /* !_NTR_OSFAMILYWINDOWSWIN32_H_ */
