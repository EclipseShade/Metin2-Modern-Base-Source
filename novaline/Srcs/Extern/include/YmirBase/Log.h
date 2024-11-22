#pragma once

enum EL_LOGA_LEVEL
{	
	EL_LL_QUIET,
	EL_LL_INFO,
	EL_LL_VERBOSE,
	EL_LL_VERBOSE2,
	EL_LL_VERBOSE3,
	EL_LL_VERBOSE4,
	EL_LL_VERBOSE5,
	EL_LL_VERBOSE6,
	EL_LL_SPECIAL,
	EL_LL_MAX,
	EL_LL_ERROR = -1,
};

enum
{
	EL_LOG_BUF_MAX_SIZE = 512,
	EL_LOG_BUF_L_MAX_SIZE = 1024,
};

EL_BASE_API EL_VOID EL_Log_SetLevel(EL_INT level);
EL_BASE_API EL_INT  EL_Log_GetLevel();

EL_BASE_API EL_BOOL EL_Log_Write(EL_INT level, EL_C_ACHAR_P msg, EL_UINT len);
EL_BASE_API EL_BOOL EL_Log_Write(EL_INT level, EL_C_WCHAR_P msg, EL_UINT len);

EL_BASE_API EL_VOID EL_Log_OpenFile(EL_C_TCHAR_P prefixz);
EL_BASE_API EL_VOID EL_Log_CloseFile();

EL_BASE_API EL_C_TCHAR_P EL_Log_GetStdOutPathz();
EL_BASE_API EL_C_TCHAR_P EL_Log_GetStdErrPathz();

// LogA
EL_BASE_API EL_VOID EL_LogA_SetMainPath(EL_C_ACHAR_P mainPath);

EL_BASE_API EL_BOOL EL_LogA_Writef(EL_UINT bufSize, EL_INT level, EL_C_ACHAR_P src, EL_INT line, EL_C_ACHAR_P func, EL_C_ACHAR_P fmt, ...);
EL_BASE_API EL_BOOL EL_LogA_AssertTrue(EL_BOOL cmp, EL_C_ACHAR_P expr, EL_C_ACHAR_P file, EL_INT line, EL_C_ACHAR_P func, EL_BOOL& skip);

// LogW
EL_BASE_API EL_VOID EL_LogW_SetLevel(EL_INT level);
EL_BASE_API EL_VOID EL_LogW_SetMainPath(EL_C_WCHAR_P mainPath);

EL_BASE_API EL_BOOL EL_LogW_Writef(EL_UINT bufSize, EL_INT level, EL_C_ACHAR_P src, EL_INT line, EL_C_ACHAR_P func, EL_C_WCHAR_P fmt, ...);
EL_BASE_API EL_BOOL EL_LogW_Writef(EL_UINT bufSize, EL_INT level, EL_C_WCHAR_P src, EL_INT line, EL_C_WCHAR_P func, EL_C_WCHAR_P fmt, ...);
EL_BASE_API EL_BOOL EL_LogW_AssertTrue(EL_BOOL cmp, EL_C_WCHAR_P expr, EL_C_WCHAR_P file, EL_INT line, EL_C_WCHAR_P func, EL_BOOL& skip);

// LOGA
#define EL_LOGA_INIT()						{EL_LogA_SetMainPath(__FILE__);}

#define EL_LOGA_INFO(fmt, ...)				{EL_LogA_Writef(EL_LOG_BUF_MAX_SIZE, EL_LL_INFO, __FILE__, __LINE__, __FUNCTION__, fmt, __VA_ARGS__);}
#define EL_LOGA_ERROR(fmt, ...)				{EL_LogA_Writef(EL_LOG_BUF_MAX_SIZE, EL_LL_ERROR, __FILE__, __LINE__, __FUNCTION__, fmt, __VA_ARGS__);}
#define EL_LOGA_ERROR_L(fmt, ...)			{EL_LogA_Writef(EL_LOG_BUF_L_MAX_SIZE, EL_LL_ERROR, __FILE__, __LINE__, __FUNCTION__, fmt, __VA_ARGS__);}
#define EL_LOGA_ERROR_ONCE(fmt, ...)		{static bool __FILE__##__LINE__##once = true;if (__FILE__##__LINE__##once) {__FILE__##__LINE__##once=false;EL_LogA_Writef(EL_LOG_BUF_MAX_SIZE, EL_LL_ERROR, __FILE__, __LINE__, __FUNCTION__, fmt, __VA_ARGS__);}}

#define EL_LOGA_VERBOSE_INIT(name, value)	static bool __EL_LOGA_LOCAL_ENABLE__ = value;void EL_LogA_ShowVerbose_##name() {__EL_LOGA_LOCAL_ENABLE__ = true;};void EL_LogA_HideVerbose_##name() {__EL_LOGA_LOCAL_ENABLE__ = false;};
#define EL_LOGA_VERBOSE(fmt, ...)			{if (__EL_LOGA_LOCAL_ENABLE__) EL_LogA_Writef(EL_LOG_BUF_MAX_SIZE, EL_LL_VERBOSE,  __FILE__, __LINE__, __FUNCTION__, fmt, __VA_ARGS__);}
#define EL_LOGA_VERBOSE2(fmt, ...)			{if (__EL_LOGA_LOCAL_ENABLE__) EL_LogA_Writef(EL_LOG_BUF_MAX_SIZE, EL_LL_VERBOSE2, __FILE__, __LINE__, __FUNCTION__, fmt, __VA_ARGS__);}
#define EL_LOGA_VERBOSE3(fmt, ...)			{if (__EL_LOGA_LOCAL_ENABLE__) EL_LogA_Writef(EL_LOG_BUF_MAX_SIZE, EL_LL_VERBOSE3, __FILE__, __LINE__, __FUNCTION__, fmt, __VA_ARGS__);}
#define EL_LOGA_VERBOSE4(fmt, ...)			{if (__EL_LOGA_LOCAL_ENABLE__) EL_LogA_Writef(EL_LOG_BUF_MAX_SIZE, EL_LL_VERBOSE4, __FILE__, __LINE__, __FUNCTION__, fmt, __VA_ARGS__);}
#define EL_LOGA_VERBOSE5(fmt, ...)			{if (__EL_LOGA_LOCAL_ENABLE__) EL_LogA_Writef(EL_LOG_BUF_MAX_SIZE, EL_LL_VERBOSE5, __FILE__, __LINE__, __FUNCTION__, fmt, __VA_ARGS__);}
#define EL_LOGA_VERBOSE6(fmt, ...)			{if (__EL_LOGA_LOCAL_ENABLE__) EL_LogA_Writef(EL_LOG_BUF_MAX_SIZE, EL_LL_VERBOSE6, __FILE__, __LINE__, __FUNCTION__, fmt, __VA_ARGS__);}

#define EL_LOGA_SPECIAL(fmt, ...)			{EL_LogA_Writef(EL_LOG_BUF_MAX_SIZE, EL_LL_SPECIAL, __FILE__, __LINE__, __FUNCTION__, fmt, __VA_ARGS__);}

#ifdef _DEBUG
#	define EL_LOGA_DEBUG(fmt, ...)			{EL_LogA_Writef(EL_LOG_BUF_MAX_SIZE, EL_LL_INFO, __FILE__, __LINE__, __FUNCTION__, fmt, __VA_ARGS__);}
#	define EL_LOGA_ASSERT(expr)				{static bool __FILE__##__LINE__##skip = false;EL_LogA_AssertTrue(expr, #expr, __FILE__, __LINE__, __FUNCTION__, __FILE__##__LINE__##skip);}
#else
#	define EL_LOGA_DEBUG(fmt, ...)
#   define EL_LOGA_ASSERT(expr) 
#endif

#define EL_LOGA_ASSERT_RETURN_PARAM(functionName, retParam)			EL_LOGA_ASSERT(retParam != NULL && #functionName": 리턴 포인터 유효하지 않음");


// LOGW
#define EL_LOGW_INIT()						{EL_LogW_SetMainPath(__FILE__);}

#define EL_LOGW_INFO(fmt, ...)				{EL_LogW_Writef(EL_LOG_BUF_MAX_SIZE, EL_LL_INFO, __FILE__, __LINE__, __FUNCTION__, fmt, __VA_ARGS__);}
#define EL_LOGW_ERROR(fmt, ...)				{EL_LogW_Writef(EL_LOG_BUF_MAX_SIZE, EL_LL_ERROR, __FILE__, __LINE__, __FUNCTION__, fmt, __VA_ARGS__);}
#define EL_LOGW_ERROR_L(fmt, ...)			{EL_LogW_Writef(EL_LOG_BUF_L_MAX_SIZE, EL_LL_ERROR, __FILE__, __LINE__, __FUNCTION__, fmt, __VA_ARGS__);}
#define EL_LOGW_ERROR_ONCE(fmt, ...)		{static bool __FILE__##__LINE__##once = true;if (__FILE__##__LINE__##once) {__FILE__##__LINE__##once=false;EL_LogW_Writef(EL_LOG_BUF_MAX_SIZE, EL_LL_ERROR, __FILE__, __LINE__, __FUNCTION__, fmt, __VA_ARGS__);}}

#define EL_LOGW_VERBOSE_INIT(name, value)	static bool __EL_LOGA_LOCAL_ENABLE__ = value;void EL_LogW_ShowVerbose_##name() {__EL_LOGA_LOCAL_ENABLE__ = true;};void EL_LogW_HideVerbose_##name() {__EL_LOGA_LOCAL_ENABLE__ = false;};
#define EL_LOGW_VERBOSE(fmt, ...)			{if (__EL_LOGA_LOCAL_ENABLE__) EL_LogW_Writef(EL_LOG_BUF_MAX_SIZE, EL_LL_VERBOSE,  __FILE__, __LINE__, __FUNCTION__, fmt, __VA_ARGS__);}
#define EL_LOGW_VERBOSE2(fmt, ...)			{if (__EL_LOGA_LOCAL_ENABLE__) EL_LogW_Writef(EL_LOG_BUF_MAX_SIZE, EL_LL_VERBOSE2, __FILE__, __LINE__, __FUNCTION__, fmt, __VA_ARGS__);}
#define EL_LOGW_VERBOSE3(fmt, ...)			{if (__EL_LOGA_LOCAL_ENABLE__) EL_LogW_Writef(EL_LOG_BUF_MAX_SIZE, EL_LL_VERBOSE3, __FILE__, __LINE__, __FUNCTION__, fmt, __VA_ARGS__);}
#define EL_LOGW_VERBOSE4(fmt, ...)			{if (__EL_LOGA_LOCAL_ENABLE__) EL_LogW_Writef(EL_LOG_BUF_MAX_SIZE, EL_LL_VERBOSE4, __FILE__, __LINE__, __FUNCTION__, fmt, __VA_ARGS__);}
#define EL_LOGW_VERBOSE5(fmt, ...)			{if (__EL_LOGA_LOCAL_ENABLE__) EL_LogW_Writef(EL_LOG_BUF_MAX_SIZE, EL_LL_VERBOSE5, __FILE__, __LINE__, __FUNCTION__, fmt, __VA_ARGS__);}
#define EL_LOGW_VERBOSE6(fmt, ...)			{if (__EL_LOGA_LOCAL_ENABLE__) EL_LogW_Writef(EL_LOG_BUF_MAX_SIZE, EL_LL_VERBOSE6, __FILE__, __LINE__, __FUNCTION__, fmt, __VA_ARGS__);}

#define EL_LOGW_SPECIAL(fmt, ...)			{EL_LogW_Writef(EL_LL_SPECIAL, __FILE__, __LINE__, __FUNCTION__, fmt, __VA_ARGS__);}

#ifdef _DEBUG
#	define EL_LOGW_DEBUG(fmt, ...)			{EL_LogW_Writef(EL_LL_INFO, __FILE__, __LINE__, __FUNCTION__, fmt, __VA_ARGS__);}
#	define EL_LOGW_ASSERT(expr)				{static bool __FILE__##__LINE__##skip = false;EL_LogA_AssertTrue(expr, #expr, __FILE__, __LINE__, __FUNCTION__, __FILE__##__LINE__##skip);}
#else
#	define EL_LOGW_DEBUG(fmt, ...)
#   define EL_LOGW_ASSERT(expr) 
#endif

#define EL_LOGW_ASSERT_RETURN_PARAM(functionName, retParam)	EL_LOGW_ASSERT(retParam != NULL && #functionName": 리턴 포인터 유효하지 않음");

#ifdef _UNICODE
	#define EL_LOG_INIT						EL_LOGA_INIT
											
	#define EL_LOG_INFO						EL_LOGW_INFO
	#define EL_LOG_ERROR					EL_LOGW_ERROR
	#define EL_LOG_ERROR_L					EL_LOGW_ERROR_L
	#define EL_LOG_ERROR_ONCE				EL_LOGW_ERROR_ONCE
											
	#define EL_LOG_VERBOSE_INIT				EL_LOGW_VERBOSE_INIT
	#define EL_LOG_VERBOSE					EL_LOGW_VERBOSE
	#define EL_LOG_VERBOSE2					EL_LOGW_VERBOSE2
	#define EL_LOG_VERBOSE3					EL_LOGW_VERBOSE3
	#define EL_LOG_VERBOSE4					EL_LOGW_VERBOSE4
	#define EL_LOG_VERBOSE5					EL_LOGW_VERBOSE5
	#define EL_LOG_VERBOSE6					EL_LOGW_VERBOSE6
											
	#define EL_LOG_SPECIAL					EL_LOGW_SPECIAL
											
	#define EL_LOG_DEBUG					EL_LOGW_DEBUG
	#define EL_LOG_ASSERT					EL_LOGW_ASSERT
											
	#define EL_LOG_ASSERT_RETURN_PARAM		EL_LOGW_ASSERT_RETURN_PARAM
#else
	#define EL_LOG_INIT						EL_LOGA_INIT
											
	#define EL_LOG_INFO						EL_LOGA_INFO
	#define EL_LOG_ERROR					EL_LOGA_ERROR
	#define EL_LOG_ERROR_L					EL_LOGA_ERROR_L
	#define EL_LOG_ERROR_ONCE				EL_LOGA_ERROR_ONCE
											
	#define EL_LOG_VERBOSE_INIT				EL_LOGA_VERBOSE_INIT
	#define EL_LOG_VERBOSE					EL_LOGA_VERBOSE
	#define EL_LOG_VERBOSE2					EL_LOGA_VERBOSE2
	#define EL_LOG_VERBOSE3					EL_LOGA_VERBOSE3
	#define EL_LOG_VERBOSE4					EL_LOGA_VERBOSE4
	#define EL_LOG_VERBOSE5					EL_LOGA_VERBOSE5
	#define EL_LOG_VERBOSE6					EL_LOGA_VERBOSE6
											
	#define EL_LOG_SPECIAL					EL_LOGA_SPECIAL
											
	#define EL_LOG_DEBUG					EL_LOGA_DEBUG
	#define EL_LOG_ASSERT					EL_LOGA_ASSERT
											
	#define EL_LOG_ASSERT_RETURN_PARAM		EL_LOGA_ASSERT_RETURN_PARAM
#endif

