#ifndef _MA_CLOCK_H_
#define _MA_CLOCK_H_

#if defined(_NTR_UNIX)
#include <pthread.h>
#endif

_MA_NAMESPACE_BEGIN

class MA_CLock
{
public:
	MA_CLock();
	MA_CLock( MA_BOOL bFast );
	~MA_CLock();

	NTR_INLINE	void	Lock( void );
	NTR_INLINE	MA_BOOL	TryLock( void );
	NTR_INLINE	MA_BOOL	TryLock( MA_INT nMiliseconds );
	NTR_INLINE	void	Unlock( void );

protected:
#if defined(_NTR_UNIX)
	pthread_mutex_t		m_stMutex;
#elif defined(_NTR_WINDOWS)
	CRITICAL_SECTION	m_stCriticalSection;
#endif
};

void MA_CLock::Lock( void )
{
#if defined(_NTR_UNIX)
	pthread_mutex_lock( &m_stMutex );
#elif defined(_NTR_WINDOWS)
	::EnterCriticalSection( &m_stCriticalSection );
#endif
}

MA_BOOL MA_CLock::TryLock( void )
{
#if defined(_NTR_UNIX)
	return pthread_mutex_trylock( &m_stMutex ) == 0;
#elif defined(_NTR_WINDOWS)
	return ::TryEnterCriticalSection( &m_stCriticalSection ) != 0;
#endif
}

MA_BOOL MA_CLock::TryLock( MA_INT /*nMiliseconds*/ )
{
	// Must be implemented
	return MA_FALSE;
}

void MA_CLock::Unlock( void )
{
#if defined(_NTR_UNIX)
	pthread_mutex_unlock( &m_stMutex );
#elif defined(_NTR_WINDOWS)
	::LeaveCriticalSection( &m_stCriticalSection );
#endif
}

_MA_NAMESPACE_END

#endif /* !_MA_CLOCK_H_ */
