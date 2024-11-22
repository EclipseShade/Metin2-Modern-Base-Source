#if !defined(GRANNY_VERSION_H)
/* ========================================================================
   $RCSfile: granny_version.h,v $
   $Date: 2005/08/18 07:21:02 $
   $Revision: 1.1 $
   $Creator: Casey Muratori $
   (C) Copyright 1999-2002 by RAD Game Tools, All Rights Reserved.
   ======================================================================== */

#if !defined(EXPMACRO)
#define EXPMACRO
#endif

#if !defined(EXPGROUP)
#define EXPGROUP(GroupName)
#endif

EXPGROUP(VersionGroup)

#define ProductVersion "2.4.0.7"  EXPMACRO
#define ProductMajorVersion   2   EXPMACRO
#define ProductMinorVersion   4   EXPMACRO
#define ProductCustomization  0   EXPMACRO
#define ProductBuildNumber    7   EXPMACRO

#define ProductReleaseName prerelease EXPMACRO
#define ProductReleaseString "pre-release"

#define ProductCompanyName "RAD Game Tools, Inc." EXPMACRO
#define ProductName "Granny" EXPMACRO
#define ProductCopyrightYears "1999-2003"
#define ProductCopyright "1999-2003 by RAD Game Tools, Inc., All Rights Reserved."  EXPMACRO
#define ProductTrademarks ProductName " is a registered trademark of " ProductCompanyName EXPMACRO
#define ProductComments "Who's your Granny?" EXPMACRO

#define ProductSupportAddress "granny1@radgametools.com" EXPMACRO
#define ProductSupportPage "www.radgametools.com/gramain.htm" EXPMACRO

#define GRANNY_VERSION_H
#endif
