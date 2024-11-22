#pragma once

#define EL_RAND_MAX RAND_MAX

// unit == 2일 경우 0, 1 의 랜덤 값을 출력한다.
extern void EL_SetRandomSeed(unsigned int seed);
extern int EL_Random(int unit);
extern int EL_Random(int from, int to);
extern int EL_Dice(int num, int size);
