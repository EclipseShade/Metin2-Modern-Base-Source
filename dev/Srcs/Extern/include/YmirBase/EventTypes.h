#pragma once

#include "SmartPointer.h"

struct EL_EventData
{};

struct EL_EventType
{
	EL_UINT		key;
	EL_C_ACHAR_P	name;

	EL_EventType(EL_UINT key=0, EL_C_ACHAR_P name=NULL) : key(key), name(name)
	{}
};

#define EL_EVENT_TYPE(e) EL_EventType(e, #e)

typedef EL_UINT32	EL_EVENT_LISTENER_ID;

EL_BOOST_STRUCT_PTR(EL_EventData);