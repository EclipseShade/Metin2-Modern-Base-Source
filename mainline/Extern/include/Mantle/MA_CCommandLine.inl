_MA_NAMESPACE_BEGIN

#if _MA_INTERNAL_CHARSET == _NTR_CHARSET_UNICODE
	#define	MA_CCommandLine		MA_CCommandLineW
#elif _MA_INTERNAL_CHARSET == _NTR_CHARSET_UTF8
	#define	MA_CCommandLine		MA_CCommandLineE
#else
	#define	MA_CCommandLine		MA_CCommandLineA
#endif

class MA_CCommandLine
{
public:
	MA_CCommandLine( void );
	MA_CCommandLine( _MA_ITLPCSTR szCommandLine, MA_BOOL bHasProgramName = MA_TRUE );
	MA_CCommandLine( MA_INT IN nArgumentCount, _MA_ITLPSTR IN aszArguments[], MA_BOOL bHasProgramName = MA_TRUE );
	~MA_CCommandLine( void );

	MA_BOOL			Set( _MA_ITLPCSTR IN szCommandLine, MA_BOOL bHasProgramName = MA_FALSE );
	MA_BOOL			Set( MA_INT IN nArgumentCount, _MA_ITLPSTR IN aszArguments[], MA_BOOL bHasProgramName = MA_TRUE );

	MA_SIZE			FindArgument( _MA_ITLPCSTR tszParameter, MA_SIZE sizeParameter = (MA_SIZE) -1 ) const;
	//MA_BOOL			DeleteArgument( MA_INT iIndex );
	_MA_ITLPCSTR	GetProgramName( void ) const										{ return (m_nArgumentCount > 0) ? m_aszArguments[0] : MA_NULL;	}
	//MA_VOID			SetProgramName( _MA_ITLPCSTR szProgramName );
	_MA_ITLPCSTR	GetCommandLine( MA_BOOL bExcludeProgramName = MA_TRUE ) const		{ return bExcludeProgramName ? (m_szCommandLine+m_sizeProgramName) : m_szCommandLine; }
	MA_INT	 		GetArgumentCount( void ) const										{ return m_nArgumentCount; }
	_MA_ITLPSTR*	GetArgumentVector( MA_BOOL bExcludeProgramName = MA_TRUE ) const	{ return bExcludeProgramName ? (m_aszArguments+1) : m_aszArguments; }
	_MA_ITLPCSTR	GetArgument( MA_INT iIndex ) const									{ return ( iIndex >= m_nArgumentCount ) ? MA_NULL : m_aszArguments[iIndex];	}
	_MA_ITLPCSTR	operator[]( MA_INT IN iIndex ) const								{ return GetArgument( iIndex );	}
	_MA_ITLPSTR		operator[]( MA_INT IN iIndex )										{ return ( iIndex >= m_nArgumentCount ) ? MA_NULL : m_aszArguments[iIndex];	}

protected:
	void			Reset( void );
	void			Free( void );
	MA_BOOL			FillCommandLine( MA_INT IN nArgumentCount, _MA_ITLPSTR IN aszArguments[], MA_BOOL bHasProgramName );
	MA_BOOL			FillArguments( _MA_ITLPCSTR IN szCommandLine, MA_BOOL bHasProgramName );

protected:
	_MA_ITLPSTR		m_szCommandLine;
	MA_SIZE			m_sizeProgramName;

	MA_INT			m_nArgumentCount;
	_MA_ITLPSTR*	m_aszArguments;
	_MA_ITLPSTR		m_szCommandBuffer;
};

#undef MA_CCommandLine

_MA_NAMESPACE_END
