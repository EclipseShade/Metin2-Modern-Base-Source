#pragma once

#include "String.h"

/*
class EL_Exception
{
public:	
	EL_Exception( const EL_String &where, const EL_String &message ,EL_INT line = __LINE__ , const EL_String& file = _T(__FILE__) )			
		:    _line(line) ,_file(file) ,_where(where) , _message(message){}
	virtual ~EL_Exception() {}

	virtual const EL_String& GetWhere() const { return _where; }
	virtual const EL_String& GetMessage() const { return _message; }

	virtual void Message() const 
	{
		printf("<<Location>>: line:%d file:%s where:%s msg:%s\n",_line, _file.c_str(), _where.c_str(), _message.c_str());		
	}

protected:
	EL_INT	_line;
	EL_String _file;
	EL_String _where;
	EL_String _message;

};

TCHAR* GetLastErrorMessage(DWORD last_error)
{
	static TCHAR errmsg[512];

	if (!FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, 
		0,
		last_error,
		0,
		errmsg, 
		511,
		NULL))
	{
		// if we fail, call ourself to find out why and return that error 
		return (GetLastErrorMessage(GetLastError()));  
	}

	return errmsg;
}		


class EL_Win32Exception : public EL_Exception
{
public:
	EL_Win32Exception( const EL_String &where, DWORD error )
		: EL_Exception( where , GetLastErrorMessage(error) ) , _error(error) {}
	~EL_Win32Exception() {}

	DWORD GetError() const { return _error; }

	virtual void Message() const
	{
		printf("<<Location>>: error:%d, line:%d file:%s where:%s msg:%s\n",_error, _line, _file.c_str(), _where.c_str(), _message.c_str());		
	}
private:
	DWORD _error;
};
*/


