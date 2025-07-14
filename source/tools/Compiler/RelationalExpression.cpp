#include "RelationalExpression.h"

using namespace WadeSpace;
using namespace std;

RelationalExpression::RelationalExpression(ShiftExpression& se) :re(nullopt), op(""), se(nullopt) {}
RelationalExpression::RelationalExpression(RelationalExpression& eq, string op, ShiftExpression& se) :re(re), op(op), se(se) {}
RelationalExpression::RelationalExpression() :re(nullopt), op(""), se(nullopt) {}
RelationalExpression::~RelationalExpression() {}