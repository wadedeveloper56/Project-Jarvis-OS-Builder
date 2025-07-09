#include "Pointer.h"

using namespace WadeSpace;

Pointer::Pointer(std::string value, std::vector<TypeQualifier>& list) :nameStr(value), list(list), level(1), ptr(std::nullopt) {}
Pointer::Pointer(std::string value, std::vector<TypeQualifier>& list, Pointer& ptr) :nameStr(value), list(list), level(1), ptr(ptr) {}
Pointer::Pointer(std::string value, Pointer& ptr) :nameStr(value), list(std::nullopt), level(1), ptr(ptr) {}
Pointer::Pointer(std::string value) :nameStr(value), list(std::nullopt), level(1), ptr(std::nullopt) {}
Pointer::Pointer() :nameStr(""), list(std::nullopt), level(1), ptr(std::nullopt) {}
Pointer::~Pointer() {}
void Pointer::inc() { level++; }
