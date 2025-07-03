#include "AssignmentOperator.h"

using namespace WadeSpace;

AssignmentOperator::AssignmentOperator(std::string value, AssignmentOperatorType type):operatorStr(value),type(type) {

}

AssignmentOperator::AssignmentOperator() :operatorStr(""), type(NONE) {

}

AssignmentOperator::~AssignmentOperator() {

}

std::string AssignmentOperator::getoperator() const {
	return operatorStr;
}

AssignmentOperatorType AssignmentOperator::getType() const {
	return type;
}
