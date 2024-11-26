#ifndef __INC_METiN_II_DBSERV_STDAFX_H__
#define __INC_METiN_II_DBSERV_STDAFX_H__

#include <map>

#include "../../ExternGame/libthecore/include/stdafx.h"

#ifndef __WIN32__
	#include <semaphore.h>
#else
	#define isdigit iswdigit
	#define isspace iswspace
#endif

#include "../common/length.h"
#include "../common/tables.h"
#include "../common/singleton.h"
#include "../common/utils.h"
#include "../common/stl.h"
#include "../common/CommonDefines.h"

#endif
