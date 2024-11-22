#if !defined(GRANNY_INSPECTOR_H)
/* ========================================================================
   (C) Copyright 1999-2002 by RAD Game Tools, All Rights Reserved.
   ======================================================================== */

#include "granny.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct granny_inspector granny_inspector;

struct granny_inspector;

/* granny_inspector_entry.h bindings: */
GRANNY_DYNLINK(granny_inspector *) GrannyOpenInspector(char const * UniqueID,
                                                       char const * Title);
GRANNY_DYNLINK(void) GrannyCloseInspector(granny_inspector * Inspector);
GRANNY_DYNLINK(void) GrannySetInspectorUpdateInterval(granny_inspector * Inspector,
                                                      granny_real32 Seconds);
GRANNY_DYNLINK(void) GrannyUpdateInspector(granny_inspector * Inspector);
GRANNY_DYNLINK(void) GrannyUpdateAllInspectors(granny_real32 SecondsElapsed);
#ifdef __cplusplus
}
#endif

#define GRANNY_INSPECTOR_H
#endif
