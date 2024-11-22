/////////////////////////////////////////////////////////////////////////////
// Name:        wx/brush.h
// Purpose:     Includes platform-specific wxBrush file
// Author:      Julian Smart
// Modified by:
// Created:
// RCS-ID:      $Id: brush.h 40865 2006-08-27 09:42:42Z VS $
// Copyright:   Julian Smart
// Licence:     wxWindows Licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _WX_BRUSH_H_BASE_
#define _WX_BRUSH_H_BASE_

#include "wx-2.8.10/defs.h"
#include "wx-2.8.10/object.h"
#include "wx-2.8.10/gdiobj.h"

// wxBrushBase
class WXDLLEXPORT wxBrushBase: public wxGDIObject
{
public:
    virtual ~wxBrushBase() { }

    virtual int GetStyle() const = 0;

    virtual bool IsHatch() const
        { return (GetStyle()>=wxFIRST_HATCH) && (GetStyle()<=wxLAST_HATCH); }
};

#if defined(__WXPALMOS__)
    #include "wx-2.8.10/palmos/brush.h"
#elif defined(__WXMSW__)
    #include "wx-2.8.10/msw/brush.h"
#elif defined(__WXMOTIF__) || defined(__WXX11__)
    #include "wx-2.8.10/x11/brush.h"
#elif defined(__WXGTK20__)
    #include "wx-2.8.10/gtk/brush.h"
#elif defined(__WXGTK__)
    #include "wx-2.8.10/gtk1/brush.h"
#elif defined(__WXMGL__)
    #include "wx-2.8.10/mgl/brush.h"
#elif defined(__WXDFB__)
    #include "wx-2.8.10/dfb/brush.h"
#elif defined(__WXMAC__)
    #include "wx-2.8.10/mac/brush.h"
#elif defined(__WXCOCOA__)
    #include "wx-2.8.10/cocoa/brush.h"
#elif defined(__WXPM__)
    #include "wx-2.8.10/os2/brush.h"
#endif

#endif
    // _WX_BRUSH_H_BASE_
