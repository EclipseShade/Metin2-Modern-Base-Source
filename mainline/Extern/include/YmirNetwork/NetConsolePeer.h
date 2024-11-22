//
// Copyright 2010 Ymir Entertainment. All rights reserved.
//
#ifndef _YMIRNETWORK_NETCONSOLEPEER_H
#define _YMIRNETWORK_NETCONSOLEPEER_H

#include "NetPeer.h"

class EL_NetConsolePeer : public EL_NetPeer
{
	public:
		explicit EL_NetConsolePeer(asio::io_service* io_service);

		virtual void OnInit();
		
		virtual void OnDisconnect();

		virtual void ProcessLine(const char* line, size_t line_size) = 0;

		virtual void HandleRead(const asio::error_code& error, size_t bytes_transferred);

	protected:
		virtual void AsyncRead(size_t size = 0);
};

#endif  // _YMIRNETWORK_NETCONSOLEPEER_H
