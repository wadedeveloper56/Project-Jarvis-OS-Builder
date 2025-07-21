#include "AssignmentExpression.h"

using namespace WadeSpace;
using namespace std;

AssignmentExpression::AssignmentExpression(ConditionalExpression* ce) :ce(ce), ue(NULL), oper(NULL), ae(NULL) {}
AssignmentExpression::AssignmentExpression(UnaryExpression* ue, AssignmentOperator* oper, AssignmentExpression* ae) :ce(NULL), ue(ue), oper(oper), ae(ae) {}
AssignmentExpression::AssignmentExpression() :ce(NULL), ue(NULL), oper(NULL), ae(NULL) {}
AssignmentExpression::~AssignmentExpression() {
	if (ce) delete ce;
	if (ue) delete ue;
	if (oper) delete oper;
	if (ae) delete ae;
}