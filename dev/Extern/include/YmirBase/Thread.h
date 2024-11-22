#ifndef EL_THREAD_H
#define EL_THREAD_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class EL_Thread
{
public:
	EL_Thread();
	virtual ~EL_Thread();

	virtual void StartThread();	
	virtual void StopThread();		

	void Wait() const;
	bool Wait(DWORD timeoutMillis) const;
	void Terminate( DWORD exitCode = 0);

	BOOL	IsRun() const;
	void	SetThreadFlag( BOOL p_bThreadFlag );	
	HANDLE	GetHandle() const;

	static DWORD WINAPI Thread( void* p );
protected:
	virtual DWORD ThreadFunc() = 0;	
private:
	HANDLE	_Handle;
	BOOL	_bThreadFlag;

};
#endif
