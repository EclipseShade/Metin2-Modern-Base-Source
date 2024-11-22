/////////////////////////////////////////////////////////////////////////////
// Name:        wx/statbmp.h
// Purpose:     wxStaticBitmap class interface
// Author:      Vadim Zeitlin
// Modified by:
// Created:     25.08.00
// RCS-ID:      $Id: statbmp.h 37066 2006-01-23 03:27:34Z MR $
// Copyright:   (c) 2000 Vadim Zeitlin
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _WX_STATBMP_H_BASE_
#define _WX_STATBMP_H_BASE_

#include "wx-2.8.10/defs.h"

#if wxUSE_STATBMP

#include "wx-2.8.10/control.h"
#include "wx-2.8.10/bitmap.h"
#include "wx-2.8.10/icon.h"

extern WXDLLEXPORT_DATA(const wxChar) wxStaticBitmapNameStr[];

// a control showing an icon or a bitmap
class WXDLLEXPORT wxStaticBitmapBase : public wxControl
{
public:
    wxStaticBitmapBase() { }
    virtual ~wxStaticBitmapBase();

    // our interface
    virtual void SetIcon(const wxIcon& icon) = 0;
    virtual void SetBitmap(const wxBitmap& bitmap) = 0;
    virtual wxBitmap GetBitmap() const = 0;
    virtual wxIcon GetIcon() const /* = 0 -- should be pure virtual */
    {
        // stub it out here for now as not all ports implement it (but they
        // should)
        return wxIcon();
    }

    // overriden base class virtuals
    virtual bool AcceptsFocus() const { return false; }
    virtual bool HasTransparentBackground() { return true; }

protected:
    virtual wxSize DoGetBestSize() const;

    DECLARE_NO_COPY_CLASS(wxStaticBitmapBase)
};

#if defined(__WXUNIVERSAL__)
    #include "wx-2.8.10/univ/statbmp.h"
#elif defined(__WXMSW__)
    #include "wx-2.8.10/msw/statbmp.h"
#elif defined(__WXMOTIF__)
    #include "wx-2.8.10/motif/statbmp.h"
#elif defined(__WXGTK20__)
    #include "wx-2.8.10/gtk/statbmp.h"
#elif defined(__WXGTK__)
    #include "wx-2.8.10/gtk1/statbmp.h"
#elif defined(__WXMAC__)
    #include "wx-2.8.10/mac/statbmp.h"
#elif defined(__WXCOCOA__)
    #include "wx-2.8.10/cocoa/statbmp.h"
#elif defined(__WXPM__)
    #include "wx-2.8.10/os2/statbmp.h"
#endif

#endif // wxUSE_STATBMP

#endif
    // _WX_STATBMP_H_BASE_
