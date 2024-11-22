#pragma once

template<typename T>
struct EL_TSize2
{
	T w;
	T h;

	EL_TSize2() : w(0), h(0) {}
	EL_TSize2(T w, T h) : w(w), h(h) {}
};

template<typename T>
struct EL_TSize3
{
	T w;
	T h;
	T d;

	EL_TSize3() : w(0), h(0), d(0) {}
	EL_TSize3(T w, T h, T d) : w(w), h(h) {}
};