#pragma once

#pragma warning(disable:4127)  // conditional expression is constant
#include <boost/pool/pool_alloc.hpp>
#pragma warning(default:4127)
#include <boost/foreach.hpp>

#include "TBasicString.h"
#include "TSimpleString.h"
#include "TSimpleStringUtils.h"

#include "TStringBuffer.h"

template<typename T, EL_SIZE MIN_BUCKET_COUNT=32>
class EL_TStringTable
{
public:
	typedef T IN_CHAR;
		
	typedef EL_TSimpleString<IN_CHAR>		IN_SimpleString;		
	typedef EL_TSimpleStringUtils<IN_CHAR>	IN_SimpleStringUtils;
	
	typedef EL_TStringBuffer<IN_CHAR>		IN_StringBuffer;

	typedef EL_TStringStaticBuffer<IN_CHAR, 0xff> IN_StringStaticBuffer_S;
	typedef EL_TStringStaticBuffer<IN_CHAR, 1024> IN_StringStaticBuffer_M;
	typedef EL_TStringStaticBuffer<IN_CHAR, 0xffff> IN_StringStaticBuffer_L;

	typedef std::basic_string<T>			IN_BasicString;	
	typedef std::vector<IN_SimpleString>	IN_SimpleStrings;

	EL_BOOL SetValue(const IN_SimpleString& key, const IN_BasicString& val)
	{
		EL_UINT32 keyHash = key.GetHash32();
		KeyValued::iterator f = m_keyValued.find(keyHash);

		if (m_keyValued.end() == f)
		{
			m_keyValued.insert(KeyValued::value_type(keyHash, val));
			return EL_TRUE;
		}
		else
		{
			f->second = val;
			return EL_FALSE;
		}
	}

	EL_BOOL SetValuei(const IN_SimpleString& key, EL_INT val)
	{
		IN_StringStaticBuffer_S buf;
		EL_StringBufferA_FromInt(buf, val);
		return SetValue(key, String(buf.GetPtr(), buf.GetLen()));
	}

	EL_BOOL SetValuef(const IN_SimpleString& key, EL_FLOAT val)
	{
		IN_StringStaticBuffer_S buf;
		EL_StringBufferA_FromFloat(buf, val);
		return SetValue(key, String(buf.GetPtr(), buf.GetLen()));
	}

	EL_BOOL SetValueb(const IN_SimpleString& key, EL_BOOL val)
	{
		IN_StringStaticBuffer_S buf;
		EL_StringBuffer_FromBool(buf, val);
		return SetValue(key, String(buf.GetPtr(), buf.GetLen()));
	}

	template<typename R>
	EL_BOOL FindValueBuf(const IN_SimpleString& key, EL_TStringBuffer<R>* ret) const
	{
		EL_LOG_ASSERT_RETURN_PARAM(EL_Environment::FindValue, ret);

		EL_UINT32 keyHash = key.GetHash32();
		KeyValued::const_iterator f = m_keyValued.find(keyHash);
		if (m_keyValued.end() == f)
		{
			return false;
		}
		else
		{
			IN_SimpleString foundValue(f->second);
			ret->SetLen(foundValue.GetValue(ret->GetPtr(), ret->GetMax()));
			return true;
		}
	}

	const IN_BasicString* FindValuePtr(const IN_SimpleString& key) const
	{
		EL_UINT32 keyHash = key.GetHash32();
		KeyValued::const_iterator f = m_keyValued.find(keyHash);
		if (m_keyValued.end() == f)
		{
			return NULL;
		}
		else
		{
			return &f->second;
		}
	}

	virtual const IN_BasicString& GetValue(const IN_SimpleString& key, const IN_BasicString& defValue) const
	{
		const IN_BasicString* valPtr = FindValuePtr(key);

		if (valPtr)
			return *valPtr;
		else
			return defValue;
	}

	template<typename R>
	R GetValue(const IN_SimpleString& key, R defValue) const
	{
		const IN_BasicString* valPtr = FindValuePtr(key);

		if (valPtr)	
			return EL_TSimpleStringCaster<IN_CHAR, R>::Cast(IN_SimpleString(*valPtr));
		else
			return defValue;
	}

	virtual EL_FLOAT GetValuef(const IN_SimpleString& key, EL_FLOAT defValue = 0.0f) const
	{
		return GetValue<EL_FLOAT>(key, defValue);
	}

	virtual EL_INT GetValuei(const IN_SimpleString& key, EL_INT defValue = 0) const
	{
		return GetValue<EL_INT>(key, defValue);
	}

	virtual EL_BOOL GetValueb(const IN_SimpleString& key, EL_BOOL defValue = false) const
	{
		return GetValue<EL_BOOL>(key, defValue);
	}

	EL_UINT CalcFlags(const IN_SimpleString& src)
	{
		EL_UINT retFlags = 0;
		IN_SimpleStrings tokens;
		if (IN_SimpleStringUtils::Split(src, IN_StringConstants::FLAG_SEP()[0], &tokens))
		{
			BOOST_FOREACH(const IN_SimpleString& token, tokens)
			{
				retFlags |= GetValue<EL_UINT>(token);
			}
		}
		return retFlags;
	}

	EL_VOID ReplaceMacros(const IN_SimpleString& src, IN_StringBuffer* out)
	{	
		EL_SIZE srcLen = src.GetLen();
		for (EL_SIZE i = 0; i < srcLen; )
		{
			const IN_CHAR s = src.GetCharAt(i++);
			IN_CHAR n;
			if (s == '$' && src.GetCharAt(i, &n) && n == '(')
			{
				i++; // $(

				IN_StringStaticBuffer_M var;
				while (src.GetCharAt(i++, &n))
				{
					if (n == ')')
						break;
					else
						var.AppendChar(n);
				}

				const IN_BasicString* valPtr = FindValuePtr(var);
				if (valPtr)
					out->Append(IN_SimpleString(*valPtr));
				else
					out->Append(IN_SimpleString(var));
			}
			else
			{
				out->AppendChar(s);
			}
		}
	}

private:
	struct HashCompare
	{
		enum
		{
			bucket_size = 4,
			min_buckets = MIN_BUCKET_COUNT,
		};

		size_t operator()(const int _Key) const
		{return (size_t)_Key;}

		bool operator()(const int _Key1, const int _Key2) const
		{return _Key1 < _Key2;}

	};

private:
	typedef boost::fast_pool_allocator<EL_UINT, boost::default_user_allocator_new_delete, boost::details::pool::null_mutex> Allocator;

	typedef stdext::hash_map<EL_UINT, IN_BasicString, HashCompare> KeyValued;

private:
	KeyValued		m_keyValued;
	IN_BasicString	m_defValue;
};

typedef EL_TStringTable<EL_ACHAR> EL_StringTableA;
typedef EL_TStringTable<EL_WCHAR> EL_StringTableW;
typedef EL_TStringTable<EL_ECHAR> EL_StringTableE;
typedef EL_TStringTable<EL_TCHAR> EL_StringTable;
