#ifndef __INC_METiN_II_DBSERV_STDAFX_H__
#define __INC_METiN_II_DBSERV_STDAFX_H__

//Common
#include "../common/CommonDefines.h"
#include "../common/length.h"
#include "../common/tables.h"
#include "../common/singleton.h"
#include "../common/utils.h"

// Standard Libraries
#include <sstream>
#include <string>
#include <memory>
#include <list>
#include <map>
#include <set>

#ifndef __WIN32__
	#include <semaphore.h>
#else
	#define isdigit iswdigit
	#define isspace iswspace
#endif

#include "../../ExternGame/libsql/AsyncSQL.h"
#include "../../ExternGame/libthecore/include/stdafx.h"

/* Support For Older Versions */
#ifndef itertype
	#if _MSC_VER <= 1500
		#include <boost/unordered_map.hpp>
		#include <boost/unordered_set.hpp>

		using std::undordered_map = boost::unordered_map;
		using std::undordered_set = boost::unordered_set;
		using std::hash = boost::hash;
		
		#define decltype typeof
		#define itertype(v) typeof((v).begin())
	#else
		#include <unordered_map>
		#include <unordered_set>
		
		#define auto_ptr unique_ptr
		#define itertype(v) decltype((v).begin())
	#endif
#endif
