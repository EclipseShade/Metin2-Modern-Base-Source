/////////////////////////////////////////////////////////////////////////////
// Name:        tooltip.h
// Purpose:     wxToolTip base header
// Author:      Robert Roebling
// Modified by:
// Created:
// Copyright:   (c) Robert Roebling
// RCS-ID:      $Id: tooltip.h 37066 2006-01-23 03:27:34Z MR $
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _WX_TOOLTIP_H_BASE_
#define _WX_TOOLTIP_H_BASE_

#include "wx-2.8.10/defs.h"

#if wxUSE_TOOLTIPS

#if defined(__WXMSW__)
#include "wx-2.8.10/msw/tooltip.h"
#elif defined(__WXMOTIF__)
// #include "wx-2.8.10/motif/tooltip.h"
#elif defined(__WXGTK20__)
#include "wx-2.8.10/gtk/tooltip.h"
#elif defined(__WXGTK__)
#include "wx-2.8.10/gtk1/tooltip.h"
#elif defined(__WXMAC__)
#include "wx-2.8.10/mac/tooltip.h"
#elif defined(__WXCOCOA__)
#include "wx-2.8.10/cocoa/tooltip.h"
#elif defined(__WXPM__)
#include "wx-2.8.10/os2/tooltip.h"
#endif

#endif
    // wxUSE_TOOLTIPS

#endif
    // _WX_TOOLTIP_H_BASE_
