/////////////////////////////////////////////////////////////////////////////
// Name:        wx/wx.h
// Purpose:     wxWidgets central header including the most often used ones
// Author:      Julian Smart
// Modified by:
// Created:     01/02/97
// RCS-ID:      $Id: wx.h 40943 2006-08-31 19:31:43Z ABX $
// Copyright:   (c) Julian Smart
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _WX_WX_H_
#define _WX_WX_H_

#include "wx-2.8.10/defs.h"
#include "wx-2.8.10/object.h"
#include "wx-2.8.10/dynarray.h"
#include "wx-2.8.10/list.h"
#include "wx-2.8.10/hash.h"
#include "wx-2.8.10/string.h"
#include "wx-2.8.10/hashmap.h"
#include "wx-2.8.10/arrstr.h"
#include "wx-2.8.10/intl.h"
#include "wx-2.8.10/log.h"
#include "wx-2.8.10/event.h"
#include "wx-2.8.10/app.h"
#include "wx-2.8.10/utils.h"
#include "wx-2.8.10/stream.h"
#include "wx-2.8.10/memory.h"
#include "wx-2.8.10/math.h"
#include "wx-2.8.10/stopwatch.h"
#include "wx-2.8.10/module.h"

#if wxUSE_GUI

#include "wx-2.8.10/window.h"
#include "wx-2.8.10/containr.h"
#include "wx-2.8.10/panel.h"
#include "wx-2.8.10/toplevel.h"
#include "wx-2.8.10/frame.h"
#include "wx-2.8.10/gdicmn.h"
#include "wx-2.8.10/gdiobj.h"
#include "wx-2.8.10/region.h"
#include "wx-2.8.10/bitmap.h"
#include "wx-2.8.10/image.h"
#include "wx-2.8.10/colour.h"
#include "wx-2.8.10/font.h"
#include "wx-2.8.10/dc.h"
#include "wx-2.8.10/dcclient.h"
#include "wx-2.8.10/dcmemory.h"
#include "wx-2.8.10/dcprint.h"
#include "wx-2.8.10/dcscreen.h"
#include "wx-2.8.10/button.h"
#include "wx-2.8.10/menuitem.h"
#include "wx-2.8.10/menu.h"
#include "wx-2.8.10/pen.h"
#include "wx-2.8.10/brush.h"
#include "wx-2.8.10/palette.h"
#include "wx-2.8.10/icon.h"
#include "wx-2.8.10/cursor.h"
#include "wx-2.8.10/dialog.h"
#include "wx-2.8.10/timer.h"
#include "wx-2.8.10/settings.h"
#include "wx-2.8.10/msgdlg.h"
#include "wx-2.8.10/cmndata.h"
#include "wx-2.8.10/dataobj.h"

#include "wx-2.8.10/control.h"
#include "wx-2.8.10/ctrlsub.h"
#include "wx-2.8.10/bmpbuttn.h"
#include "wx-2.8.10/checkbox.h"
#include "wx-2.8.10/checklst.h"
#include "wx-2.8.10/choice.h"
#include "wx-2.8.10/scrolbar.h"
#include "wx-2.8.10/stattext.h"
#include "wx-2.8.10/statbmp.h"
#include "wx-2.8.10/statbox.h"
#include "wx-2.8.10/listbox.h"
#include "wx-2.8.10/radiobox.h"
#include "wx-2.8.10/radiobut.h"
#include "wx-2.8.10/textctrl.h"
#include "wx-2.8.10/slider.h"
#include "wx-2.8.10/gauge.h"
#include "wx-2.8.10/scrolwin.h"
#include "wx-2.8.10/dirdlg.h"
#include "wx-2.8.10/toolbar.h"
#include "wx-2.8.10/combobox.h"
#include "wx-2.8.10/layout.h"
#include "wx-2.8.10/sizer.h"
#include "wx-2.8.10/mdi.h"
#include "wx-2.8.10/statusbr.h"
#include "wx-2.8.10/choicdlg.h"
#include "wx-2.8.10/textdlg.h"
#include "wx-2.8.10/filedlg.h"

// always include, even if !wxUSE_VALIDATORS because we need wxDefaultValidator
#include "wx-2.8.10/validate.h"

#if wxUSE_VALIDATORS
    #include "wx-2.8.10/valtext.h"
#endif // wxUSE_VALIDATORS

#endif // wxUSE_GUI

#endif // _WX_WX_H_
