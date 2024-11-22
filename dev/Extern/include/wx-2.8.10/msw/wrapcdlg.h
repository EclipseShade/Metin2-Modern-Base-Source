///////////////////////////////////////////////////////////////////////////////
// Name:        wx/msw/wrapcdlg.h
// Purpose:     Wrapper for the standard <commdlg.h> header
// Author:      Wlodzimierz ABX Skiba
// Modified by:
// Created:     22.03.2005
// RCS-ID:      $Id: wrapcdlg.h 43151 2006-11-07 09:08:33Z JS $
// Copyright:   (c) 2005 Wlodzimierz Skiba
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef _WX_MSW_WRAPCDLG_H_
#define _WX_MSW_WRAPCDLG_H_

#include "wx-2.8.10/defs.h"

#include "wx-2.8.10/msw/wrapwin.h"
#include "wx-2.8.10/msw/private.h"
#include "wx-2.8.10/msw/missing.h"

#if wxUSE_COMMON_DIALOGS && !defined(__SMARTPHONE__) && !defined(__WXMICROWIN__)
    #include <commdlg.h>
#endif

#include "wx-2.8.10/msw/winundef.h"

#endif // _WX_MSW_WRAPCDLG_H_

