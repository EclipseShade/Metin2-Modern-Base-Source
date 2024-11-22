//
// Copyright 2010 Ymir Entertainment. All rights reserved.
//
#ifndef _YMIRNETWORK_NETPEER_H
#define _YMIRNETWORK_NETPEER_H

#include <stdint.h>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>
#include <boost/unordered_map.hpp>
#include <boost/format.hpp>
#include <asio.hpp>

struct EL_NetPacket;

class EL_NetPeer : private boost::noncopyable
{
	public:
		enum EVERBOSE_FLAG
		{
			VERBOSE_READ = (1 << 0),
			VERBOSE_WRITE = (1 << 1),
			VERBOSE_WRITE_RESULT = (1 << 2),
			VERBOSE_REGISTER_PACKET = (1 << 3),
		};

    public:
        explicit EL_NetPeer(asio::io_service* io_service,
				size_t MaxInputSize = 32768,
				size_t ReserveInputSize = 32768,
				size_t MaxOutputSize = 65536,
				size_t ReserveOutputSize = 65536);

        template <typename T, typename Handler>
            void RegisterPacket(uint32_t type, Handler handler)
        {
			T s;

			if (m_verbose_flag & VERBOSE_REGISTER_PACKET)
				std::cout << boost::format("PEER : RegisterPacket (type: %1% size: %2%)") % type % s.size() << std::endl;

            m_handlers.insert(std::make_pair(type, std::make_pair(s.size(), handler)));
        }

		inline asio::ip::tcp::socket& GetSocket()
        {
            return m_socket;
        }

		inline const std::string& GetIP() const
		{
			return m_socket_address;
		}

        void Init();
		inline bool IsEstablished();
		virtual void Disconnect();

		void AsyncWrite(const void* data, size_t size);
		void AsyncWrite(const EL_NetPacket& p);
		
		inline void Send(const EL_NetPacket& p)
		{
			AsyncWrite(p);
		}

		// OnInit에서 RegisterPacket을 통해 패킷을 등록할 것이다.
		virtual void OnInit() = 0;

		// CheckPacket
		//
		// 용도: 가변 패킷 여부 검사와 핸들러 호출 여부 결정
		//
		// * false 리턴시 실제 패킷 핸들러를 호출하지 않는다. 패킷을 미리 검사하여
		//   핸들러 호출을 하지 않고 싶을 때 사용 (가변 패킷 처리 확실히!)
		//
		// * 고정(길이) 패킷:
		//   return true;
		//
		// * 가변 패킷:
		//
		//   길이가 부족할 때 (본 패킷 크기 제외)
		//   *additionalSize = 30;  // 30바이트 더 필요
		//   return true;
		//
		//   부족하지 않을 때
		//   return true;
		//
		// * 길이 부족 여부는 반!드!시! 서버 입력 버퍼 길이 기준으로 판단해야 한다.
		virtual bool CheckPacket(const EL_NetPacket&);

		// 접속이 끊길 때 호출 됨
		virtual void OnDisconnect();

		// false 리턴 시 핸들러 호출하지 않음, 기본적으로 true 리턴. 별도 확인 필요시
		// 상속해서 구현
		virtual void HandleRead(const asio::error_code& error, size_t bytes_transferred);

		inline void SetVerbose(EVERBOSE_FLAG e);
		inline void UnsetVerbose(EVERBOSE_FLAG e);
		inline void ToggleVerbose(EVERBOSE_FLAG e);

	protected:
		virtual void AsyncRead(size_t size = 0);
		void DisconnectedByAsio();
		asio::streambuf m_input;

    private:
		void HandleWrite(const asio::error_code& error, size_t bytes_transferred);

        // MapPacketHandlers
        //   first : packet header
        //   second {
        //      first: base size of packet
        //      second: packet handler
        //   }
        typedef boost::unordered_map<uint32_t,
                std::pair<size_t, boost::function<void(const EL_NetPacket&)> > > MapPacketHandlers;

        MapPacketHandlers m_handlers;
        asio::ip::tcp::socket m_socket;
		asio::streambuf m_output;
		std::string m_socket_address;
        bool m_established;
		long m_verbose_flag;
};

inline bool EL_NetPeer::IsEstablished()
{
	return m_established;
}

inline void EL_NetPeer::SetVerbose(EL_NetPeer::EVERBOSE_FLAG flag)
{
	m_verbose_flag |= flag;
}

inline void EL_NetPeer::UnsetVerbose(EL_NetPeer::EVERBOSE_FLAG flag)
{
	m_verbose_flag &= ~flag;
}

inline void EL_NetPeer::ToggleVerbose(EL_NetPeer::EVERBOSE_FLAG flag)
{
	m_verbose_flag ^= flag;
}

#endif  // _YMIRNETWORK_NETPEER_H
