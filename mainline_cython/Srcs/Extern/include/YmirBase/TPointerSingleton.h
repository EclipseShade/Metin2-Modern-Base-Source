#pragma once

#include "Log.h"

#define EL_DECLARE_POINTER_SINGLETON(NAME) static EL_##NAME& Get##NAME() {return EL_TPointerSingleton<EL_##NAME>::GetSingleton();}
// GenXX, DelXX, GetXX, GetXXPtr 함수 선언
#define EL_DECLARE_POINTER_SINGLETON_EX(NAME, CLASS) static CLASS& Get##NAME() {return EL_TPointerSingleton<CLASS>::GetSingleton();} 

template<typename T>
class EL_TPointerSingleton
{
public:	
	static T& GetSingleton()
	{
		EL_LOG_ASSERT(ms_singleton != NULL);
		return *static_cast<T*>(ms_singleton);
	}

	static T* GetSingletonPtr()
	{return ms_singleton;}

	static EL_BOOL IsValidSingleton()
	{return ms_singleton != NULL;}

public:
	EL_TPointerSingleton()
	{
		EL_LOG_ASSERT(ms_singleton == NULL);
		ms_singleton = this;
	}
	virtual ~EL_TPointerSingleton()
	{
		if (this == ms_singleton)
			ms_singleton = NULL;
	}

private:
	static EL_TPointerSingleton<T>* ms_singleton;
};

template<typename T> EL_TPointerSingleton<T>* EL_TPointerSingleton<T>::ms_singleton = NULL;

#define EL_LOG_ASSERT_VALID_SINGLETON(T) EL_LOG_ASSERT(EL_TPointerSingleton<T>::IsValidSingleton());