#pragma once

template<typename T> struct EL_TPos2;
template<typename T> struct EL_TPos3;

template<typename T>
struct EL_TPos2
{
	T x;
	T y;

	EL_TPos2() : x(0), y(0) {}
	EL_TPos2(T x, T y) : x(x), y(y) {}
	EL_TPos2(const EL_TPos3<T> rPos3) : x(rPos3.x), y(rPos3.y) {}

	EL_VOID Clear()
	{
		x = y = 0;
	}

	// assignment operators
	EL_TPos2& operator += (const EL_TPos2& v)
	{
		x += v.x;
		y += v.y;
		return *this;
	}

	EL_TPos2& operator -= (const EL_TPos2& v)
	{
		x -= v.x;
		y -= v.y;
		return *this;
	}

	EL_TPos2& operator *= (float)
	{
		x *= f;
		y *= f;
		return *this;
	}

	EL_TPos2& operator /= (float)
	{
		float fInv = 1.0f / f;
		x *= fInv;
		y *= fInv;
		return *this;
	}

	// unary operators
	EL_TPos2 operator + () const
	{
		return *this;
	}

	EL_TPos2 operator - () const
	{
		return EL_TPos2(-x, -y);
	}

	// binary operators
	EL_TPos2 operator + (const EL_TPos2& v) const
	{
		return EL_TPos2(x + v.x, y + v.y);
	}

	EL_TPos2 operator - (const EL_TPos2& v) const
	{
		return EL_TPos2(x - v.x, y - v.y);
	}

	EL_TPos2 operator * (float) const
	{
		return EL_TPos2(x * f, y * f);
	}

	EL_TPos2 operator / (float) const
	{
		float fInv = 1.0f / f;
		return EL_TPos2(x * fInv, y * fInv);
	}

	friend EL_TPos2 operator * (float, const EL_TPos2& v)
	{
		return EL_TPos2(f * v.x, f * v.y);
	}

	EL_BOOL operator == (const EL_TPos2& v) const
	{
		return x == v.x && y == v.y;
	}

	EL_BOOL operator != (const EL_TPos2& v) const
	{
		return !(*this == v);
	}

	void MovePosition( float radian, INT Dist)
	{
		x += sinf(radian)*Dist;
		y += cosf(radian)*Dist;
	}
	static const EL_TPos2 ZERO;
};

template<typename T>
const EL_TPos2<T> EL_TPos2<T>::ZERO(0,0,0);

template<typename T>
struct EL_TPos3
{
	T x;
	T y;
	T z;

	EL_TPos3() : x(0), y(0), z(0) {}
	EL_TPos3(T x, T y, T z) : x(x), y(y), z(z) {}
	EL_TPos3(const EL_TPos2<T> rPos2) : x(rPos2.x), y(rPos2.y), z(0) {}

	EL_VOID Clear()
	{
		x = y = z = 0;
	}

	// assignment operators
	EL_TPos3& operator += (const EL_TPos3& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}

	EL_TPos3& operator -= (const EL_TPos3& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}

	EL_TPos3& operator *= (float)
	{
		x *= f;
		y *= f;
		z *= f;
		return *this;
	}

	EL_TPos3& operator /= (float)
	{
		float fInv = 1.0f / f;
		x *= fInv;
		y *= fInv;
		z *= fInv;
		return *this;
	}

	// unary operators
	EL_TPos3 operator + () const
	{
		return *this;
	}

	EL_TPos3 operator - () const
	{
		return EL_TPos3(-x, -y, -z);
	}

	// binary operators
	EL_TPos3 operator + (const EL_TPos3& v) const
	{
		return EL_TPos3(x + v.x, y + v.y, z + v.z);
	}

	EL_TPos3 operator - (const EL_TPos3& v) const
	{
		return EL_TPos3(x - v.x, y - v.y, z - v.z);
	}

	EL_TPos3 operator * (float) const
	{
		return EL_TPos3(x * f, y * f, z * f);
	}

	EL_TPos3 operator / (float) const
	{
		float fInv = 1.0f / f;
		return EL_TPos3(x * fInv, y * fInv, z * fInv);
	}

	friend EL_TPos3 operator * (float, const struct EL_TPos3& v)
	{
		return EL_TPos3(f * v.x, f * v.y, f * v.z);
	}

	EL_BOOL operator == (const EL_TPos3& v) const
	{
		return x == v.x && y == v.y && z == v.z;
	}

	EL_BOOL operator != (const EL_TPos3& v) const
	{
		return !(*this == v);
	}

	void MovePosition( float radian, INT Dist)
	{
		x += sinf(radian)*Dist;
		y += cosf(radian)*Dist;
	}

	static const EL_TPos3 ZERO;
};

template<typename T>
const EL_TPos3<T> EL_TPos3<T>::ZERO(0,0,0);




typedef EL_TPos2<EL_INT>	EL_IPOS2;
typedef EL_TPos2<EL_FLOAT>	EL_FPOS2;

typedef EL_TPos3<EL_INT>	EL_IPOS3;
typedef EL_TPos3<EL_FLOAT>	EL_FPOS3;
