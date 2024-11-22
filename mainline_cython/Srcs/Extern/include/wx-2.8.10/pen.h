/////////////////////////////////////////////////////////////////////////////
// Name:        wx/pen.h
// Purpose:     Base header for wxPen
// Author:      Julian Smart
// Modified by:
// Created:
// RCS-ID:      $Id: pen.h 40865 2006-08-27 09:42:42Z VS $
// Copyright:   (c) Julian Smart
// Licence:     wxWindows Licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _WX_PEN_H_BASE_
#define _WX_PEN_H_BASE_

#include "wx-2.8.10/defs.h"

#if defined(__WXPALMOS__)
#include "wx-2.8.10/palmos/pen.h"
#elif defined(__WXMSW__)
#include "wx-2.8.10/msw/pen.h"
#elif defined(__WXMOTIF__) || defined(__WXX11__)
#include "wx-2.8.10/x11/pen.h"
#elif defined(__WXGTK20__)
#include "wx-2.8.10/gtk/pen.h"
#elif defined(__WXGTK__)
#include "wx-2.8.10/gtk1/pen.h"
#elif defined(__WXMGL__)
#include "wx-2.8.10/mgl/pen.h"
#elif defined(__WXDFB__)
#include "wx-2.8.10/dfb/pen.h"
#elif defined(__WXMAC__)
#include "wx-2.8.10/mac/pen.h"
#elif defined(__WXCOCOA__)
#include "wx-2.8.10/cocoa/pen.h"
#elif defined(__WXPM__)
#include "wx-2.8.10/os2/pen.h"
#endif

#endif
    // _WX_PEN_H_BASE_
