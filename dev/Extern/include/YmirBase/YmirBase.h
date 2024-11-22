// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 및 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#if defined( EL_BASE_EXPORTS )
	#define EL_BASE_API __declspec(dllexport)
#elif defined( EL_BASE_IMPORTS )
	#define EL_BASE_API __declspec(dllimport)
#else
	#define EL_BASE_API
#endif

#include <Mantle/Mantle.h>
#include <Mantle/MA_String.h>
#include <tchar.h>

#include "STLString.h"
#include "STLVector.h"
#include "STLDeque.h"
#include "STLList.h"
#include "STLMap.h"
#include "STLHashMap.h"

#include "Macro.h"
#include "Primitives.h"
