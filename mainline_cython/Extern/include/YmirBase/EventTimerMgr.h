#pragma once

#include "EventTypes.h"

#include "STLQueue.h"

typedef EL_UINT EL_EVENT_TIMER_ID;

struct EL_EventTimer
{
	EL_FLOAT invokeSec;
	
	EL_EVENT_LISTENER_ID	targets;		
	EL_EVENT_TIMER_ID		pid;	

	EL_EventType type;
	EL_EventDataPtr dataPtr;
};

struct EL_EventTimerGreater
{
	EL_BOOL operator () (const EL_EventTimer& lhs, const EL_EventTimer& rhs)
	{
		return lhs.invokeSec > rhs.invokeSec;
	}
};

EL_BOOST_PTR(EL_EventTimerMgr);

class EL_BASE_API EL_EventTimerMgr
{
public:
	virtual ~EL_EventTimerMgr();	
	EL_EventTimerMgr();
	
	EL_EVENT_TIMER_ID AddEventTimer(EL_FLOAT sec, EL_EVENT_LISTENER_ID targets, const EL_EventType& type, EL_EventDataPtr dataPtr);
	EL_VOID DelEventTimer(EL_EVENT_TIMER_ID pid);
	EL_VOID DelAllEventTimers();

	EL_VOID UpdateGlobalTime(EL_FLOAT curSec);
	EL_VOID UpdateElapsedTime(EL_FLOAT elapsedSec);

	EL_BOOL GetEventTimer(EL_EVENT_LISTENER_ID* outTargets, EL_EventType* outType, EL_EventDataPtr* outDataPtr);

private:
	typedef std::priority_queue<EL_EventTimer, std::vector<EL_EventTimer>, EL_EventTimerGreater> EL_EventTimerq;

private:
	EL_EventTimerq m_timerq;

private:
	EL_FLOAT m_curSec;
};