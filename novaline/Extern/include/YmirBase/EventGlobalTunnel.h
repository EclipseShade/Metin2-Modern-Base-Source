#pragma once

#include "EventTunnel.h"

EL_BOOST_PTR(EL_EventGlobalTunnel);

class EL_BASE_API EL_EventGlobalTunnel : public EL_EventTunnel
{
public:
	static EL_VOID GenEventGlobalTunnel();
	static EL_VOID DelEventGlobalTunnel();
	static EL_EventGlobalTunnel& GetEventGlobalTunnel();
	static EL_EventGlobalTunnelPtr GetEventGlobalTunnelPtr();
};