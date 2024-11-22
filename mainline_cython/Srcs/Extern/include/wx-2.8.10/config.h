/////////////////////////////////////////////////////////////////////////////
// Name:        config.h
// Purpose:     wxConfig base header
// Author:      Julian Smart
// Modified by:
// Created:
// Copyright:   (c) Julian Smart
// RCS-ID:      $Id: config.h 33948 2005-05-04 18:57:50Z JS $
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _WX_CONFIG_H_BASE_
#define _WX_CONFIG_H_BASE_

#include "wx-2.8.10/defs.h"
#include "wx-2.8.10/confbase.h"

#if defined(__WXMSW__) && wxUSE_CONFIG_NATIVE
#    ifdef __WIN32__
#        include "wx-2.8.10/msw/regconf.h"
#    else
#        include "wx-2.8.10/msw/iniconf.h"
#    endif
#elif defined(__WXPALMOS__) && wxUSE_CONFIG_NATIVE
#    include "wx-2.8.10/palmos/prefconf.h"
#else
#    include "wx-2.8.10/fileconf.h"
#endif

#endif
    // _WX_CONFIG_H_BASE_
