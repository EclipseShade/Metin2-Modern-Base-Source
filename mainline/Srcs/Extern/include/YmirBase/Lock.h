#ifndef _YMIRBASE_LOCK_H_
#define _YMIRBASE_LOCK_H_

class EL_Lock
{
public:
	virtual ~EL_Lock() {}

	virtual void Lock() = 0;
	virtual void Unlock() = 0;
};

class EL_CriticalSection : public EL_Lock
{
public:
	EL_CriticalSection()	{ ::InitializeCriticalSection(&m_cs);	}
	~EL_CriticalSection()	{ ::DeleteCriticalSection(&m_cs);		}
	virtual void Lock()		{ ::EnterCriticalSection(&m_cs);		}
	virtual void Unlock()	{ ::LeaveCriticalSection(&m_cs);		}

private:
	CRITICAL_SECTION m_cs;
};

class EL_ScopeLock
{
public:
	EL_ScopeLock(EL_Lock& lock)	: m_lockPtr(&lock)
	{
		m_lockPtr->Lock();
	}

	~EL_ScopeLock()
	{
		m_lockPtr->Unlock();
	}

private:
	EL_Lock*	m_lockPtr;
};

#endif /* !_YMIRBASE_LOCK_H_ */
