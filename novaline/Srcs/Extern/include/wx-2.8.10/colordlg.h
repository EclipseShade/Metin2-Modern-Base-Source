/////////////////////////////////////////////////////////////////////////////
// Name:        wx/colrdlgg.h
// Purpose:     wxColourDialog
// Author:      Vadim Zeitiln
// Modified by:
// Created:     01/02/97
// RCS-ID:      $Id: colordlg.h 36623 2006-01-02 14:26:36Z JS $
// Copyright:   (c) wxWidgets team
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _WX_COLORDLG_H_BASE_
#define _WX_COLORDLG_H_BASE_

#include "wx-2.8.10/defs.h"

#if wxUSE_COLOURDLG

#if defined(__WXMSW__) && !defined(__WXUNIVERSAL__)
    #include "wx-2.8.10/msw/colordlg.h"
#elif defined(__WXMAC__) && !defined(__WXUNIVERSAL__)
    #include "wx-2.8.10/mac/colordlg.h"
#elif defined(__WXGTK20__) && !defined(__WXUNIVERSAL__)
    #include "wx-2.8.10/gtk/colordlg.h"
#elif defined(__WXPALMOS__)
    #include "wx-2.8.10/palmos/colordlg.h"
#else
    #include "wx-2.8.10/generic/colrdlgg.h"

    #define wxColourDialog wxGenericColourDialog
#endif

// get the colour from user and return it
wxColour WXDLLEXPORT
wxGetColourFromUser(wxWindow *parent = (wxWindow *)NULL,
                    const wxColour& colInit = wxNullColour, const wxString& caption = wxEmptyString);

#endif // wxUSE_COLOURDLG

#endif
    // _WX_COLORDLG_H_BASE_
