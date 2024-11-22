#pragma once

#include "EventTypes.h"

#include "STLQueue.h"

typedef EL_UINT EL_EVENT_PULSE_ID;

struct EL_EventPulse
{
	EL_FLOAT nextSec;
	EL_FLOAT loopSec;

	EL_EVENT_LISTENER_ID	targets;		
	EL_EVENT_PULSE_ID		pid;	

	EL_EventType type;
	EL_EventDataPtr dataPtr;
};

struct EL_EventPulseGreater
{
	EL_BOOL operator () (const EL_EventPulse& lhs, const EL_EventPulse& rhs)
	{
		return lhs.nextSec > rhs.nextSec;
	}
};

EL_BOOST_PTR(EL_EventPulseMgr);

class EL_BASE_API EL_EventPulseMgr
{
public:
	virtual ~EL_EventPulseMgr();	
	EL_EventPulseMgr();
	
	EL_EVENT_PULSE_ID AddEventPulse(EL_FLOAT sec, EL_EVENT_LISTENER_ID targets, const EL_EventType& type, EL_EventDataPtr dataPtr);
	EL_VOID DelEventPulse(EL_EVENT_PULSE_ID pid);
	EL_VOID DelAllEventPulses();

	EL_VOID UpdateGlobalTime(EL_FLOAT curSec);
	EL_VOID UpdateElapsedTime(EL_FLOAT elapsedSec);

	EL_BOOL GetEventPulse(EL_EVENT_LISTENER_ID* outTargets, EL_EventType* outType, EL_EventDataPtr* outDataPtr);

private:
	typedef std::priority_queue<EL_EventPulse, std::vector<EL_EventPulse>, EL_EventPulseGreater> EL_EventPulseq;

private:
	EL_EventPulseq m_pulseq;

private:
	EL_FLOAT m_curSec;
};