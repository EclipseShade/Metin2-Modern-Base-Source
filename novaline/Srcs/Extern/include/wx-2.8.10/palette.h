/////////////////////////////////////////////////////////////////////////////
// Name:        wx/palette.h
// Purpose:     Common header and base class for wxPalette
// Author:      Julian Smart
// Modified by:
// Created:
// RCS-ID:      $Id: palette.h 41751 2006-10-08 21:56:55Z VZ $
// Copyright:   (c) Julian Smart
// Licence:     wxWindows Licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _WX_PALETTE_H_BASE_
#define _WX_PALETTE_H_BASE_

#include "wx-2.8.10/defs.h"

#if wxUSE_PALETTE

#include "wx-2.8.10/object.h"
#include "wx-2.8.10/gdiobj.h"

// wxPaletteBase
class WXDLLEXPORT wxPaletteBase: public wxGDIObject
{
public:
    virtual ~wxPaletteBase() { }

    virtual bool Ok() const { return IsOk(); }
    virtual bool IsOk() const = 0;
    virtual int GetColoursCount() const { wxFAIL_MSG( _T("not implemented") ); return 0; }
};

#if defined(__WXPALMOS__)
    #include "wx-2.8.10/palmos/palette.h"
#elif defined(__WXMSW__)
    #include "wx-2.8.10/msw/palette.h"
#elif defined(__WXMOTIF__)
    #include "wx-2.8.10/motif/palette.h"
#elif defined(__WXGTK__) || defined(__WXCOCOA__)
    #include "wx-2.8.10/generic/paletteg.h"
#elif defined(__WXX11__)
    #include "wx-2.8.10/x11/palette.h"
#elif defined(__WXMGL__)
    #include "wx-2.8.10/mgl/palette.h"
#elif defined(__WXMAC__)
    #include "wx-2.8.10/mac/palette.h"
#elif defined(__WXPM__)
    #include "wx-2.8.10/os2/palette.h"
#endif

#if WXWIN_COMPATIBILITY_2_4
    #define wxColorMap wxPalette
    #define wxColourMap wxPalette
#endif

#endif // wxUSE_PALETTE

#endif
    // _WX_PALETTE_H_BASE_
