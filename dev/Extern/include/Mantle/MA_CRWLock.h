#ifndef _MA_CRWLOCK_H_
#define _MA_CRWLOCK_H_

#include "MA_CLock.h"
#include "MA_CSemaphore.h"

_MA_NAMESPACE_BEGIN

class MA_CRWLock
{
public:
	MA_CRWLock( MA_INT nConsumers );
	~MA_CRWLock();

	NTR_INLINE	void	LockRead( void );
	NTR_INLINE	void	LockWrite( void );
	NTR_INLINE	void	UnlockRead( void );
	NTR_INLINE	void	UnlockWrite( void );

protected:
	MA_CSemaphore		m_cSemaphore;
	MA_CLock			m_cLock;

private:
	MA_CRWLock();
	MA_CRWLock(const MA_CRWLock &);
	const MA_CRWLock& operator = (const MA_CRWLock&);
};

void MA_CRWLock::LockRead( void )
{
	m_cSemaphore.Lock();
}

void MA_CRWLock::LockWrite( void )
{
	m_cLock.Lock();
	for( MA_INT i=0; i < m_cSemaphore.GetMaxCount(); i++ )
		m_cSemaphore.Lock();
	m_cLock.Unlock();
}

void MA_CRWLock::UnlockRead( void )
{
	m_cSemaphore.Unlock();
}

void MA_CRWLock::UnlockWrite( void )
{
	for( MA_INT i=0; i < m_cSemaphore.GetMaxCount(); i++ )
		m_cSemaphore.Unlock();
}

_MA_NAMESPACE_END

#endif /* !_MA_CRWLOCK_H_ */
