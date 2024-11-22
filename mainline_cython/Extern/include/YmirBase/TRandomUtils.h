#pragma once

#include "Math.h"

template<typename T>
const T& EL_TRandom_Choice(const T* sequence, int count)
{
	EL_LOG_ASSERT(count > 0);
	return sequence[EL_Random(count)];
}

template<typename T>
T EL_TRandom_RandRange(const T& begin, const T& end, const T& step=1)
{
	EL_LOG_ASSERT(end > begin);
	T count = T((end - begin + 1) / step);		
	return (T) (begin + EL_Random((int) count));
}
