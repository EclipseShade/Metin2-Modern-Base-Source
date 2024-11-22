#pragma once

EL_BOOST_PTR(EL_Language);
EL_BOOST_PTR(EL_DCFont);

class EL_Language
{
public:
	EL_Language();
	virtual ~EL_Language();

	virtual EL_VOID DecodeString(const EL_SimpleStringA& in, EL_StringBufferW* out);
	virtual EL_VOID EncodeString(const EL_SimpleStringW& in, EL_StringBufferA* out);
			
	//virtual EL_DCFontPtr GetDefaultFont();
	//virtual EL_DCFontPtr NewFont();

private:
	//EL_DCFontPtr m_defFontPtr;
};