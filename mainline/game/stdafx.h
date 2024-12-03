#ifndef __STDAFX__H
#define __STDAFX__H

// Basic features
// Enable or disable memory pooling for specific object types
//#define M2_USE_POOL
// Enable or disable heap allocation debugging
//#define DEBUG_ALLOC

#include "debug_allocator.h"

#include "../../ExternGame/libthecore/include/stdafx.h"

// COMMON
#include "../common/utils.h"
#include "../common/CommonDefines.h"
#include "../common/tables.h"
#include "../common/length.h"
#include "../common/billing.h"
#include "../common/singleton.h"
#include "../common/teen_packet.h"
#include "../common/VnumHelper.h"

// Standard Libraries
#include <algorithm>	// For std::transform (used for applying a function to a range of elements)
#include <math.h>		// For mathematical functions (e.g., sin, cos, sqrt, etc.)
#include <list>			// For std::list (a doubly linked list implementation)
#include <map>			// For std::map (a sorted associative container that contains key-value pairs)
#include <set>			// For std::set (a sorted container that contains unique elements)
#include <queue>		// For std::queue (a first-in, first-out data structure)
#include <string>		// For std::string (to handle strings more conveniently)
#include <vector>		// For std::vector (a dynamic array that can change size)
#include <sstream>		// For std::stringstream (for input and output string streams)
#include <fstream>		// For file stream classes (e.g., std::ifstream, std::ofstream)
#include <utility>		// For std::pair (a simple container for two values)
#include <functional>	// For std::function (to store functions or function objects)
#include <iomanip>		// For std::setw and std::setfill
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <stack>

inline void stl_lowers(std::string& rstRet)
{
	for (size_t i = 0; i < rstRet.length(); ++i)
		rstRet[i] = tolower(rstRet[i]);
}

namespace std {
	template <typename T> T MINMAX(T min, T value, T max)
	{
		T tv;

		tv = (min > value ? min : value);
		return (max < tv) ? max : tv;
	}
} 

#if _MSC_VER > 1500
	#define auto_ptr unique_ptr
#endif

#ifdef __GNUC__
	#include <float.h>
	#include <tr1/unordered_map>
	#include <tr1/unordered_set>
	#include <ext/functional>
	
	#define TR1_NS std::tr1
#else	
	#define TR1_NS boost
	#define isdigit iswdigit
	#define isspace iswspace
#endif

#include "typedef.h"
#include "event.h"

#define PASSES_PER_SEC(sec) ((sec) * passes_per_sec)

#ifndef M_PI
	#define M_PI    3.14159265358979323846 /* pi */
#endif

#ifndef M_PI_2
	#define M_PI_2  1.57079632679489661923 /* pi/2 */
#endif

#define IN
#define OUT





/* OTHER STANDARD LIBRARIES ETC

// Standard Libraries
#include <algorithm>            // For standard algorithms (e.g., sort, transform).
#include <any>                  // For std::any, type-safe container for any type.
#include <array>                // For std::array, fixed-size array wrapper.
#include <atomic>               // For atomic operations.
#include <barrier>              // For thread synchronization at specific points.
#include <bit>                  // For bit manipulations and operations.
#include <cassert>              // For assert statements for debugging.
#include <chrono>               // For time utilities (time_point, duration, etc.).
#include <cctype>               // For character classification and case conversion functions.
#include <cerrno>               // For error handling.
#include <cfenv>                // For floating-point environment.
#include <cfloat>               // For limits of floating-point types.
#include <climits>              // For limits of integral types.
#include <cstring>              // For C-style string handling functions.
#include <cstdlib>              // For general utilities (memory allocation, process control, etc.).
#include <ctime>                // For time and date functions.
#include <deque>                // For std::deque, a double-ended queue.
#include <exception>            // For exception handling.
#include <execution>            // For execution policies (e.g., parallel algorithms).
#include <filesystem>           // For file system manipulation (paths, directories, files).
#include <format>               // For type-safe string formatting utilities.
#include <future>               // For async tasks and futures.
#include <iomanip>              // For input/output manipulators.
#include <initializer_list>     // For standardized initializer syntax.
#include <iterator>             // For iterator support.
#include <list>                 // For std::list, a doubly linked list.
#include <map>                  // For std::map, a sorted associative container.
#include <memory>               // For smart pointers and memory management utilities.
#include <memory_resource>      // For polymorphic memory resources.
#include <mutex>                // For mutexes and locks.
#include <new>                  // For low-level memory management utilities.
#include <numeric>              // For numerical operations (e.g., accumulate).
#include <optional>             // For std::optional, representing values that may or may not be present.
#include <queue>                // For std::queue, a first-in, first-out data structure.
#include <random>               // For random number generation facilities.
#include <ranges>               // For range-based operations on collections.
#include <regex>                // For regular expressions.
#include <set>                  // For std::set, a sorted container that contains unique elements.
#include <shared_mutex>         // For shared mutexes (reader-writer locks).
#include <span>                 // For std::span, providing a view into a contiguous sequence.
#include <stdexcept>            // For standard exceptions.
#include <string>               // For std::string handling.
#include <string_view>          // For non-owning views of strings.
#include <thread>               // For multithreading support.
#include <tuple>                // For std::tuple, a fixed-size collection of heterogeneous values.
#include <type_traits>          // For type manipulation and traits.
#include <typeinfo>             // For runtime type information.
#include <utility>              // For std::pair and utility functions.
#include <variant>              // For std::variant, a type-safe union.
#include <valarray>             // For valarray, optimized for numerical tasks.
#include <semaphore>            // For semaphores for thread synchronization.
#include <source_location>      // For obtaining source information at function call.
#include <locale>               // For localization and internationalization support.
#include <csignal>              // For handling signals (e.g., interrupts).

// Additional commonly used C++ libraries
#include <cassert>      // For assert statement. Available since GCC 3.0.
#include <ctime>        // For time and date functions. Available since GCC 3.0.
#include <thread>       // For multithreading support. Available since GCC 4.8.
#include <mutex>        // For mutexes and locks. Available since GCC 4.8.
#include <condition_variable> // For condition variables, available since GCC 4.8.
#include <array>        // For std::array (fixed-size array wrapper). Available since GCC 4.3.
#include <tuple>        // For std::tuple (fixed-size collection of heterogeneous values). Available since GCC 4.0.
#include <unordered_map> // For std::unordered_map (hash table-based associative container). Available since GCC 4.3.
#include <unordered_set> // For std::unordered_set (hash table-based unique container). Available since GCC 4.3.
#include <functional>   // For std::function (generic function wrappers). Available since GCC 4.2.
#include <numeric>      // For numerical operations (e.g., accumulate). Available since GCC 3.0.
#include <iterator>     // For iterator support. Available since GCC 3.0.

// Additions for C++11 and later
#include <chrono>                     // For time utilities (time_point, duration, etc.). Available since GCC 4.3.
#include <initializer_list>           // For initializer lists, allowing easy initialization of containers. Available since GCC 4.3.
#include <thread>                     // For std::thread, for creating threads, Available since GCC 4.8.
#include <future>                     // For async tasks and futures, Available since GCC 4.8.
#include <regex>                      // For regular expressions, Available since GCC 4.9.
#include <random>                     // For random number generation facilities, Available since GCC 4.3.
#include <shared_mutex>               // For shared mutexes (reader-writer locks), Available since GCC 7.1.
#include <scoped_lock>                // For RAII-style locking, Available since GCC 7.1.
#include <filesystem>                 // For file system library (path manipulation, file system queries), Available since GCC 8.
#include <variant>                    // For std::variant (type-safe union), Available since GCC 7.1.
#include <any>                        // For std::any (type-safe container for single values of any type), Available since GCC 7.1.
#include <optional>                  // For std::optional (optional values), Available since GCC 7.1.
#include <string_view>                // For std::string_view (non-owning views of strings), Available since GCC 7.1.
#include <list>                       // For std::list, a doubly linked list, Available since GCC 3.0.
#include <span>                       // For std::span, which provides a view into a contiguous sequence of elements, Available since GCC 11.
#include <barrier>                    // For synchronization between a number of threads, Available since GCC 11.
#include <semaphore>                  // For semaphores for thread synchronization, Available since GCC 11.

// Additions for C++17
#include <optional>                       // For std::optional (optional values), introduced in C++17.
#include <variant>                        // For std::variant (type-safe union), introduced in C++17.
#include <string_view>                   // For std::string_view (non-owning views of strings), introduced in C++17.
#include <charconv>                      // For converting between characters and numbers, introduced in C++17.
#include <filesystem>                    // For filesystem support (path manipulation, file queries), improved C++17 support.
#include <memory_resource>               // For memory resource management (polymorphic allocators), introduced in C++17.
#include <execution>                     // For execution policies (parallel algorithms), introduced in C++17.
#include <shared_mutex>                  // For shared mutexes (reader-writer locks), introduced in C++17.
#include <any>                           // For std::any (type-safe container for single values of any type), introduced in C++17.

// Additions for C++20
#include <concepts>                     // For concepts to specify template requirements, introduced in C++20.
#include <ranges>                       // For view and algorithm support, introduced in C++20.
#include <span>                         // For std::span, which provides a view into a contiguous sequence of elements, introduced in C++20.
#include <barrier>                      // For synchronization between a number of threads, introduced in C++20.
#include <semaphore>                     // For semaphores for thread synchronization, introduced in C++20.
#include <format>                       // For format strings and type-safe formatting, introduced in C++20.
#include <source_location>              // For obtaining source information at the point of a function call, introduced in C++20.
#include <bit>                          // For bit manipulations and operations, introduced in C++20.
#include <std::print>                   // For printf-style formatting functions, introduced in C++20.

// Additions for C++23
#include <expected>                   // For std::expected, a type that represents success or failure, introduced in C++23.
#include <synchronization>             // For improved synchronization primitives, introduced in C++23.
#include <std::span>                   // Updates and improvements to std::span, introduced in C++20 and still relevant in C++23.
#include <std::type_traits>            // Enhanced type manipulation and traits, introduced in C++11 and further improvements in C++23.

//
#include <locale>                       // For localization and internationalization support.
#include <iomanip>                      // For input/output manipulators (formatting in I/O).
#include <valarray>                     // For valarray (optimized for numerical tasks using arrays).
#include <tuple>                        // For std::tuple, a fixed-size collection of heterogeneous values, available since GCC 4.0.
#include <chrono>                       // For time utilities (time_point, duration, etc.).
#include <numeric>                      // For numerical operations, such as accumulate and adjacent_difference.
#include <iterator>                     // For iterator utilities (including std::back_inserter and std::next).
#include <cctype>                       // For character classification and case conversion functions.
#include <csignal>                     // For handling signals (e.g., interrupts).
#include <cstdlib>                     // For general utilities (memory allocation, process control, etc.).

*/
#endif