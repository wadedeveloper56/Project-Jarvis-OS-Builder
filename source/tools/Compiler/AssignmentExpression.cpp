#include "AssignmentExpression.h"

using namespace WadeSpace;

AssignmentExpression::AssignmentExpression() :Expression() {}
AssignmentExpression::AssignmentExpression(Expression& left) :Expression(left) {}
AssignmentExpression::AssignmentExpression(Expression& left, AssignmentOperator& ao, Expression& right) :Expression(left, ao, right) {}
