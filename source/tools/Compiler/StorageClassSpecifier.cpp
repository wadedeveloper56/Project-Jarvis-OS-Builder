#include "StorageClassSpecifier.h"

using namespace WadeSpace;

StorageClassSpecifier::StorageClassSpecifier(std::string value, TokenType type) :operatorStr(value), type(type) {}
StorageClassSpecifier::StorageClassSpecifier() :operatorStr(""), type(NONE) {}
StorageClassSpecifier::~StorageClassSpecifier() {}
