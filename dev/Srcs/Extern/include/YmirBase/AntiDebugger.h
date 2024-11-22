#pragma once

class EL_CLocalDecryptor
{
public:
	EL_ACHAR_P EL_FORCEINLINE DecryptText( EL_C_ACHAR_P szText )
	{
		Decrypt( (EL_UBYTE_P) m_szText, (EL_C_UBYTE_P) szText, (int) strlen( szText )  );
		return m_szText;
	}

	bool EL_FORCEINLINE Encrypt( EL_UBYTE_P pbyDestination, EL_C_UBYTE_P pbySource, int nLength )
	{
		for( int i=0; i < nLength; i++ )
			*(pbyDestination + i) = (EL_UINT8) (*(pbySource + i) - i);
		return true;
	}

	bool EL_FORCEINLINE Decrypt( EL_UBYTE_P pbyDestination, EL_C_UBYTE_P pbySource, int nLength )
	{
		for( int i=0; i < nLength; i++ )
			*(pbyDestination + i) = (EL_UINT8) (*(pbySource + i) + i);
		return true;
	}

protected:
	enum {
		MAX_TEXT_LENGTH = 256
	};
	EL_ACHAR	m_szText[MAX_TEXT_LENGTH];
};

BOOL EL_FORCEINLINE EL_DetectSoftIce( void )
{
	EL_CLocalDecryptor cDecrypt;

	EL_BOOL bSoftICE = (CreateFileA( cDecrypt.DecryptText( "\\[,YOD=>" ), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0 ) != INVALID_HANDLE_VALUE ); // \\.\SICE
	EL_BOOL bNTICE = (CreateFileA( cDecrypt.DecryptText( "\\[,YJOC<=" ), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0 ) != INVALID_HANDLE_VALUE ); // \\.\NTICE
	return bSoftICE || bNTICE;
}

BOOL EL_FORCEINLINE EL_DetectDebugger( void )
{
	HMODULE hKernel;
	EL_CLocalDecryptor cDecrypt;

	if( NULL == (hKernel = LoadLibraryA( cDecrypt.DecryptText( "KDPKAG-+&;BA" ))) ) // LoadLibrary( "KERNEL32.DLL" );
		return FALSE;
	BOOL (WINAPI *pIsDebuggerPresent)( void );
	pIsDebuggerPresent = GetProcAddress( (HMODULE) hKernel, cDecrypt.DecryptText( "IrBb^pa`]iFgYfW_d" ) ); // GetProcAddress( "IsDebuggerPresent" );
	BOOL bDebugger = pIsDebuggerPresent();
	FreeLibrary( hKernel );
	return bDebugger;
}

BOOL EL_FORCEINLINE EL_DetectDebuggerByTrapFlags( void )
{
#ifdef _WIN64
	return FALSE;
#else
	EL_BOOL bExceptionHit = EL_FALSE;

	__try {
		__asm {
			PUSHFD
			OR		DWORD PTR [ESP], 0x100
			POPFD
			NOP
		}
	}
	__except( EXCEPTION_EXECUTE_HANDLER ) {
		bExceptionHit = EL_TRUE;
	}
	return (bExceptionHit == FALSE);
#endif
}
