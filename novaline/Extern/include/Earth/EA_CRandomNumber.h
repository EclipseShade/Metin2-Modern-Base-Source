#ifndef	_EA_CRANDOMNUMBER_H_
#define	_EA_CRANDOMNUMBER_H_

_EA_NAMESPACE_BEGIN

class EA_CRandomNumber
{
public:
	// constructor
	EA_CRandomNumber()									{}
	EA_CRandomNumber( u32 uSeed )						{ SetSeed( uSeed ); }
	// destructor
	~EA_CRandomNumber()									{}

	void	SetSeed( u32 uSeed )						{ m_uSeed = uSeed; }
	u32	GetSeed()										{ return m_uSeed; }

	s32	IncrementalRandom();

	/**
	 * @remark	0 <= [return value] < sEnd
	 */
	s32	IncrementalRandom( s32 sEnd );
	/**
	 * @remark	sBegin <= [return value] < sEnd
	 */
	s32	IncrementalRandom( s32 sBegin, s32 sEnd );

	s32	SimpleRandom();
	/**
	 * @remark	0 <= [return value] < sEnd
	 */
	s32	SimpleRandom( s32 sEnd );
	/**
	 * @remark	sBegin <= [return value] < sEnd
	 */
	s32	SimpleRandom( s32 sBegin, s32 sEnd );

	s32	NormalRandom();
	/**
	 * @remark	0 <= [return value] < sEnd
	 */
	s32	NormalRandom( s32 sEnd );
	/**
	 * @remark	sBegin <= [return value] < sEnd
	 */
	s32	NormalRandom( s32 sBegin, s32 sEnd );

	s32	ComplexRandom();
	/**
	 * @remark	0 <= [return value] < sEnd
	 */
	s32	ComplexRandom( s32 sEnd );
	/**
	 * @remark	sBegin <= [return value] < sEnd
	 */
	s32	ComplexRandom( s32 sBegin, s32 sEnd );

private:
	u32	m_uSeed;
};

_EA_NAMESPACE_END

#endif // !_EA_CRANDOMNUMBER_H_
