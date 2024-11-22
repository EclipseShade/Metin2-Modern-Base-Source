/////////////////////////////////////////////////////////////////////////////
// Name:        wx/minifram.h
// Purpose:     wxMiniFrame base header
// Author:      Julian Smart
// Modified by:
// Created:
// Copyright:   (c) Julian Smart
// RCS-ID:      $Id: minifram.h 49299 2007-10-21 18:07:29Z PC $
// Licence:     wxWindows Licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _WX_MINIFRAM_H_BASE_
#define _WX_MINIFRAM_H_BASE_

#include "wx-2.8.10/defs.h"

#if wxUSE_MINIFRAME

#if defined(__WXPALMOS__)
#include "wx-2.8.10/palmos/minifram.h"
#elif defined(__WXMSW__)
#include "wx-2.8.10/msw/minifram.h"
#elif defined(__WXMOTIF__)
#include "wx-2.8.10/motif/minifram.h"
#elif defined(__WXGTK20__)
#include "wx-2.8.10/gtk/minifram.h"
#elif defined(__WXGTK__)
#include "wx-2.8.10/gtk1/minifram.h"
#elif defined(__WXX11__)
#include "wx-2.8.10/x11/minifram.h"
#elif defined(__WXMAC__)
#include "wx-2.8.10/mac/minifram.h"
#elif defined(__WXPM__)
#include "wx-2.8.10/os2/minifram.h"
#else
// TODO: it seems that wxMiniFrame could be just defined here generically
//       instead of having all the above port-specific headers
#include "wx-2.8.10/frame.h"
typedef wxFrame wxMiniFrame;
#endif

#endif // wxUSE_MINIFRAME
#endif // _WX_MINIFRAM_H_BASE_
