/**
 * @file	EA_Log.h
 * @brief	Log function for Earth
 * @author	Standil (cpascal@cpascal.net)
 * 
 * @version	2009/06/27 cpascal - First Release
 */

#ifndef _EA_LOG_H_
#define _EA_LOG_H_

// 소스 레벨 정의
#define EA_SOURCE_LEVEL_NONE		0	// No output
#define EA_SOURCE_LEVEL_MINIMUM		1	// Only output errors
#define EA_SOURCE_LEVEL_RELEASE		2	// Normal release mode
#define EA_SOURCE_LEVEL_BETA		3	// Normal beta season mode
#define EA_SOURCE_LEVEL_DEBUG		4	// Output mostly
#define EA_SOURCE_LEVEL_FULL		5	// Output fully

#ifndef EA_SOURCE_LEVEL
	#ifdef _DEBUG
		#define EA_SOURCE_LEVEL		EA_SOURCE_LEVEL_DEBUG
	#else
		#define EA_SOURCE_LEVEL		EA_SOURCE_LEVEL_RELEASE
	#endif
#endif

#ifndef EA_SOURCE_CATEGORY
#define EA_SOURCE_CATEGORY			0
#endif

#if( EA_LOGPOLICY_LEVEL == EA_SOURCE_LEVEL_FULL )
	#define _EA_LOGPOLICY_USE_FATAL_
	#define _EA_LOGPOLICY_USE_ERROR_
	#define _EA_LOGPOLICY_USE_WARNING_
	#define _EA_LOGPOLICY_USE_INFO_
	#define _EA_LOGPOLICY_USE_DEBUG_
	#define _EA_LOGPOLICY_USE_TRACE_
#elif( EA_LOGPOLICY_LEVEL == EA_SOURCE_LEVEL_DEBUG )
	#define _EA_LOGPOLICY_USE_FATAL_
	#define _EA_LOGPOLICY_USE_ERROR_
	#define _EA_LOGPOLICY_USE_WARNING_
	#define _EA_LOGPOLICY_USE_INFO_
	#define _EA_LOGPOLICY_USE_DEBUG_
#elif( EA_LOGPOLICY_LEVEL == EA_SOURCE_LEVEL_BETA )
	#define _EA_LOGPOLICY_USE_FATAL_
	#define _EA_LOGPOLICY_USE_ERROR_
	#define _EA_LOGPOLICY_USE_WARNING_
	#define _EA_LOGPOLICY_USE_INFO_
#elif( EA_LOGPOLICY_LEVEL == EA_SOURCE_LEVEL_RELEASE )
	#define _EA_LOGPOLICY_USE_FATAL_
	#define _EA_LOGPOLICY_USE_ERROR_
	#define _EA_LOGPOLICY_USE_WARNING_
#elif( EA_LOGPOLICY_LEVEL == EA_SOURCE_LEVEL_MINIMUM )
	#define _EA_LOGPOLICY_USE_FATAL_
	#define _EA_LOGPOLICY_USE_ERROR_
#endif

#if defined(_EA_LOGPOLICY_USE_FATAL_)
	#define EA_LOG_FATAL( _MESSAGE )			{ EA_LogFatal( EA_SOURCE_CATEGORY, _MESSAGE ); }
	#define EA_LOGF_FATAL( _MESSAGE )			{ EA_LogfFatal( EA_SOURCE_CATEGORY, _MESSAGE ); }
#else
	#define EA_LOG_FATAL( _MESSAGE )
	#define EA_LOGF_FATAL( _MESSAGE )
#endif

#if defined(_EA_LOGPOLICY_USE_ERROR_)
	#define EA_LOG_ERROR( _MESSAGE )			{ EA_LogError( EA_SOURCE_CATEGORY, _MESSAGE ); }
	#define EA_LOGF_ERROR( _MESSAGE )			{ EA_LogfError( EA_SOURCE_CATEGORY, _MESSAGE ); }
#else
	#define EA_LOG_ERROR( _MESSAGE )
	#define EA_LOGF_ERROR( _MESSAGE )
#endif

#if defined(_EA_LOGPOLICY_USE_WARNING_)
	#define EA_LOG_WARNING( _MESSAGE )			{ EA_LogWarning( EA_SOURCE_CATEGORY, _MESSAGE ); }
	#define EA_LOGF_WARNING( _MESSAGE )			{ EA_LogfWarning( EA_SOURCE_CATEGORY, _MESSAGE ); }
#else
	#define EA_LOG_WARNING( _MESSAGE )
	#define EA_LOGF_WARNING( _MESSAGE )
#endif

#if defined(_EA_LOGPOLICY_USE_INFO_)
	#define EA_LOG_INFO( _MESSAGE )				{ EA_LogInfo( EA_SOURCE_CATEGORY, _MESSAGE ); }
	#define EA_LOGF_INFO( _MESSAGE )			{ EA_LogfInfo( EA_SOURCE_CATEGORY, _MESSAGE ); }
#else
	#define EA_LOG_INFO( _MESSAGE )
	#define EA_LOGF_INFO( _MESSAGE )
#endif

#if defined(_EA_LOGPOLICY_USE_DEBUG_)
	#define EA_LOG_DEBUG( _MESSAGE )			{ EA_LogDebug( EA_SOURCE_CATEGORY, _MESSAGE ); }
	#define EA_LOGF_DEBUG( _MESSAGE )			{ EA_LogfDebug( EA_SOURCE_CATEGORY, _MESSAGE ); }
#else
	#define EA_LOG_DEBUG( _MESSAGE )
	#define EA_LOGF_DEBUG( _MESSAGE )
#endif

#if defined(_EA_LOGPOLICY_USE_TRACE_)
	#define EA_LOG_TRACE( _MESSAGE )			{ EA_LogTrace( EA_SOURCE_CATEGORY, _MESSAGE ); }
	#define EA_LOGF_TRACE( _MESSAGE )			{ EA_LogfTrace( EA_SOURCE_CATEGORY, _MESSAGE ); }
#else
	#define EA_LOG_TRACE( _MESSAGE )
	#define EA_LOGF_TRACE( _MESSAGE )
#endif

_EA_NAMESPACE_BEGIN

enum ELOGLEVEL
{
	eLL_TRACE = 0,
	eLL_DEBUG,
	eLL_INFO,
	eLL_WARNING,
	eLL_ERROR,
	eLL_FATAL
};

void EA_LogFatal( int iCategory, LPCTSTR tszFormat );
void EA_LogError( int iCategory, LPCTSTR tszFormat );
void EA_LogWarning( int iCategory, LPCTSTR tszFormat );
void EA_LogInfo( int iCategory, LPCTSTR tszFormat );
void EA_LogDebug( int iCategory, LPCTSTR tszFormat );
void EA_LogTrace( int iCategory, LPCTSTR tszFormat );

void EA_LogfFatal( int iCategory, LPCTSTR tszFormat, ... );
void EA_LogfError( int iCategory, LPCTSTR tszFormat, ... );
void EA_LogfWarning( int iCategory, LPCTSTR tszFormat, ... );
void EA_LogfInfo( int iCategory, LPCTSTR tszFormat, ... );
void EA_LogfDebug( int iCategory, LPCTSTR tszFormat, ... );
void EA_LogfTrace( int iCategory, LPCTSTR tszFormat, ... );

_EA_NAMESPACE_END

#endif /* !_EA_LOG_H_ */
