#ifndef __INC_METiN_II_DBSERV_STDAFX_H__
#define __INC_METiN_II_DBSERV_STDAFX_H__

// Standard Libraries
#include <functional>
#include <sstream>
#include <string>
#include <memory>
#include <list>
#include <map>
#include <set>

#include "../../ExternGame/libsql/AsyncSQL.h"
#include "../../ExternGame/libthecore/include/stdafx.h"

#ifndef __WIN32__
	#include <semaphore.h>
#else
	#define isdigit iswdigit
	#define isspace iswspace
#endif

//Common
#include "../common/CommonDefines.h"
#include "../common/length.h"
#include "../common/tables.h"
#include "../common/singleton.h"
#include "../common/utils.h"

/* Support For Older Versions */
#ifndef itertype
	#if _MSC_VER > 1500 || __FreeBSD__
		#include <unordered_map>
		#include <unordered_set>
		
		#define auto_ptr unique_ptr
		#define itertype(v) decltype((v).begin())
	#elif _MSC_VER <= 1500
		using std::undordered_map = std::map;
		using std::undordered_set = std::set;
		using std::hash = std::hash;
		
		#define decltype typeof
		#define itertype(v) typeof((v).begin())
	#endif
#endif

#endif //__INC_METiN_II_DBSERV_STDAFX_H__