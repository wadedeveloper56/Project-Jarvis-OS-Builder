#include "Expression.h"

using namespace WadeSpace;
using namespace std;

Expression::Expression(AssignmentExpression& ae) :ae(ae), oper(""), exp(nullopt) {}
Expression::Expression(Expression& exp, string oper, AssignmentExpression& ae) :ae(ae), oper(oper), exp(exp) {}
Expression::Expression() :ae(nullopt), oper(""), exp(nullopt) {}
Expression::~Expression() {}
