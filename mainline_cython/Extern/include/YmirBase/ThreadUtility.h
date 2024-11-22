#pragma once

void EL_SetThreadName( LPCSTR szThreadName, DWORD dwThreadID = 0xFFFFFFFF );
EL_SIZE EL_GetThreadName( LPSTR szThreadName, EL_SIZE sizeThreadName, HANDLE hThread = INVALID_HANDLE_VALUE );
