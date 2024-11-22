#ifndef	_EL_CRANDOMNUMBER_H_
#define	_EL_CRANDOMNUMBER_H_

class EL_CRandomNumber
{
public:
	// constructor
	EL_CRandomNumber()										{}
	EL_CRandomNumber( EL_UINT uSeed )						{ SetSeed( uSeed ); }
	// destructor
	~EL_CRandomNumber()										{}

	void	SetSeed( EL_UINT uSeed )						{ m_uSeed = uSeed; }
	EL_UINT	GetSeed()										{ return m_uSeed; }

	EL_INT	IncrementalRandom();

	/**
	 * @remark	0 <= [return value] < sEnd
	 */
	EL_INT	IncrementalRandom( EL_INT sEnd );
	/**
	 * @remark	sBegin <= [return value] < sEnd
	 */
	EL_INT	IncrementalRandom( EL_INT sBegin, EL_INT sEnd );

	EL_INT	SimpleRandom();
	/**
	 * @remark	0 <= [return value] < sEnd
	 */
	EL_INT	SimpleRandom( EL_INT sEnd );
	/**
	 * @remark	sBegin <= [return value] < sEnd
	 */
	EL_INT	SimpleRandom( EL_INT sBegin, EL_INT sEnd );

	EL_INT	NormalRandom();
	/**
	 * @remark	0 <= [return value] < sEnd
	 */
	EL_INT	NormalRandom( EL_INT sEnd );
	/**
	 * @remark	sBegin <= [return value] < sEnd
	 */
	EL_INT	NormalRandom( EL_INT sBegin, EL_INT sEnd );

	EL_INT	ComplexRandom();
	/**
	 * @remark	0 <= [return value] < sEnd
	 */
	EL_INT	ComplexRandom( EL_INT sEnd );
	/**
	 * @remark	sBegin <= [return value] < sEnd
	 */
	EL_INT	ComplexRandom( EL_INT sBegin, EL_INT sEnd );

private:
	EL_UINT	m_uSeed;
};

#endif // !_EL_CRANDOMNUMBER_H_
