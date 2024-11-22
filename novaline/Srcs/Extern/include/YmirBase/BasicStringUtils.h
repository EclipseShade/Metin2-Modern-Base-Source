#pragma once

#include "TBasicString.h"

EL_BasicStringA EL_BasicStringA_FromInt(EL_INT val);
EL_BasicStringA EL_BasicStringA_FromFloat(EL_FLOAT val);
EL_BasicStringA EL_BasicStringA_FromBool(EL_BOOL val);

EL_BasicStringW EL_BasicStringW_FromInt(EL_INT val);
EL_BasicStringW EL_BasicStringW_FromFloat(EL_FLOAT val);
EL_BasicStringW EL_BasicStringW_FromBool(EL_BOOL val);

EL_BasicStringE EL_BasicStringE_FromInt(EL_INT val);
EL_BasicStringE EL_BasicStringE_FromFloat(EL_FLOAT val);
EL_BasicStringE EL_BasicStringE_FromBool(EL_BOOL val);

#if defined( _UNICODE )
#	define EL_BasicString_FromInt EL_BasicStringW_FromInt
#	define EL_BasicString_FromFloat EL_BasicStringW_FromFloat
#	define EL_BasicString_FromBool EL_BasicStringW_FromBool
#else
#	define EL_BasicString_FromInt EL_BasicStringA_FromInt
#	define EL_BasicString_FromFloat EL_BasicStringA_FromFloat
#	define EL_BasicString_FromBool EL_BasicStringA_FromBool
#endif