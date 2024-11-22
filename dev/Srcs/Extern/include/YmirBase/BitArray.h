/*
 * Project     : Inferna
 * Author      : ymir | SeMinZ 
 */

#ifndef _BitArray_h_
#define _BitArray_h_


class EL_BitArray
{
    public:
	// typedef unsigned long store_type;
	// typedef unsigned char store_type;
	typedef unsigned int store_type;

	class EL_BitProxy;
	// 
	// Constructors and destructor
	// 

	explicit EL_BitArray(unsigned size)
	{
	    Init(size);
	    // Clear last bits
	    Trim();
	}

	EL_BitArray(const EL_BitArray &that)
	{
	    mpStore = 0;
	    *this = that;
	}

	virtual ~EL_BitArray()
	{
	    if (mLength > 1)
		delete mpStore;
	}
	// 
	// Operators	      
	// 

	EL_BitArray &operator = (const EL_BitArray &that)
	{
	    if (this != &that)
	    {
		if (mLength > 1)
		    delete mpStore;

		Init(that.mNumBits);

		memcpy(mpStore, that.mpStore, mLength * sizeof(store_type));
	    }
	    return *this;
	}

	EL_BitProxy operator[](unsigned pos)
	{
	    assert(pos < mNumBits);
	    return EL_BitProxy(*this, pos);
	}

	const EL_BitProxy operator[](unsigned pos) const
	{
	    assert(pos < mNumBits);
	    return EL_BitProxy(const_cast<EL_BitArray &>(*this), pos);
	}

	bool operator ==(const EL_BitArray &that) const
	{
	    if (mNumBits != that.mNumBits)
		return false;

	    for (unsigned i = 0; i < mLength; i++)
		if (mpStore[i] != that.mpStore[i])
		    return false;
	    return true;
	}

	bool operator!= (const EL_BitArray &that) const
	{
	    return !(*this == that);
	}

	EL_BitArray &operator&= (const EL_BitArray &that)
	{
	    assert(mNumBits == that.mNumBits);
	    for (unsigned i = 0; i < mLength; i++)
		mpStore[i] &= that.mpStore[i];
	    return *this;
	}

	EL_BitArray operator |= (const EL_BitArray &that)
	{
	    assert(mNumBits == that.mNumBits);
	    for (unsigned i = 0; i < mLength; i++)
		mpStore[i] |= that.mpStore[i];
	    return *this;
	}

	EL_BitArray operator ^= (const EL_BitArray &that)
	{
	    assert(mNumBits == that.mNumBits);
	    for (unsigned i = 0; i < mLength; i++)
		mpStore[i] ^= that.mpStore[i];
	    return *this;
	}

	EL_BitArray operator ~() const
	{
	    return EL_BitArray(*this).FlipAllBits();
	}

	friend EL_BitArray operator & (const EL_BitArray &a1, const EL_BitArray &a2)
	{
	    return EL_BitArray(a1) &= a2;
	}

	friend EL_BitArray operator | (const EL_BitArray &a1, const EL_BitArray &a2)
	{
	    return EL_BitArray(a1) |= a2;
	}

	friend EL_BitArray operator ^ (const EL_BitArray &a1, const EL_BitArray &a2)
	{
	    return EL_BitArray(a1) ^= a2;
	}

	// 
	// Plain English interface
	// 

	// Set all bits to false.
	void Clear()
	{
	    memset(mpStore, 0, mLength * sizeof(store_type));
	}
	void SetAllBitsTrue()
	{
	    memset(mpStore, 1, mLength * sizeof(store_type));
	}

	// Set the bit at position pos to true.
	void SetBit(unsigned pos)
	{
	    assert(pos < mNumBits);
	    mpStore[GetIndex(pos)] |= ((store_type)1) << GetOffset(pos); 
	}

	// Set the bit at position pos to false.
	void ClearBit(unsigned pos)
	{ 
	    assert(pos < mNumBits);
	    mpStore[GetIndex(pos)] &= ~(((store_type)1) << GetOffset(pos)); 
	}

	// Toggle the bit at position pos.
	void FlipBit(unsigned pos) 
	{ 
	    assert(pos < mNumBits);
	    mpStore[GetIndex(pos)] ^= ((store_type)1) << GetOffset(pos); 
	}

	// Set the bit at position pos to the given value.
	void Set(unsigned pos, bool val)
	{ 
	    val ? SetBit(pos) : ClearBit(pos);
	}

	// Returns true iff the bit at position pos is true.
	bool IsBitSet(unsigned pos) const
	{
	    assert(pos < mNumBits);
	    return (mpStore[GetIndex(pos)] & (((store_type)1) << GetOffset(pos))) != 0;
	}

	// Returns true iff all bits are false.
	bool AllBitsFalse() const
	{
	    for (unsigned i = 0; i < mLength; i++)
		if (mpStore[i] != 0)
		    return false;
	    return true;
	}

	// Change value of all bits
	EL_BitArray &FlipAllBits()
	{
	    for (unsigned i = 0; i < mLength; i++)
		mpStore[i] = ~mpStore[i];

	    Trim();
	    return *this;
	}

	// 
	// Bit proxy (for operator[])
	// 

	friend class EL_BitProxy;

	class EL_BitProxy
	{
	    public:
		EL_BitProxy(EL_BitArray &array, unsigned pos):
		    mArray(array), mPos(pos)
	    {}

		EL_BitProxy &operator = (bool value)
		{
		    mArray.Set(mPos, value);
		    return *this;
		}

		EL_BitProxy &operator = (const EL_BitProxy &that)
		{
		    mArray.Set(mPos, that.mArray.IsBitSet(that.mPos));
		    return *this;
		}

		operator bool() const
		{
		    return mArray.IsBitSet(mPos);
		}

		bool Flip()
		{
		    mArray.FlipBit(mPos);
		    return mArray.IsBitSet(mPos);
		}

	    private:
		EL_BitArray &mArray;
		unsigned  mPos;
	};

	store_type* GetStore() { return mpStore; }

    private:

	enum
	{
	    bits_per_byte = 8, 
	    cell_size     = sizeof(store_type) * bits_per_byte
	};

	store_type        *mpStore;  
	store_type         mSingleWord; // Use this buffer when mLength is 1
	unsigned           mLength;     // Length of mpStore in units of store_type
	unsigned           mNumBits;

	// Get the index and bit offset for a given bit number.
	static unsigned GetIndex(unsigned bit_num)
	{
	    return bit_num / cell_size;
	}

	static unsigned GetOffset(unsigned bit_num)
	{
	    return bit_num % cell_size;
	}

	void Init(unsigned size)
	{
	    mNumBits = size;

	    if (size == 0)
		mLength = 0;
	    else
		mLength = 1 + GetIndex(size - 1);

	    // Avoid allocation if length is 1 (common case)
	    if (mLength <= 1)
		mpStore = &mSingleWord;      
	    else
		mpStore = new store_type[mLength];
	}

	// Force overhang bits at the end to 0
	inline void Trim()
	{
	    unsigned extra_bits = mNumBits % cell_size;
	    if (mLength > 0 && extra_bits != 0)
		mpStore[mLength - 1] &= ~((~(store_type) 0) << extra_bits);
	}
};

#endif	/* _EL_BitArray_h_ */
