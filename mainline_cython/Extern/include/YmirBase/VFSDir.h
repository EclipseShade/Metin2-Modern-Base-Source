#pragma once

std::string EL_VFS_GetCurrentWorkingDir(); // 현재 작업 디렉토리를 얻어낸다
std::string EL_VFS_GetStartupDir(); // 시작 디렉토리를 얻어낸다
void EL_VFS_CreatePath(EL_C_ACHAR_P path);