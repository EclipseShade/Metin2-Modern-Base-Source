// Adapted from NCBI C++ Toolkit

#pragma once

#include "VariantType.h"

class EL_CVariant
{
public:
    // Contructors to create EL_CVariant from various primitive types
    explicit EL_CVariant( EL_INT64 v );
    explicit EL_CVariant( EL_INT32 v );
    explicit EL_CVariant( EL_INT16 v );
    explicit EL_CVariant( EL_UINT8 v );
    explicit EL_CVariant( float v );
    explicit EL_CVariant( double v );
    explicit EL_CVariant( bool v );
	explicit EL_CVariant( const std::string& v );
    explicit EL_CVariant( const char* s );

    // Factories for different types
    // NOTE: pass p = 0 to make NULL value
    static EL_CVariant BigInt       (EL_INT64 *p);
    static EL_CVariant Int          (EL_INT32 *p);
    static EL_CVariant SmallInt     (EL_INT16 *p);
    static EL_CVariant TinyInt      (EL_UINT8 *p);
    static EL_CVariant Float        (float *p);
    static EL_CVariant Double       (double *p);
    static EL_CVariant Bit          (bool *p);
    static EL_CVariant String       (size_t size, const char *p);
    static EL_CVariant Binary       (size_t size, const void *p, size_t len);

    // Make "placeholder" EL_CVariant by type, containing NULL value
    EL_CVariant(EL_EVARIANTTYPE type, size_t size = 0);

    // Make EL_CVariant from internal EL_CVariantObject
    explicit EL_CVariant(EL_CVariantObject* obj);

    // Copy constructor
    EL_CVariant(const EL_CVariant& v);

    // Destructor
    ~EL_CVariant();

    // Get methods
    EL_EVARIANTTYPE GetType() const;

    EL_INT64		GetInt8(void) const;
	std::string		GetString(void) const;
    EL_INT32		GetInt4(void) const;
    EL_INT16		GetInt2(void) const;
    EL_UINT8		GetByte(void) const;
    float			GetFloat(void) const;
    double			GetDouble(void) const;
    bool			GetBit(void) const;

    // Get the argument as default, if the column is NULL
	std::string		AsNotNullString(const std::string& v) const;

    // Status info
    bool IsNull() const;

    // NULLify
    void SetNull();

    // operators
    EL_CVariant& operator=(const EL_CVariant& v);
    EL_CVariant& operator=(const EL_INT64& v);
    EL_CVariant& operator=(const EL_INT32& v);
    EL_CVariant& operator=(const EL_INT16& v);
    EL_CVariant& operator=(const EL_UINT8& v);
    EL_CVariant& operator=(const float& v);
    EL_CVariant& operator=(const double& v);
	EL_CVariant& operator=(const std::string& v);
    EL_CVariant& operator=(const char* v);
    EL_CVariant& operator=(const bool& v);

    // Get pointer to the data buffer
    // NOTE: internal use only!
    EL_CVariantObject* GetData() const;

    // Get pointer to the data buffer, throws EL_CVariantException if buffer is 0
    // NOTE: internal use only!
    EL_CVariantObject* GetNonNullData() const;

    // Methods to work with BLOB data (Text and Image)
    size_t GetBlobSize() const;
    size_t Read(void* buf, size_t len) const;
    size_t Append(const void* buf, size_t len);
    // Truncates from buffer end to buffer start.
    // Truncates everything if no argument
    //void Truncate(size_t len = kMax_UInt);
    // Moves the internal position pointer
    bool MoveTo(size_t pos) const;

protected:
    // Set methods
    void SetData(EL_CVariantObject* o);

private:

//    void VerifyType(bool e) const;
    void CheckNull() const;

    //void x_Verify_AssignType(EL_EVARIANTTYPE db_type, const char* cxx_type) const;
    void x_Inapplicable_Method(const char* method) const;

    class EL_CVariantObject* m_data;
};

bool operator==(const EL_CVariant& v1, const EL_CVariant& v2);
bool operator<(const EL_CVariant& v1, const EL_CVariant& v2);


//================================================================
inline
EL_CVariantObject* EL_CVariant::GetData() const {
    return m_data;
}

inline
EL_EVARIANTTYPE EL_CVariant::GetType() const
{
    return m_data->GetType();
}


inline bool operator!=(const EL_CVariant& v1, const EL_CVariant& v2)
{
    return !(v1 == v2);
}

inline bool operator>(const EL_CVariant& v1, const EL_CVariant& v2)
{
    return v2 < v1;
}

inline bool operator<=(const EL_CVariant& v1, const EL_CVariant& v2)
{
    return v1 < v2 || v1 == v2;
}

inline bool operator>=(const EL_CVariant& v1, const EL_CVariant& v2)
{
    return v2 < v1 || v1 == v2;
}

