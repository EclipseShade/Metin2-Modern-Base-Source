#ifndef _MA_CSEMAPHORE_H_
#define _MA_CSEMAPHORE_H_

#if defined(_NTR_UNIX)
#include <semaphore.h>
#endif

_MA_NAMESPACE_BEGIN

class MA_CSemaphore
{
public:
	MA_CSemaphore( MA_INT nMaxCount );
	~MA_CSemaphore();

	NTR_INLINE	void	Lock( void );
	NTR_INLINE	void	Unlock( void );
	NTR_INLINE	MA_INT	GetMaxCount( void ) const;

protected:
	MA_INT				m_nMaxCount;
#if defined(_NTR_UNIX)
	sem_t				m_stSemaphore;
#elif defined(_NTR_WINDOWS)
	HANDLE				m_hSemaphore;
#endif

private:
	MA_CSemaphore();
	MA_CSemaphore(const MA_CSemaphore &);
	const MA_CSemaphore& operator = (const MA_CSemaphore&);
};

void MA_CSemaphore::Lock( void )
{
#if defined(_NTR_UNIX)
	sem_wait( &m_stSemaphore ); 
#elif defined(_NTR_WINDOWS)
	::WaitForSingleObject( m_hSemaphore, INFINITE );
#endif
}

void MA_CSemaphore::Unlock( void )
{
#if defined(_NTR_UNIX)
	sem_post( &m_stSemaphore );
#elif defined(_NTR_WINDOWS)
	::ReleaseSemaphore(m_hSemaphore, 1, NULL);
#endif
}

MA_INT MA_CSemaphore::GetMaxCount( void ) const
{
	return m_nMaxCount;
}

_MA_NAMESPACE_END

#endif /* !_MA_CSEMAPHORE_H_ */
