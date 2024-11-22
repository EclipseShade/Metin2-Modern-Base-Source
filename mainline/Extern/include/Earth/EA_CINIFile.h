#ifndef _EA_CINIFILE_H_
#define _EA_CINIFILE_H_

#include <Mantle/MA_STLVector.h>

#include "EA_CTextFile.h"

#define MAX_BUFFER_LEN		512
#define MAX_VALUE_LEN		MAX_BUFFER_LEN
#define MAX_KEY_LEN		256
#define MAX_SECTION_LEN		256

_EA_NAMESPACE_BEGIN

class EA_CINIFile
{
public:
	typedef struct tag_KeyType {
		TCHAR		szKey[MAX_KEY_LEN];
		TCHAR		szValue[MAX_VALUE_LEN];
	} KeyType;

	typedef std::vector<KeyType *> KeyArray;
	typedef KeyArray::iterator KeyItr;

	typedef struct tag_section {
		TCHAR		szName[MAX_KEY_LEN];
		KeyArray	Keys;
	} SectionType;

	typedef std::vector<SectionType *>	SectionArray;
	typedef SectionArray::iterator		SectionItr;

public:
	/// EA_CINIFile 생성자
	EA_CINIFile();
	/// EA_CINIFile 생성자
	EA_CINIFile( LPCTSTR szFileName, EA_EOpenFlags nOpenFlags = modeRead );
	/// EA_CINIFile 파괴자
	~EA_CINIFile();

	/// INI 파일을 오픈하고 내용을 메모리에 삽입시킨다.
	/**
	 * @param[in] sFileName INI 파일명
	 * @param[in] nOpenFlags INI 파일 접근권한( modeRead, modeWrite, modeCreate, modeAll )		
	 *							
	 * @return TRUE 성공
	 * @return FALSE 실패
	 */							
	BOOL Open( LPCTSTR szFileName, EA_EOpenFlags nOpenFlags = modeRead );
	/// 메모리에 있는 내용을 파일로 저장한다.
	/**
	 * @param void		
	 *							
	 * @return TRUE 성공
	 * @return FALSE 실패
	 */
	BOOL Save( void );
	/// 변경된 내용이 있으면 저장하고, 모든 메모리를 해제한다.
	/**
	 * @param void		
	 *							
	 * @return TRUE 성공
	 * @return FALSE 실패
	 */
	BOOL Close( void );

	/// 사용자가 원하는 Section 으로 이동( m_CurrentSection )
	/**
	 * @param[in] szSection 섹션명
	 *							
	 * @return TRUE 성공
	 * @return FALSE 실패
	 */
	EA_BOOL		OpenGroup( MA_LPCTSTR IN tszGroup = EA_NULL, EA_BOOL bCreateIfEmpty = EA_FALSE );

	/// Section 의 총 개수를 반환
	/**					
	 * @return Section 의 개수
	 */
	int SectionCount( void );

	/// 열거형으로 INI KeyName 을 읽어온다. KeyName 을 모를 때 사용한다.
	/**
	 * @param szKeyName[out] 키명을 반환한다.
	 * @param KeySize[in,out] szKeyName 값의 사이즈( 입력받을 수 있는 최대값을 지정한다. )
	 * @param szSection[in] 섹션명
	 *							
	 * @return TRUE 성공
	 * @return FALSE 실패
	 */
	BOOL EnumSection( LPTSTR OUT szSectionName, size_t IN OUT &SectionSize );

	/// Key 의 총 개수를 반환
	/**
	 * @param[in] szSection 섹션명
	 *							
	 * @return Key 의 개수
	 */
	int KeyCount( LPTSTR szSection = NULL );

	/// 열거형으로 INI KeyName 을 읽어온다. KeyName 을 모를 때 사용한다.
	/**
	 * @param szKeyName[out] 키명을 반환한다.
	 * @param KeySize[in,out] szKeyName 값의 사이즈( 입력받을 수 있는 최대값을 지정한다. )
	 * @param szSection[in] 섹션명
	 *							
	 * @return TRUE 성공
	 * @return FALSE 실패
	 */
	BOOL EnumKey( LPTSTR OUT szKeyName, size_t IN OUT &KeySize, LPCTSTR IN szSection = NULL );

	/// INI 내용을 읽어온다. ( for s8 )
	/**
	 * @param szKey[in] 키명
	 * @param s8Value[out] 키의 값을 반환한다.
	 * @param szSection[in] 섹션명
	 *							
	 * @return TRUE 성공
	 * @return FALSE 실패
	 */
	BOOL GetValue( LPCTSTR szKey, s8 &s8Value, LPCTSTR szSection = NULL );
	/// INI 내용을 읽어온다. ( for u8 )
	/**
	 * @param szKey[in] 키명
	 * @param u8Value[out] 키의 값을 반환한다.
	 * @param szSection[in] 섹션명
	 *							
	 * @return TRUE 성공
	 * @return FALSE 실패
	 */
	BOOL GetValue( LPCTSTR szKey, u8 &u8Value, LPCTSTR szSection = NULL );
	/// INI 내용을 읽어온다. ( for s16 )
	/**
	 * @param szKey[in] 키명
	 * @param s16Value[out] 키의 값을 반환한다.
	 * @param szSection[in] 섹션명
	 *							
	 * @return TRUE 성공
	 * @return FALSE 실패
	 */
	BOOL GetValue( LPCTSTR szKey, s16 &s16Value, LPCTSTR szSection = NULL );
	/// INI 내용을 읽어온다. ( for u16 )
	/**
	 * @param szKey[in] 키명
	 * @param u16Value[out] 키의 값을 반환한다.
	 * @param szSection[in] 섹션명
	 *							
	 * @return TRUE 성공
	 * @return FALSE 실패
	 */
	BOOL GetValue( LPCTSTR szKey, u16 &u16Value, LPCTSTR szSection = NULL );
	/// INI 내용을 읽어온다. ( for s32 )
	/**
	 * @param szKey[in] 키명
	 * @param s32Value[out] 키의 값을 반환한다.
	 * @param szSection[in] 섹션명
	 *							
	 * @return TRUE 성공
	 * @return FALSE 실패
	 */
	BOOL GetValue( LPCTSTR szKey, s32 &s32Value, LPCTSTR szSection = NULL );
	/// INI 내용을 읽어온다. ( for u32 )
	/**
	 * @param szKey[in] 키명
	 * @param u32Value[out] 키의 값을 반환한다.
	 * @param szSection[in] 섹션명
	 *							
	 * @return TRUE 성공
	 * @return FALSE 실패
	 */
	BOOL GetValue( LPCTSTR szKey, u32 &u32Value, LPCTSTR szSection = NULL );
	/// INI 내용을 읽어온다. ( for s64 )
	/**
	 * @param szKey[in] 키명
	 * @param s64Value[out] 키의 값을 반환한다.
	 * @param szSection[in] 섹션명
	 *							
	 * @return TRUE 성공
	 * @return FALSE 실패
	 */
	BOOL GetValue( LPCTSTR szKey, s64 &s64Value, LPCTSTR szSection = NULL );
	/// INI 내용을 읽어온다. ( for u64 )
	/**
	 * @param szKey[in] 키명
	 * @param u64Value[out] 키의 값을 반환한다.
	 * @param szSection[in] 섹션명
	 *							
	 * @return TRUE 성공
	 * @return FALSE 실패
	 */
	BOOL GetValue( LPCTSTR szKey, u64 &u64Value, LPCTSTR szSection = NULL );
	/// INI 내용을 읽어온다. ( for float )
	/**
	 * @param szKey[in] 키명
	 * @param fValue[out] 키의 값을 반환한다.
	 * @param szSection[in] 섹션명
	 *							
	 * @return TRUE 성공
	 * @return FALSE 실패
	 */
	BOOL GetValue( LPCTSTR szKey, float &fValue, LPCTSTR szSection = NULL );

	BOOL GetValue( LPCTSTR szKey, bool &bValue, LPCTSTR szSection = NULL );

	/// GetValueAsString() : INI 내용을 읽어온다. ( for TCHAR )
	/**
	 * @param szKey[in] 키명
	 * @param szValue[out] 키의 값을 반환한다.
	 * @param ValueSize[in] szValue 의 사이즈를 설정한다.
	 * @param szSection[in] 섹션명
	 *							
	 * @return TRUE 성공
	 * @return FALSE 실패
	 */
	BOOL GetValueAsString( LPCTSTR szKey, LPTSTR szValue, size_t ValueSize, LPCTSTR szSection = NULL );

	/// SetValue() : INI 내용을 입력한다. ( for s8 )
	/**
	 * @param szKey[in] 키명
	 * @param s8Value[in] 키의 값을 반환한다.
	 * @param szSection[in] 섹션명
	 *							
	 * @return TRUE 성공
	 * @return FALSE 실패
	 */
	BOOL SetValue( LPCTSTR szKey, s8 s8Value, LPCTSTR szSection = NULL );
	/// SetValue() : INI 내용을 입력한다. ( for u8 )
	/**
	 * @param szKey[in] 키명
	 * @param u8Value[in] 키값
	 * @param szSection[in] 섹션명
	 *							
	 * @return TRUE 성공
	 * @return FALSE 실패
	 */
	BOOL SetValue( LPCTSTR szKey, u8 u8Value, LPCTSTR szSection = NULL );
	/// SetValue() : INI 내용을 입력한다. ( for s16 )
	/**
	 * @param szKey[in] 키명
	 * @param s16Value[in] 키값
	 * @param szSection[in] 섹션명
	 *							
	 * @return TRUE 성공
	 * @return FALSE 실패
	 */
	BOOL SetValue( LPCTSTR szKey, s16 s16Value, LPCTSTR szSection = NULL );
	/// SetValue() : INI 내용을 입력한다. ( for u16 )
	/**
	 * @param szKey[in] 키명
	 * @param u16Value[in] 키값
	 * @param szSection[in] 섹션명
	 *							
	 * @return TRUE 성공
	 * @return FALSE 실패
	 */
	BOOL SetValue( LPCTSTR szKey, u16 u16Value, LPCTSTR szSection = NULL );
	/// SetValue() : INI 내용을 입력한다. ( for s32 )
	/**
	 * @param szKey[in] 키명
	 * @param s32Value[in] 키값
	 * @param szSection[in] 섹션명
	 *							
	 * @return TRUE 성공
	 * @return FALSE 실패
	 */
	BOOL SetValue( LPCTSTR szKey, s32 s32Value, LPCTSTR szSection = NULL );
	/// SetValue() : INI 내용을 입력한다. ( for u32 )
	/**
	 * @param szKey[in] 키명
	 * @param u32Value[in] 키값
	 * @param szSection[in] 섹션명
	 *							
	 * @return TRUE 성공
	 * @return FALSE 실패
	 */
	BOOL SetValue( LPCTSTR szKey, u32 u32Value, LPCTSTR szSection = NULL );
	/// SetValue() : INI 내용을 입력한다. ( for s64 )
	/**
	 * @param szKey[in] 키명
	 * @param s64Value[in] 키값
	 * @param szSection[in] 섹션명
	 *							
	 * @return TRUE 성공
	 * @return FALSE 실패
	 */
	BOOL SetValue( LPCTSTR szKey, s64 s64Value, LPCTSTR szSection = NULL );
	/// SetValue() : INI 내용을 입력한다. ( for u64 )
	/**
	 * @param szKey[in] 키명
	 * @param u64Value[in] 키값
	 * @param szSection[in] 섹션명
	 *							
	 * @return TRUE 성공
	 * @return FALSE 실패
	 */
	BOOL SetValue( LPCTSTR szKey, u64 u64Value, LPCTSTR szSection = NULL );
	/// SetValue() : INI 내용을 입력한다. ( for float )
	/**
	 * @param szKey[in] 키명
	 * @param fValue[in] 키값
	 * @param szSection[in] 섹션명
	 *							
	 * @return TRUE 성공
	 * @return FALSE 실패
	 */
	BOOL SetValue( LPCTSTR szKey, float fValue, LPCTSTR szSection = NULL );

	BOOL SetValue( LPCTSTR szKey, bool bValue, LPCTSTR szSection = NULL );

	/// SetValueAsString() : INI 내용을 입력한다. ( for TCHAR )
	/**
	 * @param szKey[in] 키명
	 * @param szValue[in] 키값
	 * @param ValueSize[in] szValue 의 사이즈를 설정한다.
	 * @param szSection[in] 섹션명
	 *							
	 * @return TRUE 성공
	 * @return FALSE 실패
	 */
	BOOL SetValueAsString( LPCTSTR szKey, 
		LPCTSTR szValue, 
		size_t ValueSize, 
		LPCTSTR szSection = NULL );

	/// Load() : 메모리에 있는 INI 파일에서 내용을 읽어 클래스에 삽입시킨다.
	BOOL Load( LPTSTR tszMemory );
	/// Load() : INI 파일에서 내용을 읽어 클래스에 삽입시킨다.
	BOOL Load( EA_CTextFile *plfFile );
	/// Save() : 클래스에 있는 내용을 파일로 저장한다.
	BOOL Save( EA_CTextFile*plfFile );

private:
	/// GetSection() : 사용자가 원하는 Section 을 SectionType * 로 반환
	SectionType *GetSection( LPCTSTR szSection );

	/// GetKey() : 사용자가 원하는 Key 를 KeyType * 로 반환
	KeyType *GetKey( LPCTSTR szKey );
	/// GetKey() : 사용자가 원하는 Key 를 KeyType * 로 반환
	KeyType	*GetKey( LPCTSTR szKey, LPCTSTR szSection );

	/// CheckWriteFlag() : 파일에 쓸 수 있는지 오픈할 때 입력된 플래그를 검사한다.
	BOOL CheckWriteFlag( void );
	/// SetValue() : Key 를 생성하여 Section 에 삽입시킨다. 해당 Section 이 없다면 새로 생성한다.
	BOOL SetValue( LPCTSTR szKey, LPCTSTR szValue, LPCTSTR szSection );

	/// CreateSection() : Section 한개를 새로 생성한다.
	BOOL CreateSection( LPCTSTR szSection );
	/// CreateSection() : Section 한개를 새로 생성한다.
	BOOL CreateSection( LPCTSTR szSection, KeyArray Keys );

	/// WriteLn() : 파일에 포맷에 맞춰서 한줄을 저장한다.
	int WriteLn( EA_CTextFile *plfFile, LPCTSTR fmt, ... );

private:
	SectionArray	m_Sections;
	TCHAR		m_szFileName[MA_MAX_PATH];

	u32		m_u32CurrentSIndex;
	TCHAR		m_szCurrentSectionName[MA_MAX_PATH];
	BOOL		m_bDirty;
	u32		m_u32CurrentKeyIndex;
	EA_EOpenFlags	m_nFlag;
};

_EA_NAMESPACE_END

#endif /* _EA_CINIFILE_H_ */
