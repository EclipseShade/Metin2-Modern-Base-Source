#pragma once

#include "TStatus.h"

EL_BOOL EL_Disk_MakeDirectory(EL_C_TCHAR_P dirz, EL_Status* statusPtr=NULL);
EL_BOOL EL_Disk_RemoveDirectory(EL_C_TCHAR_P dirz, EL_Status* statusPtr=NULL);

EL_BOOL EL_Disk_IsDir(EL_C_ACHAR_P dirz);
EL_BOOL EL_Disk_IsDir(EL_C_WCHAR_P dirz);
EL_BOOL EL_Disk_IsFile(EL_C_ACHAR_P filePathz);
EL_BOOL EL_Disk_IsFile(EL_C_WCHAR_P filePathz);
EL_BOOL EL_Disk_IsFileWritable(EL_C_ACHAR_P filePathz);
EL_BOOL EL_Disk_IsFileWritable(EL_C_WCHAR_P filePathz);