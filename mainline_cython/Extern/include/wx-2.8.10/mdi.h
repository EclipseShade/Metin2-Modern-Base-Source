/////////////////////////////////////////////////////////////////////////////
// Name:        wx/mdi.h
// Purpose:     wxMDI base header
// Author:      Julian Smart
// Modified by:
// Created:
// Copyright:   (c) Julian Smart
// RCS-ID:      $Id: mdi.h 37066 2006-01-23 03:27:34Z MR $
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _WX_MDI_H_BASE_
#define _WX_MDI_H_BASE_

#include "wx-2.8.10/defs.h"

#if wxUSE_MDI

#if defined(__WXUNIVERSAL__)
    #include "wx-2.8.10/generic/mdig.h"
#elif defined(__WXMSW__)
    #include "wx-2.8.10/msw/mdi.h"
#elif defined(__WXMOTIF__)
    #include "wx-2.8.10/motif/mdi.h"
#elif defined(__WXGTK20__)
    #include "wx-2.8.10/gtk/mdi.h"
#elif defined(__WXGTK__)
    #include "wx-2.8.10/gtk1/mdi.h"
#elif defined(__WXMAC__)
    #include "wx-2.8.10/mac/mdi.h"
#elif defined(__WXCOCOA__)
    #include "wx-2.8.10/cocoa/mdi.h"
#elif defined(__WXPM__)
    #include "wx-2.8.10/generic/mdig.h"
#endif

#endif // wxUSE_MDI

#endif
    // _WX_MDI_H_BASE_
