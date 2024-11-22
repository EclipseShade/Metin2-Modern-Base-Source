#ifndef _EA_STLHASH_H_
#define _EA_STLHASH_H_

#define LINKOFFSET_UNKNOWN		0xDDDDDDDD

class EA_HASHKEY_NONE
{
	bool operator ==( EA_HASHKEY_NONE& __formal )
	{
		return TRUE;
	}
};

class EA_HASHKEY_CONSTSTR
{
public:
	EA_HASHKEY_CONSTSTR();
	EA_HASHKEY_CONSTSTR( char* str ) : m_str( str ) {};

	bool operator ==( char* );
	bool operator ==( EA_HASHKEY_CONSTSTR& );

	char* GetString();

protected:
	char* m_str;
};

class EA_HASHKEY_CONSTSTRI : public EA_HASHKEY_CONSTSTR
{
public:
	EA_HASHKEY_CONSTSTRI();
	EA_HASHKEY_CONSTSTRI( char* str );

	bool operator ==( char* str );
	bool operator ==( EA_HASHKEY_CONSTSTRI& );
};

class EA_HASHKEY_STR
{
public:
	EA_HASHKEY_STR();
	EA_HASHKEY_STR( char * );
	EA_HASHKEY_STR( EA_HASHKEY_STR& );
	~EA_HASHKEY_STR();

	EA_HASHKEY_STR& operator =( char* str );
	EA_HASHKEY_STR& operator =( EA_HASHKEY_STR& );
	bool operator ==( char* );
	bool operator ==( EA_HASHKEY_STR& );

	char* GetString();

protected:
	char* m_str;
};

class EA_HASHKEY_STRI : public EA_HASHKEY_STR
{
public:
	EA_HASHKEY_STRI();
	EA_HASHKEY_STRI( char* );
	EA_HASHKEY_STRI( EA_HASHKEY_STRI& );
	~EA_HASHKEY_STRI();

	EA_HASHKEY_STRI& operator =( EA_HASHKEY_STRI& );
	EA_HASHKEY_STRI& operator =( char* str );
	bool operator == ( char* str );
	bool operator == ( EA_HASHKEY_STRI& );
};

class EA_HASHKEY_INT
{
public:
	EA_HASHKEY_INT();
	EA_HASHKEY_INT( unsigned int );
	EA_HASHKEY_INT( int );
	bool operator ==( EA_HASHKEY_INT& );
	EA_HASHKEY_INT& operator=( EA_HASHKEY_INT& );
};

class EA_HASHKEY_LONGLONG
{
public:
	EA_HASHKEY_LONGLONG();
	EA_HASHKEY_LONGLONG( EA_HASHKEY_LONGLONG& );
	EA_HASHKEY_LONGLONG( __int64 );
	EA_HASHKEY_LONGLONG( int );
	EA_HASHKEY_LONGLONG& operator=( EA_HASHKEY_LONGLONG& );
	int operator==(class EA_HASHKEY_LONGLONG&);
	__int64 GetLongLong();

protected:
	__int64 m_key;
};

class EA_HASHKEY_LANGUAGE
{
	EA_HASHKEY_LANGUAGE( EA_HASHKEY_LANGUAGE& );
	EA_HASHKEY_LANGUAGE( unsigned int, unsigned int );
	bool operator == ( EA_HASHKEY_LANGUAGE& );
	EA_HASHKEY_LANGUAGE& operator=( EA_HASHKEY_LANGUAGE& );

	unsigned int m_languageID;
	unsigned int m_length;
};

//class EA_HASHKEY_TEXTUREFILE
//{
//	char* m_filename;
//	struct CGxTexFlags m_flags;
//
//	void EA_HASHKEY_TEXTUREFILE(char*, struct CGxTexFlags);
//	void EA_HASHKEY_TEXTUREFILE(class EA_HASHKEY_TEXTUREFILE&);
//	void EA_HASHKEY_TEXTUREFILE();
//	void ~EA_HASHKEY_TEXTUREFILE();
//	class EA_HASHKEY_TEXTUREFILE& operator=(class EA_HASHKEY_TEXTUREFILE&);
//	bool operator ==(class EA_HASHKEY_TEXTUREFILE&);
//};

class EA_HASHKEY_PTR
{
	void* m_key;
	void EA_HASHKEY_PTR( EA_HASHKEY_PTR& );
	void EA_HASHKEY_PTR( void* );
	void EA_HASHKEY_PTR();
	EA_HASHKEY_PTR& operator=( EA_HASHKEY_PTR& );
	int operator==( EA_HASHKEY_PTR& );
	void* GetPtr();
};

class EA_HASHKEY_DWORD
{
	unsigned long m_key;
	void EA_HASHKEY_DWORD( EA_HASHKEY_DWORD& );
	void EA_HASHKEY_DWORD( unsigned long );
	int operator==( class EA_HASHKEY_DWORD& );
	unsigned long GetDword();
};

template< class KeyType, class DataType >
class HashEntry
{
public:
	KeyType		m_Key;
	DataType	m_Data;
};

template< class KeyType, class DataType >
class EA_HashTable
{
public:
	typedef HashEntry<KeyType, DataType> Entry;
	int		m_nSize;
	int		m_nCount;
	TSFixedArray< STNTLinkedList< Entry > > m_Table;
	unsigned long int (*m_HashFunction)(KeyType);
};

template< class DataType, class HashFunctionClass >
class EA_TSHashObject
{
	u32			m_u32HashValue;
	TSLink<DataType>	m_LinkToSlot;
	TSLink<DataType>	m_LinkToFull;
	HashFunctionClass	m_HashFunction;

	EA_TSHashObject();
	~EA_TSHashObject();
	EA_TSHashObject( const EA_TSHashObject & );
	EA_TSHashObject& operator=( EA_TSHashObject & );

	HashFunctionClass	GetKey();

	void*			GetData();
	char*			GetString();
	u32			GetHashValue();
};

template< class DataType, class HashFunctionClass >
class EA_EA_TSHashObjectChunk
{
	TSGrowableArray< DataType >					m_Array;
	TSLink<EA_EA_TSHashObjectChunk< DataType, HashFunctionClass> >	m_Link;

	EA_EA_TSHashObjectChunk();
	~EA_EA_TSHashObjectChunk();
	EA_EA_TSHashObjectChunk( const EA_EA_TSHashObjectChunk & );
	EA_EA_TSHashObjectChunk& operator=( EA_EA_TSHashObjectChunk & );
};

template< class DataType, class HashFunctionClass >
class EA_TSHashTable
{
	virtual ~EA_TSHashTable();
	u32 ComputeSlot( u32 );
	void GrowListArray( u32 );
	void Initialize();
	int Initialized();
	void InternalClear( int );
	int MonitorFullness( u32 slot);
	void InternalLinkNode( DataType*, u32 );
	DataType* InternalNew( u32, unsigned long, unsigned long );
	class EA_TSHashTable& NonConst();
	int GetLinkOffset();
	void EA_TSHashTable();
	void EA_TSHashTable( class EA_TSHashTable& );
	class EA_TSHashTable& operator=( EA_TSHashTable& );
	void Clear();
	void Delete( char* );
	void Delete( u32, char* );
	void Delete( u32, HashFunctionClass& );
	void Delete( DataType* );
	DataType* DeleteNode( DataType* );
	DataType* Head();
	void Insert( DataType*, char*);
	void Insert( DataType*, u32, char* );
	void Insert( DataType*, u32, HashFunctionClass& );
	DataType* New( char*, unsigned long, unsigned long );
	DataType* New( u32, char*, unsigned long, unsigned long );
	DataType* New( u32, class HashFunctionClass&, unsigned long, unsigned long );
	DataType* Next( DataType* );
	DataType* Prev( DataType* );
	DataType* Ptr( char* );
	DataType* Ptr( u32, char* );
	DataType* Ptr( u32, class HashFunctionClass& );
	DataType* RawNext( DataType* );
	DataType* Tail();
	void Unlink(DataType*);
	void SetTableSize( u32 );
	float GetAverageBinDepth();
	u32 GetPeakBinDepth();

	virtual void InternalDelete( DataType* ptr );
	virtual DataType* InternalNew( EA_TSExplicitList< DataType, 0xDDDDDDDD >* listptr, unsigned long extrabytes, unsigned long flags );
	virtual void Destroy();

	static u32	Hash( char * );

protected:
	EA_TSExplicitList< DataType, 0xDDDDDDDD >						m_FullList;
	u32																m_nFullnessIndicator;
	TSGrowableArray< EA_TSExplicitList< DataType, 0xDDDDDDDD > >	m_SlotListArray;
	u32																m_SlotMask;
};

template< class DataType, class HashFunctionClass, int Number >
class EA_EA_TSHashTableReuse : class EA_TSHashTable< DataType, HashFunctionClass >
{
	EA_TSExplicitList< DataType, LINKOFFSET_UNKNOWN >							m_reuseList;
	u32												m_nChunkSize;
	EA_TSExplicitList< EA_EA_TSHashObjectChunk< DataType, HashFunctionClass, LINKOFFSET_UNKNOWN >, 20 >	m_ChunkList;

	EA_EA_TSHashTableReuse();
	EA_EA_TSHashTableReuse( EA_EA_TSHashTableReuse & );
	EA_EA_TSHashTableReuse& operator=( EA_EA_TSHashTableReuse& );

	virtual void InternalDelete( HashFunctionClass* ptr );
	virtual struct DataType* InternalNew( EA_TSExplicitList< DataType, LINKOFFSET_UNKNOWN >* listptr, unsigned long extrabytes, unsigned long flags );
	virtual void ~EA_EA_TSHashTableReuse();
	virtual void Destroy();
};

#endif /* _EA_STLHASH_H_ */


/*

template<class T, class THashFunctor, EA_PFHASHPROTOTYPE pfHashFunction = EA_SDBMHashStringUpper>
class EA_TDHashTable
{
public : 
	EA_TDHashTable();
	~EA_TDHashTable();

	typedef	EA_TDHashObject<T, THashFunctor>		HashObject;
	typedef	HashObject*					PHashObject;

	typedef	EA_TDCExplicitList<T>				ListHashObject;
	//typedef	EA_TDCExplicitList<HashObject, offsetof( HashObject, m_cLinkToEntireTable ) >	ListHashObject;
	//typedef	EA_TDCExplicitList<HashObject, offsetof( HashObject, m_cLinkToSlot )>		ListEntireEntry;


	void	Initialize();
	void	SetTableSize( u32 u32TableSize );
	u32	GetTableSize();
	void	GrowTable( u32 u32GlowSize );

	u32	ComputeSlot( u32 u32Hash );
	u32	ComputeTableSize( u32 u32Size );

	T*	Begin();
	T*	End();
	T*	GetHead();
	T*	GetTail();
	T*	GetNext( T* pPointerToLink );
	T*	GetPrev( T* pPointerToLink );

	T*	Begin( u32 u32TableIndex );
	T*	End( u32 u32TableIndex );
	T*	GetHead( u32 u32TableIndex );
	T*	GetTail( u32 u32TableIndex );
	T*	GetNext( u32 u32TableIndex, T* pPointerToLink );
	T*	GetPrev( u32 u32TableIndex, T* pPointerToLink );

	T*	GetPtr( LPCTSTR tszString );
	T*	GetPtr( LPCTSTR tszString, THashFunctor& rCompareFunctor );

	void	Unlink( T* pPointerToLink );

	void	Clear();

	void	Insert( LPCTSTR tszString, T* pPointerToLink );
protected:
	ListHashObject 			m_cListEntireTable;
	EA_TArray<ListHashObject>	m_cArrListTable;
	u32				m_u32SlotMask;
	u32				m_u32FullnessIndecator;

	const	u32			m_cu32SlotLinkOffset;
	const	u32			m_cu32EntireTableLinkOffset;
private:
	EA_TDHashTable( EA_TDHashTable<T, THashFunctor, pfHashFunction>& );
	EA_TDHashTable<T, THashFunctor, pfHashFunction>& operator = ( EA_TDHashTable<T, THashFunctor, pfHashFunction>& rRHS );
};

*/
