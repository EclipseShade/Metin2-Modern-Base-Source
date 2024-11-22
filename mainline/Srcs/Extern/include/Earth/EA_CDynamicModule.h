/**
 * @file	EA_CDynamicModule.h
 * @brief	Earth Dynamic Module class header
 * @author	Standil (cpascal@cpascal.net)
 *
 * @version	2009/11/16 cpascal - First release
 */

#ifndef _EA_CDYNAMICMODULE_H_
#define _EA_CDYNAMICMODULE_H_

_EA_NAMESPACE_BEGIN

class EA_CDynamicModule
{
public:
	// EA_CDynamicModule 생성자
	EA_CDynamicModule( void ) : m_hDM( EA_NULL )		{}

	// EA_CDynamicModule 파괴자
	virtual ~EA_CDynamicModule( void )			{ Destroy(); }

	void	Destroy( void )						{ EA_SAFE_FREELIBRARY( m_hDM ); }


	/**
	 * @brief	라이브러리가 로드되어 있는지 확인한다.
	 * @returns	파일 열기에 성공하면 EA_TRUE를, 그렇지 않으면 EA_FALSE를 리턴
	 */
	EA_BOOL	IsLoaded( void ) const
	{
		return (m_hDM != EA_NULL)? EA_TRUE: EA_FALSE;
	}

	/**
	 * @brief	라이브러리를 로드한다.
	 * @param[in]	tszDll - DLL 파일명
	 * @returns	초기화에 성공하면 EA_TRUE를, 그렇지 않으면 EA_FALSE를 리턴
	 */
	virtual EA_BOOL	vInit( MA_PCTSTR IN /*tszDll*/ )		{ return EA_FALSE; }

protected:
	EA_HMODULE	m_hDM;
};


// Macros: DECLARE_DM_FUNCTION
// 함수를 정의한다.
#define EA_DECLARE_DM_FUNCTION( ret, cc, func, params )						\
		ret ( cc *func )params;

// Macros: BEGIN_DM_VINIT
// vInit() 오버라이딩 함수 시작, 라이브러리를 로드한다.
#define EA_BEGIN_DM_VINIT()													\
	EA_BOOL	vInit( MA_PCTSTR IN tszDll )									\
	{																		\
		EA_SAFE_FREELIBRARY( m_hDM );										\
		m_hDM = ::LoadLibrary( tszDll );									\
		EA_BOOL	bOk = EA_FALSE;

// Macros: VINIT_DM_TWIN_FUNCTION
// 사용할 함수의 포인터를 가져온다. 함수명 변경 가능.
#define EA_VINIT_DM_TWIN_FUNCTION_NULLABLE( ret, cc, func, params, origin )	\
		if( m_hDM )															\
			func = ( ret ( cc * )params )GetProcAddress( m_hDM, origin );	\
		else																\
			func = Earth::EA_NULL;											\

// Macros: VINIT_DM_TWIN_FUNCTION
// 사용할 함수의 포인터를 가져온다. 함수명 변경 가능.
#define EA_VINIT_DM_TWIN_FUNCTION( ret, cc, func, params, origin )			\
		EA_VINIT_DM_TWIN_FUNCTION_NULLABLE( ret, cc, func, params, origin )	\
		if( func )															\
			bOk = EA_TRUE;

// Macros: VINIT_DM_FUNCTION
// 사용할 함수의 포인터를 가져온다. 함수명 변경 불가.
#define EA_VINIT_DM_FUNCTION_NULLABLE( ret, cc, func, params )				\
		if( m_hDM )															\
			func = ( ret ( cc * )params )GetProcAddress( m_hDM, #func );	\
		else																\
			func = EA_NULL;													\

// Macros: VINIT_DM_FUNCTION
// 사용할 함수의 포인터를 가져온다. 함수명 변경 불가.
#define EA_VINIT_DM_FUNCTION( ret, cc, func, params )						\
		EA_VINIT_DM_FUNCTION_NULLABLE( ret, cc, func, params )				\
		if( func )															\
			bOk = EA_TRUE;

// Macros: END_DM_VINIT
// vInit() 오버라이딩 함수 끝
#define EA_END_DM_VINIT()								\
		return bOk;										\
	}

_EA_NAMESPACE_END

#endif /* !_EA_CDYNAMICMODULE_H_ */
