//
// Copyright 2010 Ymir Entertainment. All rights reserved.
//
#ifndef _YMIRNETWORK_YMIRNETWORKLINK_H
#define _YMIRNETWORK_YMIRNETWORKLINK_H

#if defined(_MT)
    #define _EL_RUNTIME_THREADMODEL "MT"
#else
    #define _EL_RUNTIME_THREADMODEL "ST"
#endif

#if defined(_DLL)
    #error "YmirNetwork doesn't support Multithreaded-DLL threading model currently."
#endif

#if defined(_DEBUG) || defined(DEBUG)
    #define _EL_RUNTIME_DEBUG "d"
#else
    #define _EL_RUNTIME_DEBUG ""
#endif

#define _EL_RUNTIME_LIBRARY         _EL_RUNTIME_THREADMODEL _EL_RUNTIME_DEBUG

#pragma comment(lib, "YmirNetwork" _EL_RUNTIME_LIBRARY ".lib")

#endif  // _YMIRNETWORK_YMIRNETWORKLINK_H
