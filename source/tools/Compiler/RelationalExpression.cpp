#include "RelationalExpression.h"

using namespace WadeSpace;
using namespace std;

RelationalExpression::RelationalExpression(ShiftExpression* se) :re(NULL), op(""), se(NULL) {}
RelationalExpression::RelationalExpression(RelationalExpression* eq, string op, ShiftExpression* se) :re(re), op(op), se(se) {}
RelationalExpression::RelationalExpression() :re(NULL), op(""), se(NULL) {}
RelationalExpression::~RelationalExpression() {}