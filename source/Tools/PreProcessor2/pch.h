#pragma once
#if defined(_WIN32) || defined(__CYGWIN__) || defined(__MINGW32__)
#  define _WIN32_WINNT 0x0602
#  define NOMINMAX
#  include <windows.h>
#  undef ERROR
#endif
#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cstddef> // IWYU pragma: keep
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <exception>
#include <fstream>
#include <iostream>
#include <istream>
#include <limits>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <mutex>
#include <unordered_map>
#include <utility>
#include <vector>
#include <direct.h>

#pragma warning(disable:4267)
#pragma warning(disable:4244)
#pragma warning(disable:4018)
#pragma warning(disable:4311)
#pragma warning(disable:4146)
#pragma warning(disable:4113)
#pragma warning(disable:5286)
#pragma warning(disable:4312)
#pragma warning(disable:4477)
#pragma warning(disable:5287)
#pragma warning(disable:4047)
#pragma warning(disable:4065)
#pragma warning(disable:4005)

