/**
 * @file	EA_CSystemService.h
 * @brief	System service class for Earth
 * @author	Standil (cpascal@cpascal.net)
 * 
 * @version	2006/01/04 cpascal - First Release
 */

#ifndef _EA_CSYSTEMSERVICE_H_
#define _EA_CSYSTEMSERVICE_H_

#include <winsvc.h>

_EA_NAMESPACE_BEGIN

class EA_CSystemService
{
public:
	EA_CSystemService( void );
	EA_CSystemService( LPCTSTR IN tszMachineName, LPCTSTR IN tszDatabaseName=NULL, const DWORD dwDesiredAccess=SC_MANAGER_ALL_ACCESS );
	~EA_CSystemService( void );

	/**
	 * @brief	Open source control manager
	 */
	BOOL		OpenManager( LPCTSTR IN tszMachineName=NULL, LPCTSTR IN tszDatabaseName=NULL, const DWORD dwDesiredAccess=SC_MANAGER_ALL_ACCESS );

	/**
	 * @brief	Close source control manager
	 */
	void		CloseManager( void );

	/**
	 * @brief	Check source control manager is opened
	 */
	BOOL		IsManagerOpened( void )				{ return (m_hSCManager != NULL); }

	/**
	 * @brief	Enumerate service
	 */
	BOOL		Enumerate( LPBYTE OUT pOutBuffer, DWORD* INOUT pdwOutBufferSize, DWORD* INOUT pdwServiceReturned );
	/**
	 * @brief	Install service
	 */
	BOOL		Install( LPCTSTR IN tszService, LPCTSTR IN tszDisplay, LPCTSTR IN tszExecutable, 
				 const DWORD IN dwStartType, LPCTSTR IN tszDependencies=NULL, LPCTSTR IN tszAccount=NULL, LPCTSTR IN tszPassword=NULL );
	/**
	 * @brief	Uninstall service
	 */
	BOOL		Uninstall( LPCTSTR IN tszService );
	/**
	 * @brief	Start service
	 */
	BOOL		Start( LPCTSTR IN tszService, int nArgc, TCHAR* tszArgv[] );
	/**
	 * @brief	Stop service
	 */
	BOOL		Stop( LPCTSTR IN tszService );
	/**
	 * @brief	Control service
	 */
	BOOL		Control( LPCTSTR IN tszService, const DWORD IN dwControl, LPSERVICE_STATUS INOUT pServiceStatus );

	/**
	 * @brief	Get service's current state
	 */
	DWORD		GetCurrentState( LPCTSTR IN tszService );
	/**
	 * @brief	Get service's current state
	 */
	BOOL		GetStatus( LPCTSTR IN tszService, SERVICE_STATUS* OUT pServiceStatus );

private:
	SC_HANDLE	m_hSCManager;
};

_EA_NAMESPACE_END

#endif /* !_EA_CSYSTEMSERVICE_H_ */
