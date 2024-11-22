#pragma once

#include "TSimpleStringCaster.h"

template<typename T>
struct EL_TSimpleStringUtils
{
	typedef T IN_CHAR;

	typedef EL_TStringConstants<T>	IN_StringConstants;		

	typedef EL_TSimpleString<T>			IN_SimpleString;	
	
	template<typename R>
	static EL_VOID Split(const IN_SimpleString& self, T sep, std::vector<R>* outsPtr)
	{
		EL_SIZE sepPos = self.FindLeftCharAt(sep, 0);
		if (sepPos == (EL_SIZE)-1)
		{
			outsPtr->push_back(EL_TSimpleStringCaster<T, R>::Cast(self));
		}
		else
		{
			outsPtr->push_back(EL_TSimpleStringCaster<T, R>::Cast(self.Slice(0, sepPos)));
			
			Split(self.Slice(sepPos + 1), sep, outsPtr);
		}
	}

	template<typename R>
	static EL_VOID Split(const IN_SimpleString& self, T sep, R* left, R* right)
	{
		EL_SIZE sepPos = self.FindLeftCharAt(sep, 0);
		if (sepPos == (EL_SIZE)-1)
		{
			if (left != right)
				*left = EL_TSimpleStringCaster<T, R>::Cast(self);
		}
		else
		{
			if (left != right)
				*left++ = EL_TSimpleStringCaster<T, R>::Cast(self.Slice(0, sepPos));
			
			Split(self.Slice(sepPos + 1), sep, left, right);
		}
	}
};

typedef EL_TSimpleStringUtils<EL_ACHAR> EL_SimpleStringUtilsA;
typedef EL_TSimpleStringUtils<EL_ECHAR> EL_SimpleStringUtilsE;
typedef EL_TSimpleStringUtils<EL_WCHAR> EL_SimpleStringUtilsW;
typedef EL_TSimpleStringUtils<EL_TCHAR> EL_SimpleStringUtils;

