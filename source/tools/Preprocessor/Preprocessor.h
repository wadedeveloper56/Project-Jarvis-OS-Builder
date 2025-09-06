#pragma once

#ifdef PREPROCESSOR_EXPORTS
#define PREPROCESSOR_API __declspec(dllexport)
#else
#define PREPROCESSOR_API __declspec(dllimport)
#endif

#include <string>
#include <vector>

using namespace std;

namespace PreProcessor {
}
