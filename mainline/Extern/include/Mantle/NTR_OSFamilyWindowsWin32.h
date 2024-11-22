/**
 * @file	NTR_OSFamilyWindowsWin32.h
 * @brief	Nature windows Win32 platform header file
 * @author	Standil (cpascal@cpascal.net)
 *
 * @version	2009/08/19 cpascal - First release
 */

#ifndef _NTR_OSFAMILYWINDOWSWIN32_H_
#define _NTR_OSFAMILYWINDOWSWIN32_H_

// Minimum System Requirements: Windows 2000
#ifndef WINVER
#define _WIN32_WINNT				0x500
#define _WIN32_WINDOWS				0x500
#define WINVER						0x500
#endif

#define _NTR_WINDOWS_INTEL

#pragma warning( push, 3 )
#pragma pack(push)
#pragma pack(8)
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <string.h>
#include <tchar.h>
#include <stdio.h>
#pragma pack(pop)
#pragma warning( pop )

#endif /* !_NTR_OSFAMILYWINDOWSWIN32_H_ */
