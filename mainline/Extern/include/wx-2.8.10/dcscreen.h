/////////////////////////////////////////////////////////////////////////////
// Name:        wx/dcscreen.h
// Purpose:     wxScreenDC base header
// Author:      Julian Smart
// Modified by:
// Created:
// Copyright:   (c) Julian Smart
// RCS-ID:      $Id: dcscreen.h 40865 2006-08-27 09:42:42Z VS $
// Licence:     wxWindows Licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _WX_DCSCREEN_H_BASE_
#define _WX_DCSCREEN_H_BASE_

#include "wx-2.8.10/defs.h"

#if defined(__WXPALMOS__)
#include "wx-2.8.10/palmos/dcscreen.h"
#elif defined(__WXMSW__)
#include "wx-2.8.10/msw/dcscreen.h"
#elif defined(__WXMOTIF__)
#include "wx-2.8.10/motif/dcscreen.h"
#elif defined(__WXGTK20__)
#include "wx-2.8.10/gtk/dcscreen.h"
#elif defined(__WXGTK__)
#include "wx-2.8.10/gtk1/dcscreen.h"
#elif defined(__WXX11__)
#include "wx-2.8.10/x11/dcscreen.h"
#elif defined(__WXMGL__)
#include "wx-2.8.10/mgl/dcscreen.h"
#elif defined(__WXDFB__)
#include "wx-2.8.10/dfb/dcscreen.h"
#elif defined(__WXMAC__)
#include "wx-2.8.10/mac/dcscreen.h"
#elif defined(__WXCOCOA__)
#include "wx-2.8.10/cocoa/dcscreen.h"
#elif defined(__WXPM__)
#include "wx-2.8.10/os2/dcscreen.h"
#endif

#endif
    // _WX_DCSCREEN_H_BASE_
