#pragma once

template<typename T>
struct EL_TColor3
{
	T r;
	T g;
	T b;

	EL_TColor3() : r(0), g(0), b(0) {}
	EL_TColor3(T r, T g, T b) : r(r), g(g), b(b) {}
};

template<typename T>
struct EL_TColor4
{	
	T r;
	T g;
	T b;
	T a;

	EL_TColor4() : r(0), g(0), b(0), a(0) {}
	EL_TColor4(T r, T g, T b, T a) : r(r), g(g), b(b), a(a) {}
};