#pragma once

#include "TPos.h"

template<typename T>
EL_TPos2<T> EL_TPos2_Subtract(const EL_TPos2<T>& self, const EL_TPos2<T>& value)
{return EL_TPos2<T>(self.x - value.x, self.y - value.y);}

template<typename T>
T EL_TPos2_CalcLengthSq(const EL_TPos2<T>& self, const EL_TPos2<T>& value)
{
	EL_TPos2<T> delta(EL_TPos2_Subtract(self, value));	
	return delta.x * delta.x + delta.y * delta.y;
}

template<typename T>
T EL_TPos2_CalcLength(const EL_TPos2<T>& self, const EL_TPos2<T>& value)
{return (T)sqrt(EL_TPos2_CalcLengthSq(self, value));}

template<typename T>
EL_BOOL EL_TPos2_IsSame(const EL_TPos2<T>& self, const EL_TPos2<T>& value)
{return self.x == value.x && self.y == value.y;}

template<typename T>
EL_BOOL EL_TPos2_IsInRange(const EL_TPos2<T>& self, const EL_TPos2<T>& value, T range)
{return EL_TPos2_CalcLengthSq(self, value) < range * range;}

template<typename T, typename S>
void EL_TPos2_Assign(EL_TPos2<T>& self, const EL_TPos2<S>& value)
{
	self.x = value.x;
	self.y = value.y;
}

// 윈도우 특화 함수
#ifdef _WIN32
	template<typename T>
	void EL_TPos2_AssignFromParam(EL_TPos2<T>& self, LPARAM lParam)
	{
		self.x = T(short(LOWORD(lParam)));
		self.y = T(short(HIWORD(lParam)));	
	}
#endif


