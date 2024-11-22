/**
 * @file	EA_CUAC.h
 * @brief	UAC class for Earth
 * @author	Standil (cpascal@cpascal.net)
 * 
 * @version	2010/04/26 cpascal - First Release
 */

#ifndef _EA_CUAC_H_
#define _EA_CUAC_H_

_EA_NAMESPACE_BEGIN

#if !defined(NTDDI_VISTA)
enum TOKEN_ELEVATION_TYPE { 
	TokenElevationTypeDefault = 1, 
	TokenElevationTypeFull, 
	TokenElevationTypeLimited 
};

enum _TOKEN_INFORMATION_CLASS___VISTA {
	TokenElevationType = (TokenOrigin+1),
	TokenLinkedToken,
	TokenElevation,
	TokenHasRestrictions,
	TokenAccessInformation,
	TokenVirtualizationAllowed,
	TokenVirtualizationEnabled,
	TokenIntegrityLevel,
	TokenUIAccess,
	TokenMandatoryPolicy,
	TokenLogonSid,
};
#endif

class EA_CUAC
{
public:
	EA_CUAC();
	~EA_CUAC();

	MA_BOOL		Init( void );

	MA_BOOL		RunElevated( MA_LPCTSTR tszFile, MA_LPCTSTR tszParameters );
	MA_BOOL		HasAdminRights( void ) const;
	DWORD		GetElevationType( TOKEN_ELEVATION_TYPE* peTokenElevationType ) const;
	MA_BOOL		IsUACSupported( void ) const;
	MA_BOOL		IsFileWritable( MA_LPCTSTR tszFile ) const;

protected:
	MA_BOOL		m_bInit;
};

_EA_NAMESPACE_END

#endif /* !_EA_CUAC_H_ */
