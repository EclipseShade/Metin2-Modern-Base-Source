//
// Copyright 2010 Ymir Entertainment. All rights reserved.
//
#ifndef _YMIRNETWORK_YMIRNETWORKPCH_H
#define _YMIRNETWORK_YMIRNETWORKPCH_H

#ifdef _WIN32
#ifndef _WIN32_WINNT
// 0x0501 == Windows XP
#define _WIN32_WINNT 0x0501
#endif
#endif

#include <boost/weak_ptr.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/format.hpp>
#include <boost/bind.hpp>
#include <boost/noncopyable.hpp>
#include <boost/unordered_map.hpp>
#include <asio.hpp>

#include <iostream>
#include <string>
#include <vector>

#endif  // _YMIRNETWORK_YMIRNETWORKPCH_H
