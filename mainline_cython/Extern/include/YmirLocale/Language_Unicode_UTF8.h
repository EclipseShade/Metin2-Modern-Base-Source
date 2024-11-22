#pragma once

#include "Language.h"

EL_BOOST_PTR(EL_DCFont);

class EL_Language_Unicode_UTF8 : public EL_Language
{
public:
	virtual ~EL_Language_Unicode_UTF8();

	virtual void DecodeString(const EL_SimpleStringA& in, EL_StringBufferW* out);
	virtual void EncodeString(const EL_SimpleStringW& in, EL_StringBufferA* out);

	//virtual EL_DCFontPtr NewDefaultFont();
};