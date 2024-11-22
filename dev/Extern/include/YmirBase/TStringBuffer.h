#pragma once

#include "TSimpleString.h"

template<typename T>
class EL_TStringBuffer
{
public:
	operator const T* ()
	{return m_bufPtr;}

	operator EL_TSimpleString<T> ()
	{return EL_TSimpleString<T>(m_bufPtr, m_len);}

public:	
	EL_TStringBuffer(T* bufPtr, EL_SIZE bufCapacity) : m_bufPtr(bufPtr), m_max(bufCapacity), m_len(0)
	{
		m_bufPtr[0] = 0;
	}

	EL_SIZE Assign(const EL_TSimpleString<T>& src)
	{				
		EL_SIZE copyLen = src.GetLen();
		if (copyLen > m_max-1)
			copyLen = m_max-1;
		
		const T* srcPtr = src.GetPtr();
		for (EL_SIZE i = 0; i != copyLen; ++i)
			m_bufPtr[i] = srcPtr[i];

		m_len = copyLen;
		m_bufPtr[m_len] = 0;		
		return m_len;
	}

	EL_SIZE Append(const EL_TSimpleString<T>& src)
	{
		EL_LOG_ASSERT(m_len <= (m_max - 1));
		EL_SIZE base = m_len;
		EL_SIZE restLen = (m_max - 1) - base;
		EL_SIZE copyLen = src.GetLen();
		if (copyLen > restLen)
			copyLen = restLen;

		const T* srcPtr = src.GetPtr();
		for (EL_SIZE i = 0; i != copyLen; ++i)
			m_bufPtr[base + i] = srcPtr[i];

		m_len = base + copyLen;
		m_bufPtr[m_len] = 0;
		return m_len;
	}
	EL_SIZE AppendChar(const T chr)
	{
		if (m_len < m_max-1)
		{
			m_bufPtr[m_len++] = chr;	
			m_bufPtr[m_len] = 0;
			return m_len;
		}
		else
		{
			return m_len;
		}			
	}

	EL_BOOL SetLen(EL_SIZE len)
	{
		if (len < m_max-1)
		{
			m_bufPtr[len] = 0;
			m_len = len;
			return true;
		}
		else
		{
			return false;
		}			
	}

	T* GetPtr() const
	{return m_bufPtr;}

	EL_SIZE GetLen() const
	{return m_len;}

	EL_SIZE GetMax() const
	{return m_max;}

	EL_TSimpleString<T> GetStr()
	{return EL_TString<T>(m_bufPtr, m_len);}

private:		
	T*		m_bufPtr;
	EL_SIZE m_max;
	EL_SIZE m_len;		
};

typedef EL_TStringBuffer<EL_ACHAR>		EL_StringBufferA;
typedef EL_TStringBuffer<EL_WCHAR>		EL_StringBufferW;
typedef EL_TStringBuffer<EL_ECHAR>		EL_StringBufferE;
typedef EL_TStringBuffer<EL_TCHAR>		EL_StringBuffer;

template<typename T, EL_SIZE MAX_LEN>
class EL_TStringStaticBuffer : public EL_TStringBuffer<T>
{
public:
	EL_TStringStaticBuffer()
	: EL_TStringBuffer(m_buf, MAX_LEN)
	{}
	EL_TStringStaticBuffer(const EL_StringBufferA& src)
	: EL_TStringBuffer(m_buf, MAX_LEN)
	{
		SetLen(EL_SimpleStringA(src.GetPtr(), src.GetLen()).GetValue(m_buf, MAX_LEN));
	}
	EL_TStringStaticBuffer(const EL_StringBufferE& src)
	: EL_TStringBuffer(m_buf, MAX_LEN)
	{
		SetLen(EL_SimpleStringE(src.GetPtr(), src.GetLen()).GetValue(m_buf, MAX_LEN));
	}
	EL_TStringStaticBuffer(const EL_StringBufferW& src)
	: EL_TStringBuffer(m_buf, MAX_LEN)
	{
		SetLen(EL_SimpleStringW(src.GetPtr(), src.GetLen()).GetValue(m_buf, MAX_LEN));
	}
	EL_TStringStaticBuffer(const EL_SimpleStringA& src)
	: EL_TStringBuffer(m_buf, MAX_LEN)
	{
		SetLen(src.GetValue(m_buf, MAX_LEN));
	}
	EL_TStringStaticBuffer(const EL_SimpleStringE& src)
	: EL_TStringBuffer(m_buf, MAX_LEN)
	{
		SetLen(src.GetValue(m_buf, MAX_LEN));
	}
	EL_TStringStaticBuffer(const EL_SimpleStringW& src)
	: EL_TStringBuffer(m_buf, MAX_LEN)
	{
		SetLen(src.GetValue(m_buf, MAX_LEN));
	}
	
private:
	T m_buf[MAX_LEN];
};

typedef EL_TStringStaticBuffer<EL_ACHAR, 0xff>	 EL_StringBufferA_S;
typedef EL_TStringStaticBuffer<EL_ACHAR, 1024>	 EL_StringBufferA_M;
typedef EL_TStringStaticBuffer<EL_ACHAR, 0xffff> EL_StringBufferA_L;

typedef EL_TStringStaticBuffer<EL_WCHAR, 0xff>	 EL_StringBufferW_S;
typedef EL_TStringStaticBuffer<EL_WCHAR, 1024>	 EL_StringBufferW_M;
typedef EL_TStringStaticBuffer<EL_WCHAR, 0xffff> EL_StringBufferW_L;

typedef EL_TStringStaticBuffer<EL_ECHAR, 0xff*4>   EL_StringBufferE_S;
typedef EL_TStringStaticBuffer<EL_ECHAR, 1024*4>   EL_StringBufferE_M;
typedef EL_TStringStaticBuffer<EL_ECHAR, 0xffff*4> EL_StringBufferE_L;

typedef EL_TStringStaticBuffer<EL_TCHAR, 0xff>	 EL_StringBuffer_S;
typedef EL_TStringStaticBuffer<EL_TCHAR, 1024>	 EL_StringBuffer_M;
typedef EL_TStringStaticBuffer<EL_TCHAR, 0xffff> EL_StringBuffer_L;
