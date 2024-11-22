#ifndef _EA_CCRTLEAKFINDER_H_
#define _EA_CCRTLEAKFINDER_H_

#if defined(_NTR_WINDOWS_INTEL)

_EA_NAMESPACE_BEGIN

class EA_CCRTLeakFinder
{
public:
	enum {
		eOPERATION_NONE				= 0,
		eOPERATION_ALLOCATING,
		eOPERATION_REALLOCATING,
		eOPERATION_FREE
	};

	typedef struct _tagSMEMORY_DATA {
		const unsigned char*		szFileName;
		int							nLine;
		int							nCount;
		struct _tagSMEMORY_DATA*	pNext;
	} SMEMORY_DATA, *PSMEMORY_DATA;

	EA_CCRTLeakFinder();
	~EA_CCRTLeakFinder();

	MA_BOOL			Init( int nBucketSize );
	MA_BOOL			Close( void );

	MA_BOOL			IncreaseCount( const unsigned char* szFileName, int nLine );
	MA_BOOL			DecreaseCount( const unsigned char* szFileName, int nLine );

	MA_BOOL			Report( int nDurable );

	static int		sAllocHook( int nAllocType, void* pvData, size_t nSize, int nBlockUse, long lRequest, const unsigned char* szFileName, int nLine );

protected:
	int				AllocHook( int nAllocType, void* pvData, size_t nSize, int nBlockUse, long lRequest, const unsigned char* szFileName, int nLine );
	PSMEMORY_DATA	AllocNewNode( const unsigned char* szFileName, int nLine );

	MA_UINT			m_nBucketSize;
	PSMEMORY_DATA*	m_astBuckets;
	PSMEMORY_DATA	m_astMemoryPool;
};

extern EA_CCRTLeakFinder cCRTLeakFinder;

_EA_NAMESPACE_END

#endif

#endif /* !_EA_CCRTLEAKFINDER_H_ */
