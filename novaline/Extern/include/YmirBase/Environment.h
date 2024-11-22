#pragma once

#include "TStringBuffer.h"
#include "TStringTable.h"
#include "TPointerSingleton.h"

class EL_Environment
: public EL_TPointerSingleton<EL_Environment>
, public EL_TStringTable<EL_TCHAR>
{
public:
	EL_DECLARE_POINTER_SINGLETON(Environment)

public:
	EL_Environment();

	EL_UINT32 GetAllocationGranularity();

public:
	const IN_BasicString& GetValue(const IN_SimpleString& key) const
	{
		return EL_TStringTable::GetValue(key, m_defaultValue);
	}

	EL_FLOAT GetValuef(const IN_SimpleString& key) const
	{
		return EL_TStringTable::GetValue<EL_FLOAT>(key, 0.0f);
	}

	EL_INT GetValuei(const IN_SimpleString& key) const
	{
		return EL_TStringTable::GetValue<EL_INT>(key, 0);
	}

	EL_BOOL GetValueb(const IN_SimpleString& key) const
	{
		return EL_TStringTable::GetValue<EL_BOOL>(key, EL_FALSE);
	}

private:
	// 기본값을 SetValue로 미리 정해야 사용할 수 있도록 기본값이 인자로 들어가는 함수를
	// private으로 옮겨서 의도적으로 오류가 나도록 한다.
	virtual const IN_BasicString& GetValue(const IN_SimpleString&, const IN_BasicString& defValue) const
	{
		return defValue;
	}

	virtual EL_FLOAT GetValuef(const IN_SimpleString&, EL_FLOAT) const
	{
		return 0.0f;
	}

	virtual EL_INT GetValuei(const IN_SimpleString&, EL_INT) const
	{
		return 0;
	}

	virtual EL_BOOL GetValueb(const IN_SimpleString&, EL_BOOL) const
	{
		return EL_FALSE;
	}

private:
	SYSTEM_INFO m_sysInfo;
	IN_BasicString m_defaultValue;
};
