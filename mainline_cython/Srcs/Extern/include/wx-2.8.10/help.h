/////////////////////////////////////////////////////////////////////////////
// Name:        help.h
// Purpose:     wxHelpController base header
// Author:      wxWidgets Team
// Modified by:
// Created:
// Copyright:   (c) Julian Smart
// RCS-ID:      $Id: help.h 33948 2005-05-04 18:57:50Z JS $
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _WX_HELP_H_BASE_
#define _WX_HELP_H_BASE_

#include "wx-2.8.10/defs.h"

#if wxUSE_HELP

#include "wx-2.8.10/helpbase.h"

#ifdef __WXWINCE__
    #include "wx-2.8.10/msw/wince/helpwce.h"

    #define wxHelpController wxWinceHelpController
#elif defined(__WXPALMOS__)
    #include "wx-2.8.10/palmos/help.h"

    #define wxHelpController wxPalmHelpController
#elif defined(__WXMSW__)
    #include "wx-2.8.10/msw/helpchm.h"

    #define wxHelpController wxCHMHelpController
#else // !MSW

#if wxUSE_WXHTML_HELP
    #include "wx-2.8.10/html/helpctrl.h"
    #define wxHelpController wxHtmlHelpController
#else
    #include "wx-2.8.10/generic/helpext.h"
    #define wxHelpController wxExtHelpController
#endif

#endif // MSW/!MSW

#endif // wxUSE_HELP

#endif
    // _WX_HELP_H_BASE_
