#pragma once

#include "TSimpleString.h"
#include "TStringBuffer.h"

#include <Mantle/MA_StringNumeric.h>

template<typename T>
struct EL_TStringBufferUtils
{
	typedef EL_TSimpleString<T>		IN_SimpleString;
	typedef EL_TStringBuffer<T>		IN_StringBuffer;

	static EL_SIZE	Assigni(IN_StringBuffer& self, EL_INT val);
	static EL_SIZE	Assignf(IN_StringBuffer& self, EL_FLOAT val);

	static EL_SIZE	Assignb(IN_StringBuffer& self, EL_BOOL val)
	{
		if (val)
			return self.Assign(IN_StringConstants::TEXT_ZERO());
		else
			return self.Assign(IN_StringConstants::TEXT_FALSE());
	}	
};

// StringBufferE
template<>
inline EL_SIZE	EL_TStringBufferUtils<EL_ECHAR>::Assigni(IN_StringBuffer& self, EL_INT val)
{
	MA_SIZE len = MA_StringCountE(MA_Int32ToRadixStringE(val, self.GetPtr(), self.GetMax(), 10));
	self.SetLen(len);
	return len;
}

template<>
inline EL_SIZE	EL_TStringBufferUtils<EL_ECHAR>::Assignf(IN_StringBuffer& self, EL_FLOAT val)
{
	MA_SIZE len = MA_StringCountE(MA_FloatToStringE(val, self.GetPtr(), self.GetMax(), 2));
	self.SetLen(len);
	return len;
}

// StringBufferW
template<>
inline EL_SIZE	EL_TStringBufferUtils<EL_WCHAR>::Assigni(IN_StringBuffer& self, EL_INT val)
{
	EL_SIZE len = _snwprintf_s(self.GetPtr(), self.GetMax(), self.GetMax()-1, EL_TEXTW("%d"), val);
	self.SetLen(len);
	return len;
}

template<>
inline EL_SIZE	EL_TStringBufferUtils<EL_WCHAR>::Assignf(IN_StringBuffer& self, EL_FLOAT val)
{
	EL_SIZE len = _snwprintf_s(self.GetPtr(), self.GetMax(), self.GetMax()-1, EL_TEXTW("%f"), val);
	self.SetLen(len);
	return len;
}

typedef EL_TStringBufferUtils<EL_ACHAR> EL_StringBufferUtilsA;
typedef EL_TStringBufferUtils<EL_ECHAR> EL_StringBufferUtilsE;
typedef EL_TStringBufferUtils<EL_WCHAR> EL_StringBufferUtilsW;
typedef EL_TStringBufferUtils<EL_TCHAR> EL_StringBufferUtils;