/*-------------------------------------------------------------------------*\

   FILE: ARTPCLNT.H

   Auto RTPatch constants and declares


   (c) Copyright 2002, Pocket Soft, Inc. ALL RIGHTS RESERVED.

   This source file is proprietary and confidential to Pocket Soft, Inc.


   Version: 7.00


\*-------------------------------------------------------------------------*/

// AutoRTPatch32 return codes
# define RTP_AUTO_NO_UPDATE         0x101
# define RTP_AUTO_NOT_TRUSTED       0x102
# define RTP_AUTO_CANCELLED         0x103
# define RTP_AUTO_INET_FAILURE      0x104
# define RTP_AUTO_VERIFY_ERROR      0x105
# define RTP_AUTO_DLL_VERIFY_ERROR  0x106
# define RTP_AUTO_RTP_VERIFY_ERROR  0x107
# define RTP_AUTO_DLL_DL_ERROR      0x108
# define RTP_AUTO_INTERNAL_ERROR    0x109
# define RTP_AUTO_REGISTRY_ERROR    0x10A
# define RTP_AUTO_RTP_DL_ERROR      0x10B
# define RTP_AUTO_CYCLICAL_ERROR    0x10C
# define RTP_AUTO_SCHEDULED         0x10D
# define RTP_AUTO_LOCKED            0x10E
# define RTP_AUTO_LOCKED_MORE       0x10F
# define RTP_AUTO_NO_PATCH_DLL      0x110
# define RTP_AUTO_NO_VERSION        0x111
# define RTP_AUTO_NO_URL            0x112
# define RTP_AUTO_BAD_DLL_VER       0x113
# define RTP_AUTO_NO_CABARC         0x114
# define RTP_AUTO_INVALID_PASSWORD  0x115


typedef LPVOID (CALLBACK* PATCHUPDATECALLBACK) (UINT, LPVOID, LPVOID);

// Main DLL entry point
# ifdef __cplusplus
  extern "C" {
# endif /*__cplusplus */

int __declspec (dllimport) AutoRTPatch32 (
        HKEY BaseKey,
        LPCSTR lpszSubKey, 
        LPCSTR lpszProxyName,
        PATCHUPDATECALLBACK CallBack, 
        LPVOID lParam);
# ifdef __cplusplus
  }
# endif /*__cplusplus */