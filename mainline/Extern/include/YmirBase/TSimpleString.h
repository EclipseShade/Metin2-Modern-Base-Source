#pragma once

#include <Mantle/MA_StringCharSet.h>

#include "Log.h"

template<typename T>
class EL_TSimpleString
{
public:
	typedef std::basic_string<T> IN_BasicString;
	typedef EL_TSimpleString<T>  IN_SimpleString;

	operator const T* () const
	{return m_ptr;}

	operator IN_BasicString () const
	{return IN_BasicString(GetPtr(), GetLen());}
	
public:
	EL_TSimpleString()
	: m_ptr(EMPTY)
	, m_len(EL_SIZE(-1))
	, m_hash32(0)
	{
	}

	EL_TSimpleString(const T* ptr, EL_SIZE len=(EL_SIZE)-1, EL_UINT32 hash32=0) : m_ptr(ptr ? ptr : EMPTY), m_len(len), m_hash32(hash32)
	{		
	}

	EL_TSimpleString(const IN_BasicString& src) : m_ptr(src.c_str()), m_len(src.length()), m_hash32(0)
	{
	}

	const T* GetPtr() const
	{return m_ptr;}

	const T& GetCharAt(EL_SIZE idx) const
	{
		EL_LOG_ASSERT(m_ptr != NULL);
		return m_ptr[idx];			
	}

	EL_BOOL IsEmpty() const
	{
		if (!m_ptr)
			return true;
		
		if (m_ptr[0] == 0)
			return true;
		
		if (GetLen() == 0)
			return true;

		return false;
	}

	EL_BOOL GetCharAt(EL_SIZE idx, T* ret) const
	{
		if (!m_ptr)
			return false;

		EL_SIZE len = GetLen();
		if (idx >= len)
			return false;
		
		*ret = m_ptr[idx];
		return true;		
	}
	EL_BOOL IsCharAt(EL_SIZE idx, T test) const
	{
		if (!m_ptr)
			return false;

		EL_SIZE len = GetLen();
		if (idx >= len)
			return false;
		
		return test == m_ptr[idx];				
	}

	EL_SIZE FindLeftCharAt(T test, EL_SIZE offset) const
	{
		if (m_ptr)
		{
			EL_SIZE i = offset;
			for (; i < m_len && m_ptr[i]; i++)
				if (m_ptr[i] == test)
					return i;
		}
		return (EL_SIZE)-1;
	}

	EL_SIZE FindRightCharAt(T test, EL_SIZE offset) const
	{
		if (m_ptr)
		{
			EL_INT i = GetLen() - 1 - offset;
			for (; i >= 0; i--)
				if (m_ptr[i] == test)
					return i;
		}
		return (EL_SIZE)-1;
	}

	EL_SIZE GetValue(EL_ACHAR* bufPtr, EL_SIZE bufSize) const;
	EL_SIZE GetValue(EL_ECHAR* bufPtr, EL_SIZE bufSize) const;
	EL_SIZE GetValue(EL_WCHAR* bufPtr, EL_SIZE bufSize) const;

	EL_SIZE	GetLen() const
	{
		if (EL_SIZE(-1) == m_len)	
		{
			m_len = CalcLen(0xffff);			
		}
		return m_len;		
	}

	EL_UINT32 GetHash32() const
	{
		if (EL_SIZE(0) == m_hash32)
		{
			m_hash32 = CalcHash32();
		}
		return m_hash32;
	}

	EL_SIZE CalcLen(EL_SIZE max) const
	{
		if (m_ptr)
		{
			EL_SIZE i = 0;
			while (m_ptr[i++] && i != max);	
			return i - 1;
		}
		else
		{
			return 0;
		}
	}

	EL_UINT32 CalcHash32() const
	{
		if (m_ptr)
		{
			EL_UINT32 ret = 0;
			EL_UINT32 xor = 0;
			EL_SIZE i = 0;

			for (; i != m_len && m_ptr[i]; i++) // GetLen 을 호출하지 않았다면 무한루프를 돌지만
			{	
				EL_UINT32 item = EL_UINT32(m_ptr[i]);
				ret = ( ( ret << 8 ) | item ) % 16777213UL;
				xor ^= item;
			}

			return ret | (xor<<24);
		}
		else
		{
			return 0;
		}
	}

	EL_TSimpleString<T> Slice(EL_SIZE left, EL_SIZE right=(EL_SIZE)-1) const
	{
		EL_SIZE len = GetLen();
		if (left < len && left < right)
		{
			if (right > len)
				right = len;

			return EL_TSimpleString<T>(m_ptr + left, right - left);
		}
		else
		{
			return EL_TSimpleString<T>(m_ptr + m_len, 0);
		}
	}

	EL_BOOL IsPostfix(const IN_SimpleString& test) const
	{
		EL_SIZE len = GetLen();
		if (len > test.GetLen())
		{
			return Slice(len - test.GetLen()).IsPrefix(test);
		}
	}

	EL_BOOL IsSame(const IN_SimpleString& test) const;	
	EL_BOOL IsSameCI(const IN_SimpleString& test) const;

	EL_BOOL IsPrefix(const IN_SimpleString& test) const;	
	EL_BOOL IsPrefixCI(const IN_SimpleString& test) const;
		
private:
	const T* m_ptr;
	mutable EL_SIZE	m_len;
	mutable EL_UINT m_hash32;

private:
	static const T* EMPTY;
};

// EL_SimpleStringA
template<>
inline EL_SIZE EL_TSimpleString<EL_ACHAR>::GetValue(EL_ACHAR* bufPtr, EL_SIZE bufSize) const
{return m_ptr ? Mantle::MA_MBtoMB(GetPtr(), GetLen(), bufPtr, bufSize) : 0;}

template<>
inline EL_SIZE EL_TSimpleString<EL_ACHAR>::GetValue(EL_ECHAR* bufPtr, EL_SIZE bufSize) const
{return m_ptr ? Mantle::MA_MBtoEC(GetPtr(), GetLen(), bufPtr, bufSize) : 0;}

template<>
inline EL_SIZE EL_TSimpleString<EL_ACHAR>::GetValue(EL_WCHAR* bufPtr, EL_SIZE bufSize) const
{return m_ptr ? Mantle::MA_MBtoWC(GetPtr(), GetLen(), bufPtr, bufSize) : 0;}

template<>
inline EL_BOOL EL_TSimpleString<EL_ACHAR>::IsSame(const EL_TSimpleString<EL_ACHAR>& test) const
{return MA_StringCompareA(GetPtr(), test.GetPtr()) == 0;}

template<>
inline EL_BOOL EL_TSimpleString<EL_ACHAR>::IsSameCI(const EL_TSimpleString<EL_ACHAR>& test) const
{return MA_StringCompareCIA(GetPtr(), test.GetPtr()) == 0;}

template<>
inline EL_BOOL EL_TSimpleString<EL_ACHAR>::IsPrefix(const EL_TSimpleString<EL_ACHAR>& test) const
{return MA_StringNCompareA(GetPtr(), test.GetPtr(), test.GetLen()) == 0;}

template<>
inline EL_BOOL EL_TSimpleString<EL_ACHAR>::IsPrefixCI(const EL_TSimpleString<EL_ACHAR>& test) const
{return MA_StringNCompareCIA(GetPtr(), test.GetPtr(), test.GetLen()) == 0;}

// EL_SimpleStringE
template<>
inline EL_SIZE EL_TSimpleString<EL_ECHAR>::GetValue(EL_ACHAR* bufPtr, EL_SIZE bufSize) const
{return m_ptr ? Mantle::MA_ECtoMB(GetPtr(), GetLen(), bufPtr, bufSize) : 0;}

template<>
inline EL_SIZE EL_TSimpleString<EL_ECHAR>::GetValue(EL_ECHAR* bufPtr, EL_SIZE bufSize) const
{return m_ptr ? Mantle::MA_ECtoEC(GetPtr(), GetLen(), bufPtr, bufSize) : 0;}

template<>
inline EL_SIZE EL_TSimpleString<EL_ECHAR>::GetValue(EL_WCHAR* bufPtr, EL_SIZE bufSize) const
{return m_ptr ? Mantle::MA_ECtoWC(GetPtr(), GetLen(), bufPtr, bufSize) : 0;}

template<>
inline EL_BOOL EL_TSimpleString<EL_ECHAR>::IsSame(const EL_TSimpleString<EL_ECHAR>& test) const
{return MA_StringCompareE(GetPtr(), test.GetPtr()) == 0;}

template<>
inline EL_BOOL EL_TSimpleString<EL_ECHAR>::IsSameCI(const EL_TSimpleString<EL_ECHAR>& test) const
{return MA_StringCompareCIE(GetPtr(), test.GetPtr()) == 0;}

template<>
inline EL_BOOL EL_TSimpleString<EL_ECHAR>::IsPrefix(const EL_TSimpleString<EL_ECHAR>& test) const
{return MA_StringNCompareE(GetPtr(), test.GetPtr(), test.GetLen()) == 0;}

template<>
inline EL_BOOL EL_TSimpleString<EL_ECHAR>::IsPrefixCI(const EL_TSimpleString<EL_ECHAR>& test) const
{return MA_StringNCompareCIE(GetPtr(), test.GetPtr(), test.GetLen()) == 0;}

// EL_SimpleStringW
template<>
inline EL_SIZE EL_TSimpleString<EL_WCHAR>::GetValue(EL_ACHAR* bufPtr, EL_SIZE bufSize) const
{return m_ptr ? Mantle::MA_WCtoMB(GetPtr(), GetLen(), bufPtr, bufSize) : 0;}

template<>
inline EL_SIZE EL_TSimpleString<EL_WCHAR>::GetValue(EL_ECHAR* bufPtr, EL_SIZE bufSize) const
{return m_ptr ? Mantle::MA_WCtoEC(GetPtr(), GetLen(), bufPtr, bufSize) : 0;}

template<>
inline EL_SIZE EL_TSimpleString<EL_WCHAR>::GetValue(EL_WCHAR* bufPtr, EL_SIZE bufSize) const
{return m_ptr ? Mantle::MA_WCtoWC(GetPtr(), GetLen(), bufPtr, bufSize) : 0;}

template<>
inline EL_BOOL EL_TSimpleString<EL_WCHAR>::IsSame(const EL_TSimpleString<EL_WCHAR>& test) const
{return MA_StringCompareW(GetPtr(), test.GetPtr()) == 0;}

template<>
inline EL_BOOL EL_TSimpleString<EL_WCHAR>::IsSameCI(const EL_TSimpleString<EL_WCHAR>& test) const
{return MA_StringCompareCIW(GetPtr(), test.GetPtr()) == 0;}

template<>
inline EL_BOOL EL_TSimpleString<EL_WCHAR>::IsPrefix(const EL_TSimpleString<EL_WCHAR>& test) const
{return MA_StringNCompareW(GetPtr(), test.GetPtr(), test.GetLen()) == 0;}

template<>
inline EL_BOOL EL_TSimpleString<EL_WCHAR>::IsPrefixCI(const EL_TSimpleString<EL_WCHAR>& test) const
{return MA_StringNCompareCIW(GetPtr(), test.GetPtr(), test.GetLen()) == 0;}



typedef EL_TSimpleString<EL_ACHAR>	EL_SimpleStringA;
typedef EL_TSimpleString<EL_WCHAR>	EL_SimpleStringW;
typedef EL_TSimpleString<EL_ECHAR>	EL_SimpleStringE;
typedef EL_TSimpleString<EL_TCHAR>	EL_SimpleString;

#define EL_SIMPLE_STRINGA_CONSTANT(n) EL_SimpleStringA n(EL_TEXTA(#n))
#define EL_SIMPLE_STRINGW_CONSTANT(n) EL_SimpleStringW n(EL_TEXTW(#n))
#define EL_SIMPLE_STRINGE_CONSTANT(n) EL_SimpleStringE n(EL_TEXTE(#n))
#define EL_SIMPLE_STRING_CONSTANT(n) EL_SimpleString n(EL_TEXT(#n))