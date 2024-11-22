#pragma once

/// \brief 사용자 정보를 반환한다.
LPCTSTR EL_GetUserInfo();

/// \brief 윈도우즈 버전을 반환한다.
LPCTSTR EL_GetOSInfo();

/// \brief CPU 정보를 반환한다.
LPCTSTR EL_GetCpuInfo();

/// \brief 메모리 정보를 반환한다.
LPCTSTR EL_GetMemoryInfo();

/// \brief 윈도우즈 버전을 알아낸다.
bool EL_GetWinVersion( LPTSTR pszVersion, int *nVersion, LPTSTR pszMajorMinorBuild );

// \brief 파일의 버전을 알아낸다
VS_FIXEDFILEINFO EL_GetFixedFileInfo( LPCTSTR tszFileName );
