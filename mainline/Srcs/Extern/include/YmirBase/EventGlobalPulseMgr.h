#pragma once

#include "EventPulseMgr.h"

EL_BOOST_PTR(EL_EventGlobalPulseMgr);

class EL_BASE_API EL_EventGlobalPulseMgr : public EL_EventPulseMgr
{
public:
	static void GenEventGlobalPulseMgr();
	static void DelEventGlobalPulseMgr();

	static EL_EventGlobalPulseMgr&		GetEventGlobalPulseMgr();
	static EL_EventGlobalPulseMgrPtr	GetEventGlobalPulseMgrPtr();
};