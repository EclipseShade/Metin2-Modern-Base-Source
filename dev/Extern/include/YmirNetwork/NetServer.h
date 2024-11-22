//
// Copyright 2010 Ymir Entertainment. All rights reserved.
//
#ifndef _YMIRNETWORK_NETSERVER_H
#define _YMIRNETWORK_NETSERVER_H

#include <stdint.h>
#include <boost/noncopyable.hpp>
#include <asio.hpp>
#include <string>

class EL_NetPeer;

class EL_NetServer : private boost::noncopyable
{
    protected:
        asio::ip::tcp::acceptor m_acceptor;

    public:
        explicit EL_NetServer(asio::io_service* io_service);
		virtual ~EL_NetServer();

        bool Bind(uint16_t port);
        bool Bind(std::string address, uint16_t port);
        bool Bind(const asio::ip::tcp::endpoint& endpoint);

	private:
		void AsyncAccept();
		void HandleAccept(const asio::error_code& e, EL_NetPeer* peerPtr);

		// 어플리케이션에 알맞게 EL_NetPeer를 상속한 클래스를 리턴할 것이다.
		virtual EL_NetPeer* NewPeer() = 0;
};

#endif  // _YMIRNETWORK_NETSERVER_H
