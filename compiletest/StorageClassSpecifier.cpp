#include "StorageClassSpecifier.h"

using namespace WadeSpace;

StorageClassSpecifier::StorageClassSpecifier(std::string value, StorageClassSpecifierType type) :operatorStr(value), type(type) {
}

StorageClassSpecifier::StorageClassSpecifier() :operatorStr(""), type(NONE2) {
}

StorageClassSpecifier::~StorageClassSpecifier() {
}

std::string StorageClassSpecifier::getoperator() const {
	return operatorStr; 
}

StorageClassSpecifierType StorageClassSpecifier::getType() const {
	return type; 
}
