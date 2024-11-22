#pragma once

#pragma warning(disable:4127)  // conditional expression is constant
#include <boost/pool/pool_alloc.hpp>
#pragma warning(default:4127)
#include "TSimpleString.h"
#include "TBasicString.h"

template<typename T>
class EL_TFixedStringMaker
{
public:
	typedef T IN_CHAR;
	typedef const IN_CHAR* IN_C_CHAR_P;

	typedef EL_TSimpleString<IN_CHAR> IN_SimpleString;
	typedef std::basic_string<IN_CHAR> IN_BasicString;

public:
	EL_VOID Reserve(EL_SIZE capacity)
	{
		m_stringTrunk.reserve(capacity);
	}

	EL_VOID Clear()
	{
		m_stringTrunk.clear();
		m_stringd.clear();
	}

	const EL_BasicStringA& GetStringTrunk()
	{
		return m_stringTrunk;
	}

	const IN_SimpleString& MakeFixedString(const IN_SimpleString& src)
	{
		if (src.IsEmpty())
			return src;

		EL_UINT32 srcHash = src.GetHash32();		
		IN_SimpleStringd::iterator f = m_stringd.find(srcHash);
		if (m_stringd.end() == f)
		{			
			IN_C_CHAR_P srcPtr = src.GetPtr();
			EL_SIZE srcLen = src.GetLen();

			EL_UINT appendPos = m_stringTrunk.length();
			m_stringTrunk.append(srcPtr, srcLen+1); // 널문자 포함해서 입력

			IN_SimpleString& newString = m_stringd[srcHash];
			newString = IN_SimpleString(&m_stringTrunk[appendPos], srcLen, srcHash);
			return newString;
		}
		else
		{				
			return f->second;
		}
	}

private:
	struct HashCompare
	{
		enum
		{
			bucket_size = 4,
			min_buckets = 256,
		};

		size_t operator()(const int _Key) const
		{return (size_t)_Key;}

		bool operator()(const int _Key1, const int _Key2) const
		{return _Key1 < _Key2;}

	};

private:
	typedef boost::fast_pool_allocator<EL_UINT32, boost::default_user_allocator_new_delete, boost::details::pool::null_mutex> Allocator;
	typedef stdext::hash_map<EL_UINT32, IN_SimpleString, HashCompare, Allocator> IN_SimpleStringd;		

private:
	IN_SimpleStringd m_stringd;
	IN_BasicString	 m_stringTrunk;
};

typedef EL_TFixedStringMaker<EL_ACHAR> EL_FixedStringMakerA;
typedef EL_TFixedStringMaker<EL_WCHAR> EL_FixedStringMakerW;
typedef EL_TFixedStringMaker<EL_ECHAR> EL_FixedStringMakerE;
typedef EL_TFixedStringMaker<EL_TCHAR> EL_FixedStringMaker;