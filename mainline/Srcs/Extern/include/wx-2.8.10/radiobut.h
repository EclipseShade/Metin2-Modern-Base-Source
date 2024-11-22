///////////////////////////////////////////////////////////////////////////////
// Name:        wx/radiobut.h
// Purpose:     wxRadioButton declaration
// Author:      Vadim Zeitlin
// Modified by:
// Created:     07.09.00
// RCS-ID:      $Id: radiobut.h 37066 2006-01-23 03:27:34Z MR $
// Copyright:   (c) Vadim Zeitlin
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef _WX_RADIOBUT_H_BASE_
#define _WX_RADIOBUT_H_BASE_

#include "wx-2.8.10/defs.h"

#if wxUSE_RADIOBTN

/*
   There is no wxRadioButtonBase class as wxRadioButton interface is the same
   as wxCheckBox(Base), but under some platforms wxRadioButton really
   derives from wxCheckBox and on the others it doesn't.

   The pseudo-declaration of wxRadioButtonBase would look like this:

   class wxRadioButtonBase : public ...
   {
   public:
        virtual void SetValue(bool value);
        virtual bool GetValue() const;
   };
 */

#include "wx-2.8.10/control.h"

extern WXDLLEXPORT_DATA(const wxChar) wxRadioButtonNameStr[];

#if defined(__WXUNIVERSAL__)
    #include "wx-2.8.10/univ/radiobut.h"
#elif defined(__WXMSW__)
    #include "wx-2.8.10/msw/radiobut.h"
#elif defined(__WXMOTIF__)
    #include "wx-2.8.10/motif/radiobut.h"
#elif defined(__WXGTK20__)
    #include "wx-2.8.10/gtk/radiobut.h"
#elif defined(__WXGTK__)
    #include "wx-2.8.10/gtk1/radiobut.h"
#elif defined(__WXMAC__)
    #include "wx-2.8.10/mac/radiobut.h"
#elif defined(__WXCOCOA__)
    #include "wx-2.8.10/cocoa/radiobut.h"
#elif defined(__WXPM__)
    #include "wx-2.8.10/os2/radiobut.h"
#elif defined(__WXPALMOS__)
    #include "wx-2.8.10/palmos/radiobut.h"
#endif

#endif // wxUSE_RADIOBTN

#endif
    // _WX_RADIOBUT_H_BASE_
