#pragma once

typedef EL_UINT32 EL_CRC32;

EL_BASE_API EL_CRC32 EL_CRC32_Make(EL_C_VOID_P data, EL_SIZE size);
EL_BASE_API EL_CRC32 EL_CRC32_Makei(EL_C_ACHAR_P data, EL_SIZE size);