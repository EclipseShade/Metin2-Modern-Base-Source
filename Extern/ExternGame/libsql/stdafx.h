#include <string>

#if __linux__
	#define strlcpy strncpy	
#endif

#include <cstdlib>
#include <cstring>

#include "../libthecore/include/stdafx.h"
#include "AsyncSQL.h"
