#pragma once

#include "EventTypes.h"

#define EL_EVENT_CALL0(T, func)					func()
#define EL_EVENT_CALL1(T, func, data, x)		func(((const T&)data).x)
#define EL_EVENT_CALL2(T, func, data, x, y)		func(((const T&)data).x, ((const T&)data).y)
#define EL_EVENT_CALL3(T, func, data, x, y, z)	func(((const T&)data).x, ((const T&)data).y, ((const T&)data).z)
#define EL_EVENT_CALL4(T, func, data, x, y, z, f)	func(((const T&)data).x, ((const T&)data).y, ((const T&)data).z,  ((const T&)data).f)

class EL_BASE_API EL_EventListener
{
public:
	virtual ~EL_EventListener() {}

	virtual EL_EVENT_LISTENER_ID GetEventListenerId() = 0;

	virtual EL_BOOL OnRecvEvent(const EL_EventType& type, const EL_EventData& data) = 0;
};