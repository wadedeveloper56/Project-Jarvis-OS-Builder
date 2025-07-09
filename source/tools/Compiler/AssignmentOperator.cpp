#include "AssignmentOperator.h"

using namespace WadeSpace;

AssignmentOperator::AssignmentOperator(std::string value, TokenType type):operatorStr(value),type(type) {

}

AssignmentOperator::AssignmentOperator() :operatorStr(""), type(NONE) {

}

AssignmentOperator::~AssignmentOperator() {

}
