/**
 * @file	EA_CEXCEPTION_REPORT.h
 * @brief	UAC class for Earth
 * @author	Standil (cpascal@cpascal.net)
 * 
 * @version	2010/04/26 cpascal - First Release
 */

#ifndef _EA_CEXCEPTION_REPORT_H_
#define _EA_CEXCEPTION_REPORT_H_

_EA_NAMESPACE_BEGIN

typedef LONG (CALLBACK *EA_FATALERROR_CALLBACK)( LPVOID pDebugLog );

#define EA_FATALERROR( u32ErrorCode, tszDescription, bRecoverable, u32ExitCode )	\
	{										\
		DWORD	dwStack;							\
		DWORD	dwStackFrame;							\
											\
		_asm { MOV dwStack, ESP	}						\
		_asm { MOV dwStackFrame, EBP }						\
		::Solar::EA_FatalError::FatalError( u32ErrorCode, _T(__FILE__), __LINE__, tszDescription, dwStack, dwStackFrame, bRecoverable, u32ExitCode ); \
	}

//void	SetFatalErrorCallback( EA_FATALERROR_CALLBACK pCustomFunction );
//MA_BOOL	FatalError( u32 u32ErrorCode, LPCTSTR tszFileName, int nLine, LPCTSTR tszDescription, DWORD dwStack, DWORD dwStackFrame, BOOL bRecoverable, u32 u32ExitCode );
MA_BOOL	UnhandledExceptionError( PEXCEPTION_POINTERS pExceptionInfo, PCONTEXT pContext, LPCTSTR tszFaultReason, LPCTSTR tszDescription );

void	ReadyToCatchUnhandledExceptions( void );

_EA_NAMESPACE_END

#endif /* !_EA_CEXCEPTION_REPORT_H_ */

