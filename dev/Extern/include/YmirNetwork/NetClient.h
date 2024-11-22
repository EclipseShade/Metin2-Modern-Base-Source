//
// Copyright 2010 Ymir Entertainment. All rights reserved.
//
#ifndef _YMIRNETWORK_NETCLIENT_H
#define _YMIRNETWORK_NETCLIENT_H

#include <stdint.h>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <asio.hpp>
#include <string>
#include "NetPeer.h"

struct EL_NetPacket;

class EL_NetClient : public EL_NetPeer
{
	public:
		explicit EL_NetClient(asio::io_service* io_service,
				uint32_t autoReconnectCycle = 0,        // 0 == 재접속하지 않음
				size_t MaxInputSize = 1024*1024*4,      // 입력 버퍼 최대 4MB
				size_t ReserveInputSize = 1024*1024,    // 입력 버퍼 초기 1MB
				size_t MaxOutputSize = 1024*1024*4,     // 입력 버퍼 최대 4MB
				size_t ReserveOutputSize = 1024*1024);  // 입력 버퍼 초기 1MB

		virtual void OnDisconnect();  // 상속시 자식에서도 EL_NetCliente::OnDisconnect 반드시 불러줘야함

		bool Connect(const std::string& host, const std::string& service);
		bool Connect(const std::string& host, uint16_t port);

		void Reconnect(const std::string& host, const std::string& service);
		void Reconnect(const std::string& host, uint16_t port);

		// SetAutoReconnectCycle
		// 0을 넣어 재접속 시도 종료, !0을 넣어 재시작 가능
		void SetAutoReconnectCycle(uint32_t autoReconnectCycle);

	protected:
		asio::ip::tcp::resolver::iterator m_endpointStart;
		uint32_t m_autoReconnectCycle;  // Millisecond
		bool m_connected;
		asio::deadline_timer m_reconnectTimer;
		bool m_isReconnectOnce;

	private:
		bool TryReconnect();  // 재접속 시도
		bool Connect(asio::ip::tcp::resolver::iterator endpoint_iterator);  // 실제 접속 함수 호출
		void HandleConnect(const asio::error_code& e, asio::ip::tcp::resolver::iterator endpoint_iterator);
};

typedef boost::shared_ptr<EL_NetClient> EL_NetClientPtr;

#endif  // _YMIRNETWORK_NETCLIENT_H
