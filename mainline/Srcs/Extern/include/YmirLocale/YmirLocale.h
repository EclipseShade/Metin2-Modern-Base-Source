#pragma once

#define WIN32_LEAN_AND_MEAN		// 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
#include <windows.h>

#include <YmirBase/YmirBase.h>
#include <YmirBase/Primitives.h>
#include <YmirBase/SmartPointer.h>
#include <YmirBase/Log.h>
#include <YmirBase/TStringBuffer.h>

 #if defined( EL_LOCALE_EXPORTS )
	#define EL_LOCALE_API __declspec(dllexport)
#elif defined( EL_LOCALE_IMPORTS )
	#define EL_LOCALE_API __declspec(dllimport)
#else
	#define EL_LOCALE_API
#endif
