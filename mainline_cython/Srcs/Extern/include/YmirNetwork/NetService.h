//
// Copyright 2010 Ymir Entertainment. All rights reserved.
//
//
#ifndef _YMIRNETWORK_NETSERVICE_H
#define _YMIRNETWORK_NETSERVICE_H

// Note about asio
//
// BOOST_ASIO_ENABLE_BUFFER_DEBUGGING / BOOST_ASIO_DISABLE_BUFFER_DEBUGGING to
// enable / disable buffer debugging, with buffer debugging below code will
// raise assertion.
//
// void dont_do_this()
// {
//    std::string msg = "Hello, world!";
//    asio::async_write(sock, asio::buffer(msg), my_handler);
// }
//
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <asio.hpp>

class EL_NetService : boost::noncopyable
{
    public:
        size_t Poll()
        {
            return io_service.poll();
        }

        size_t Run()
        {
            return io_service.run();
		}
		
		void Stop()
		{
			io_service.stop();
		}

        asio::io_service* operator() (void)
        {
            return &io_service;
        }

        asio::io_service io_service;
};

typedef boost::shared_ptr<EL_NetService> EL_NetServicePtr;

#endif  // _YMIRNETWORK_NETSERVICE_H
