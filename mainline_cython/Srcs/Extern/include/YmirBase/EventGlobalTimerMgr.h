#pragma once

#include "EventTimerMgr.h"

EL_BOOST_PTR(EL_EventGlobalTimerMgr);

class EL_BASE_API EL_EventGlobalTimerMgr : public EL_EventTimerMgr
{
public:
	static void GenEventGlobalTimerMgr();
	static void DelEventGlobalTimerMgr();

	static EL_EventGlobalTimerMgr&		GetEventGlobalTimerMgr();
	static EL_EventGlobalTimerMgrPtr	GetEventGlobalTimerMgrPtr();
};