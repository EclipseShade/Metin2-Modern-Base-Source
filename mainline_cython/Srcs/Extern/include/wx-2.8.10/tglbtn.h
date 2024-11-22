/////////////////////////////////////////////////////////////////////////////
// Name:        wx/tglbtn.h
// Purpose:     This dummy header includes the proper header file for the
//              system we're compiling under.
// Author:      John Norris, minor changes by Axel Schlueter
// Modified by:
// Created:     08.02.01
// RCS-ID:      $Id: tglbtn.h 39293 2006-05-23 17:53:50Z JS $
// Copyright:   (c) 2000 Johnny C. Norris II
// License:     wxWindows Licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _WX_TOGGLEBUTTON_H_BASE_
#define _WX_TOGGLEBUTTON_H_BASE_

#include "wx-2.8.10/defs.h"

#if wxUSE_TOGGLEBTN

#include "wx-2.8.10/event.h"
#include "wx-2.8.10/control.h"     // base class

BEGIN_DECLARE_EVENT_TYPES()
    DECLARE_EVENT_TYPE(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, 19)
END_DECLARE_EVENT_TYPES()

#define EVT_TOGGLEBUTTON(id, fn) \
    wx__DECLARE_EVT1(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, id, wxCommandEventHandler(fn))

#if defined(__WXUNIVERSAL__)
    #include "wx-2.8.10/univ/tglbtn.h"
#elif defined(__WXMSW__)
    #include "wx-2.8.10/msw/tglbtn.h"
#elif defined(__WXGTK20__)
    #include "wx-2.8.10/gtk/tglbtn.h"
#elif defined(__WXGTK__)
    #include "wx-2.8.10/gtk1/tglbtn.h"
# elif defined(__WXMOTIF__)
    #include "wx-2.8.10/motif/tglbtn.h"
#elif defined(__WXMAC__)
    #include "wx-2.8.10/mac/tglbtn.h"
#elif defined(__WXPALMOS__)
    #include "wx-2.8.10/palmos/tglbtn.h"
#elif defined(__WXPM__)
    #include "wx-2.8.10/os2/tglbtn.h"
#endif

#endif // wxUSE_TOGGLEBTN

#endif // _WX_TOGGLEBUTTON_H_BASE_

