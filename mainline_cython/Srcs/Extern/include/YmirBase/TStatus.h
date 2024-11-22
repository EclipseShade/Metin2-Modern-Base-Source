#pragma once

#include <boost/foreach.hpp>
#include "TSimpleString.h"
#include "TBasicString.h"
#include "TStringConstants.h"

template<typename T>
class EL_TStatus
{
public:
	typedef T			IN_CHAR;
	typedef const T*	IN_C_CHAR_P;

	typedef std::basic_string<T>	IN_BasicString;
	typedef EL_TSimpleString<T>		IN_SimpleString;

public:
	struct Log
	{
		IN_CHAR type;
		IN_BasicString line;

		Log(IN_CHAR type, const IN_BasicString& line) : type(type), line(line) {}
	};

	typedef std::vector<Log> Logs;

public:
	virtual ~EL_TStatus()
	{}

public:
	EL_VOID Writef(IN_CHAR type, IN_C_CHAR_P fmtz, ...);

	EL_VOID Writez(IN_CHAR type, IN_C_CHAR_P strz)
	{
		IN_SimpleString str(strz);
		Write(type, str);
	}

	EL_VOID Write(IN_CHAR type, const IN_SimpleString& str)
	{
		m_cur.assign(str.GetPtr(), str.GetLen());
		m_logs.push_back(Log(type, m_cur));	
	}

	EL_BOOL GetLogText(IN_BasicString* ret, const IN_BasicString& linesep=EL_TStringConstants<T>::LINE_SEP(), IN_CHAR filter = 0)
	{
		EL_LOG_ASSERT_RETURN_PARAM(EL_TStatus::GetLogText, ret);

		if (m_logs.empty())
			return false;
		
		EL_SIZE count = m_logs.size();

		EL_LOG_ASSERT(count > 0);
		EL_SIZE last = count - 1;

		EL_SIZE capacity = linesep.length() * last;
		BOOST_FOREACH(const Log& log, m_logs)
		{
			capacity += log.line.size() + (filter == 0 ? 3 : 1); // type + ': ' + line length
		}

		ret->clear();
		ret->reserve(capacity);

		for (EL_SIZE i = 0; i <= last; i++)
		{
			const Log& log = m_logs[i];
			
			if (filter != 0 && log.type != filter)
				continue;
			else if (filter == 0)
			{
				ret->append(1, log.type);
				ret->append(EL_TStringConstants<T>::NAME_SEP());
			}

			ret->append(log.line);

			if (i != last)
				ret->append(linesep);
		}

		return true;
	}

	virtual const Logs& GetLogs()
	{return m_logs;}

private:
	IN_BasicString m_cur;

private:
	Logs m_logs;
};

template<>
inline EL_VOID EL_TStatus<EL_ACHAR>::Writef(IN_CHAR type, IN_C_CHAR_P fmtz, ...)
{
	IN_CHAR buf[1024];

	va_list argList;
	va_start(argList, fmtz);
	EL_SIZE bufLen = _vsnprintf_s(buf, _countof(buf), _countof(buf)-1, fmtz, argList);			
	va_end(argList);

	IN_SimpleString str(buf, bufLen);
	Write(type, str);
}

template<>
inline EL_VOID EL_TStatus<EL_ECHAR>::Writef(IN_CHAR type, IN_C_CHAR_P fmtz, ...)
{
	IN_CHAR buf[1024];

	va_list argList;
	va_start(argList, fmtz);
	EL_SIZE bufLen = _vsnprintf_s((char*)buf, _countof(buf), _countof(buf)-1, (const char*)fmtz, argList);			
	va_end(argList);

	IN_SimpleString str(buf, bufLen);
	Write(type, str);
}

template<>
inline EL_VOID EL_TStatus<EL_WCHAR>::Writef(IN_CHAR type, IN_C_CHAR_P fmtz, ...)
{
	IN_CHAR buf[1024];

	va_list argList;
	va_start(argList, fmtz);
	EL_SIZE bufLen = _vsnwprintf_s(buf, _countof(buf), _countof(buf)-1, fmtz, argList);			
	va_end(argList);

	IN_SimpleString str(buf, bufLen);
	Write(type, str);
}

typedef EL_TStatus<EL_ACHAR> EL_StatusA;
typedef EL_TStatus<EL_WCHAR> EL_StatusW;
typedef EL_TStatus<EL_TCHAR> EL_Status;

#define EL_STATUSA_INFOZ(statusPtr, msgz)			{if (statusPtr) (statusPtr)->Writez(EL_ACHAR('I'), msgz);}
#define EL_STATUSA_ERRORZ(statusPtr, msgz)			{if (statusPtr) (statusPtr)->Writez(EL_ACHAR('E'), msgz);}
#define EL_STATUSA_WARNINGZ(statusPtr, msgz)		{if (statusPtr) (statusPtr)->Writez(EL_ACHAR('W'), msgz);}

#define EL_STATUSA_INFOF(statusPtr, fmtz, ...)		{if (statusPtr) (statusPtr)->Writef(EL_ACHAR('I'), fmtz, __VA_ARGS__);}
#define EL_STATUSA_ERRORF(statusPtr, fmtz, ...)		{if (statusPtr) (statusPtr)->Writef(EL_ACHAR('E'), fmtz, __VA_ARGS__);}
#define EL_STATUSA_WARNINGF(statusPtr, fmtz, ...)	{if (statusPtr) (statusPtr)->Writef(EL_ACHAR('W'), fmtz, __VA_ARGS__);}

#define EL_STATUSE_INFOZ(statusPtr, msgz)			{if (statusPtr) (statusPtr)->Writez(EL_ECHAR('I'), msgz);}
#define EL_STATUSE_ERRORZ(statusPtr, msgz)			{if (statusPtr) (statusPtr)->Writez(EL_ECHAR('E'), msgz);}
#define EL_STATUSE_WARNINGZ(statusPtr, msgz)		{if (statusPtr) (statusPtr)->Writez(EL_ECHAR('W'), msgz);}

#define EL_STATUSE_INFOF(statusPtr, fmtz, ...)		{if (statusPtr) (statusPtr)->Writef(EL_ECHAR('I'), fmtz, __VE_ARGS__);}
#define EL_STATUSE_ERRORF(statusPtr, fmtz, ...)		{if (statusPtr) (statusPtr)->Writef(EL_ECHAR('E'), fmtz, __VE_ARGS__);}
#define EL_STATUSE_WARNINGF(statusPtr, fmtz, ...)	{if (statusPtr) (statusPtr)->Writef(EL_ECHAR('W'), fmtz, __VE_ARGS__);}

#define EL_STATUSW_INFOZ(statusPtr, msgz)			{if (statusPtr) (statusPtr)->Writez(EL_WCHAR(L'I'), msgz);}
#define EL_STATUSW_ERRORZ(statusPtr, msgz)			{if (statusPtr) (statusPtr)->Writez(EL_WCHAR(L'E'), msgz);}
#define EL_STATUSW_WARNINGZ(statusPtr, msgz)		{if (statusPtr) (statusPtr)->Writez(EL_WCHAR(L'W'), msgz);}

#define EL_STATUSW_INFOF(statusPtr, fmtz, ...)		{if (statusPtr) (statusPtr)->Writef(EL_WCHAR(L'I'), fmtz, __VA_ARGS__);}
#define EL_STATUSW_ERRORF(statusPtr, fmtz, ...)		{if (statusPtr) (statusPtr)->Writef(EL_WCHAR(L'E'), fmtz, __VA_ARGS__);}
#define EL_STATUSW_WARNINGF(statusPtr, fmtz, ...)	{if (statusPtr) (statusPtr)->Writef(EL_WCHAR(L'W'), fmtz, __VA_ARGS__);}

#define EL_STATUS_INFOZ(statusPtr, msgz)			{if (statusPtr) (statusPtr)->Writez(EL_TCHAR('I'), msgz);}
#define EL_STATUS_ERRORZ(statusPtr, msgz)			{if (statusPtr) (statusPtr)->Writez(EL_TCHAR('E'), msgz);}
#define EL_STATUS_WARNINGZ(statusPtr, msgz)			{if (statusPtr) (statusPtr)->Writez(EL_TCHAR('W'), msgz);}

#define EL_STATUS_INFOF(statusPtr, fmtz, ...)		{if (statusPtr) (statusPtr)->Writef(EL_TCHAR('I'), fmtz, __VA_ARGS__);}
#define EL_STATUS_ERRORF(statusPtr, fmtz, ...)		{if (statusPtr) (statusPtr)->Writef(EL_TCHAR('E'), fmtz, __VA_ARGS__);}
#define EL_STATUS_WARNINGF(statusPtr, fmtz, ...)	{if (statusPtr) (statusPtr)->Writef(EL_TCHAR('W'), fmtz, __VA_ARGS__);}