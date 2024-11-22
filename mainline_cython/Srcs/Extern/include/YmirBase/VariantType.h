#pragma once

#define HAVE_STRING

#include <Mantle/MA_CStringBits.h>
#include <Mantle/MA_CStringType.h>

enum EL_EVARIANTTYPE {
	eVT_UNKNOWN	= 0,
    eVT_INT8,
    eVT_INT16,
    eVT_INT32,
    eVT_INT64,
    eVT_STRINGA,
    eVT_STRINGW,
    eVT_STRINGE,
    eVT_F32,
    eVT_F64,
    eVT_BOOL,
    eVT_BINARY,
    eVT_QUANTITY
};

#ifdef _UNICODE
#define sStringToTypeName		sStringToTypeNameW
#define sGetTypeName			sGetTypeNameW
#else
#define sStringToTypeName		sStringToTypeNameA
#define sGetTypeName			sGetTypeNameA
#endif

class EL_CVariantObject
{
public:
    EL_CVariantObject( bool is_null = true );
    virtual ~EL_CVariantObject();

    bool IsNULL() const  { return m_Null; }
    virtual void AssignNULL();

    virtual EL_EVARIANTTYPE    GetType() const = 0;
    virtual EL_CVariantObject* Clone()   const = 0;
    virtual void AssignValue(const EL_CVariantObject& v) = 0;

    // Create and return a new object (with internal value NULL) of type "type".
    // NOTE:  "size" matters only for eVT_STRING, eVT_BINARY, eVT_LongChar, eVT_LongBinary.
    static EL_CVariantObject*	Create( EL_EVARIANTTYPE type, size_t size = 1 );

    // Get human-readable type name for db_type
    static LPCSTR				sGetTypeNameA( EL_EVARIANTTYPE eType );
	static LPCWSTR				sGetTypeNameW( EL_EVARIANTTYPE eType );

	static EL_SIZE				sGetTypeSize( EL_EVARIANTTYPE eType );
	static EL_EVARIANTTYPE		sStringToTypeNameA( MA_LPCASTR szTypeName );
	static EL_EVARIANTTYPE		sStringToTypeNameW( MA_LPCWSTR szTypeName );

protected:
    void SetNULL( bool flag = true ) { m_Null = flag; }

private:
    bool m_Null;
};

/////////////////////////////////////////////////////////////////////////////
class CVariant_Int : public EL_CVariantObject
{
public:
    CVariant_Int();
    CVariant_Int(const EL_INT32& i);
    virtual ~CVariant_Int(void);

    CVariant_Int& operator= (const EL_INT32& i) {
        SetNULL(false);
        m_Val  = i;
        return *this;
    }

    EL_INT32  Value()   const  { return IsNULL() ? 0 : m_Val; }
    void* BindVal() const  { return (void*) &m_Val; }

    virtual EL_EVARIANTTYPE    GetType() const;
    virtual EL_CVariantObject* Clone() const;
    virtual void AssignValue(const EL_CVariantObject& v);

protected:
    EL_INT32 m_Val;
};



/////////////////////////////////////////////////////////////////////////////
class CVariant_SmallInt : public EL_CVariantObject
{
public:
    CVariant_SmallInt();
    CVariant_SmallInt(const EL_INT16& i);
    virtual ~CVariant_SmallInt(void);

    CVariant_SmallInt& operator= (const EL_INT16& i) {
        SetNULL(false);
        m_Val = i;
        return *this;
    }

    EL_INT16  Value()   const  { return IsNULL() ? (EL_INT16) 0 : m_Val; }
    void* BindVal() const  { return (void*) &m_Val; }

    virtual EL_EVARIANTTYPE    GetType() const;
    virtual EL_CVariantObject* Clone() const;
    virtual void AssignValue(const EL_CVariantObject& v);

protected:
    EL_INT16 m_Val;
};



/////////////////////////////////////////////////////////////////////////////
class CVariant_TinyInt : public EL_CVariantObject
{
public:
    CVariant_TinyInt();
    CVariant_TinyInt(const EL_UINT8& i);
    virtual ~CVariant_TinyInt(void);

    CVariant_TinyInt& operator= (const EL_UINT8& i) {
        SetNULL(false);
        m_Val = i;
        return *this;
    }

    EL_UINT8 Value()   const  { return IsNULL() ? (EL_UINT8) 0 : m_Val; }
    void* BindVal() const  { return (void*) &m_Val; }

    virtual EL_EVARIANTTYPE    GetType() const;
    virtual EL_CVariantObject* Clone()   const;
    virtual void AssignValue(const EL_CVariantObject& v);

protected:
    EL_UINT8 m_Val;
};



/////////////////////////////////////////////////////////////////////////////
class CVariant_BigInt : public EL_CVariantObject
{
public:
    CVariant_BigInt();
    CVariant_BigInt(const EL_INT64& i);
    virtual ~CVariant_BigInt(void);

    CVariant_BigInt& operator= (const EL_INT64& i) {
        SetNULL(false);
        m_Val = i;
        return *this;
    }

    EL_INT64 Value() const  { return IsNULL() ? 0 : m_Val; }
    void* BindVal() const  { return (void*) &m_Val; }


    virtual EL_EVARIANTTYPE    GetType() const;
    virtual EL_CVariantObject* Clone()   const;
    virtual void AssignValue(const EL_CVariantObject& v);

protected:
    EL_INT64 m_Val;
};

/////////////////////////////////////////////////////////////////////////////
class CVariant_String : public EL_CVariantObject
{
public:
    CVariant_String(void);
    CVariant_String(const CVariant_String& other);
    explicit CVariant_String(size_t s);
    explicit CVariant_String(const std::string& s);
	explicit CVariant_String(const char* s, std::string::size_type size = std::string::npos);
	explicit CVariant_String(const std::string& s, std::string::size_type size = std::string::npos);
    virtual ~CVariant_String(void);

public:
    // Assignment operators
    CVariant_String& operator= (const CVariant_String& other);
    CVariant_String& operator= (const std::string& s);
    CVariant_String& operator= (const char* s);

public:
    // Conversion operators
    operator const char*(void) const
    {
        return m_strString.c_str();
    }
    operator const std::string&(void) const
    {
        return m_strString;
    }

public:
#if defined(HAVE_WSTRING)
    // enc - expected source string encoding.
    const wchar_t*  AsUnicode(EEncoding enc) const
    {
        return IsNULL() ? NULL : m_WString.AsUnicode(enc).c_str();
    }
#endif

    const char* Value(void) const
    {
        return IsNULL() ? NULL : static_cast<const char*>(m_strString.c_str());
    }
    size_t Size(void) const
    {
		return IsNULL() ? 0 : m_strString.length();
    }


public:
    virtual EL_EVARIANTTYPE    GetType() const;
    virtual EL_CVariantObject* Clone()   const;
    virtual void AssignValue(const EL_CVariantObject& v);

	void SetValue(const char* str, size_t len);

	// set-value methods
    void Assign(const CVariant_String& other);
    void Assign(const char* s, std::string::size_type size = std::string::npos);
	void Assign(const std::string& s, std::string::size_type size = std::string::npos);

private:
	std::string	m_strString;
};

/////////////////////////////////////////////////////////////////////////////
class CVariant_Binary : public EL_CVariantObject
{
public:
    CVariant_Binary(size_t s = 1);
    CVariant_Binary(size_t s, const void* v, size_t v_size);
    CVariant_Binary(const CVariant_Binary& v);
    virtual ~CVariant_Binary();

public:
    void SetValue(const void* v, size_t v_size);

    CVariant_Binary& operator= (const CVariant_Binary& v);

    //
    const void* Value() const  { return IsNULL() ? NULL : (void*) m_Value.c_str(); }
    size_t      Size()  const  { return IsNULL() ? 0 : m_Value.size(); }

    virtual EL_EVARIANTTYPE    GetType() const;
    virtual EL_CVariantObject* Clone()   const;

    virtual void AssignValue(const EL_CVariantObject& v);

protected:
    size_t m_Size;
	std::string m_Value;
};

/////////////////////////////////////////////////////////////////////////////
class CVariant_Float : public EL_CVariantObject
{
public:
    CVariant_Float();
    CVariant_Float(float i);
    virtual ~CVariant_Float(void);

    CVariant_Float& operator= (const float& i);
public:

    float Value()   const { return IsNULL() ? 0 : m_Val; }
    void* BindVal() const { return (void*) &m_Val; }

    virtual EL_EVARIANTTYPE    GetType() const;
    virtual EL_CVariantObject* Clone()   const;
    virtual void AssignValue(const EL_CVariantObject& v);

protected:
    float m_Val;
};

/////////////////////////////////////////////////////////////////////////////
class CVariant_Double : public EL_CVariantObject
{
public:
    CVariant_Double();
    CVariant_Double(double i);
    virtual ~CVariant_Double(void);

public:
    CVariant_Double& operator= (const double& i);

    //
    double Value()   const  { return IsNULL() ? 0 : m_Val; }
    void*  BindVal() const  { return (void*) &m_Val; }

    virtual EL_EVARIANTTYPE    GetType() const;
    virtual EL_CVariantObject* Clone()   const;
    virtual void AssignValue(const EL_CVariantObject& v);

protected:
    double m_Val;
};

/////////////////////////////////////////////////////////////////////////////
class CVariant_Bool : public EL_CVariantObject
{
public:
    CVariant_Bool();
    CVariant_Bool(int  i);
    CVariant_Bool(bool i);
    virtual ~CVariant_Bool(void);

public:
    CVariant_Bool& operator= (const int& i);
    CVariant_Bool& operator= (const bool& i);

    int   Value()   const  { return IsNULL() ? 0 : (int) m_Val; }
    void* BindVal() const  { return (void*) &m_Val; }

    virtual EL_EVARIANTTYPE    GetType() const;
    virtual EL_CVariantObject* Clone()   const;
    virtual void AssignValue(const EL_CVariantObject& v);

protected:
    EL_UINT8 m_Val;
};

class EL_CVariantType
{
public:
	EL_CVariantType() {}
	virtual ~EL_CVariantType()	{}

	void					SetType( EL_EVARIANTTYPE eType )	{ m_eType = eType; }
	virtual EL_EVARIANTTYPE	vGetType( void )					{ return m_eType; }
	virtual EL_BOOL			vStringToType( MA_LPCTSTR tszString, LPVOID pvType, EL_SIZE sizeType )		= 0;
	virtual EL_BOOL			vLoad( MA_LPCTSTR /*tszFileName*/ ) { return EL_FALSE; }
protected:
	EL_EVARIANTTYPE			m_eType;
};

class EL_CVariantType_Bits : public EL_CVariantType
{
public:
	EL_CVariantType_Bits() {}
	virtual ~EL_CVariantType_Bits() {}

	virtual EL_BOOL			vStringToType( MA_LPCTSTR tszString, LPVOID pvType, EL_SIZE sizeType );
	virtual EL_BOOL			vLoad( MA_LPCTSTR tszFileName );

protected:
	Mantle::MA_CStringBitsSerial	m_cStringBits;
};

class EL_CVariantType_Type : public EL_CVariantType
{
public:
	EL_CVariantType_Type() {}
	virtual ~EL_CVariantType_Type() {}

	virtual EL_BOOL			vStringToType( MA_LPCTSTR tszString, LPVOID pvType, EL_SIZE sizeType );
	virtual EL_BOOL			vLoad( MA_LPCTSTR tszFileName );

protected:
	Mantle::MA_CStringTypeSerial	m_cStringType;
};
