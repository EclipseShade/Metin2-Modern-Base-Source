#pragma once

#include "SmartPointer.h"

EL_BOOST_PTR(EL_State);

class EL_StateMgr
{
public:
	virtual ~EL_StateMgr();

	EL_BOOL PushState(EL_StatePtr newStatePtr);
	EL_VOID PopState();

private:
	typedef std::vector<EL_StatePtr> EL_StatePtrs;

private:
	EL_StatePtrs m_statePtrs;
};