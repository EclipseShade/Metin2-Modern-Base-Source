#if !defined(GRN2GR2_H)
/* ========================================================================
   $RCSfile: grn2gr2.h,v $
   $Date: 2005/08/18 07:21:02 $
   $Revision: 1.1 $
   $Creator: Casey Muratori $
   (C) Copyright 1999-2002 by RAD Game Tools, All Rights Reserved.
   ======================================================================== */

#if _WIN32
#define GRANNY_DYNEXP(ret) __declspec(dllexport) ret __stdcall
#else
#define GRANNY_DYNEXP(ret) ret
#endif

GRANNY_DYNEXP(void) GRN2GR2ConvertGRNFile(char const *InGRNFile,
                                          char const *OutGR2File,
                                          bool ShowInterface,
                                          char const *LoadSettingsFile);
GRANNY_DYNEXP(void) GRN2GR2DumpFile(char const *GRNFileName);

#define GRN2GR2_H
#endif
