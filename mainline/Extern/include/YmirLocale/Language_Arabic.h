#pragma once

#include "Language.h"

class EL_Language_Arabic : public EL_Language
{
public:
	static EL_VOID EncodeShape(const EL_SimpleStringW& orig, EL_StringBufferW* retShape);
};