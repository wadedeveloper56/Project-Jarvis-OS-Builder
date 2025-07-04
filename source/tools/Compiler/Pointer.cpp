#include "Pointer.h"

using namespace WadeSpace;

Pointer::Pointer(std::string value, std::vector<TypeQualifier>* list) :nameStr(value), list(list), level(1), ptr(NULL) {}
Pointer::Pointer(std::string value, std::vector<TypeQualifier>* list, Pointer* ptr) :nameStr(value), list(list), level(1), ptr(ptr) {}
Pointer::Pointer(std::string value, Pointer* ptr) :nameStr(value), list(NULL), level(1), ptr(ptr) {}
Pointer::Pointer(std::string value) :nameStr(value), list(NULL), level(1), ptr(NULL) {}
Pointer::Pointer() :nameStr(""), list(NULL), level(1), ptr(NULL) {}
Pointer::~Pointer() {}
std::string Pointer::getNameStr() const { return nameStr; }
std::vector<TypeQualifier>* Pointer::getList() const { return list; }
int Pointer::getLevel() const { return level; }
void Pointer::inc() { level++; }
