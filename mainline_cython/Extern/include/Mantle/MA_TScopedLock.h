#ifndef _MA_TSCOPEDLOCK_H_
#define _MA_TSCOPEDLOCK_H_

#include "MA_CLock.h"

_MA_NAMESPACE_BEGIN

template <class T>
class TScopedLock
{
public:
	TScopedLock( T* pcLock ) : m_pcLock(pcLock)
	{
		pcLock->Lock();
	}

	void Unlock( void )
	{
		if( m_pcLock ) {
			m_pcLock->Unlock();
			m_pcLock = NULL;
		}
	}

	~TScopedLock()
	{
		if( m_pcLock )
			m_pcLock->Unlock();
	}

protected:
	T*	m_pcLock;
};

_MA_NAMESPACE_END

#endif /* !_MA_TSCOPEDLOCK_H_ */
