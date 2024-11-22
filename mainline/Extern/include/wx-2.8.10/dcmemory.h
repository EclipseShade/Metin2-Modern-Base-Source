/////////////////////////////////////////////////////////////////////////////
// Name:        wx/dcmemory.h
// Purpose:     wxMemoryDC base header
// Author:      Julian Smart
// Modified by:
// Created:
// Copyright:   (c) Julian Smart
// RCS-ID:      $Id: dcmemory.h 43843 2006-12-07 05:44:44Z PC $
// Licence:     wxWindows Licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _WX_DCMEMORY_H_BASE_
#define _WX_DCMEMORY_H_BASE_

#include "wx-2.8.10/bitmap.h"

// NOTE: different native implementations of wxMemoryDC will derive from
//       different wxDC classes (wxPaintDC, wxWindowDC, etc), so that
//       we cannot derive wxMemoryDCBase from wxDC and then use it as the
//       only base class for native impl of wxMemoryDC...
class WXDLLEXPORT wxMemoryDCBase
{
public:
    wxMemoryDCBase() { }

    // avoid warnings about having virtual functions but non virtual dtor
    virtual ~wxMemoryDCBase() { }

    // select the given bitmap to draw on it
    void SelectObject(wxBitmap& bmp)
    {
        // make sure that the given wxBitmap is not sharing its data with other
        // wxBitmap instances as its contents will be modified by any drawing
        // operation done on this DC
        if (bmp.IsOk())
            bmp.UnShare();

        DoSelect(bmp);
    }

    // select the given bitmap for read-only
    virtual void SelectObjectAsSource(const wxBitmap& bmp)
    {
        DoSelect(bmp);
    }

protected:
    virtual void DoSelect(const wxBitmap& bmp) = 0;
};

#if defined(__WXPALMOS__)
#include "wx-2.8.10/palmos/dcmemory.h"
#elif defined(__WXMSW__)
#include "wx-2.8.10/msw/dcmemory.h"
#elif defined(__WXMOTIF__)
#include "wx-2.8.10/motif/dcmemory.h"
#elif defined(__WXGTK20__)
#include "wx-2.8.10/gtk/dcmemory.h"
#elif defined(__WXGTK__)
#include "wx-2.8.10/gtk1/dcmemory.h"
#elif defined(__WXX11__)
#include "wx-2.8.10/x11/dcmemory.h"
#elif defined(__WXMGL__)
#include "wx-2.8.10/mgl/dcmemory.h"
#elif defined(__WXDFB__)
#include "wx-2.8.10/dfb/dcmemory.h"
#elif defined(__WXMAC__)
#include "wx-2.8.10/mac/dcmemory.h"
#elif defined(__WXCOCOA__)
#include "wx-2.8.10/cocoa/dcmemory.h"
#elif defined(__WXPM__)
#include "wx-2.8.10/os2/dcmemory.h"
#endif

#endif
    // _WX_DCMEMORY_H_BASE_
