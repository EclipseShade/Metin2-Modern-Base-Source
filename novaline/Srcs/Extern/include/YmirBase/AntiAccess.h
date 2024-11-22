#pragma once

#include "AccCtrl.h"
#include "Aclapi.h"

BOOL EL_FORCEINLINE EL_DenyProcessAccess( void )
{
	BYTE	abyBuffer[0x200];
	PACL	pACL;
	SID_IDENTIFIER_AUTHORITY stIdentifierAuthority = SECURITY_WORLD_SID_AUTHORITY;
	PSID pSid = NULL;
	BOOL bRet = FALSE;
	DWORD dwSize = 0;
	HANDLE hToken = NULL;
	HANDLE hProcess = ::GetCurrentProcess();
	PTOKEN_USER pUserInfo = NULL;

 	if( ::AllocateAndInitializeSid( &stIdentifierAuthority, 1, SECURITY_WORLD_RID, 0, 0, 0, 0, 0, 0, 0, &pSid ) == FALSE )
		goto Cleanup;
	if( ::OpenProcessToken( hProcess, TOKEN_QUERY, &hToken ) == FALSE )
		goto Cleanup;
	::GetTokenInformation( hToken, TokenUser, NULL, NULL, &dwSize );
	if( dwSize > 1024 )
		goto Cleanup;
	pUserInfo = (PTOKEN_USER) ::GlobalAlloc( GPTR, dwSize );
	if( pUserInfo == NULL )
		goto Cleanup;
	if( ::GetTokenInformation( hToken, TokenUser, pUserInfo, dwSize, &dwSize ) == FALSE )
		goto Cleanup;
	pACL = (PACL) &abyBuffer;
	if( ::InitializeAcl( pACL, 0x200, ACL_REVISION ) == FALSE )
		goto Cleanup;
	// Deny except PROCESS_TERMINATE and PROCESS_SET_SESSIONID
	if( ::AddAccessDeniedAce( pACL, ACL_REVISION, PROCESS_CREATE_PROCESS | PROCESS_DUP_HANDLE | PROCESS_VM_WRITE | PROCESS_VM_READ | PROCESS_VM_OPERATION | PROCESS_CREATE_THREAD, pSid ) == FALSE )
		goto Cleanup;
	// Allow SYNCHRONIZE, PROCESS_QUERY_INFORMATION, PROCESS_SET_INFORMATION, PROCESS_SET_QUOTA and PROCESS_TERMINATE
	if( ::AddAccessAllowedAce( pACL, ACL_REVISION, SYNCHRONIZE | PROCESS_QUERY_INFORMATION | PROCESS_SET_INFORMATION | PROCESS_SET_QUOTA | PROCESS_TERMINATE, pUserInfo->User.Sid ) == FALSE )
		goto Cleanup;
	if( ::SetSecurityInfo( hProcess, SE_KERNEL_OBJECT, PROTECTED_DACL_SECURITY_INFORMATION | DACL_SECURITY_INFORMATION, 0, 0, pACL, 0 ) != ERROR_SUCCESS )
		goto Cleanup;
	bRet = TRUE;
Cleanup:
	if ( hToken )
		::CloseHandle( hToken );
	if ( pSid )
		::FreeSid( pSid );
	return bRet;
}
