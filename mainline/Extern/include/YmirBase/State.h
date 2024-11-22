#pragma once

EL_BOOST_PTR(EL_State);

class EL_State
{
public:
	virtual ~EL_State() {}

	virtual EL_VOID OnEnterState() = 0;
	virtual EL_VOID OnLeaveState() = 0;
	virtual EL_VOID OnPauseState() = 0;
	virtual EL_VOID OnResumeState() = 0;	
};