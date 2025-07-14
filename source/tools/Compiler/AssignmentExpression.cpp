#include "AssignmentExpression.h"

using namespace WadeSpace;
using namespace std;

AssignmentExpression::AssignmentExpression(ConditionalExpression& ce) :ce(ce), ue(nullopt), oper(nullopt), ae(nullopt) {}
AssignmentExpression::AssignmentExpression(UnaryExpression& ue, AssignmentOperator oper, AssignmentExpression& ae) :ce(nullopt), ue(ue), oper(oper), ae(ae) {}
AssignmentExpression::AssignmentExpression() :ce(nullopt), ue(nullopt), oper(nullopt), ae(nullopt) {}
AssignmentExpression::~AssignmentExpression() {}