#pragma once

#include "TSimpleString.h"
#include "TStringConstants.h"

#include <Mantle/MA_StringNumeric.h>

template<typename T, typename R>
struct EL_TSimpleStringCaster
{
	typedef T IN_CHAR;

	typedef EL_TSimpleString<IN_CHAR>		IN_SimpleString;
	typedef EL_TStringConstants<IN_CHAR>	IN_StringConstants;	

	static R Cast(const IN_SimpleString& self);
};

// EL_SimpleStringA
template<>
inline EL_BOOL EL_TSimpleStringCaster<EL_ACHAR, EL_BOOL>::Cast(const IN_SimpleString& self)
{return !self.IsEmpty() && !self.IsSame(IN_StringConstants::TEXT_ZERO()) && !self.IsSameCI(IN_StringConstants::TEXT_FALSE());}

template<>
inline EL_INT EL_TSimpleStringCaster<EL_ACHAR, EL_INT>::Cast(const IN_SimpleString& self)
{return MA_StringToInt32A(self.GetPtr(), self.GetLen());}

template<>
inline EL_UINT EL_TSimpleStringCaster<EL_ACHAR, EL_UINT>::Cast(const IN_SimpleString& self)
{return MA_StringToUInt32A(self.GetPtr(), self.GetLen());}

template<>
inline EL_FLOAT EL_TSimpleStringCaster<EL_ACHAR, EL_FLOAT>::Cast(const IN_SimpleString& self)
{return MA_StringToFloatA(self.GetPtr(), self.GetLen());}

template<>
inline EL_SimpleStringA EL_TSimpleStringCaster<EL_ACHAR, EL_SimpleStringA>::Cast(const EL_SimpleStringA& self)
{return self;}

// EL_SimpleStringE
template<>
inline EL_BOOL EL_TSimpleStringCaster<EL_ECHAR, EL_BOOL>::Cast(const IN_SimpleString& self)
{return !self.IsEmpty() && !self.IsSame(IN_StringConstants::TEXT_ZERO()) && !self.IsSameCI(IN_StringConstants::TEXT_FALSE());}

template<>
inline EL_INT EL_TSimpleStringCaster<EL_ECHAR, EL_INT>::Cast(const IN_SimpleString& self)
{return MA_StringToInt32E(self.GetPtr(), self.GetLen());}

template<>
inline EL_UINT EL_TSimpleStringCaster<EL_ECHAR, EL_UINT>::Cast(const IN_SimpleString& self)
{return MA_StringToUInt32E(self.GetPtr(), self.GetLen());}

template<>
inline EL_FLOAT EL_TSimpleStringCaster<EL_ECHAR, EL_FLOAT>::Cast(const IN_SimpleString& self)
{return MA_StringToFloatE(self.GetPtr(), self.GetLen());}

template<>
inline EL_SimpleStringE EL_TSimpleStringCaster<EL_ECHAR, EL_SimpleStringE>::Cast(const EL_SimpleStringE& self)
{return self;}

// EL_SimpleStringW
template<>
inline EL_BOOL EL_TSimpleStringCaster<EL_WCHAR, EL_BOOL>::Cast(const IN_SimpleString& self)
{return !self.IsEmpty() && !self.IsSame(IN_StringConstants::TEXT_ZERO()) && !self.IsSameCI(IN_StringConstants::TEXT_FALSE());}

template<>
inline EL_INT EL_TSimpleStringCaster<EL_WCHAR, EL_INT>::Cast(const IN_SimpleString& self)
{return MA_StringToInt32W(self.GetPtr(), self.GetLen());}

template<>
inline EL_UINT EL_TSimpleStringCaster<EL_WCHAR, EL_UINT>::Cast(const IN_SimpleString& self)
{return MA_StringToUInt32W(self.GetPtr(), self.GetLen());}

template<>
inline EL_FLOAT EL_TSimpleStringCaster<EL_WCHAR, EL_FLOAT>::Cast(const IN_SimpleString& self)
{return MA_StringToFloatW(self.GetPtr(), self.GetLen());}

template<>
inline EL_SimpleStringW EL_TSimpleStringCaster<EL_WCHAR, EL_SimpleStringW>::Cast(const EL_SimpleStringW& self)
{return self;}
